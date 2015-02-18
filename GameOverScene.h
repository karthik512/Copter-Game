#ifndef __GAME_OVER_SCENE_H__
#define __GAME_OVER_SCENE_H__


#include "cocos2d.h"
#include "HighScore.h"

class GameOverScene:public cocos2d::Layer
{
	public:
		static cocos2d::Scene* createScene(unsigned int tempScore);
		virtual bool init();
		CREATE_FUNC(GameOverScene);
		unsigned int highScore1,highScore2,highScore3,highScore4,highScore5;
		unsigned int getHigh();
	
	private:
		void GoToMainMenuScene( cocos2d::Ref *sender );
		void GoToGameScene( cocos2d::Ref *sender );
    
};

#endif // __GAME_OVER_SCENE_H__
