#include "MainMenu.h"
#include "GameScene.h"
#include "HighScore.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255,102,102,255)))
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	auto menu_item1 = MenuItemFont::create("Play",CC_CALLBACK_1(MainMenu::GoToGameScene,this));
	menu_item1->setPosition(visibleSize.width/2,visibleSize.height*0.8);

	auto menu_item2 = MenuItemFont::create("HighScore",CC_CALLBACK_1(MainMenu::GoToHighScore,this));
	menu_item2->setPosition(visibleSize.width/2,visibleSize.height*0.5);

	auto menu = Menu::create(menu_item1,menu_item2,NULL);
	menu->setPosition(Point(0,0));
	this->addChild(menu);
    return true;
}
void MainMenu::GoToGameScene(cocos2d::Ref *sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void MainMenu::GoToHighScore(cocos2d::Ref *sender)
{
	auto scene = HighScore::createScene();
	Director::getInstance()->pushScene(scene);
}
