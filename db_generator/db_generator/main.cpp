// db_generator.cpp : Defines the entry point for the console application.
//

// Ќе думаю что дл€ всех слов имеет смысл считать все штуки, так что
// ќпределим какую длинну мы хотим и только дл€ этих слов будем считать.
// ќстальные слова будут тупо 0 хранить ссылок 

#include "stdafx.h"
#include <ostream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <string>


#include "thirdparty\sqlite\sqlite3.h"

#include "word.h"

// ћинимальна€ и максимальна€ длинна слова, дл€ которого будут искатьс€ вход€щие в него слова
const size_t MIN_LENGTH = 7;
const size_t MAX_LENGTH = 11;


void loadWords(std::vector<Word> &dict){
	std::ifstream inf("words.txt");
	std::string str;
	while (inf >> str){
		dict.emplace_back(Word(str));
	}
}


/*

найдем все слова которые можно составить из букв слова
¬ажно чтобы он не нашел себ€! 
*/
void calcWord(Word &word, std::vector<Word> &dict){
	// ≈сли слово другое больше нашего, то точно неправильное

	for(size_t wordId = 0; wordId < dict.size(); ++wordId){
		const Word &other = dict[wordId];
		if(word.length() >= other.length()){
			if(word != other){
				if(word.contains(other)){
					word.ids.push_back(wordId);
				}
			}
		}

	}

}

// ƒл€ всех слов длинна которых больше MIN_LENGTH но меньше MAX_LENGTH
void calcAllWords(std::vector<Word> &dict){
	const size_t size = dict.size();

	for(size_t wordId = 0; wordId < size; ++wordId){
		if((dict[wordId].length() >= MIN_LENGTH) && (dict[wordId].length() <= MAX_LENGTH)){
			calcWord(dict[wordId], dict);
			std::cout<<"calculated ["<<wordId+1<<" / "<<size<<"] ("<<(int)((((double)(wordId+1))/size)*100)<<"%)\r";
		}
	}
	std::cout<<"\n";
}


void saveToDB(std::vector<Word> &dict){
	sqlite3 *db;
	sqlite3_open("words.sqlite", &db);
	sqlite3_exec(db, "CREATE TABLE words (id integer NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, word text, count integer, contains text);", NULL, 0, NULL);
	
	sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);

	// открываем транзакцию
	for(int wordId = 0; wordId < dict.size(); ++wordId){
		const Word &word = dict[wordId];

		std::stringstream  s;
		
		std::copy(word.ids.begin(), word.ids.end(),std::ostream_iterator<int>(s,","));
		std::string ids = s.str();
		s.clear();

		char query[8192];
		sprintf(query, "INSERT INTO words (word, count, contains) values ('%s', %i ,'%s');", word.str.c_str(), word.ids.size(), ids.c_str());
		sqlite3_exec(db, query, NULL, 0, NULL);
		std::string error = sqlite3_errmsg(db);

		 if(error != "not an error") std::cout<< error << std::endl;

	}
	// закрываем транзацкию
	// Any (modifying) SQL commands executed here are not committed until at the you call:
	sqlite3_exec(db, "END TRANSACTION;", NULL, NULL, NULL);
	
	sqlite3_close(db);

}

// TODO вместо того чтобы сравнивать с собой можно передавать id

// TODO - баг - пишет щас что есть id = 49 втф, как?
// типо если тупо добавить слово 1 ти пишет херню как так?
// баг еще в том что почему то индекмы отрицательные стали - вообще прочекать втф!!!
// TODO !!!! забыл добавть колноку - сколько там foriegn keys!!!!!
int main(){
	std::vector<Word> dictionary;
	std::cout<<"loading words...\n";
	//dictionary.push_back(Word("1"));
	loadWords(dictionary);
	std::cout<<"calculation...\n";
	calcAllWords(dictionary);
	std::cout<<"saving to db...\n";
	saveToDB(dictionary);
	
	system("pause");
	return 0;
}

