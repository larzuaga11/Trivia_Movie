#pragma once
/**********************
Double linked node
This class implements the singly linked list using templates
Each list has two attributes:
	-head: first node in the list
	-tail: last node in the list

Considerations:
1. head and tail point to null in an empty list
2. tail->next=null
******************/

#include "DLLNode.h"
#include<iostream>

template <class T>
class DLList {
public:
	//Default constructor: creates an empty list
	DLList();

	//Destructor: deallocate memory
	~DLList();

	//addToHead(T val): creates a new node with val as info, 
	//and this new node is the new head 
	void addToHead(Movie movie);

	//addToTail(T val): creates a new node with val as info, 
	//and this new node is the new tail 	
	void addToTail(Movie movie);

	//deleteFromHead: remove head from the list,
	//the new head is the previous head->next
	//if the list had only one node, head and tail point null
	void deleteFromHead();

	//deleteFromTail: remove tail from the list,
	//the new tail is the previous node to tail
	//if the list had only one node, head and tail point null
	void deleteFromTail();

	//In the list is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//sortInsert(T val): creates a new node, and it is inserted sortly
	void sortInsert(Movie movie);

	//printList(): prints all nodes in the list from head to tail
	void printList();

	//printList(): prints all nodes in the list from tail to head
	void printRevList();
	//Busca la pelicula en la lista doble enlazada
	Movie searchMovie(string title);

	void modifyMovie(string title); 

	void addMovie(Movie movie);

	void deleteMovie(string);

	void printAllMovie();

private:
	DLLNode<T>* head; //A pointer to the first node
	DLLNode<T>* tail; //A pointer to the last node
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
DLList<T>::DLList()
{
	tail = head = 0;
}
/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
DLList<T>::~DLList()
{
	//Declare a pointer prtNode	
	DLLNode<T>* prtNode;
	//prtNode points head
	prtNode = head;

	//While there is a node in the list, remove it
	while (prtNode != 0)
	{
		//prtNode points head->next
		prtNode = head->getNext();

		//delete head
		delete head;

		//the new head is prtNode
		head = prtNode;
	}
}

/***********************
	Implement other methods

***********************/
//AddToHead ()
template <class T>
void DLList<T> ::addToHead(Movie movie) {
	if (head != 0) { //Si la lista no esta vacia

		head->setPrev(new DLLNode<T>(0, movie, head)); //Creamos un nuevo nodo en el prev de el nodo head donde su prev esta apuntando a null, su info es val y su next esta apuntando al nodo de head
		head = head->getPrev(); //Head estara apuntando al nuevo nodo

	}
	else //Si la lista esta vacia 
	{
		tail = head = new DLLNode<T>(0, movie, head); //Head y tail estaran apuntando al nuevo nodo donde su prev va a apuntar a null, su info sera val y su next estara apuntado a null.

	}
}


//AddToTail ()
template <class T>
void DLList<T> ::addToTail(Movie movie) {
	if (head != 0) { //Si head no esta apuntado a null

		tail->setNext(new DLLNode<T>(tail, movie, 0)); //EL proximo de tail va a ser un nuevo nodo donde su prev esta apuntado al nodo de tail, la info sera val y el  next estara apuntado a null
		tail = tail->getNext(); //Tail estara apuntado a el nuevo nodo

	}
	else //Si head esta apuntando a null 
	{
		head = tail = new DLLNode<T>(tail, movie, 0); //head y tail estaran apuntando a un nuevo nodo en el que su prev esta apundo a 0 y su info sera val y su next esta apuntado a null
	}


}


//deleteFromHead ()
template <class T>
void DLList<T> ::deleteFromHead() {
	if (head != 0) {

		DLLNode<T>* tmp; //Creamos un puntero temporero
		tmp = head; //El Puntero Temporero estara apuntando al nodo de head
		head = head->getNext(); //Head estara apuntando el next nodo

		if (head == 0) { //Si head esta apuntando a null

			tail = 0; //Tail estara apuntado tambien a null
		}
		else //Si head no esta apuntando a null 
		{
			head->setPrev(0); //El prev del nodo head estara apuntaod a null
			
		}

		delete tmp; //Eliminamos nodo
	}
}

//deleteFromTail()
template <class T>
void DLList<T> ::deleteFromTail(){
	if (head != 0) {

		DLLNode<T>* tmp; //Creamos una variable temporera llamada tmp
		tmp = tail; //Tmp apuntara a el nodo de tail 
		
		if (head == tail) { //Si tail esta apuntando al mismo nodo que head

			head = tail = 0; //Eliminamos el nodo 
		}
		else //Si tail no esta apuntando al mismo nodo que head
		{
			tail = tail->getPrev(); //tail apuntara al prev
			tail->setNext(0); //El puntero next del nodo tail estara apuntando a null
			
		}

		delete tmp; //Eliminamos el puntero tmp;
	}
}

//isEmpty ()
template<class T>
bool DLList<T> ::isEmpty(){

	bool res;
	res = false;
	if (head == 0) { 
		res = true; 
	}
	return res; //Retorna cierto si esto se cumple

}

//sortInsert (T val)
template<class T>
void DLList<T> ::sortInsert(Movie movie) {
	if (head == 0) { //Si la lista esta vacia 

		addToHead(movie); //Se aplica un addToHead
	}
	else //Si la lista no esta vacia 
	{
		DLLNode<T>* tmp, * tmp2 = 0; //Se crea dos punteros temporeor llamados tmp1 y tmp2 
		tmp = head; //Tmp estara apuntando a el nodo de head 

		while( tmp != 0 && movie.getTitle()[0] < tmp->getMovie().getTitle()[0]) //Mientras que val sea menor que el proximo nodo y tmp no este apuntando a tail 
		{
			tmp2 = tmp; //Tmp2 estara apuntando al nodo de tmp 
			tmp = tmp->getNext(); //Tmp se estara moviendo al proximo nodo 
		}

		if (tmp == 0) //Si tmp esta apuntando a null
		{
			addToTail(movie); //Realizamos un addToTail
		}
		else 
		{
			
			if (tmp2 != 0) {

				tmp2->setNext(new DLLNode<T>(tmp2, movie, tmp));

			}
			else
			{
				addToHead(movie);
			}

			if (tmp != 0) {
				tmp->setPrev(new DLLNode<T>(tmp2, movie, tmp));

			}
			else
			{
				addToTail(movie);
			}
		}	
	}
}

//printList ()
template<class T>
void DLList<T> ::printList() {
	DLLNode<T>* tmp; //Creamos un Puntero Temporero llamado tmp 
	tmp = head; //Tmp va a estar apuntando a tmp 

	while (tmp != 0) { //Mientras que tmp no este apuntando a null
		cout << tmp->getMovie() << " "; //Imprime la info del nodo en el que esta apuntando
		tmp = tmp->getNext(); //Tmp se mueve al next nodo
	}
}

//printRevList ()
template<class T>
void DLList<T> ::printRevList() {
	DLLNode<T>* tmp; //Se crea un puntero temporero llamado tmp
	tmp = tail; // Tmp estara apuntando al nodo de tail

	while (tmp != 0) { //Mientras que tmp no este apuntando a null
		cout << tmp->getMovie() << " "; //Imprime la informacion de el nodo
		tmp = tmp->getPrev(); //Tmp se mueve al nodo prev
	}
}



/*
*
*		Movie Function 
*/

/*
* Funcion addMovie
* 
* Agrega una pelicula a la lista enlazada doble
*/
template<class T>
void DLList<T> ::addMovie(Movie movie) {

	sortInsert(movie);

}

/*
* 
* Funcion searchMovie
* 
* Esta funcion se encarga de buscar la pelicula en la lista enlazada doble 
* 
*/
template<class T>
Movie DLList<T> ::searchMovie(string title) {
	Movie movie; //Objecto Movie 

	if (head != 0) { //Si la lista no esta vacia

		DLLNode<T>* tmp; //Puntero temporero llamado tmp
		tmp = head; //Tmp va a estar apuntando al nodo de head

		//Mientras que el proximo nodo de tmp no sea nullo Y que el titulo del nodo de tmp no sea igual al titulo buscado
		while (tmp->getNext() != nullptr && tmp->getMovie().getTitle() != title) {

			tmp = tmp->getNext(); //Se mueve por la lista

		}

		if (tmp->getMovie().getTitle() == title) { //Si el titulo de nodo apuntado por tmp es igual al titulo buscado 

			movie = tmp->getMovie(); //Almacena la movie en el objecto movie
			return movie; //Retorna movie
		}		
	}

	return Movie();
}



template<class T>
void DLList<T> ::deleteMovie(string title) {
	Movie movie = searchMovie(title);

	if (movie.getTitle() == title) { //Si la pelicula existe
		if (head != 0) {

			DLLNode<T>* tmp;
			tmp = head;

			if (tmp->getMovie().getTitle() == title) {

				deleteFromHead();
				cout << "The Movie has been deleted" << endl; //Notifica que la pelicula fue eliminada
			}
			else
			{
				while (tmp->getNext() != 0 && tmp->getNext()->getMovie().getTitle() != title) {

					tmp = tmp->getNext();
				}

				if (tmp->getNext() != 0) {
					DLLNode<T>* deleteNode = tmp->getNext();
					tmp->setNext(deleteNode->getNext());
					deleteNode->getNext()->setPrev(tmp);
					delete deleteNode;
					cout << "The Movie has been deleted" << endl; //Notifica que la pelicula fue eliminada
				}
			}
		}
	}
	else
	{
		cout << "Movie doesn't exist" << endl;
	}
}

/*
* Funcion modifyMovie
* 
* Esta funcion se encarga de modificar la pelicula utiliznado la funcion searchMovie
* 
*/
template<class T>
void DLList<T> ::modifyMovie(string title) {
	Movie movie = searchMovie(title); //Alamcenamos la movie encontrada por la funcion searchMovie en el objecto movie

	if (movie.getTitle() == title) { //Si existe la pelicula
		deleteMovie(title); //Eliminamos la pelicula
		movie = movie.createMovie(); //Creamos la pelicula nueva
		addMovie(movie); //Anadimos la Pelicula
		cout << "The Movie has been Modified" << endl; //Informamos que la Pelicula fue modificada
		movie.printMovie(movie); //Imprimimos la pelicula nueva
	}
	else
	{
		cout << "The Movie not found" << endl; //La pelicula no fue encontrada 
	}
}

/*
* Funcion PrintAllMovie
* 
* Esta funcion se va a encargar de imprimir 
* 
*/
template<class T>
void DLList<T>::printAllMovie() {
	if (head != 0) { //Si la lista no esta vacia

		DLLNode<T>* tmp; //Creamos un puntero temporero 
		tmp = head; //El puntero temporero apuntadra a head

		while (tmp != 0) { //Mientras que tmp no este apuntando a null
			tmp->getMovie().printMovie(tmp->getMovie()); //Imprime la pelicula del nodo
			tmp = tmp->getNext(); //Se mueve al proximo nodo
		}
	}
	else
	{
		cout << "The List is Empty" << endl; //Si la lista esta vacia notifica que esta vacia 
	}
}
