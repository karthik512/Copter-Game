#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenu.h"
#include "HighScore.h"

USING_NS_CC;

unsigned int iscore;

Scene* GameOverScene::createScene(unsigned int tempScore)
{
	iscore = tempScore;
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();



	auto gameOver = LabelTTF::create("GAME OVER!!","fonts/Marker Felt.ttf",visibleSize.height*0.1);
    gameOver->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height*0.9));
	this->addChild(gameOver);
	CCLOG("Game Over");


	auto urScore = LabelTTF::create("Your Score: ","fonts/Marker Felt.ttf",visibleSize.height*0.05);
    urScore->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height*0.7));
	this->addChild(urScore);
	CCLOG("Your Score");


	__String *tempScore = __String::createWithFormat("%i",iscore);   
    auto currentScore = LabelTTF::create(tempScore->getCString(),"fonts/Marker Felt.ttf",visibleSize.height*0.05);
    currentScore->setPosition(Point(visibleSize.width/2,visibleSize.height*0.5));
    this->addChild(currentScore);
	CCLOG("Your Score");
    
    auto retryItem = MenuItemImage::create("retry.png","retry.png",CC_CALLBACK_1(GameOverScene::GoToGameScene,this));
    retryItem->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height*0.4));
	CCLOG("Menu 1");
 
    auto mainMenuItem = MenuItemImage::create("menu.png","menu.png",CC_CALLBACK_1(GameOverScene::GoToMainMenuScene,this));
    mainMenuItem->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height*0.3));
	CCLOG("Menu 2");
    
    auto menu = Menu::create(retryItem,mainMenuItem,NULL);
    menu->setPosition(Point::ZERO);  
    this->addChild(menu);

	UserDefault *def1 = UserDefault::getInstance( ); 
    highScore1 = def1->getIntegerForKey("HIGHSCORE1",0);

	UserDefault *def2 = UserDefault::getInstance( ); 
    highScore2 =  def2->getIntegerForKey("HIGHSCORE2",0);

	UserDefault *def3 = UserDefault::getInstance( ); 
    highScore3 =  def3->getIntegerForKey("HIGHSCORE3",0);

	UserDefault *def4 = UserDefault::getInstance( ); 
    highScore4 =  def4->getIntegerForKey("HIGHSCORE4",0);

	UserDefault *def5 = UserDefault::getInstance( ); 
    highScore5 = def5->getIntegerForKey("HIGHSCORE5",0);
	int highscoreArray[5];
	if (iscore>highScore5)
    {
		highscoreArray[0] = highScore1;
		highscoreArray[1] = highScore2;
		highscoreArray[2] = highScore3;
		highscoreArray[3] = highScore4;
		highscoreArray[4] = iscore;

		for(int i=0;i<4;i++)
        for(int j=i+1;j<5;j++)
		{
			if(highscoreArray[i]>highscoreArray[j])
			{
				int t;
				t = highscoreArray[i];
				highscoreArray[i] = highscoreArray[j];
				highscoreArray[j] = t;
			}
		}  
        def1->setIntegerForKey("HIGHSCORE5",highscoreArray[0]);
		def2->setIntegerForKey("HIGHSCORE4",highscoreArray[1]);
		def3->setIntegerForKey("HIGHSCORE3",highscoreArray[2]);
		def4->setIntegerForKey("HIGHSCORE2",highscoreArray[3]);
		def5->setIntegerForKey("HIGHSCORE1",highscoreArray[4]);
    }
    def1->flush();
	def2->flush();
	def3->flush();
	def4->flush();
	def5->flush();
 
    return true;
}

/*
unsigned int GameOverScene::getHigh()
{
	return highScore;
}
*/
void GameOverScene::GoToMainMenuScene(cocos2d::Ref *sender)
{
    auto scene = MainMenu::createScene(); 
    Director::getInstance()->replaceScene(TransitionFade::create(0.5,scene));
}

void GameOverScene::GoToGameScene(cocos2d::Ref *sender)
{
    auto scene = GameScene::createScene();   
    Director::getInstance()->replaceScene(TransitionFade::create(0.5,scene));
}
