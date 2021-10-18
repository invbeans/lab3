#pragma once
#include <iostream>
#include <string>
#include "ScientificBook.h"
#include "Unit.h"
#include "List.h"

using namespace std;

class ScientificLibraryHall {
	List* bookList;
	string hallName;


public:
	ScientificLibraryHall() {
		this->bookList = new List();
	}

	ScientificLibraryHall(string hallName, int booksAmount) {
		ScientificBook *book = new ScientificBook();
		this->bookList = new List();
		for (int i = 0; i < booksAmount; i++) {
			this->bookList->addElemByNumber(i, *book);
		}
		this->hallName = hallName;
	}
	ScientificLibraryHall(string hallName, ScientificBook *otherList, int booksAmount) { 
		this->hallName = hallName;
		this->bookList = new List();
		for (int i = 0; i < booksAmount; i++) {
			this->bookList->addElemByNumber(i, *(otherList + i));
		}
	}
	ScientificLibraryHall(const ScientificLibraryHall& other) {
		this->hallName = other.hallName;
		this->bookList = new List();
		for (int i = 0; i < other.bookList->booksAmount; i++) {
			ScientificBook temp = *other.bookList->getBookByNumber(i);
			this->bookList->addElemByNumber(i, temp);
		}
	}

	//----методы устнавки и получения-------
	void setHallName(string hallName) {
		this->hallName = hallName;
	}
	string getHallName() {
		return this->hallName;
	}

	//----другие методы------------------
	//получения количества книг в зале
	int getBooksAmount();

	//выводящий на экран список названий всех книг в зале
	void printBooksNames();

	//получения общей стоимости всех книг в зале
	float getOverallBooksPrice();

	//переопределите оператор[] на чтение и на запись

	//добавления книги по номеру;
	void addBookByNumber(int number, ScientificBook book);

	//изменение книги
	void changeBookByNumber(int number, ScientificBook book);

	// удаления книги по номеру
	void deleteBookByNumber(int number);

	//возвращающий книгу с самой высокой стоимостью
	ScientificBook getBestBook();

	//получение книги по номеру
	ScientificBook getBookByNumber(int number);

	//сортировка
	ScientificLibraryHall sortHall();

	ScientificBook& operator[] (const int number) {
		return *(bookList->getBookByNumber(number));
	}
	//const ScientificBook& operator[] (const int number) const;

	ScientificLibraryHall& operator=(const ScientificLibraryHall& hall);

};