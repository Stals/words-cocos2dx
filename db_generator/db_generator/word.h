#pragma once
#include <string>
#include <vector>
#include <algorithm>

class Word
{
public:
	Word(std::string word);
	~Word(void);

	bool operator==(const Word &other);
	bool operator!=(const Word &other);

	// TODO должен позволять хранить unicode - и отображаться потом в cocos label - так что глянуть как там
	std::string str;
	// Хранит id тех слов которые из этого слова можно сделать
	std::vector<size_t> ids;

	size_t length() const {return str.length();};

	// проверяет если ли все символы из word в this
	bool contains(const Word& word) const;

private:
	Word();
};

