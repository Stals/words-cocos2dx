#include "db.h"
#include <ctime>
#include <boost\algorithm\string.hpp>

DB::DB(void):
	conn("words.sqlite"),
	countWords( conn, "SELECT count(*) FROM words WHERE count > 20;" )
{
	srand(std::time(0));
}

// TODO ����������� ��� , ����� ����� ������� ����� �� �������� ���������� id - ������ ������ ��������� ���� ��� �� ����� ������� � ������ ��� ������
Word* DB::getRandomWord(){
	///try{
	sqlite::query randomWord( conn, "SELECT id, word, contains FROM words WHERE count > 20 LIMIT :rand, 1;" );

		int count = 0; // ������� ���������� ���� � ����
		sqlite::row r1 = countWords.step();
		r1.column( 0, count );

		int random = rand() % count; // TODO rewrite

		randomWord.bind(":rand", random);
		sqlite::row wordRow = randomWord.step();

		int id = wordRow.column< int >( 0 );
		Word *word = new Word(wordRow.column< std::string >( 1 ), Word::Game);
		std::string contains = wordRow.column< std::string >( 2 );

		std::vector<std::string> wordIds = split(contains, ',');
		for (int i = 0; i < wordIds.size(); ++i){
			word->addContainedWord(getWordById(atoi(wordIds[i].c_str())));
		}



	// �������� ��� ����� �� �������
	// �������� �� ��� ���������.
		// ����� �������� ������� ��� ����� ����, ������ ������. � ����� ������ ������, ������ ��� �� ������� - � ������ ��� ��������
		// ���� ���� ����� - ������ skip(rand).limit(1) � ��� �������� ��� ������

	// ����� �� ���� contains ����� ������ getWordById � ���������� ������ ����� ������...
	// ����� ���� ������ ������� �����.

		
	//}catch( sqlite::sqlite_error &e ) {
	//	std::cerr << "error: " << e.what() << ", code " << e.get_code() << std::endl;	
	//}	

	return word;
}


std::string DB::getWordById(int id){
	
	//try{
	sqlite::query wordById( conn, "SELECT word FROM words WHERE id= :id");
	wordById.clear_bindings();
		wordById.bind( ":id", id ); 
		
		sqlite::row wordRow = wordById.step();
		return boost::to_upper_copy(wordRow.column< std::string >( 0 ));
	//}catch( sqlite::sqlite_error &e ) {
	//	std::cerr << "error: " << e.what() << ", code " << e.get_code() << std::endl;	
	//}

}

DB::~DB(void)
{
}
