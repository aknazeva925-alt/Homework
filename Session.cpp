#include <iostream>
#include <string>
#include "Session.h"
#include "film.h"

using namespace std;

//реализация методов класса Session

Session::Session(int hallNumber_, const string& time_, Film* film_) {
	hallNumber = new int(hallNumber_);
	startTime = new string(time_);
	film = film_;
}
Session::~Session() {
    delete hallNumber;
    delete startTime;
}

Session* Session::createSession(int hallNumber_, const string& time_, Film* film_) {
    if (hallNumber_ <= 0) throw invalid_argument("Номер зала должен быть положительным!");
    if (time_.empty()) throw invalid_argument("Время не может быть пустым!");
    if (film_ == nullptr) throw invalid_argument("Указатель на фильм не может быть пустым!");
    return new Session(hallNumber_, time_, film_);
}

void Session::setHallNumber(int hallNum) {
    if (hallNum <= 0) throw invalid_argument("Номер зала должен быть положительным!");
    *hallNumber = hallNum;
}

void Session::setStartTime(const string& time_) {
    if (time_.empty()) throw invalid_argument("Время не может быть пустым");
    *startTime = time_;
}

int Session::getHallNumber() const { return *hallNumber; }
string Session::getStartTime() const { return *startTime; }

void Session::changePrice(double newPrice) {
    film->setPrice(newPrice);
    cout << "!!Цена билета на фильм изменена!!" << endl;
}

void Session::changeDirName(const string& newDirector) {
    FilmCrew* crewFilm = dynamic_cast<FilmCrew*>(film);
    if (crewFilm != nullptr) {
        crewFilm->setNameDirector(newDirector);
        cout << endl << "!!Имя режиссера изменено.!!" << endl;
    }
    else {
        cout << endl << "Ошибка.";
    }
}

void Session::changeDirFilm(const string& newDirFilm) {
    DirectorPopularFilm* dirFilm = dynamic_cast<DirectorPopularFilm*>(film);
    if (dirFilm != nullptr) {
        dirFilm->setNameFilmDir(newDirFilm);
        cout << endl << "!!Название популярного фильма режиссера изменено.!!" << endl;
    }
    else {
        cout << endl << "Ошибка.";
    }
}

void Session::showSession() const {
    cout << endl << "--- ИНФОРМАЦИЯ О СЕАНСЕ ---" << endl;
    cout << "Зал № " << *hallNumber << endl;
    cout << "Время начала: " << *startTime << endl;
    cout << "--- ИНФОРМАЦИЯ О ФИЛЬМЕ ---" << endl;
    film->showFilm();
}