#include "letter.h"

USING_NS_CC;
Letter::Letter(char letter, size_t id): letter(letter), id(id){
	// TODO - ����� ���� ������ rect ����� ����� ���������� ������ �������
	// ���� �� �� �������� ����� ��������. � �� ����
	CCSprite::init();
	this->autorelease();
	//this->setIsTouchEnabled(true);

	// TODO 1 ��� �������� - ��� ���� ������������ �����
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
