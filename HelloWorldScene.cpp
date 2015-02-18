#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenu.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
	CCLOG("Before Splash");

	this->scheduleOnce(schedule_selector(HelloWorld::GoToMenuScene),3);
	auto splashsprite = Sprite::create("splash.png");
	CCLOG("After Splash");
	splashsprite->setPosition(visibleSize.width/2+origin.x,visibleSize.height/2+origin.y);
	this->addChild(splashsprite);
	//CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("ttnu.mp3");
	//CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("ttnu.mp3");
    
    
    return true;
}

void HelloWorld::GoToMenuScene(float dt)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}
