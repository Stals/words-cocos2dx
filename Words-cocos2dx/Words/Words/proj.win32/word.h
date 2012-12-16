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

	void alignLettersHorizontallyWithPadding(float padding);
	void randomlyRotateLetters();

private:
	std::vector<Letter*> letters;
};

