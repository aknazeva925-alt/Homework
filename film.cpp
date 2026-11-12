#include <iostream>
#include <string>
#include <stdexcept>
#include "film.h"

using namespace std;

//реализация методов классов Film, FilmCrew, DirectorPopularFilm

int Film::revenue() const {
	return seats * (*ticket_price);
}

void Film::showCommon() const {
	cout << "Фильм: " << *film_name << endl
		<< "Жанр: " << *genre << endl
		<< "Длительность (в минутах): " << *time << endl
		<< "Стоимость билета: " << *ticket_price << " рублей" << endl
		<< "Выручка с полного зала (" << seats << " мест): "
		<< revenue() << " рублей" << endl;
}

Film::Film(const string& nameFilm, const string& genre_,
	int time_, double price_)
{
	film_name = new string(nameFilm);
	genre = new string(genre_);
	time = new int(time_);
	ticket_price = new double(price_);
}

Film::~Film() {
	delete film_name;
	delete genre;
	delete time;
	delete ticket_price;
}

void Film::setFilm_name(const string& nameFilm) {
	if (nameFilm.empty()) {
		throw invalid_argument("Поле не может быть пустым!");
	}
	*film_name = nameFilm;
}

string Film::getFilm_name() const {
	return *film_name;
}
void Film::setGenre(const string& genre_) {
	if (genre_.empty()) {
		throw invalid_argument("Поле не может быть пустым!");
	}
	*genre = genre_;
}
string Film::getGenre() const {
	return *genre;
}

void Film::setTime(int time_) {
	if (time_ <= 0) {
		throw invalid_argument("Длительность фильма не может быть меньше или равна 0.");
	}
	*time = time_;
}

int Film::getTime() const {
	return *time;
}
void Film::setPrice(double price_) {
	if (price_ <= 0) {
		throw NegativePrice(price_);
	}
	if (price_ > 1500) {
		throw out_of_range("Стоимость билета не может быть больше 1500.");
	}
	*ticket_price = price_;
}

//__________________________________________

FilmCrew::FilmCrew(const string& nameFilm, const string& genre_,
	int time_, double price_,
	const string& nameDirector_, const string& nameMainActor_) : Film(nameFilm, genre_, time_, price_) {
	nameMainActor = new string(nameMainActor_);
	nameDirector = new string(nameDirector_);
}
FilmCrew::~FilmCrew()
{
	delete nameMainActor;
	delete nameDirector;

}

void FilmCrew::setNameDirector(const string nameDirector_) {
	if (nameDirector_.empty()) {
		throw invalid_argument("Поле не может быть пустым!");
	}
	*nameDirector = nameDirector_;
}

void FilmCrew::setNameMainActor(const string nameMainActor_) {
	if (nameMainActor_.empty()) {
		throw invalid_argument("Поле не может быть пустым!");
	}
	*nameMainActor = nameMainActor_;
}

void FilmCrew::showFilm() const {
	showCommon();
	cout << "Режиссёр: " << *nameDirector << endl
		<< "Главная роль: " << *nameMainActor << endl << endl;
}

//_______________________________________________________

DirectorPopularFilm::DirectorPopularFilm(const string& nameFilm, const string& genre_,
	int time_, double price_,
	const string& nameDirector_, const string& nameMainActor_,
	const string& nameFilmDir_) : FilmCrew(nameFilm, genre_, time_, price_,
		nameDirector_, nameMainActor_)
{
	nameFilmDir = new string(nameFilmDir_);

}

DirectorPopularFilm::~DirectorPopularFilm()
{
	delete nameFilmDir;
}

void DirectorPopularFilm::setNameFilmDir(const string nameFilmDir_) {
	if (nameFilmDir_.empty()) {
		throw invalid_argument("Поле не может быть пустым!");
	}
	*nameFilmDir = nameFilmDir_;
}
void DirectorPopularFilm::showFilm() const {
	FilmCrew::showFilm();
	cout << "Другой популярный фильм режиссера: " << *nameFilmDir << endl << endl;
}
