#include "GameScene.h"
#include "Copter.h"
#include "Rock.h"
#include "SimpleAudioEngine.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask( PhysicsWorld::DEBUGDRAW_ALL );
    
    scene->getPhysicsWorld()->setGravity(Vect(0,-100));
	
	auto layer = GameScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());

    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    //Setting up background
	bg1 = Sprite::create("bg1.png");
	bg1->setPosition(origin.x,visibleSize.height/2+origin.y);
	bg1->setGlobalZOrder(1);
	this->addChild(bg1);
	bg2 = Sprite::create("bg2.png");
	bg2->setPosition(bg2->getContentSize().width/2-visibleSize.width/2,visibleSize.height/2+origin.y);
	bg2->setGlobalZOrder(2);
	this->addChild(bg2);
	//Creating Copter
	copter =new Copter(this);
	copter->copterSprite->setGlobalZOrder(100);
	//Setting up score
	score =0;
	__String *scoreString = __String::createWithFormat("%i",score);
	scoreLabel = Label::createWithTTF(scoreString->getCString(),"fonts/Marker Felt.ttf",visibleSize.height*0.1);
	scoreLabel->setPosition(visibleSize.width*0.85,visibleSize.height*0.85);
	scoreLabel->setColor( Color3B::MAGENTA);
	this->addChild(scoreLabel);
	scoreLabel->setGlobalZOrder(500);
	//Creating Rocks
	for(int i=0;i<5;i++)
	new Rock(this);
	//Setting up Events
	Device::setAccelerometerEnabled(true);
	//Touch Event
	auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this); 
	listener->onTouchMoved =CC_CALLBACK_2(GameScene::onTouchMoved,this);
	listener->onTouchEnded =CC_CALLBACK_2(GameScene::onTouchEnded,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	//Accelerometer Event
	auto acclistener = EventListenerAcceleration::create(CC_CALLBACK_2(GameScene::onAcceleration,this));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(acclistener,this);
	//Collision Event
	auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("gamecopter.mp3");
    
   CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("gamecopter.mp3", true);
	//Scheduling
	this->schedule(schedule_selector(GameScene::UpdateAll));
    return true;
}
bool GameScene::onTouchBegan(cocos2d::Touch *touch,cocos2d::Event *event)
{
	copter->invertCopterMovement(true);
	return true;
}
void GameScene::onTouchMoved(cocos2d::Touch *touch,cocos2d::Event *event)
{
	copter->invertCopterMovement(true);
}
void GameScene::onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *event)
{
	copter->invertCopterMovement(false);
}
void GameScene::onAcceleration(cocos2d::Acceleration *acc,cocos2d::Event *event)
{
       if(acc->x<-0.2)
		   copter->setMovingDown(true);
	   else if(acc->x>0.2)
		   copter->setMovingUp(true);
	   else
	   {
		   copter->setMovingUp(false);
		   copter->setMovingDown(false);
	   }
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{
    PhysicsBody *a = contact.getShapeA()->getBody();
    PhysicsBody *b = contact.getShapeB()->getBody();
    
    
    if ( ( 1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask() ) || ( 2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask() ) )
    {
        CCLOG( "COLLISION HAS OCCURED" );
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		copter->DestroyCopter();
        auto scene = GameOverScene::createScene(score);
        Director::getInstance()->replaceScene(TransitionFade::create(0.5,scene));
    }
    
    return true;
}
void GameScene::UpdateAll(float dt)
{
	int ix=0;
    //Moving invisible
	ix = copter->MoveInvisible();
	//Calculating Score
	score = ix*0.5;
	//Creating Rocks
	if(ix%1000==0)
	new Rock(this,ix+visibleSize.width);
	//Displaying Score
	__String *scoreString = __String::createWithFormat("%i",score);
	scoreLabel->setString(scoreString->getCString());
	scoreLabel->setPosition(ix,visibleSize.height*0.90);
	//Scrolling code below
	if(bg1->getPosition().x+bg1->getContentSize().width<ix)
		bg1->setPosition(bg2->getPosition().x+(bg2->getContentSize().width),visibleSize.height/2+origin.y);
	if(bg2->getPosition().x+bg2->getContentSize().width<ix)
		bg2->setPosition(bg1->getPosition().x+(bg1->getContentSize().width),visibleSize.height/2+origin.y);
	//Moving Copter
	copter->CheckFalling();
	if(copter->copterBody->getPosition().y>visibleSize.height*0.3);
	copter->MoveUp();
	if(copter->copterBody->getPosition().y<visibleSize.height*0.9)
	copter->MoveDown();
}
