#include "StdAfx.h"
#include "word.h"

// если std::includes смотрит на 2 символа то вообще ок вроде.
// 

Word::Word(std::string word):str(word){
}



Word::~Word(void){
}

bool Word::operator==(const Word &other){
	if(this->str.compare(other.str) == 0)
		return true;
	return false;
}


bool Word::operator!=(const Word &other){
	return !((*this) == other);
}


// Проверяет чтобы в this были все символы из word
// Причем в правильно количества
bool Word::contains(const Word& word) const{
	std::string first = this->str; std::sort(first.begin(), first.end());
	std::string second = word.str; std::sort(second.begin(), second.end());

	// возрващает true если second входит в first
	return std::includes(first.begin(), first.end(), second.begin(), second.end());
}