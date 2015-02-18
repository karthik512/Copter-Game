#ifndef __COPTER_H__
#define __COPTER_H__

#include "cocos2d.h"
static int iXi;
class Copter
{
public:

	bool isMovingUp,isMovingDown,invert;
	float iX,iY;
	cocos2d::Size visibleSize;
	cocos2d::Sprite *copterSprite,*invisible;
	cocos2d::SpriteFrame *copterSprite1,*copterSprite2,*copterSprite3;
	cocos2d::Animate *copterAnimate;
	Copter(cocos2d::Layer *l);
	void MoveUp();
	void MoveDown();
	void Animate();
	cocos2d::PhysicsBody *copterBody;
	cocos2d::Point origin;
	void setMovingUp(bool b);
	void setMovingDown(bool b);
	int MoveInvisible();
	void invertCopterMovement(bool b);
	void setIXZero();
	void DestroyCopter();
	void CheckFalling();
};

#endif // __COPTER_H__
