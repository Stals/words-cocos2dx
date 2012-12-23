#pragma once
//http://ed.am/dev/sqlite3cc
#include <sqlite3cc.h> 
#include "utils\split.h"

#include "word.h"


class DB
{
public:
	DB(void);
	~DB(void);

	// ���������� ��������� ����� �� ����, �� ����� ������� ������� � ���� ������
	Word* getRandomWord();
private:
	// ���������� ����� � ���� ������ �� ��� id
	std::string getWordById(int id);

	sqlite::connection conn;
	sqlite::query countWords;
	sqlite::query randomWord;
	sqlite::query wordById;
};

