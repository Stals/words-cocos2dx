#include "letter.h"
#include "gameLayer.h"

USING_NS_CC;
Letter::Letter(char letter, size_t id): letter(toupper(letter)), id(id){
	// TODO - нужно либо делать rect метод чтобы правильный размер сделать
	// либо он на автомате будет работать. я не знаю
	CCSprite::init();
	//this->setTouchEnabled(true);
	this->autorelease();

	// TODO 1 раз получать - для всех использовать потом
	letterImage = CCSprite::create("letter32_2.png");
	letterImage->setScale(32 / letterImage->getContentSize().width);
	char arr[2] = {this->letter, '\0'};


	//CCLabelTTF *letterLabel = CCLabelTTF::create(arr, "fonts/Schwarzwald Regular.ttf", 22);
	//CCLabelTTF *left = CCLabelTTF::create("alignment left", pFont, fontSize,
	//                                      blockSize, kCCTextAlignmentLeft, verticalAlignment[vAlignIdx]);

	//CCLabelTTF *letterLabel = CCLabelTTF::create(arr, /*"fonts\sylfaen.ttf"*/"Sylfaen", 50);


	//CCLabelBMFont *letterLabel = CCLabelBMFont::create(arr, "fonts/hd/markerFelt.fnt", 10);
	//letterLabel->setScale(0.5);

	CCLabelAtlas *letterLabel = CCLabelAtlas::create(arr, "fonts/hd/larabie-16.plist");
	letterLabel->setAnchorPoint(ccp(0.5f, 0.5f));
	letterLabel->setColor(ccc3(85,47,17));
	//letterLabel->setColor(ccc3(0,0,0));

	this->addChild(letterImage,1);
	this->addChild(letterLabel,2);
}


Letter::~Letter(void)
{
}

/*
bool Letter::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event){

}
*/

void Letter::onEnter(){
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	CCSprite::onEnter();
}
void Letter::onExit(){
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}
bool Letter::ccTouchBegan(CCTouch* touch, CCEvent* event){
	if(this->isVisible()){
		if (this->containsTouchLocation(touch)){
			((GameLayer*)this->getParent()->getParent())->letterClicked(this);
			return true;
		}
	}
	return false;
}

void Letter::ccTouchMoved(CCTouch* touch, CCEvent* event){

}

void Letter::ccTouchEnded(CCTouch* touch, CCEvent* event){

}

bool Letter::containsTouchLocation(cocos2d::CCTouch *touch) {
	CCPoint point = touch->locationInView();
	return CCRect::CCRectContainsPoint(rect(),
			this->convertTouchToNodeSpaceAR(touch));
}

CCRect Letter::rect() {
	CCRect c = CCRectMake(
			(letterImage->getPosition().x
					- (this->letterImage->getTextureRect().size.width / 2)
							* this->letterImage->getScaleX()),
			(letterImage->getPosition().y
					- (this->letterImage->getTextureRect().size.height / 2)
							* this->letterImage->getScaleY()),
			this->letterImage->getTextureRect().size.width
					* this->letterImage->getScaleX(),
			this->letterImage->getTextureRect().size.height
					* this->letterImage->getScaleY());
					
	return c;
}
