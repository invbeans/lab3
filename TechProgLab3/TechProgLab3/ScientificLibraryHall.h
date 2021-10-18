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

	//----������ �������� � ���������-------
	void setHallName(string hallName) {
		this->hallName = hallName;
	}
	string getHallName() {
		return this->hallName;
	}

	//----������ ������------------------
	//��������� ���������� ���� � ����
	int getBooksAmount();

	//��������� �� ����� ������ �������� ���� ���� � ����
	void printBooksNames();

	//��������� ����� ��������� ���� ���� � ����
	float getOverallBooksPrice();

	//�������������� ��������[] �� ������ � �� ������

	//���������� ����� �� ������;
	void addBookByNumber(int number, ScientificBook book);

	//��������� �����
	void changeBookByNumber(int number, ScientificBook book);

	// �������� ����� �� ������
	void deleteBookByNumber(int number);

	//������������ ����� � ����� ������� ����������
	ScientificBook getBestBook();

	//��������� ����� �� ������
	ScientificBook getBookByNumber(int number);

	//����������
	ScientificLibraryHall sortHall();

	ScientificBook& operator[] (const int number) {
		return *(bookList->getBookByNumber(number));
	}
	//const ScientificBook& operator[] (const int number) const;

	ScientificLibraryHall& operator=(const ScientificLibraryHall& hall);

};