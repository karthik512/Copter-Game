#include "Rock.h"
#include "CCPhysicsBody.h"

USING_NS_CC;

Rock::Rock(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	float random = visibleSize.height;	
	float random_height = CCRANDOM_0_1()*random;
	auto random1 = CCRANDOM_0_1()*300;

	this->posX = 1.5*visibleSize.width;
	this->posY = random_height;

	rockSprite = Sprite::create("rock.png");
	rockSprite->setGlobalZOrder(150);
	rockSprite->setPosition(posX,posY);

	body1 = PhysicsBody::createCircle(15,PhysicsMaterial(0,1,0));
	body1->setCollisionBitmask(1);
	body1->setContactTestBitmask(true);
	rockSprite->setPhysicsBody(body1);

	layer->addChild(rockSprite);
	body1->setGravityEnable(false);
	body1->setVelocity(Vect(-random1,0));
   
	

}
Rock::Rock(cocos2d::Layer *layer,int w)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	float random = visibleSize.height;	
	float random_height = CCRANDOM_0_1()*random;
	auto random1 = CCRANDOM_0_1()*300;

	this->posX = w;
	this->posY = random_height;

	rockSprite = Sprite::create("rock.png");
	rockSprite->setGlobalZOrder(150);
	rockSprite->setPosition(posX,posY);

	body1 = PhysicsBody::createCircle(15,PhysicsMaterial(0,1,0));
	body1->setCollisionBitmask(1);
	body1->setContactTestBitmask(true);
	rockSprite->setPhysicsBody(body1);

	layer->addChild(rockSprite);
	body1->setGravityEnable(false);
	body1->setVelocity(Vect(-random1,0));
}
