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

	// ����� ������ alighn ������!
	void appendLetter(char letter);
	void appendLetter(Letter *letter);
	void removeLetter(size_t id);
	// deletes all letters
	void removeWord();
	Letter* getLetter(size_t id);

	void showLetter(size_t id);
	// ������ ��� ����� � ����� setVisible(true);
	void showWord();
	void hideLetter(size_t id);
	
	// ���������� ����� � ���� ������
	std::string getString();
	size_t getLength();

	void alignLettersHorizontallyWithPadding(float padding);
	void randomlyRotateLetters();
	
	virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

	void registerWithTouchDispatcher();

	// �������� �����, ������ ������ � ���� �����
	void addContainedWord(const std::string &word);
	// ������� ����� �� ������ �������� � ����. ������������ ��� ���� ����� ����� �� ��� ��������� ��� ������� ���� � ���� �����
	void removeContainedWord(const std::string &word);
	// ��������� ���� �� ����� ����� ��� ��� ����� ��������� �� ���� ����� - � ���� � �������
	bool isContained(std::string word);

	void setType(Word::Type type);
	Word::Type getType();
	
private:
	//std::vector<Letter*> letters;
	std::set<std::string> contains;
	Word::Type type;
};


