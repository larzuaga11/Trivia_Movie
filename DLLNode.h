#pragma once
#include <iostream>
#include "Movie.h"
using namespace std;

/**********************
	Class Declaration
***********************/
template <class T>
class DLLNode {
public:
	DLLNode(); // Default constructor
	DLLNode(DLLNode<T>*, Movie, DLLNode<T>*); // Special constructor 
	DLLNode<T>* getNext(); // Get next
	DLLNode<T>* getPrev(); // Get previous	
	Movie getMovie();
	void setNext(DLLNode<T>*); // Set next
	void setPrev(DLLNode<T>*); // Set previous
	void setMovie(const Movie&);	

private:
	DLLNode<T>* prev; // Points to the previous node in the list	
	DLLNode<T>* next; // Points to the next node in the list
	Movie movie;
};

/*****
	Default constructor
	Creates a empty node
*****/
template <class T>
DLLNode<T>::DLLNode()
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
DLLNode<T>::DLLNode(DLLNode<T>* p, Movie m, DLLNode<T>* n)
{
	prev = p;
	next = n;
	movie = m;
	
}

/********
	getNext
	returns a point to next node the list
**********/
template <class T>
DLLNode<T>* DLLNode<T>::getNext()
{
	return next;
}

/********
	getPrev
	returns a point to prev node the list
**********/
template <class T>
DLLNode<T>* DLLNode<T>::getPrev()
{
	return prev;
}

template<class T>
Movie DLLNode<T> ::getMovie() {

	return movie;
}

/********
	setNext
	Points next attribute to the next list node
********/
template <class T>
void DLLNode<T>::setNext(DLLNode<T>* n)
{
	next = n;
}

/********
	setPrev
	Points next attribute to the prev list node
********/
template <class T>
void DLLNode<T>::setPrev(DLLNode<T>* p)
{
	prev = p;
}


template<class T>
void DLLNode<T> ::setMovie(const Movie& m) {

	movie = m;

}
