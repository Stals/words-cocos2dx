#pragma once 

#include "cocos2d.h"
using namespace cocos2d;

class GameOverLayer : public cocos2d::CCLayer{
public:
  GameOverLayer(int score);
	~GameOverLayer();

private:
	// Полупрозрачный слой размером с экран
	cocos2d::CCLayerColor *bg;
	cocos2d::CCLabelTTF *scoreLabel;
	cocos2d::CCMenu *menu;

	void setupBackground();
	void setupScore(int score);
	void setupButtons();

	void newGameAction(CCObject *pSender);
	void mainMenuAction(CCObject *pSender);

    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    virtual void registerWithTouchDispatcher();
};
