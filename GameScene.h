#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Copter.h"
#include "Rock.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();  
    CREATE_FUNC(GameScene);
	cocos2d::Size visibleSize,windowSize;
	cocos2d::Point origin;
	void onAcceleration(cocos2d::Acceleration *acc,cocos2d::Event *event);
	bool onTouchBegan(cocos2d::Touch *touch,cocos2d::Event *event);
	void onTouchMoved(cocos2d::Touch *touch,cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *event);
	void UpdateAll(float dt);
	void CreateRocks(int x);
	Rock *rock[5];
	Copter *copter;
	cocos2d::PhysicsWorld *gworld;
	cocos2d::PhysicsBody *g1,*g2;
	int score;
	cocos2d::Label *scoreLabel;
	cocos2d::Sprite *bg1,*bg2,*grd1,*grd2;
	bool onContactBegin(cocos2d::PhysicsContact &contact);
	void setPhysicsWorld(cocos2d::PhysicsWorld *world){ gworld = world; }
};

#endif // __GAME_SCENE_H__
