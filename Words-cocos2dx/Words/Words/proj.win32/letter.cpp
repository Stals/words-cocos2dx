#include "letter.h"

USING_NS_CC;
Letter::Letter(char letter, size_t id): letter(letter), id(id){
	// TODO - нужно либо делать rect метод чтобы правильный размер сделать
	// либо он на автомате будет работать. я не знаю
	CCSprite::init();
	this->autorelease();
	//this->setIsTouchEnabled(true);

	// TODO 1 раз получать - для всех использовать потом
	CCSprite *letterImage = CCSprite::spriteWithFile("letter32.png");
	char arr[2] = {letter, '\0'};
	CCLabelTTF *letterLabel = CCLabelTTF::create(arr, "Sylfaen", 22);
	letterLabel->setColor(ccc3(85,47,17));

	this->addChild(letterImage,1);
	this->addChild(letterLabel,2);
}


Letter::~Letter(void)
{
}
