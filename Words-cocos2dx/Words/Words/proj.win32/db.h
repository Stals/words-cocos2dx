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

	// ¬озвращает случайное слово из базы, со всеми словами которые в него вход€т
	Word* getRandomWord();
private:
	// ¬озвращает слово в виде строки по его id
	std::string getWordById(int id);

	sqlite::connection conn;
	sqlite::query countWords;
	sqlite::query randomWord;
	sqlite::query wordById;
};

