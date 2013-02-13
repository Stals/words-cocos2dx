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
	if ( !CCLayer::init() )
	{
		return false;
	}

	gameWord = NULL;
	playerWord = NULL;
	score = 0;
	timer = 120;
	    
	setupBackGround();
	setupTopButtons();
	setupPlayerWord();
	startNewGame();
	setupSubmitButton();
	setupScore();
	setupTimer();

	return true;
}


void GameLayer::mainMenuAction(CCObject *pSender){
	CCDirector::sharedDirector()->replaceScene(TitleLayer::scene());
}


void GameLayer::submitButtonAction(CCObject *pSender){
	if(gameWord->isContained(playerWord->getString())){		
		addScore(playerWord->getLength() * 50);
		gameWord->removeContainedWord(playerWord->getString());

		CCArray *letters = playerWord->getChildren();
		for(int i = 0; i < playerWord->getChildrenCount(); ++i){
			Letter *from = (Letter*)letters->objectAtIndex(i);
			moveLetter(from, gameWord->getLetter(from->id));
		}
		
		playerWord->removeWord();
		//gameWord->showWord();
	}
}


void GameLayer::letterClicked(Letter *letter){
	Letter* newLetter = NULL;
	Word *clickedWord = (Word*)letter->getParent();

	Word::Type wordType = clickedWord->getType();
	switch(wordType){
	case Word::Game:
		newLetter = playerWord->appendLetter(letter);
		playerWord->alignLettersHorizontallyWithPadding(42);
		newLetter->setVisible(false);
		this->moveLetter(letter, newLetter);
		break;

	case Word::Player:
		moveLetter(letter, gameWord->getLetter(letter->id));	
		letter->removeFromParentAndCleanup(true);
		playerWord->alignLettersHorizontallyWithPadding(42);
		break;
	}

}

void GameLayer::deleteLetter(CCNode *letter){
	letter->removeFromParentAndCleanup(true);
}

void GameLayer::setupBackGround(){
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	/* BackGround image */
	CCSprite *backImage = CCSprite::create("menu/bg_game4.png");
    backImage->setPosition(ccp(windowSize.width/2, windowSize.height/2));
    this->addChild(backImage);
}

void GameLayer::setupTopButtons(){
	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite *toMainMenuSprite = CCSprite::create("toMainMenu2.png");
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

	CCSprite *submitSprite = CCSprite::create("submit2.png");
	CCSprite *submitPressedSprite = CCSprite::create("submit_pressed2.png");
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
	playerWord->setType(Word::Player);
	this->addChild(playerWord);
}


void GameLayer::setupScore(){
	//scoreLabel = CCLabelTTF::create("Hello there this is a text", "Arial", 25);
	scoreLabel = CCLabelTTF::create("0", "Arial", 18, CCSize(215, 18), kCCTextAlignmentRight);
	scoreLabel->setColor(ccc3(208,192,143));
	
	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
	scoreLabel->setPositionY(windowSize.height - (scoreLabel->getContentSize().height/2) - 10);

	this->addChild(scoreLabel);
}

void GameLayer::setupTimer(){
	timerLabel = CCLabelTTF::create("0", "Arial", 18, CCSize(215, 18), kCCTextAlignmentRight);
	timerLabel->setColor(ccc3(208,192,143));

	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
	timerLabel->setPositionY(windowSize.height - (timerLabel->getContentSize().height/2) - 10);
	timerLabel->setPositionX(177);
	updateTimer(0);
	this->addChild(timerLabel);


	this->schedule( schedule_selector(GameLayer::updateTimer), 1.0 );
}

void GameLayer::startNewGame(){	
	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	if(gameWord != NULL)
		gameWord->removeFromParentAndCleanup(true);
	
	//playerWord->clear(); // TODO ������ ��� ����� �� ����� ������ ���� ����� ����.


	gameWord = db.getRandomWord();
	gameWord->alignLettersHorizontallyWithPadding(42);
	gameWord->setPosition(windowSize.width/2, windowSize.height - 70);
	gameWord->randomlyRotateLetters();
	gameWord->setType(Word::Game);
	this->addChild(gameWord);
}

void GameLayer::gameOver(){
	GameOverLayer *gameOverLayer = new GameOverLayer(score);
	gameOverLayer->autorelease();
	this->addChild(gameOverLayer);
}

void GameLayer::addScore(int n){
	score += n;
	char arr[16];
	itoa(score, arr, 10);
	scoreLabel->setString(arr);
}

void GameLayer::updateTimer(float dt){
	timer -= 1;

	int min = timer / 60;
	int sec = timer - (min * 60);
	char arr[16];
	
	if(min > 0){
		if(sec >= 10)
			sprintf(arr, "%i:%i", min, sec);
		else
			sprintf(arr, "%i:0%i", min, sec);
	}
	else
		sprintf(arr, "%i", sec); 

	timerLabel->setString(arr);

	if(timer == 0){
		this->unschedule(schedule_selector(GameLayer::updateTimer));
		gameOver();
	}
}

void GameLayer::addTime(int seconds){
	timer += seconds;
	
	// Показываем рядом с таймерм сколько времени было добавлено	
	
	// делаем schedule уменьшения видимости этого label'a
}

void GameLayer::moveLetter(Letter* from, Letter* to){
	//CCPoint fromPoint = gameWord->convertToWorldSpace(from->getPosition());
	CCPoint fromPoint = from->getParent()->convertToWorldSpace(from->getPosition());	
	//CCPoint toPoint = playerWord->convertToWorldSpace(to->getPosition());
	CCPoint toPoint = to->getParent()->convertToWorldSpace(to->getPosition());

	from->setVisible(false);

	Letter* movingLetter = new Letter(from->letter, from->id);
	movingLetter->setPosition(fromPoint); // это позиция относительно Word мне кажется а мне нужна относительно gameLayer
	this->addChild(movingLetter);
	//CCJumpTo* move = CCJumpTo::create(1, toPoint, 10, 50);
	CCMoveTo* move = CCMoveTo::create(0.5, toPoint);
	CCCallFuncN* remove = cocos2d::CCCallFuncN ::create(movingLetter, callfuncN_selector(GameLayer::deleteLetter));
	
	movingLetter->runAction(cocos2d::CCSequence::create(move, remove, NULL));// CCJumpBy::create(1.0, to->getPosition(), 10, 5));
	to->runAction(CCBlink::create(1, 1));


}