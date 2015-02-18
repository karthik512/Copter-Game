#include "Copter.h"
#include "cocos2d.h"

USING_NS_CC;
Copter::Copter(Layer *l)
{
	iX=100;
	iY=300;
	iXi = visibleSize.width;
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	copterSprite = Sprite::create("Copters1.png");
	invisible = Sprite::create();
	copterSprite1 = SpriteFrame::create("Copters1.png",Rect(0,0,copterSprite->getContentSize().width,copterSprite->getContentSize().height));
	copterSprite2 = SpriteFrame::create("Copters2.png",Rect(0,0,copterSprite->getContentSize().width,copterSprite->getContentSize().height));
	copterSprite3 = SpriteFrame::create("Copters3.png",Rect(0,0,copterSprite->getContentSize().width,copterSprite->getContentSize().height));
	copterSprite->setPosition(iX,iY);
	Vector<SpriteFrame*> anim;
	anim.pushBack(copterSprite1);
	anim.pushBack(copterSprite2);
	anim.pushBack(copterSprite3);
	auto copterAnimation = Animation::createWithSpriteFrames(anim,0.1f);
	copterAnimate = Animate::create(copterAnimation);
	copterSprite->runAction(RepeatForever::create(copterAnimate));

	auto follow = Follow::create(invisible,Rect::ZERO);
	copterBody = PhysicsBody::createBox(copterSprite->getContentSize(),PhysicsMaterial(0,1,0));
	copterBody->setCollisionBitmask(2);
	copterBody->setContactTestBitmask( true );

	invisible->setPosition(200,150);
	copterSprite->setPhysicsBody(copterBody);

	l->addChild(copterSprite);
	l->addChild(invisible);
	l->runAction(follow);
	
	isMovingUp = false;
	isMovingDown = false;
	invert = false;
    
}

void Copter::MoveUp()
{
	if(invert==false)
	{

		if(isMovingUp==true)
		{
			if(copterBody->getPosition().x<=visibleSize.width*0.75+origin.x)
				copterBody->setVelocity(Vect(45,-100));
			else
				copterBody->setVelocity(Vect(0,-100));
		}
		else
		{
			copterBody->setLinearDamping(0.2);
		}
	 }
	else
	{
		if(isMovingUp==true)
		{
			if(copterBody->getPosition().y==visibleSize.height*0.85)
			{
				copterBody->setVelocity(Vect(45,0));
			}
			else
			{
			if(copterBody->getPosition().x>=visibleSize.width*0.05)
				copterBody->setVelocity(Vect(-45,-100));
			else
				copterBody->setVelocity(Vect(0,-100));
			}
		}
		else
		{
			copterBody->setLinearDamping(0.2);
		}
	}
}

void Copter::MoveDown()
{

	if(invert==false)
	{
		if(isMovingDown==true)
		{
			if(copterBody->getPosition().x<=visibleSize.width*0.75)
				copterBody->setVelocity(Vect(45,100));
			else
				copterBody->setVelocity(Vect(0,100));
		
		}
		else
		{
			copterBody->setLinearDamping(0.2);
		}
	 }
	else
	{
		if(isMovingDown==true)
		{
			if(copterBody->getPosition().x>=visibleSize.width*0.05)
				copterBody->setVelocity(Vect(-45,100));
			else
				copterBody->setVelocity(Vect(0,100));
		
		}
		else
		{
			copterBody->setLinearDamping(0.2);
		}
	}
}

void Copter::setMovingUp(bool b)
{
	isMovingUp = b;
}

void Copter::setMovingDown(bool b)
{
	isMovingDown = b;
}

int Copter::MoveInvisible()
{
	iY=visibleSize.height/2+origin.y;
	iXi +=1;
	invisible->setPosition(iXi,iY);
	return iXi;
}

void Copter::invertCopterMovement(bool b)
{
	invert = b;
}
void Copter::DestroyCopter()
{
	iXi = 0;
}
void Copter::CheckFalling()
{
	if(copterBody->getPosition().y<visibleSize.height*0.1)
		copterBody->setVelocity(Vect(0,10));
}
