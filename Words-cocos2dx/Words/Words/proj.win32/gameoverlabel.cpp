#include "gameoverlayer.h"

#include <sstream>

GameOverLayer::GameOverLayer(int score){
  CCLayer::init();	
	setupBackground();
	setupScore(score);
	setupButtons();
}

GameOverLayer::~GameOverLayer(){
	
}

void GameOverLayer::setupBackground(){
	bg = new CCLayer();
	// semi transparent background
	bg->initWithColor(ccc4(0,0,0,127));
	this->addChild(bg);
}


void GameOverLayer::setupScoreLabel(int score){
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
    std::sstream sstr;
    sstr << "Final Score: ";
    sstr << score;
    std::string text = sstr.str();

	scoreLabel = CCLabel::create(text.c_str(), "Arial", 50);
	scoreLabel->setPositionY((windowSize.height / 2) + 100);
	scoreLabel->setPositionX(windowsSize.width / 2);

	this->addChild(scoreLabel);
}

void GameOverLayer::setupButtons(){
   // Get window size
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite *newGameSprite = CCSprite::spriteWithFile("menu/new_game.png");
	CCMenuItemSprite *newGameButton = CCMenuItemSprite::itemWithNormalSprite(newGameSprite, newGameSprite, newGameSprite,
		this, menu_selector(GameOverLayer::newGameAction));

	CCSprite *mainMenuSprite = CCSprite::spriteWithFile("menu/main_menu.png");
	CCMenuItemSprite *mainMenuButton = CCMenuItemSprite::itemWithNormalSprite(leaderboardSprite, leaderboardSprite, leaderboardSprite,
		this, menu_selector(GameOverLayer::mainMenuAction));

   
	menu = CCMenu::menuWithItems(newGameButton, mainMenuButton, NULL);
	menu->alignItemsVerticallyWithPadding(20);
    
	// Set position of menu to be below the title text
    menu->setPosition(ccp(windowSize.width / 2, 100));

    // Add menu to layer
    this->addChild(menu, 2);
}


void GameOverLayer::newGameAction(CCObject *pSender){
	// просто заново запустить сцену
	CCDirector::sharedDirector()->replaceScene(GameLayer::scene());
}


void GameOverLayer::mainMenuAction(CCObject *pSender){
	CCDirector::sharedDirector()->replaceScene(TitleLayer::scene());
}


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
    CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, -126, true);
}
