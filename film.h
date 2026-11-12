#include <iostream>
#include <string>

using namespace std;

//для класса-исключения
class NegativePrice : public exception {
private:
	string message;
public:
	NegativePrice(double price) {
		message = "Цена не может быть отрицательной.";
	}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

class Film
{
private:
	string* film_name;
	string* genre;
	int* time; //в минутах
	double* ticket_price;

protected:
	int seats = 200;
	int revenue() const;

	void showCommon() const;

public:
	//конструктор 1
	Film(const string& nameFilm, const string& genre_,
		int time_, double price_);

	//деконструктор
	virtual ~Film();

	//1 set & get
	void setFilm_name(const string& nameFilm);
	string getFilm_name() const;
	//2 set & get
	void setGenre(const string& genre_);
	string getGenre() const;
	//3 set & get
	void setTime(int time_);
	int getTime() const;
	//4 set & get
	void setPrice(double price_);
	//вывод
	virtual void showFilm() const = 0;
};  

class FilmCrew : public Film {
private:
	string* nameDirector;
	string* nameMainActor;
public:
	//конструктор
	FilmCrew(const string& nameFilm, const string& genre_,
		int time_, double price_,
		const string& nameDirector_, const string& nameMainActor_);
	//деконструктор
	~FilmCrew() override;
	void setNameDirector(const string nameDirector_);
	void setNameMainActor(const string nameMainActor_);
	void showFilm() const override;
};


class DirectorPopularFilm : public FilmCrew {
private:
	string* nameFilmDir;
public:
	//конструктор
	DirectorPopularFilm(const string& nameFilm, const string& genre_,
		int time_, double price_,
		const string& nameDirector_, const string& nameMainActor_,
		const string& nameFilmDir_);
	//деконструктор
	~DirectorPopularFilm() override;
	void setNameFilmDir(const string nameFilmDir_);
	void showFilm() const override;
};
