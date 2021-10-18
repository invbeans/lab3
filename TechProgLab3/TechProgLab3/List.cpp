#pragma once
#include <iostream>
#include <string>
#include "ScientificBook.h"
#include "Unit.h"
#include "List.h"

using namespace std;

bool List::isEmpty() {
	Unit* pointer = Head->next;
	if (pointer != Head) return false;
	else return true;

}

bool List::addElemByNumber(int number, ScientificBook newBook) {
	Unit* newUnit = new Unit(newBook);
	if (isEmpty() && this->booksAmount != 0) { 
		cout << "Не удалось добавить элемент" << endl;
		return false; 
	}
	if (number >= this->booksAmount + 1) {
		cout << "Пропущен элемент цепи" << endl;
		return false;
	}
	Unit* pointer = Head->next;
	this->booksAmount++;

	int amount = number;
	bool replace = this->booksAmount - 1 >= number;
	if (replace) amount -= 1;
	for (int i = 0; i < amount; i++) {
		if (pointer->next != Head) {
			pointer = pointer->next;
		}
	}
	
	Unit* temp;
	if (number == 0 && !replace) {
		temp = Head;
	}
	else if (number == 0 && replace) {
		temp = Head->next;
		pointer = Head;
	}
	else temp = pointer->next;
	newUnit->next = temp;
	pointer->next = newUnit;
	
	return true;
}

bool List::changeElemByNumber(int number, ScientificBook changeBook) {
	Unit* newUnit = new Unit(changeBook);
	if (isEmpty()) {
		cout << "Невозможно заменить элемент в пустом списке" << endl;
		return false;
	}
	if (number >= this->booksAmount + 1) {
		cout << "В списке нет такого количества книг" << endl;
		return false;
	}
	Unit* pointer = Head->next;

	for (int i = 0; i < number - 1; i++) {
		if (pointer->next != Head) {
			pointer = pointer->next;
		}
	}

	Unit* temp;
	temp = pointer->next;
	newUnit->next = temp;
	if (number == 0) Head->next = newUnit;
	else pointer->next = newUnit;

	return true;
}

bool List::deleteElemByNumber(int number) {
	if (isEmpty()) {
		cout << "Не удалось удалить элемент" << endl;
		return false;
	}
	if (this->booksAmount <= number) {
		cout << "Элемента с таким номером нет в списке" << endl;
		return false;
	}
	Unit* pointer = Head;

	for (int i = 0; i < number; i++) {
		if (pointer->next != Head) {
			pointer = pointer->next;
		}
	}
	Unit* temp = pointer->next->next;
	delete[] pointer->next;
	pointer->next = temp;
	this->booksAmount--;
	
	return true;
}

void List::printUnitByNumber(int number) {
	if (isEmpty()) {
		cout << "Список не содержит элементов" << endl;
		return;
	}
	Unit* pointer = Head->next;
	if(number != 0) {
		for (int i = 0; i < number; i++) {
			pointer = pointer->next;
		}
	}
	cout << "Книга в этом узле:" << endl;
	cout << "Название: " << pointer->book->getName() << endl;
}

void List::printAllUnits() {
	if (isEmpty()) {
		cout << "Список не содержит элементов" << endl;
		return;
	}
	Unit* pointer = Head->next;
	cout << "Книги в этом списке:" << endl;
	for (int i = 0; i < this->booksAmount; i++) {
		cout << "Название: " << pointer->book->getName() << endl;
		pointer = pointer->next;
	}
}

ScientificBook* List::getBookByNumber(int number) {
	if (this->booksAmount == 0) {
		cout << "Список пуст" << endl;
		return nullptr;
	}
	Unit* pointer = Head->next;
	for (int i = 0; i < number; i++) {
		if (pointer->next != Head) {
			pointer = pointer->next;
		}
	}
	return pointer->book;
}

