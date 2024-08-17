#include <iostream>
#include "circDLList.h"
#include "Movie.h"

using namespace std; 

int movieMenu ();

int main(){

    int input;
    string g, t;
    circDLList<string> list;
    Movie movie;
    
   do{
      
    input = movieMenu();

    switch(input){

        case 1: 
            system("CLS");
            
            cout << "\t\tAdd A Genre\n"
                << "--------------------------------------------------------\n";
            cout << "Enter the genre:\n";
            cin >> g;

            list.addGenre(g); //Llama la funcion addGenre

            cout << "The Genre has been Added" << endl; //Confirma que el genero fue anadido
            cout << "Genre Added: " << g << endl; //Te muestra el genero que fue anadido
            cout << "All genre of the List: "; //Te muestra una lista en orden alfabetico de todos los generos
            list.printRevList();
            cout << endl;
            
        break;
        
        case 2:
            system("CLS");
            cout << "\t\tAdd a Movie\n"
                 << "--------------------------------------------------------\n";
            cout << "This are the Genre: \n";
            list.printRevList();
            cout << endl;
            cout << "Enter the Genre do you want to add a movie: \n";
            cin >> g;

            if (list.searchGenre(g) != nullptr) {

                list.addMovie(g, movie.createMovie());
                movie.printMovie(movie);
            }
            else
            {
                cout << "Genre doesn't exist. Movie not added." << endl;
            }
            cout << endl;
            break;

        case 3: 
            system("CLS");
            cout << "\t\tModify Movie\n"
                << "--------------------------------------------------------\n";
            cout << "This are the Genre: \n";
            list.printRevList();
            cout << endl;
            cout << "Enter the Genre do you want to modify the movie: \n";
            cin >> g;
                 
            if (list.searchGenre(g) != nullptr) {

                cout << "Enter the Title of the Movie: \n";
                cin >> t;
               
                    list.modifyMovieCDLL(g, t); 

                    
            }
            else
            {
                cout << "Genre doesn't exist. Movie was not modified." << endl;

            }
            cout << endl;
            break;

        case 4:
            system("CLS");
            cout << "\t\tListing All Genre\n"
                << "--------------------------------------------------------\n";
            cout << "This are the Genre: \n";
            list.printRevList();
            cout << endl;
            break;

        case 5: 
            system("CLS");
            cout << "\t\tDelete a Movie\n"
                 << "--------------------------------------------------------\n";
            list.printRevList();
            cout << endl;
            cout << "Enter the Genre: \n";
            cin >> g;
            
            if (list.searchGenre(g) != nullptr) {

                cout << "Enter the Title of the Movie: \n";
                cin >> t;

                list.deleteMovieCDLL(g, t);

            }
            else
            {
                cout << "Genre doesn't exist. Movie not added." << endl;

            }
            cout << endl;
            break;
        case 6:
            system("CLS");
            cout << "\t\tListing All Movies for a Genre\n"
                << "--------------------------------------------------------\n";
            list.printRevList();
            cout << endl;
            cout << "Enter the Genre: \n";
            cin >> g;

            list.printAllMovieCDLL(g);
            cout << endl;
            break;

        case 7:
            system("CLS");
            cout << "\t\tSearching Movie\n"
                << "--------------------------------------------------------\n";
            cout << "This are the Genre: \n";
            list.printRevList();
            cout << endl;
            cout << "Enter the Genre: \n";
            cin >> g;

            if (list.searchGenre(g) != nullptr) {

                cout << "Enter the Title of the Movie: \n";
                cin >> t;

                list.searchMovieCDLL(g, t);

            }
            else
            {
                cout << "Genre doesn't exist. Movie not added." << endl;

            }
            cout << endl;
            break;

        case 8:
            system("CLS");
            cout << "Closing Program" << endl;
           
    }

   }while(input != 8);

    return 0;
}

int movieMenu(){

int input; 

    cout << "   \t\tMovie DataBase Menu\n   "
         << "-------------------------------------------------------------------------------------\n"
         << " Welcome to the Movie Database Menu. Please choose one of the function of this menu\n"
         << " Enter the number paired with the following function:\n"
         << " ------------------------------------------------------------------------------------\n"
         << " 1. Add a Genre\n" 
         << " 2. Add a Movie\n" 
         << " 3. Modify a Movie\n" 
         << " 4. List of All Genre\n" 
         << " 5. Delete a Movie\n"
         << " 6. List of AllMovies for a Selected Genre\n"
         << " 7. Search for a Movie\n"
         << " 8. EXIT\n"
         << "--------------------------------------------------------------------------------------\n"
         << " Choose: ";
    cin >> input;

    while (input <= 0 || input >= 9){
        system("CLS");
        cout << "ERROR. Please enter a number between 1 - 8: " << endl;
        cout << endl;
      
        movieMenu();
     
    }

    return input;
}