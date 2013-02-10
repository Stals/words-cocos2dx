#pragma once
#include "cocos2d.h"
#include <string>
#include <vector>

#include "letter.h"

class Word : public cocos2d::CCLayer
{
public:
	enum Type{
		Game,
		Player		
	};

	Word();
	Word(std::string word, Word::Type type);
	~Word(void);

	void initWithString(std::string word);

	// нужно делать alighn заново!
	void appendLetter(char letter);
	void appendLetter(Letter *letter);
	void removeLetter(size_t id);
	// deletes all letters
	void removeWord();
	Letter* getLetter(size_t id);

	void showLetter(size_t id);
	// делает все буквы в слове setVisible(true);
	void showWord();
	void hideLetter(size_t id);
	
	// Возвращает слово в виде строки
	std::string getString();
	size_t getLength();

	void alignLettersHorizontallyWithPadding(float padding);
	void randomlyRotateLetters();
	
	virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

	void registerWithTouchDispatcher();

	// Добавить слово, которе входит в этом слово
	void addContainedWord(const std::string &word);
	// убирает слово из списка входящих в него. Используется для того чтобы игрок не мог несколько раз сказать одно и тоже слово
	void removeContainedWord(const std::string &word);
	// проверяет если ли слово среди тех что можно составить из букв слова - и есть в словаре
	bool isContained(std::string word);

	void setType(Word::Type type);
	Word::Type getType();
	
private:
	//std::vector<Letter*> letters;
	std::set<std::string> contains;
	Word::Type type;
};


