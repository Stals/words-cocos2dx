#include "db.h"
#include <ctime>

DB::DB(void):
	conn("words.sqlite"),
	countWords( conn, "SELECT count(*) FROM words WHERE count > 20;" ),
	randomWord( conn, "SELECT id, word, contains FROM words WHERE count > 20 LIMIT :rand, 1;" ),
	wordById( conn, "SELECT word WHERE id = :id")
{


	sqlite::command c1( conn,
    "SELECT id, word, count, contains FROM words WHERE count > 20;" );
	c1.step();

}

// TODO ����������� ��� , ����� ����� ������� ����� �� �������� ���������� id - ������ ������ ��������� ���� ��� �� ����� ������� � ������ ��� ������
Word* DB::getRandomWord(){
	///try{
		int count = 0; // ������� ���������� ���� � ����
		sqlite::row r1 = countWords.step();
		r1.column( 0, count );

		int random = rand() % count; // TODO rewrite

		randomWord.bind(":rand", random);
		sqlite::row wordRow = randomWord.step();

		int id = wordRow.column< int >( 0 );
		std::string word = wordRow.column< std::string >( 1 );
		std::string contains = wordRow.column< std::string >( 2 );

		int i = 0;


	// �������� ��� ����� �� �������
	// �������� �� ��� ���������.
		// ����� �������� ������� ��� ����� ����, ������ ������. � ����� ������ ������, ������ ��� �� ������� - � ������ ��� ��������
		// ���� ���� ����� - ������ skip(rand).limit(1) � ��� �������� ��� ������

	// ����� �� ���� contains ����� ������ getWordById � ���������� ������ ����� ������...
	// ����� ���� ������ ������� �����.

		
	//}catch( sqlite::sqlite_error &e ) {
	//	std::cerr << "error: " << e.what() << ", code " << e.get_code() << std::endl;	
	//}	

	return new Word("word");
}


std::string DB::getWordById(int id){
	std::string result;
	//try{
		wordById.bind( ":id", id ); 
		//wordById.step();
	//}catch( sqlite::sqlite_error &e ) {
	//	std::cerr << "error: " << e.what() << ", code " << e.get_code() << std::endl;	
	//}
	return result;
}

DB::~DB(void)
{
}
