#include "gameLayer.h"

#include "titleLayer.h"
//#include "ScoresLayer.h"
//#include "ControlsLayer.h"

USING_NS_CC;

CCScene* GameLayer::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
	// 'layer' is an autorelease object
	GameLayer *layer = GameLayer::create();    
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

bool GameLayer::init(){
	gameWord = NULL;
	playerWord = NULL;
// TODO
// когда я кликаю - буква уже добавилась у игрока. - но она visible(false)
// когда фейковая буква до туда долетает - мы просто её удаляем и делаем visible(true). 

	if ( !CCLayer::init() )
	{
		return false;
	}
    
    //this->setIsTouchEnabled(true);

	/* Title */
	//CCSprite *titleImage = CCSprite::spriteWithFile("menu/title.png");
	
	//titleImage->setPosition(ccp(windowSize.width/2, windowSize.height - 50)); // 50 - title height
    //this->addChild(titleImage, 1);
    

	/* Menu */
 //   // Create "play," "scores," and "controls" buttons - when tapped, they call methods we define: playButtonAction and scoresButtonAction
	//CCSprite *newGameSprite = CCSprite::spriteWithFile("menu/new_game_2.png");
	//CCMenuItemSprite *newGameButton = CCMenuItemSprite::itemWithNormalSprite(newGameSprite, newGameSprite, newGameSprite, this, menu_selector(TitleLayer::newGameAction));

	//CCSprite *leaderboardSprite = CCSprite::spriteWithFile("menu/leaderboard_2.png");
	//CCMenuItemSprite *leaderboardButton = CCMenuItemSprite::itemWithNormalSprite(leaderboardSprite, leaderboardSprite, leaderboardSprite,
	//	this, menu_selector(TitleLayer::leaderboardAction));

 //  
	//CCMenu *menu = CCMenu::menuWithItems(newGameButton, leaderboardButton, NULL);
	//menu->alignItemsVerticallyWithPadding(20);
 //   
	//// Set position of menu to be below the title text
 //   menu->setPosition(ccp(windowSize.width / 2, 100));

 //   // Add menu to layer
 //   this->addChild(menu, 2);
 //       

	///* testing */
	///*Letter *letter = new Letter("W");
	//letter->setPosition(ccp(windowSize.width - 50, windowSize.height - 50));
	//letter->runAction(CCRotateBy::create(10, 360));
	//this->addChild(letter);*/

	//Word *PcWord = new Word("123LONGWORD");
	//PcWord->alignLettersHorizontallyWithPadding(42);
	//PcWord->setPosition(ccp(windowSize.width/2, windowSize.height - 50));
	//PcWord->randomlyRotateLetters();

	//Word *PlayerWord = new Word("WORDS");
	//PlayerWord->alignLettersHorizontallyWithPadding(42);
	//PlayerWord->setPosition(ccp(windowSize.width/2, 50));
	//PlayerWord->randomlyRotateLetters();

	//this->addChild(PcWord);
	//this->addChild(PlayerWord);


	// TODO - не забыть удалить слово. - хот в терии должно само

	//Word * dbWord = db.getRandomWord();
	//dbWord->alignLettersHorizontallyWithPadding(42);
	//dbWord->setPosition(ccp(windowSize.width/2, windowSize.height - 50));
	//dbWord->randomlyRotateLetters();
	//this->addChild(dbWord);


	//
	//gameWord = new Word;
	//gameWord->setPosition(ccp(windowSize.width/2, windowSize.height - 50));
	//playerWord = new Word;
	//playerWord->setPosition(ccp(windowSize.width/2, 50));

	setupBackGround();
	setupTopButtons();
	setupPlayerWord();
	startNewGame();
	setupSubmitButton();

	Letter *letter = this->gameWord->getLetter(1);
	letter->setVisible(false);
	this->playerWord->appendLetter(letter);

	return true;
}

void GameLayer::playAgainAction(CCObject *pSender){
	//CCDirector::sharedDirector()->replaceScene(GameLayer::scene());
}

void GameLayer::mainMenuAction(CCObject *pSender){
	CCDirector::sharedDirector()->replaceScene(TitleLayer::scene());
}


void GameLayer::submitButtonAction(CCObject *pSender){
	// TODO - если слово подходит
		// Очищаем слово игрока и покаываем все буквы у копа
	// если нет
		// Говорим что слово не подходит - пока не знаю как, но ничего не меняем, вдруг игрок опечатался или типо того.
}


void GameLayer::setupBackGround(){
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	/* BackGround image */
	CCSprite *backImage = CCSprite::spriteWithFile("menu/bg_game4.jpg");
    backImage->setPosition(ccp(windowSize.width/2, windowSize.height/2));
    this->addChild(backImage);
}

void GameLayer::setupTopButtons(){
	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite *toMainMenuSprite = CCSprite::spriteWithFile("toMainMenu2.png");
	CCMenuItemSprite *mainMenuButton = CCMenuItemSprite::itemWithNormalSprite(toMainMenuSprite, toMainMenuSprite, toMainMenuSprite,
		this, menu_selector(GameLayer::mainMenuAction));

   
	CCMenu *menu = CCMenu::menuWithItems(mainMenuButton, NULL);
	//menu->alignItemsVerticallyWithPadding(20);


	menu->setPosition(ccp(windowSize.width - (toMainMenuSprite->getContentSize().width/2) - 7,
							windowSize.height - (toMainMenuSprite->getContentSize().height/2) - 5));

	// Set position of menu to be below the title text
	//menu->setPosition(ccp(0/*(-windowSize.width/4) + (menu->getContentSize().width)*/ , 0));
	//menu->setPosition(ccp(-windowSize.width / 2, (windowSize.height/2) - menu->getContentSize().height));
	this->addChild(menu);
}

void GameLayer::setupSubmitButton(){
	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite *submitSprite = CCSprite::spriteWithFile("submit.png");
	CCSprite *submitPressedSprite = CCSprite::spriteWithFile("submit_pressed.png");
	CCMenuItemSprite *submitButton = CCMenuItemSprite::itemWithNormalSprite(submitSprite, submitPressedSprite, submitSprite,
		this, menu_selector(GameLayer::submitButtonAction));

   
	CCMenu *menu = CCMenu::menuWithItems(submitButton, NULL);
	//menu->alignItemsVerticallyWithPadding(20);

	menu->setPositionX(windowSize.width/2);
	menu->setPositionY(((gameWord->getPositionY() + playerWord->getPositionY()) / 2) /*- (submitSprite->getContentSize().height / 2)*/);


	this->addChild(menu);

}


void GameLayer::setupPlayerWord(){
	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
	playerWord = new Word;
	playerWord->alignLettersHorizontallyWithPadding(42);
	playerWord->setPosition(ccp(windowSize.width/2, 50));
	playerWord->randomlyRotateLetters();
	this->addChild(playerWord);
}

void GameLayer::startNewGame(){	
	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	if(gameWord != NULL)
		gameWord->removeFromParentAndCleanup(true);
	
	//playerWord->clear(); // TODO убрать все буквы из слова игрока если такие есть.


	gameWord = db.getRandomWord();
	gameWord->alignLettersHorizontallyWithPadding(42);
	gameWord->setPosition(windowSize.width/2, windowSize.height - 70);
	gameWord->randomlyRotateLetters();
	this->addChild(gameWord);
	

}

