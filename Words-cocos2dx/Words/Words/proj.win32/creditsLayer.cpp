#include "creditsLayer.h"
#include "titleLayer.h"

USING_NS_CC;
CCScene* CreditsLayer::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        CreditsLayer *layer = CreditsLayer::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CreditsLayer::init()
{

	CCLayer::init();	
	//this->setTouchEnabled(true);
	setupBackground();
	setupText();
	setupButtons();
	return true;
}


void CreditsLayer::setupBackground(){
	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite *backImage = CCSprite::spriteWithFile("menu/bg_credits.png");
    backImage->setPosition(ccp(windowSize.width/2, windowSize.height/2));
    this->addChild(backImage);
}


void CreditsLayer::setupText(){
	/*std::string str = "Programming and art"
	"Stanislav Korotaev"
"Music"
	"Remaxim: opengameart.org/users/remaxim"
		"Golden Wings"
		"Town Theme"
		"Old City Theme"
	"Brendan Kinsella"
		"Mozart Piano Sonata in B-flat major III Allegretto Grazioso"
	"Kevin MacLeod"
		"J.S. Bach Prelude in C";

	//text = CCLabelTTF::create(str, */
}

void CreditsLayer::setupButtons(){
	// Get window size
	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite *mainMenuSprite = CCSprite::create("menu/main_menu.png");
	mainMenuSprite->setScale(0.5);
	mainMenuSprite->setContentSize(CCSize(mainMenuSprite->getContentSize().width * mainMenuSprite->getScaleX(),
										  mainMenuSprite->getContentSize().height * mainMenuSprite->getScaleY()));

	CCMenuItemSprite *mainMenuButton = CCMenuItemSprite::itemWithNormalSprite(mainMenuSprite, mainMenuSprite, mainMenuSprite,
		this, menu_selector(CreditsLayer::mainMenuAction));


	menu = CCMenu::menuWithItems(mainMenuButton, NULL);


	// Set position of menu to be below the title text
	menu->setPosition(ccp(windowSize.width / 2, 100));

	// Add menu to layer
	this->addChild(menu, 2);
}



void CreditsLayer::mainMenuAction(CCObject *pSender){
	CCDirector::sharedDirector()->replaceScene(TitleLayer::scene());
}

/*
bool GameOverLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
	// Так как тач уже был в меню - мы можем не пропустить его дальше 
	// (При таком варианте можно будет нажать кнопку MainMenu справа сверху, но это не критично)
	return true;
}

void GameOverLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
}

void GameOverLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
}

void GameOverLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent){
}

void GameOverLayer::registerWithTouchDispatcher(){
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -126, true);
}
*/