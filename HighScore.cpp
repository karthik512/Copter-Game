#include "HighScore.h"
#include "GameOverScene.h"

USING_NS_CC;

unsigned int myScore;

Scene* HighScore::createScene()
{
	auto scene = Scene::create();
    auto layer = HighScore::create();
    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool HighScore::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

	auto high = LabelTTF::create("HIGHSCORES","fonts/Marker Felt.ttf",visibleSize.height*0.1);
    high->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height*0.90));
	this->addChild(high);

	DisplayScore();

    return true;
}

void HighScore::DisplayScore()
{
	int highScore1, highScore2, highScore3, highScore4, highScore5;

	UserDefault *def1 = UserDefault::getInstance( );
    highScore1 = def1->getIntegerForKey("HIGHSCORE1",0);

	__String *nScore1 = __String::createWithFormat("1. %i",highScore1); 
	auto score1 = LabelTTF::create(nScore1->getCString(),"fonts/Marker Felt.ttf",visibleSize.height*0.07);
    score1->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height*0.8));
	this->addChild(score1);

	UserDefault *def2 = UserDefault::getInstance( ); 
    highScore2 =  def2->getIntegerForKey("HIGHSCORE2",0);

	__String *nScore2 = __String::createWithFormat("2. %i",highScore2); 
	auto score2 = LabelTTF::create(nScore2->getCString(),"fonts/Marker Felt.ttf",visibleSize.height*0.07);
    score2->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height*0.7));
	this->addChild(score2);

	UserDefault *def3 = UserDefault::getInstance( ); 
    highScore3 =  def3->getIntegerForKey("HIGHSCORE3",0);

	__String *nScore3 = __String::createWithFormat("3. %i",highScore3); 
	auto score3 = LabelTTF::create(nScore3->getCString(),"fonts/Marker Felt.ttf",visibleSize.height*0.07);
    score3->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height*0.6));
	this->addChild(score3);

	UserDefault *def4 = UserDefault::getInstance( ); 
    highScore4 =  def4->getIntegerForKey("HIGHSCORE4",0);

	__String *nScore4 = __String::createWithFormat("4. %i",highScore4); 
	auto score4 = LabelTTF::create(nScore4->getCString(),"fonts/Marker Felt.ttf",visibleSize.height*0.07);
    score4->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height*0.5));
	this->addChild(score4);

	UserDefault *def5 = UserDefault::getInstance( ); 
    highScore5 = def5->getIntegerForKey("HIGHSCORE5",0);
	
	__String *nScore5 = __String::createWithFormat("5. %i",highScore5); 
	auto score5 = LabelTTF::create(nScore5->getCString(),"fonts/Marker Felt.ttf",visibleSize.height*0.07);
    score5->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height*0.4));
	this->addChild(score5);
}
