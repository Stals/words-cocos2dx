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

// TODO Единстенное что , нужно будет сделать чтобы не возврвли одинаковое id - тоесть заново рандомить пока оно не будет входить в список уже бывших
Word* DB::getRandomWord(){
	///try{
		int count = 0; // сколько подходящих слов в базе
		sqlite::row r1 = countWords.step();
		r1.column( 0, count );

		int random = rand() % count; // TODO rewrite

		randomWord.bind(":rand", random);
		sqlite::row wordRow = randomWord.step();

		int id = wordRow.column< int >( 0 );
		std::string word = wordRow.column< std::string >( 1 );
		std::string contains = wordRow.column< std::string >( 2 );

		int i = 0;


	// Получаем все слова по запросу
	// Выбираем из них случайное.
		// можно узнавать сколько там таких слов, делать рандом. и потом делать запрос, скипая все до нужного - и только его получать
		// либо если можно - делать skip(rand).limit(1) и так получить его одного

	// потом по полю contains нужно делать getWordById и запихивать внутрь слова самого...
	// После чего просто вернуть слово.

		
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
