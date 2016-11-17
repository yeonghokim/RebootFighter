#include "AppDelegate.h"
#include "MenuScene.h"


USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

static int register_all_packages()
{
    return 0;
}

bool AppDelegate::applicationDidFinishLaunching() {

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("My Game",Rect(0,0,720,1280));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(720,1280,ResolutionPolicy::SHOW_ALL);
    
    director->setDisplayStats(false);

    director->setAnimationInterval(1.0 / 60);

    register_all_packages();

    auto scene = MenuScene::createScene();

    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
