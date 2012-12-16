#include "titleLayer.h"

//#include "GameLayer.h"
//#include "ScoresLayer.h"
//#include "ControlsLayer.h"

USING_NS_CC;

CCScene* TitleLayer::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	TitleLayer *layer = TitleLayer::create();
    
	// add layer as a child to scene
	scene->addChild(layer);
    
	// return the scene
	return scene;
}

bool TitleLayer::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}
    
    // Get window size
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();

	/* BackGround image */
	CCSprite *backImage = CCSprite::spriteWithFile("menu/bg_darkwood.jpg");
    backImage->setPosition(ccp(windowSize.width/2, windowSize.height/2));
    this->addChild(backImage);
    //this->setIsTouchEnabled(true);

	/* Title */
	//CCSprite *titleImage = CCSprite::spriteWithFile("menu/title.png");
	
	//titleImage->setPosition(ccp(windowSize.width/2, windowSize.height - 50)); // 50 - title height
    //this->addChild(titleImage, 1);
    

	/* Menu */
    // Create "play," "scores," and "controls" buttons - when tapped, they call methods we define: playButtonAction and scoresButtonAction
	CCSprite *newGameSprite = CCSprite::spriteWithFile("menu/new_game_2.png");
	CCMenuItemSprite *newGameButton = CCMenuItemSprite::itemWithNormalSprite(newGameSprite, newGameSprite, newGameSprite, this, menu_selector(TitleLayer::newGameAction));

	CCSprite *leaderboardSprite = CCSprite::spriteWithFile("menu/leaderboard_2.png");
	CCMenuItemSprite *leaderboardButton = CCMenuItemSprite::itemWithNormalSprite(leaderboardSprite, leaderboardSprite, leaderboardSprite,
		this, menu_selector(TitleLayer::leaderboardAction));

   
	CCMenu *menu = CCMenu::menuWithItems(newGameButton, leaderboardButton, NULL);
	menu->alignItemsVerticallyWithPadding(20);
    
	// Set position of menu to be below the title text
    menu->setPosition(ccp(windowSize.width / 2, 100));

    // Add menu to layer
    this->addChild(menu, 2);
        

	/* testing */
	/*Letter *letter = new Letter("W");
	letter->setPosition(ccp(windowSize.width - 50, windowSize.height - 50));
	letter->runAction(CCRotateBy::create(10, 360));
	this->addChild(letter);*/

	Word *word = new Word("WORDS");
	this->addChild(word);
	word->alignLettersHorizontallyWithPadding(42);
	word->setPosition(ccp(windowSize.width/2, windowSize.height - 50));

	return true;
}

void TitleLayer::newGameAction(CCObject *pSender){
	//CCDirector::sharedDirector()->replaceScene(GameLayer::scene());
}

void TitleLayer::leaderboardAction(CCObject *pSender){
	//CCDirector::sharedDirector()->resplaceScene(Leaderboard::scene());
}
