#pragma once
/**********************
	Circular Doubly linked List
	This class implements the circular doubly linked list using templates
	Each list has one attribute:
		-head: the node that you are step in
	Considerations:
	1. head point to null in an empty list
	2. There is not need of a tail pointer
******************/
#include "circDLLNode.h"
#include "DLList.h"
#include "DLLNode.h"
#include <iostream>


template <class T>
class circDLList {
public:
	// Default constructor: creates an empty list
	circDLList();

	// Destructor: deallocate memory
	~circDLList();

	// addToHead(T val): creates a new node with val as info, 
	// and this new node is the new head 
	void addToHead(T val);

	// addToTail(T val): creates a new node with val as info, 
	// and this new node is the new tail 	
	void addToTail(T val);

	// deleteFromHead: remove head from the list,
	// the new head is the previous head->next
	// if the list had only one node, head and tail point null
	void deleteFromHead();

	// deleteFromTail: remove tail from the list,
	// the new tail is the previous node to tail
	// if the list had only one node, head and tail point null
	void deleteFromTail();

	// In the list is empty, returns true
	// otherwise, returns false
	bool isEmpty();

	// printList(): prints all nodes in the list from head to tail
	void printList();

	// printList(): prints all nodes in the list from tail to head
	void printRevList();

	void sortInsert(string);

	/*
	* 
	*  Trivia Movie DataBase Extra Function
	* 
	*/
	void addGenre(string genre); //Agrega Generos a la Lista Doble Enlazada Circular
	circDLLNode<T>* searchGenre(string);//Buscae el Nodo que contiene el genero que deseamos y devuelve un puntero con el nodo 
	void addMovie(string g, Movie m);//Agrega una pelicula en la lista enlazada doble del nodo del genero que indicamos
	void searchMovieCDLL(string, string); //Busca la pelicula en la lista doble enlazada utilizando la funcion searchGenre para buscar el genero antes
	void modifyMovieCDLL(string, string); // Modifica la pelicula del genero que indiquemos
	void deleteMovieCDLL(string,string); //Eliminamos la pelicula del genero que indiquemos 
	void printAllMovieCDLL(string); //Imprimimos todas las peliculas que contendga ese genero

private:
	circDLLNode<T>* head; // A pointer to the first node
	
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
circDLList<T>::circDLList()
{
	head = 0;
}
/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
circDLList<T>::~circDLList()
{
	while (!isEmpty())
		this->deleteFromHead();
}

/***********************
	printList(): prints all nodes in the list
*****************/
template <class T>
void circDLList<T>::printList()
{
	circDLLNode<T>* prtNode;
	prtNode = head;
	if (prtNode != 0)
	{
		while (prtNode->getNext() != head) {
			cout << prtNode->getGenre() << " ";
			prtNode = prtNode->getNext();
		}
		cout << prtNode->getGenre() << " ";
	}
}

/***********************
	printRevList(): prints all nodes in the list from tail to head
*****************/
template <class T>
void circDLList<T>::printRevList()
{
	circDLLNode<T>* prtNode;
	prtNode = head;
	if (prtNode != 0)
	{
		while (prtNode->getPrev() != head) {
			prtNode = prtNode->getPrev();
			cout << prtNode->getGenre() << " ";
		}
		cout << head->getGenre() << " ";
	}
}

/***********************
	If the list is empty, returns true
	otherwise, returns false
*****************/
template <class T>
bool circDLList<T>::isEmpty()
{
	bool res;
	res = false;
	if (head == 0)
	{
		res = true;
	}
	return res;
}

/***********************
	Implement other methods
***********************/

template <class T>
void circDLList<T>::addToHead(T val)
{
	if (head != 0) //Si la lista no esta vacia
	{
		circDLLNode<T>* tmp; //Creamos un puntero temporero llamado tmp
		tmp = new circDLLNode<T>(head->getPrev(), val, DLList<T>(), head); //Tmp va a estar apuntando a un nuevo nodo 
		head->getPrev()->setNext(tmp); //el prev de head va a hacer su next el nuevo nodo
		head->setPrev(tmp); //El prev de head va a estar apuntando a el nuevo nodo
		head = tmp; //Head va a apuntar al nuevo nodo
	}
	else //Si la lista esta vacia 
	{
		head = new circDLLNode<T>(0, val, DLList<T>(), 0); //Creamos un nuevo nodo con el prev apuntando a null y el next apuntando a null y head apuntara al nuevo nodo
		head->setNext(head); //El nodo nuevo su next estara apuntando el mismo nodo
		head->setPrev(head);//El nodo nuevo su orev estara apuntando el mismo nodo
	}
}

template <class T>
void circDLList<T>::addToTail(T val)
{
	if (head != 0) //Si la lista no esta vacia 
	{
		circDLLNode<T>* tmp; //Creamos un puntero nuevo llamado tmp
		tmp = new circDLLNode<T>(head->getPrev(), val, DLList<T>(), head); //Se crea un nuevo nodo 
		head->getPrev()->setNext(tmp);//El next del nodo de head estara apuntando al nodo de tmp
		head->setPrev(tmp); //El prev del nodo de head estara apuntando a el nodo de tmp
	}
	else //Si esta vacia 
	{
		head = new circDLLNode<T>(0, val, DLList<T>(), 0); //Creamos un nuevo nodo donde su next y prev apuntaran a null
		head->setNext(head); //El next del nuevo nodo se apunta a si mismo
		head->setPrev(head); //El prev del nuevo nodo se apunta a si mismo 
	}
}

template <class T>
void circDLList<T>::deleteFromHead()
{
	if (head != 0) //Si la lista no esta vacia 
	{
		circDLLNode<T>* tmp; //Creamos un puntero temporero llamado tmp
		tmp = head; //Tmp estara apuntando a el nodo de head 

		if (head == head->getNext()) //Si la lista solamente tiene 1 nodo
		{
			head = 0; //Hacemos que head apunte a 0
		}
		else
		{
			head->getNext()->setPrev(head->getPrev());//Hacemos el prev del proximo nodo de head el prev de head
			head->getPrev()->setNext(head->getNext()); //Hacemos el prev de head el next del proximo de head 
			head = head->getNext(); //Head estara apuntando al proximo nodo
		}

		delete tmp; //Eliminamos tmp
	}
}

template <class T>
void circDLList<T>::deleteFromTail()
{
	if (head != 0) //Si la lista no esta vacia 
	{
		circDLLNode<T>* tmp; //Creamos un puntero temporero 
		tmp = head->getPrev(); //Tmp estara apuntando al prec de head 

		if (head == head->getNext())  //Si solamente hay un solo nodo
		{
			head = 0; //Head estara apuntanod a null
		}
		else //Si hay mas de un nodo 
		{
			tmp->getPrev()->setNext(head); //El nodo prev de tmp va a ser su next el nodo head
			head->setPrev(tmp->getPrev()); //Va a ser el prev de head el prev de tmp

		}

		delete tmp; //Eliminamos nodo 
	}
}

template<class T>
void circDLList<T> ::sortInsert(string genre) {

	if (head == 0) { //Si la lista esta vacia

		addToHead(genre); //Agregamos al principio de la lista

	}
	else //Si la lista no esta vacia 
	{
		circDLLNode<T>* tmp; //Creamos un puntero temporero de tipo circDLLNode
		tmp = head; //El puntero tmp va a estar apunatndo al nodo de head 
		//Mientras que el largo del genero del nodo apuntado por tmp sea mayor que 0 y que el primer caracter del genero entrado sea menor que el primer caracter del genero del nodo
		//y el proximo del nodo de tmp no sea igual a el nodo apuntado por head
		while (tmp->getGenre().length() > 0 && genre[0] < tmp->getGenre()[0] && tmp->getNext() != head) { 
			
			tmp = tmp->getNext(); //Estaremos moviendonos por la lista circular

		}
		//Si el proximo nodo de tmp es igual a el nodo de head Y que el primer caracter del genero entrado sea menor que el primer caracter del genero del nodo O el largo del genero del 
		//nodo sea igual a 0
		if (tmp->getNext() == head && (genre[0] < tmp->getGenre()[0] || tmp->getGenre().length() == 0)) {

			addToTail(genre); //Agregamos al final de la lista
		}
		else
		{
			//Si tmp esta apuntando al mismo nodo que head Y que el primer caracter del genero entrado es mayor que el primer caracter dle genero del noso O que el largo del 
			//genero del nodo sea igual a 0
			if (tmp == head && (genre[0] > tmp->getGenre()[0] || tmp->getGenre().length() == 0)) {

				addToHead(genre); //Agregamos al principio de la lista

			}
			else //Si se agraga en el medio
			{
				//Creamos un Nodo nuevo con su prev a null, su next a null, genre y una lista doble 
				circDLLNode<T>* newNode = new circDLLNode<T>(nullptr, genre, DLList<T>(), nullptr); 
				newNode->setNext(tmp); //El next de newNode va a apuntar a el nodo de tmp
				newNode->setPrev(tmp->getPrev()); //El prev de newNode va a apuntar al nodo prev de tmp
				tmp->getPrev()->setNext(newNode); //El nodo prev de tmp va a apuntar su next al nuevo nodo
				tmp->setPrev(newNode); //El prev de tmp va a apuntar al nuevo nodo


			}
		}
	}
}

/* 
* 
*			Movie Function			
* 
* 
*/

/*
* Funcion addGenre
* 
* Esta funcion se encarga de agregar el genero a la lista doble enlazada circular
* 
*/
template<class T> 
void circDLList<T> ::addGenre(string genre){

	sortInsert(genre);

}

/*
* Funcion searchGenre
* 
* Esta funcion se encarga de buscar el genero de la lista doble enlazada circular y estaria devolviendo el nodo apuntado por el puntero tmp
* 
*/
template<class T>
circDLLNode<T>* circDLList<T> ::searchGenre(string g) {
	if (!isEmpty()) { //Si la Lista No Esta Vacia
		circDLLNode<T>* tmp; //Crea un Puntero Temporero llamado tmp
		tmp = head; //TMP estara apuntando a el nodo de head

		while (tmp->getNext() != head && tmp->getGenre() != g){ // Mientras que el genero del nodo apuntado por tmp no sea igual al genero entrado
			
			tmp = tmp->getNext(); //Nos movemos en la lista enlazada

		}

		if (tmp->getGenre() == g) { //Si el genero del nodo es igual al genero a buscar

			return tmp; //Retornamos el nodo 
		}	
	}	
	return nullptr; //Retornamos null
}

/*
*	Funcion addMovie
* 
* Esta funcion se encarga de agregar la pelicula a la lista enlazada doble utilizando la funcion searchGenre para buscar el genero que contiene la lista enlazada que 
* se va a agregar la pelicula
*/
template<class T>
void circDLList<T> ::addMovie(string g, Movie m) {
	circDLLNode<T>* search = searchGenre(g); //Creamos un puntero circDLLNode llamado search que estara apuntando al nodo que contiene el genero que queremos

	if (search != nullptr) { //Si nos retorno un nodo

		DLList<T>* dllist; //Se crea un puntero de tipo DLList llamado dllist que estra apuntando a la lista doble enlazada
		dllist = search->getDLL(); //Dllist estara apuntando a la lista enlazada del nodo
		
		dllist->addMovie(m); //Agregamos la pelicula al nodo de la doble lista enlazada

		cout << "The Movie was Successfully Added" << endl; //Confirmamos que la lista fue agregada
	}		
}

/*
* Funcion searchMovieCDLL
* 
* Esta funcion se encargara de buscar la pelicual en la lista doble enlazada utilizando la funcion searchGenre para buscar el genero que contiene la lista enlazada con las movie
*/
template<class T>
void circDLList<T> ::searchMovieCDLL(string g, string title) {

	circDLLNode<T>* search = searchGenre(g); //Creamos un puntero circDLLNode llamado search que estara apuntando al nodo que contiene el genero que queremos
	Movie m; //Objecto movie

	if (search != nullptr) { //Si nos retorno un nodo

		DLList<T>* dllist; //Se crea un puntero de tipo DLList llamado dllist que estra apuntando a la lista doble enlazada
		dllist = search->getDLL(); //Dllist estara apuntando a la lista enlazada del nodo

		Movie movie = dllist->searchMovie(title); //Alamcenamos la pelicula que buscamos en el objecto movie

		if (movie.getTitle() == title) {

			m.printMovie(movie); //Imprimimos la pelicula 
		}
		else
		{
			cout << "The Movie doesn't exist" << endl;
		}
	}
}

/*
* Funcion ModifyMovieCDLL
* 
* La funcion se encarga de modificar la pelicula utilizazndos searchGenre para buscar el genero 
* 
*/
template<class T>
void circDLList<T> ::modifyMovieCDLL(string g, string title) {
	circDLLNode<T>* search = searchGenre(g); //Creamos un puntero circDLLNode llamado search que estara apuntando al nodo que contiene el genero que queremos
	char ans; //Variable que obtendra la contestacion del usuario

	if (search != 0) { //Si nos retorno un nodo

		DLList<T>* dllist; //Se crea un puntero de tipo DLList llamado dllist que estra apuntando a la lista doble enlazada
		dllist = search->getDLL(); //Dllist estara apuntando a la lista enlazada del nodo

		Movie movie = dllist->searchMovie(title);
		movie.printMovie(movie);

		cout << "Do you wanna modify the movie " << title << "? " << endl; //Le pregunta al usuario que si quiere modificarla
		cin >> ans;
		
		if (ans == 'y' || ans == 'Y') { //Si La contestacion es y o Y 

			dllist->modifyMovie(title); //Modificamos la Pelicula			

		}
		else //Si no entran y o Y 
		{
			cout << "The Modification has been Cancel" << endl; //Notifica que que la modificacion fue cancelada
		}		
	}
}

/*
* Funcion deleteMovieCDLL
* 
* Esta funcion se encarga de eliminar la pelicula de la lista utilizando searchGenre para busacr el genero
*/
template<class T>
void circDLList<T> ::deleteMovieCDLL(string g, string title) {
	circDLLNode<T>* search = searchGenre(g); //Creamos un puntero circDLLNode llamado search que estara apuntando al nodo que contiene el genero que queremos
	char ans;

	if (search != 0) { //Si nos retorno un nodo

		DLList<T>* dllist; //Se crea un puntero de tipo DLList llamado dllist que estra apuntando a la lista doble enlazada
		dllist = search->getDLL();//Dllist estara apuntando a la lista enlazada del nodo

		cout << "Do you wanna delete the movie " << title << "? " << endl; //Le pregunta al usuario que si quiere modificarla
		cin >> ans;

		if (ans == 'y' || ans == 'Y') { //Si La contestacion es y o Y 

			dllist->deleteMovie(title); //Eliminamos la pelicula 
			
		}
		else
		{
			cout << "The elimination was cancelled " << endl;
		}
	}
	else
	{
		cout << "Genre doesn't exist" << endl; //Le informamos que el genero no existe

	}
}

/*
* Funcion prinALLMovieCDLL
* 
* Esta funcion se encarga de imprimir todas las peliculas de la lista 
*/
template<class T>
void circDLList<T> ::printAllMovieCDLL(string g) {
	circDLLNode<T>* search = searchGenre(g); //Creamos un puntero circDLLNode llamado search que estara apuntando al nodo que contiene el genero que queremos

	if (search != 0) { //Si nos retorno un nodo

		DLList<T>* dllist; //Se crea un puntero de tipo DLList llamado dllist que estra apuntando a la lista doble enlazada
		dllist = search->getDLL(); //Dllist estara apuntando a la lista enlazada del nodo

		dllist->printAllMovie();

	}
	else
	{
		cout << "Genre doesn't exist" << endl; //Le informamos que el genero no existe
	}
}