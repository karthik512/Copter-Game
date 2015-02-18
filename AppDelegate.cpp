#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

/*
typedef struct tagResource
{
   cocos2d::CCSize size;
   char directory[100];
}Resource;

static Resource smallResource  =  {cocos2d::CCSizeMake(480,320),"small"};
static Resource mediumResource =  {cocos2d::CCSizeMake(640,480),"medium"};
static Resource largeResource  =  {cocos2d::CCSizeMake(960,720),"large"};
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(480,320);
*/


AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    
	// initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

	// turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

	auto fileUtils = FileUtils::getInstance();
    auto frameSize = glview->getFrameSize();
    std::vector<std::string> resDirOrders;

	if (frameSize.height > 480)
    { 
		resDirOrders.push_back("large");
		resDirOrders.push_back("medium");
		resDirOrders.push_back("small");
        //director->setContentScaleFactor(largeResource.size.height/designResolutionSize.height);
		glview->setDesignResolutionSize(960,720, ResolutionPolicy::NO_BORDER);
    }
	// if the frame's height is larger than the height of small resource size, select medium resource.
    else if (frameSize.height > 320)
    { 
		resDirOrders.push_back("medium");
		resDirOrders.push_back("small");
        //director->setContentScaleFactor(mediumResource.size.height/designResolutionSize.height);
		glview->setDesignResolutionSize(640,480, ResolutionPolicy::NO_BORDER);
    }
    // if the frame's height is smaller than the height of medium resource size, select small resource.
    else
    { 
		resDirOrders.push_back("small");
        //director->setContentScaleFactor(smallResource.size.height/designResolutionSize.height);
		glview->setDesignResolutionSize(480,320, ResolutionPolicy::NO_BORDER);
     }
    
	fileUtils->setSearchPaths(resDirOrders);
    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
