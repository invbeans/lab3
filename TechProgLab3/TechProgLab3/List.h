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


	//������ ������ ��� ���
	bool isEmpty();

	//������������ ���������� ���������
	int getBooksAmount() {
		return this->booksAmount;
	}

	//������������ ����� �������� �� ������
	ScientificBook* getBookByNumber(int number);

	//���������� �������� �� ������
	bool addElemByNumber(int number, ScientificBook newBook);

	//��������� �������� �� ������
	bool changeElemByNumber(int number, ScientificBook changeBook);

	//�������� �������� �� ������
	bool deleteElemByNumber(int number);

	//��������
	void printUnitByNumber(int number);

	void printAllUnits();

};
