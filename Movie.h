#pragma once

#pragma once
#include <string>
#include <iostream>
#include <limits>

using namespace std;

class Movie {
public:
	/*Constructors*/
	Movie(); //When movie is empty
	Movie(string, string, string, int); //Special Constructor
	
	Movie createMovie();
	void printMovie(Movie);


	/*Getters*/
	string getTitle()const;
	string getSynopsis()const;
	string getDirector()const;
	int getRYear()const;

	/*Setters*/
	void setTitle(string);
	void setSynopsis(string);
	void setDirector(string);
	void setRYear(int);

	bool movieExist()const;

private:
	string title;
	string synopsis;
	string director;
	int ryear;
};

/*Empty Movie*/
Movie::Movie() {
	title = synopsis = director = ryear = 0;
}

/*Special Constructor*/
Movie::Movie(string t, string s, string d, int r) {
	title = t;
	synopsis = s;
	director = d;
	ryear = r;
}

/*GetTitle Function*/
string Movie::getTitle()const{
	return title;
}

/*GetSynopsis Function*/
string Movie::getSynopsis()const{
	return synopsis;
}

/*GetDirector Function*/
string Movie::getDirector()const{
	return director;
}

/*GetRYear Function*/
int Movie::getRYear()const{
	return ryear;
}

/*SetTitle Function*/
void Movie::setTitle(string t) {
	title = t;
}

/*SetSynopsis Function*/
void Movie::setSynopsis(string s) {
	synopsis = s;
}

/*SetDirector Function*/
void Movie::setDirector(string d) {
	director = d;
}

/*SetRYear Function*/
void Movie::setRYear(int r) {
	ryear = r;
}

bool Movie::movieExist()const {
	return !title.empty();
}

/*
* Funcion createMovie
* 
* Funcion se encarga de crear la pelicula 
* 
*/
Movie Movie::createMovie() {

	Movie userMovie;

	cout << "\t\tCreating a New Movie\n"
		<< "----------------------------------------------\n"
		<< "To Create a Movie we need the following information (Without space):\n"
		<< "Title: Title of the Movie\n"
		<< "Synopsis: A short summary of the movie\n"
		<< "Director: Director of the Movie\n"
		<< "Release Year: Year of Publication\n"
		<< "-----------------------------------------------\n";

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Title: \n";
	getline(cin, title);
	userMovie.setTitle(title);

	cout << "Synopsis: \n";
	getline(cin, synopsis);
	userMovie.setSynopsis(synopsis);

	cout << "Director: \n";
	getline(cin, director);
	userMovie.setDirector(director);

	cout << "Release Year: \n";
	cin >> ryear;
	userMovie.setRYear(ryear);
	 
	return userMovie;

}

/*
* Funcion PrintMovie
* 
* La funcion se encarga de imprimer la Movie
*/
void Movie :: printMovie(Movie movie){

	cout << "Movie" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "Title: " << movie.getTitle() << endl;
	cout << endl;
	cout << "Synopsis: " << movie.getSynopsis() << endl;
	cout << endl;
	cout << "Director: " << movie.getDirector() << endl;
	cout << endl;
	cout << "Released Year: " << movie.getRYear() << endl;
	cout << endl;

}

