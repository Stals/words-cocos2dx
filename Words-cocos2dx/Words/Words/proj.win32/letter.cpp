#include "letter.h"

USING_NS_CC;
Letter::Letter(char letter, size_t id): letter(letter), id(id){
	// TODO - нужно либо делать rect метод чтобы правильный размер сделать
	// либо он на автомате будет работать. я не знаю
	CCSprite::init();
	//this->setTouchEnabled(true);
	this->autorelease();

	// TODO 1 раз получать - для всех использовать потом
	CCSprite *letterImage = CCSprite::create("letter32_2.png");
	letterImage->setScale(32 / letterImage->getContentSize().width);
	char arr[2] = {toupper(letter), '\0'};
	
	
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
	cocos2d::CCPoint touchLocation = touch->getLocationInView();
	touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
	touchLocation.x = touchLocation.x - (CCDirector::sharedDirector()->getWinSize().width/2);
	//touchLocation = convertToNodeSpace(touchLocation);

	float wigth = 32; //getContentSize().width;
	float height = 32; //getContentSize().height;
	
	//  получение габаритов кнопки 
	cocos2d::CCPoint letterLocation = CCDirector::sharedDirector()->convertToGL(getPosition());
	cocos2d::CCRect r ( letterLocation.x - wigth/2, 
		       letterLocation.y - (70 - wigth/2) - wigth, 
			   wigth, 
			   height );
	
	/*
	if(CCRect::CCRectContainsPoint(r, touchLocation)){
		CCSprite *letterImage = CCSprite::create("letter32.png");
		this->addChild(letterImage, 3);
	}
	*/

	// если вернёт true - то дальше не пойдет
	return CCRect::CCRectContainsPoint(r, touchLocation);
}

void Letter::ccTouchMoved(CCTouch* touch, CCEvent* event){
    
}

void Letter::ccTouchEnded(CCTouch* touch, CCEvent* event){

}


/*
	// TODO  при определении точки еще нужно скорее всего учитывать padding - типо width + padding*id
	
	

*/