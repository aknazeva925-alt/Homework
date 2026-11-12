#include <iostream>
#include "film.h"
#include "Session.h"

using namespace std;

int main()
{
	setlocale(0, "");

	FilmCrew duneFC("Оппенгеймер", "Биография", 180, 900, "Кристофер Нолан", "Киллиан Мерфи");
	DirectorPopularFilm duneDPC("Интерстеллар", "Фантастика", 169, 800, "Кристофер Нолан", "Мэттью МакКонахи", "Начало");

	Session* session1 = Session::createSession(5, "18:30", &duneFC);
	//session1->showSession();
	delete session1;

	//тест работы нисходящего приведения типов
	DirectorPopularFilm godfather("Крестный отец", "драма", 175, 670, "Френсис Форд Коппола", "Марлон Брандо", "Апокалипсис сегодня");
	
	//!!---ИСКЛЮЧЕНИЯ----
	try {
		Session* session1 = Session::createSession(-1, "12:00", &godfather);
	}
	catch (const invalid_argument) {
		cout << endl << "!!!-----------------!!!" << endl;
		cout << "Номер зала не может быть отрицательным!" << endl;
		cout << "!!!-----------------!!!" << endl;
	}
	try {
		Session* session3 = Session::createSession(2, "12:00 ", nullptr);
	}
	catch (const invalid_argument) {
		cout << endl << "!!!-----------------!!!" << endl;
		cout << "Наименование фильма не может быть пустым!" << endl;
		cout << "!!!-----------------!!!" << endl;
	}
	try {
		duneFC.setPrice(-475);
		cout << endl;
	}
	catch (const NegativePrice& e) {
		cout << endl << "!!!-----------------!!!" << endl << e.what();
		
	}


	//-----------------------------------
	

	Session* session2 = Session::createSession(1, "12:00", &godfather);
	cout << endl << "1) Было: " << endl;
	session2->showSession();

	cout << endl << "2) Стало: " << endl << endl;
	session2->changePrice(455);
	session2->changeDirName("Фрэнсис Коппола");
	session2->changeDirFilm("Сады камней");
	session2->showSession();

	delete session2;
	

}

