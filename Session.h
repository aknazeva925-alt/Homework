#include <iostream>
#include <string>

using namespace std;

class Film;

//lab9 & 10
class Session {
private:
	int* hallNumber;
	string* startTime;
	Film* film;           //поле род.класса (вложенное поле)

	Session(int hallNumber_, const string& time_, Film* film_);
public:
	~Session();
		//--- статический метод
	static Session* createSession(int hallNumber_, const string& time_, Film* film_);

	void setHallNumber(int hallNum);
	void setStartTime(const string& time_);

	int getHallNumber() const;
	string getStartTime() const;

	//---методы для дз10---
	  //класс Film
	void changePrice(double newPrice);
	//класс FilmCrew
	void changeDirName(const string& newDirector);
	//класс DirectorPopularFilm
	void changeDirFilm(const string& newDirFilm);
	void showSession() const;
};