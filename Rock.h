#ifndef __ROCk_H__
#define __ROCk_H__


#include "cocos2d.h"

class Rock
{
public:
	
	Rock(cocos2d::Layer *l);
	Rock(cocos2d::Layer *l,int x);
	cocos2d::Size visibleSize;
	cocos2d::Point origin;
	cocos2d::Sprite *rockSprite;
	cocos2d::PhysicsBody *body1;
	int posX,posY;
    
};

#endif // __ROCk_H__
