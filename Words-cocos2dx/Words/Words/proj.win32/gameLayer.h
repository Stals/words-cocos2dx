#pragma once
#include "cocos2d.h"
#include "db.h"

#include "word.h"

class GameLayer : public cocos2d::CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
    
	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();
    
	// implement the "static node()" method manually
	CREATE_FUNC(GameLayer);
    
	void playAgainAction(CCObject *pSender);
	void mainMenuAction(CCObject *pSender);
	void submitButtonAction(CCObject *pSender);

	// if gameWord was clicked - append to player, if gameword was clicked - then return it back
	void letterClicked(Letter *letter);

private:
	DB db;
	Word* gameWord;
	Word* playerWord;

	int score;
	cocos2d::CCLabelTTF *scoreLabel;
	int timer;
	cocos2d::CCLabelTTF *timerLabel;


	void setupBackGround();
	void setupTopButtons();
	void setupSubmitButton();
	void setupPlayerWord();
	void setupScore();
	void setupTimer();

	void startNewGame();
	void gameOver();

	// Добавляет n очков к score. И отображает это игроку
	void addScore(int n);
	// Обновляет таймер
	void updateTimer(float dt);
};

