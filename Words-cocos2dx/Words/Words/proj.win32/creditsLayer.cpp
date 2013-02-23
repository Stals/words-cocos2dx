#include "creditsLayer.h"
#include "titleLayer.h"
#include "word.h"

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
	this->setTouchEnabled(true);
	setupBackground();
	setupText();
	setupWords();
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
		CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

std::string str = "\n" //Programming and art
	"Stanislav Korotaev\n"
"\n" //MUSIC
"Remaxim (opengameart.org/users/remaxim):\n"
		"Golden Wings\n"
		"Town Theme\n"
		"Old City Theme\n\n"
		"Brendan Kinsella:\n"
		"Mozart Piano Sonata in B-flat major III Allegretto Grazioso\n\n"
		"Kevin MacLeod:\n"
		"J.S. Bach Prelude in C\n";

text = CCLabelTTF::create(str.c_str(), "Sylfaen", 17, CCSizeMake(500,500), kCCTextAlignmentCenter);
	

	// Set position of menu to be below the title text
	text->setPosition(ccp(windowSize.width / 2, 70));

this->addChild(text);
}

void CreditsLayer::setupWords(){
	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	Word *prog = new Word("Programming and Art", Word::Player);
	prog->alignLettersHorizontallyWithPadding(42);
	prog->randomlyRotateLetters();

	prog->setScale(0.5);
	prog->setPosition(ccp(120, 225));

	
	Word *music = new Word("MUSIC", Word::Player);
	music->alignLettersHorizontallyWithPadding(42);
	music->randomlyRotateLetters();

	music->setScale(0.5);
	music->setPosition(ccp(120, 185));


	this->addChild(prog);
	this->addChild(music);
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
	menu->setPosition(ccp(windowSize.width / 2, 20));

	// Add menu to layer
	this->addChild(menu, 2);
}



void CreditsLayer::mainMenuAction(CCObject *pSender){
	CCDirector::sharedDirector()->replaceScene(TitleLayer::scene());
}


bool CreditsLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
	// Так как тач уже был в меню - мы можем не пропустить его дальше 
	// (При таком варианте можно будет нажать кнопку MainMenu справа сверху, но это не критично)
	return true;
}

void CreditsLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
}

void CreditsLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
}

void CreditsLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent){
}

void CreditsLayer::registerWithTouchDispatcher(){
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -126, true);
}
