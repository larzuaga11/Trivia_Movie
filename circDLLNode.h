#pragma once
/**********************
	Circular Doubly linked node
	This class implements the circular doubly linked node using templates
	Each nodes three attributes:
		-info: stores the actual value
		-next: a pointer to the next node in the list
		-prev: a pointer to the previous node in the list
******************/
#include <iostream>
#include "DLLNode.h"
#include "DLList.h"
using namespace std;

/**********************
	Class Declaration
***********************/
template <class T>
class circDLLNode {
public:
	circDLLNode(); // Default constructor
	circDLLNode(circDLLNode<T>*, string, DLList<T>, circDLLNode<T>*); // Special constructor
	string getGenre(); // Get information 
	circDLLNode<T>* getNext(); // Get next
	circDLLNode<T>* getPrev(); // Get previous
	DLList<T>* getDLL(); //Get Double Linked List
	void setGenre(string); // setInfo 
	void setNext(circDLLNode<T>*); // Set next
	void setPrev(circDLLNode<T>*); // Set previous
	void setDLL(DLList<T>*); //Set dll
private:
	circDLLNode<T>* prev; // Points to the previous node in the list
	string genre; // Actual data	
	circDLLNode<T>* next; // Points to the next node in the list
	DLList<T> dll;	
};

/*****
	Default constructor
	Creates a empty node
*****/
template <class T>
circDLLNode<T>::circDLLNode()
{
	next = prev = 0;
}

/******
	Special constructor:
	Creates a node with value i in the info attribute and next pointing to null
	@params:
		*p: pointer to the previous node
		i: actual value to be stored
		*n: pointer to the next node
*******/
template <class T>
circDLLNode<T>::circDLLNode(circDLLNode<T>* p, string g, DLList<T> d, circDLLNode<T>* n)
{
	genre = g;
	prev = p;
	next = n;
	dll = d;
}

/********
	getInfo
	returns the info value
*********/
template <class T>
string circDLLNode<T>::getGenre()
{
	return genre;
}

/********
	getNext
	returns a point to next node the list	
**********/
template <class T>
circDLLNode<T>* circDLLNode<T>::getNext()
{
	return next;
}

/********
	getPrev
	returns a point to prev node the list
**********/
template <class T>
circDLLNode<T>* circDLLNode<T>::getPrev()
{
	return prev;
}

/********
	setInfo
	Set i as the node info
*******/
template <class T>
void circDLLNode<T>::setGenre(string g)
{
	genre = g;
}

/********
	setNext
	Points next attribute to the next list node
********/
template <class T>
void circDLLNode<T>::setNext(circDLLNode<T>* n)
{
	next = n;
}

/********
	setPrev
	Points next attribute to the prev list node
********/
template <class T>
void circDLLNode<T>::setPrev(circDLLNode<T>* p)
{
	prev = p;
}

//Obtiene la Lista Doble Enlazada 
template<class T>
DLList<T>* circDLLNode<T> :: getDLL() {

	return &dll;

}

//Apunta a la lista 
template<class T>
void circDLLNode<T> ::setDLL(DLList<T>* d) {

	dll = d;
}

