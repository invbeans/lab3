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
		cout << "�� ������� �������� �������" << endl;
		return false; 
	}
	if (number >= this->booksAmount + 1) {
		cout << "�������� ������� ����" << endl;
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
		cout << "���������� �������� ������� � ������ ������" << endl;
		return false;
	}
	if (number >= this->booksAmount + 1) {
		cout << "� ������ ��� ������ ���������� ����" << endl;
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
		cout << "�� ������� ������� �������" << endl;
		return false;
	}
	if (this->booksAmount <= number) {
		cout << "�������� � ����� ������� ��� � ������" << endl;
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
		cout << "������ �� �������� ���������" << endl;
		return;
	}
	Unit* pointer = Head->next;
	if(number != 0) {
		for (int i = 0; i < number; i++) {
			pointer = pointer->next;
		}
	}
	cout << "����� � ���� ����:" << endl;
	cout << "��������: " << pointer->book->getName() << endl;
}

void List::printAllUnits() {
	if (isEmpty()) {
		cout << "������ �� �������� ���������" << endl;
		return;
	}
	Unit* pointer = Head->next;
	cout << "����� � ���� ������:" << endl;
	for (int i = 0; i < this->booksAmount; i++) {
		cout << "��������: " << pointer->book->getName() << endl;
		pointer = pointer->next;
	}
}

ScientificBook* List::getBookByNumber(int number) {
	if (this->booksAmount == 0) {
		cout << "������ ����" << endl;
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

