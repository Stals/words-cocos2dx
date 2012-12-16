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

	// TODO ������ ��������� ������� unicode - � ������������ ����� � cocos label - ��� ��� ������� ��� ���
	std::string str;
	// ������ id ��� ���� ������� �� ����� ����� ����� �������
	std::vector<size_t> ids;

	size_t length() const {return str.length();};

	// ��������� ���� �� ��� ������� �� word � this
	bool contains(const Word& word) const;

private:
	Word();
};

