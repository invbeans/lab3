#pragma once
#include <iostream>
#include <string>
#include "ScientificBook.h"

using namespace std;

class Unit {
public:
	ScientificBook* book;
	Unit* next;

	Unit(){
		this->book = new ScientificBook();
		this->next = nullptr; 
	}

	Unit(ScientificBook book) {
		this->book = new ScientificBook(book);
		this->next = next;
	}

};