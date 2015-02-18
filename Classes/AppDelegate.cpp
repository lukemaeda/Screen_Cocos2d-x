#include "AppDelegate.h"
#include "TopScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }

    ////////////////////////////////////////
    
    // デザイン解像度の設定（縦） iPhone 5s SHOW_ALL
    glview->setDesignResolutionSize(1136, 640, ResolutionPolicy::SHOW_ALL);
    
    ////////////////////////////////////////
    
    //glview->setDesignResolutionSize(320.0f, 480.0f, ResolutionPolicy::SHOW_ALL);
    
    Size frameSize = glview->getFrameSize();
    std::vector< std::string > searchPath;
    if (frameSize.width >= 640.0f) {
        searchPath.push_back("hd");
        director->setContentScaleFactor(2.0f);
    }
    else {
        searchPath.push_back("sd");
    }
    
    FileUtils::getInstance()->setSearchPaths(searchPath);
    
    // turn on display FPS
    //director->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    auto scene = TopScene::createScene();
    
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
