#pragma once
#include <string>
#include "cocos2d.h"

class Letter : public cocos2d::CCSprite{
public:
	Letter(char letter, size_t id);
	~Letter(void);
	size_t id;
};

