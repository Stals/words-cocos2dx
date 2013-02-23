#pragma once
#include "cocos2d.h"
#include "word.h"
#include "SimpleAudioEngine.h"  

class TitleLayer :	public cocos2d::CCLayer
{
public:
	public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
    
	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();
    
	// implement the "static node()" method manually
	CREATE_FUNC(TitleLayer);
    
	void newGameAction(CCObject *pSender);
	void creditsAction(CCObject *pSender);
private:
};

