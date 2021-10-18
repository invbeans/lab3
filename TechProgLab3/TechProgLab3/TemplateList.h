#pragma once
#include <iostream>
#include <string>
#include "ScientificBook.h"
#include "Unit.h"

using namespace std;

class TemplateList {
public:
	//это заглушка, нам нужен новый юнит
	Unit* next;
	Unit* prev;
	int booksAmount;
};