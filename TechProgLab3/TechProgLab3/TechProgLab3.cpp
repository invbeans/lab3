#include <iostream>
#include "ScientificBook.h"
#include "List.h"
#include "Unit.h"
#include "ScientificLibraryHall.h"
#include <string>

using namespace std;

int main()
{
    system("chcp 1251>null");
    cout << "Создан зал, книги в нем:" << endl;
    ScientificBook book0("Дауни Аллен Б.", "Основы Python. Научитесь мыслить как программист", 991.0f, 2021, 9.9f);
    ScientificBook book1("Молинаро Энтони, Грааф Роберт де", "SQL. Сборник рецептов. Решения и методики построения запросов для разработчиков баз данных", 1029.0f, 2020, 8.7f);
    ScientificBook book2("Сьерра Кэтти, Бейтс Берт", "Изучаем Java", 1232.0f, 2012, 7.75f);
    ScientificBook book3("Бэнкс Алекс, Порселло Ева", "React. Современные шаблоны для разработки приложений", 1537.0f, 2021, 10.0f);
    ScientificBook bookList[4] = { book0, book1, book2, book3 };
    ScientificLibraryHall* libraryHall = new ScientificLibraryHall("Программирование", bookList, 4);   
    libraryHall->printBooksNames();

    cout << endl << "изменение книги" << endl;
    ScientificBook book4("Бхаргава Адитья", "Грокаем алгоритмы. Иллюстрированное пособие для программистов и любопытствующих", 820.0f, 2019, 10.0f);
    libraryHall->changeBookByNumber(0, book4);
    libraryHall->printBooksNames();

    cout << endl << "удаление книги" << endl;
    libraryHall->deleteBookByNumber(2);
    libraryHall->printBooksNames();

    cout << endl << "вывод автора лучшей книги" << endl;
    cout << "Автор лучшей книги: " << libraryHall->getBestBook().getAuthor() << endl;

    cout << endl << "Вывод списка книг по убыванию цены" << endl;
    libraryHall = &libraryHall->sortHall();
    libraryHall->printBooksNames();

    book0 = libraryHall[0];


}