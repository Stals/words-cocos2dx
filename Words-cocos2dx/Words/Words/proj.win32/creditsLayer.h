#pragma once 

#include "cocos2d.h"
using namespace cocos2d;

class CreditsLayer : public cocos2d::CCLayer{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();

	// implement the "static node()" method manually
    CREATE_FUNC(CreditsLayer);
private:
	// Полупрозрачный слой размером с экран
	cocos2d::CCSprite *bg;
	cocos2d::CCLabelTTF *text;
	cocos2d::CCMenu *menu;

	void setupBackground();
	void setupText();
	void setupWords();
	void setupButtons();

	void mainMenuAction(CCObject *pSender);

	
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    virtual void registerWithTouchDispatcher();
	
};
