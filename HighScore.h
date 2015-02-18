#ifndef __HIGHSCORE_H__
#define __HIGHSCORE_H__


#include "cocos2d.h"
#include "GameOverScene.h"

class HighScore:public cocos2d::Layer
{
	public:
		cocos2d::Size visibleSize;
		cocos2d::Point origin;
		static cocos2d::Scene* createScene();
		virtual bool init();  
		CREATE_FUNC(HighScore);
		void DisplayScore();
    
};

#endif // __HIGHSCORE_H__
