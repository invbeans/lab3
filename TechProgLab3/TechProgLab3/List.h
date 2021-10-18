#pragma once
#include <iostream>
#include <string>
#include "ScientificBook.h"
#include "Unit.h"

using namespace std;


class List {
public:
	Unit* Head;
	int booksAmount;

	List() {
		this->Head = new Unit();
		this->booksAmount = 0;
		this->Head->next = Head;
	}

	List(ScientificBook *bookList, int amount) {
		List();
		for (int i = 0; i < amount; i++) {
			this->addElemByNumber(i, *(bookList + i));
		}
	}

	~List() {
		for (int i = this->getBooksAmount() - 1; i >= 0; i--) {
			this->deleteElemByNumber(i);
		}
		Head = NULL;
		delete[] Head;
	}


	//пустой список или нет
	bool isEmpty();

	//возвращающий количество элементов
	int getBooksAmount() {
		return this->booksAmount;
	}

	//возвращающий адрес элемента по номеру
	ScientificBook* getBookByNumber(int number);

	//добавление элемента по номеру
	bool addElemByNumber(int number, ScientificBook newBook);

	//изменение элемента по номеру
	bool changeElemByNumber(int number, ScientificBook changeBook);

	//удаление элемента по номеру
	bool deleteElemByNumber(int number);

	//проверка
	void printUnitByNumber(int number);

	void printAllUnits();

};
