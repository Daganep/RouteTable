#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <windows.h>
#include <exception>

class BusList {
public:

	//	������ �������� ������
	struct Marsh {
		int number;			//	����� ��������
		std::string start;	//	��������� ����� ��������
		std::string final;	//	�������� ����� ��������
		Marsh();
	};

	//	������� ������
	struct List {
		Marsh data;				//	��������� ������
		List* next;				//	��������� �� ��������� �������
		List();
	};

	BusList();
	~BusList();

	Marsh getData();	//��������� ������ ����
	List* getBegin();	//��������� ������ ������� ����

	//	���������� �������� � ������
	void addNode(int number, std::string start, std::string finish);

	//	�������� �������� �� ������
	void deleteNode(int n);//, List* _begin

	//����� ��������
	bool searchNode(int _number);

	//�������� ����� ���������� ��������
	int getLastNumber();

	//����� ������ � �������
	void printList();

	//�������� ������� �� �����
	void loadFromFile(std::ifstream& file);

	//���������� ������� � ����
	void saveToFile(std::ofstream& file);

	//������� ������ �������
	bool popFront();

	//	�������� ������
	void clear();

	//���������� �������
	List* sortBySelection();

	//�������������� ��������
	void change(int _number, std::string start, std::string finish);
};