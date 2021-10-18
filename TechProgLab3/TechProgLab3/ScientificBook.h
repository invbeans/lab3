#pragma once
#include <iostream>
#include <string>

using namespace std;

class ScientificBook {
	std::string author;
	std::string name;
	float price;
	int year;
	float quoteIndex;

public:
	//----�����������--------------------
	//����������� �� ���������
	ScientificBook() {
		this->author = "�� ����������";
		this->name = "�� ����������";
		this->price = 0.0f;
		this->year = 0;
		this->quoteIndex = 0.0f;
	}

	//����������� �� ����� �����������
	ScientificBook(string author, string name, float price, int year, float quoteIndex) {
		this->author = author;
		this->name = name;
		this->price = price;
		this->year = year;
		this->quoteIndex = quoteIndex;
	}

	//����������� � 2 �����������: ����� � ���
	ScientificBook(string author, int year):ScientificBook() {
		
		this->author = author;
		this->year = year;
	}

	//������ ��������� � ��������� ��������
	void setAuthor(string author) {
		this->author = author;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPrice(float price) {
		this->price = price;
	}
	void setYear(int year) {
		this->year = year;
	}
	void setQuoteIndex(float quoteIndex) {
		this->quoteIndex = quoteIndex;
	}

	string getAuthor() {
		return this->author;
	}
	string getName() {
		return this->name;
	}
	float getPrice() {
		return this->price;
	}
	int getYear() {
		return this->year;
	}
	float getQuoteIndex() {
		return this->quoteIndex;
	}

	ScientificBook& operator=(const ScientificBook& oth) {
		this->author = oth.author;
		this->name = oth.name;
		this->price = oth.price;
		this->year = oth.year;
		this->quoteIndex = oth.quoteIndex;
		return *this;

	}
};
