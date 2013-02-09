#pragma once
#include <string>
#include "cocos2d.h"

class GameLayer;

class Letter : public cocos2d::CCSprite, public cocos2d::CCTargetedTouchDelegate {
public:
	Letter(char letter, size_t id);
	~Letter(void);
	size_t id;
	char letter;

private:
	virtual void onEnter();
    virtual void onExit();

	virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

	void registerWithTouchDispatcher();
};

