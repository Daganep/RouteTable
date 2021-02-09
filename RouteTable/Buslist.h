#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <windows.h>
#include <exception>

class BusList {
public:

	//	Данные элемента списка
	struct Marsh {
		int number;			//	Номер маршрута
		std::string start;	//	Начальный пункт маршрута
		std::string final;	//	Конечный пункт маршрута
		Marsh();
	};

	//	Элемент списка
	struct List {
		Marsh data;				//	Структура данных
		List* next;				//	Указатель на следующий элемент
		List();
	};

	BusList();
	~BusList();

	Marsh getData();	//получение данных узла
	List* getBegin();	//получение адреса первого узла

	//	Добваление элемента в список
	void addNode(int number, std::string start, std::string finish);

	//	Удаление элемента из списка
	void deleteNode(int n);//, List* _begin

	//поиск элемента
	bool searchNode(int _number);

	//получить номер последнего элемента
	int getLastNumber();

	//вывод списка в консоль
	void printList();

	//загрузка таблицы из файла
	void loadFromFile(std::ifstream& file);

	//сохранение таблицы в файл
	void saveToFile(std::ofstream& file);

	//удалить первый элемент
	bool popFront();

	//	очистить список
	void clear();

	//сортировка выбором
	List* sortBySelection();

	//редактирование элемента
	void change(int _number, std::string start, std::string finish);
};