#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    CREATE_FUNC(MainMenu);
	void GoToGameScene(cocos2d::Ref *sender);
	void GoToHighScore(cocos2d::Ref *sender);
};

#endif // __MAIN_MENU_H__
