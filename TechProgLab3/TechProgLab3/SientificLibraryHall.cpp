#include <iostream>
#include <string>
#include "ScientificBook.h"
#include "ScientificLibraryHall.h"
#include "Unit.h"
#include "List.h"

using namespace std;

int ScientificLibraryHall::getBooksAmount() {
	return this->bookList->booksAmount;
}

void ScientificLibraryHall::printBooksNames() {
	this->bookList->printAllUnits();
}

float ScientificLibraryHall::getOverallBooksPrice() {
	Unit* pointer = this->bookList->Head;
	float amount = 0;
	for (int i = 0; i < this->bookList->booksAmount; i++) {
		pointer = pointer->next;
		amount += pointer->book->getPrice();
	}
	return amount;
}

//ScientificBook& ScientificLibraryHall::operator[] (const int number) {
//	return * (bookList->getBookByNumber(number));
//}

//const ScientificBook& ScientificLibraryHall::operator[] (const int number) const {
//	return *bookList->getBookByNumber(number);
//}

ScientificLibraryHall& ScientificLibraryHall::operator=(const ScientificLibraryHall& hall) {
	if (this == &hall) return *this;
	this->hallName = hall.hallName;
	this->bookList = hall.bookList;
	return *this;
}

ScientificBook ScientificLibraryHall::getBookByNumber(int number) {
	return *this->bookList->getBookByNumber(number);
}

void ScientificLibraryHall::addBookByNumber(int number, ScientificBook book) {
	this->bookList->addElemByNumber(number, book);
}

void ScientificLibraryHall::changeBookByNumber(int number, ScientificBook book) {
	this->bookList->changeElemByNumber(number, book);
}

void ScientificLibraryHall::deleteBookByNumber(int number) {
	this->bookList->deleteElemByNumber(number);
}

ScientificBook ScientificLibraryHall::getBestBook() {
	float maxPrice = 0.0f;
	ScientificBook *temp = new ScientificBook();
	Unit* pointer = this->bookList->Head;
	for (int i = 0; i < this->bookList->booksAmount; i++) {
		pointer = pointer->next;
		if (pointer->book->getPrice() > maxPrice) {
			temp = pointer->book;
			maxPrice = pointer->book->getPrice();
		}
	}
	return *temp;
}

void sortRecursive(ScientificBook* mas, int size) {
	int i = 0;
	int j = size - 1;
	ScientificBook mid = mas[size / 2];
	do {
		while (mas[i].getPrice() > mid.getPrice()) {
			i++;
		}
		while (mas[j].getPrice() < mid.getPrice()) {
			j--;
		}
		if (i <= j) {
			ScientificBook temp = mas[i];
			mas[i] = mas[j];
			mas[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		sortRecursive(mas, j + 1);
	}
	if (i < size) {
		sortRecursive(mas, size - i);
	}
}

ScientificLibraryHall ScientificLibraryHall::sortHall() {
	int amount = this->bookList->booksAmount;
	ScientificBook *temp = new ScientificBook[amount];
	Unit* pointer = this->bookList->Head;
	for (int i = 0; i < this->bookList->booksAmount; i++) {
		pointer = pointer->next;
		temp[i] = *pointer->book;
	}
	sortRecursive(temp, amount);
	ScientificLibraryHall* sortedHall = new ScientificLibraryHall(this->hallName, temp, amount);
	delete[] temp;
	return *sortedHall;
}




