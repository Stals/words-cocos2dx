#pragma once
#include "cocos2d.h"
#include <string>
#include <vector>

#include "letter.h"

class Word : public cocos2d::CCLayer
{
public:
	Word(std::string word);
	~Word(void);

	// нужно делать alighn заново!
	void appendLetter(char letter);
	void removeLetter(size_t id);

	void showLetter(size_t id);
	void hideLetter(size_t id);
	
	std::string getString();

	void alignLettersHorizontallyWithPadding(float padding);
	void randomlyRotateLetters();
	
	virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

	void registerWithTouchDispatcher();
	
private:
	//std::vector<Letter*> letters;
};

