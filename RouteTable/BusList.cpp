///�������� ������. ������ z8432k, ������ �.�.
///������� �10
///���������� ������� � ����������. ������ � �������� �������� � ��������� � ������ MARSH, ���������� ��������� ����:
/// - �������� ���������� ������ ��������;
/// - �������� ��������� ������ ��������;
/// - ����� ��������.
///������� �� ����� : ����� ��������, ������� ���������� ��� ������������ � ������, �������� �������� ������� � ����������.

#include "BusList.h"
#include <vector>
#include <sstream>

BusList::List* begin;		//	��������� �� ������ ������
BusList::Marsh newData;		//	��������� ��� ���������� ������ ��������
bool newNumb;				//	��������� ������� �������� � ������
const int stringSize = 20;	//	������������ ����� �����

//����������� ���� (��� split � java)
std::vector<std::string> split(const std::string& s, const char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

//���������� ������
BusList::BusList() {
	BusList::List* begin = nullptr;		//	��������� �� ������ ������
	BusList::Marsh newData;				//	��������� ��� ���������� ������ ��������
	bool newNumb = true;				//	��������� ������� �������� � ������
}

//���������� ������
BusList::~BusList() {
	clear();
}

//����������� ��������� ������
BusList::Marsh::Marsh() {
	int number = 0;			//	����� ��������
	std::string start = "";	//	��������� ����� ��������
	std::string final = "";	//	�������� ����� ��������
}

//����������� ����
BusList::List::List() {
	Marsh data;				//	��������� ������
	List* next = nullptr;	//	��������� �� ��������� �������
}

//���������� �������� � ������
void BusList::addNode(int number, std::string start, std::string finish) {
	BusList::List* newNode = new List();	//	��������� ����� ������� ��� �������
	BusList::List* tempNode = begin;		//	��������� ��������� ��������������� �������

	newNode->data.number = number;			//	����������� ������ �������� �������� ������
	newNode->data.start = start;
	newNode->data.final = finish;
	newNode->next = nullptr;

	//	���� ������ ����
	if (begin == nullptr) {
		begin = newNode;
	}
	//	���� �� ����, ������� � ����� ������
	else {
		while (tempNode->next) {		//	������� ������� �������
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;		//	� ���� next �������� �������� ���������� ����� ������ ��������
	}
}

//�������� ������ ������ ������
BusList::Marsh BusList::getData() {
	return begin->data;
};

//�������� ����� ���������� ��������
int BusList::getLastNumber() {
	BusList::List* tempNode1 = begin;
	int result = 0;
	//	���� ������ ����
	if (!tempNode1) {
		return NULL;
	}
	else {
		while (tempNode1->next != nullptr) {
			tempNode1 = tempNode1->next;
		}
		result = tempNode1->data.number;
	}
	return result;
}

//�������� ��������� �� ������ ������
BusList::List* BusList::getBegin() {
	return begin;
};

//�������� �������� �� ������
void BusList::deleteNode(int n) {//, BusList::List* _begin

	int delNum = 0;
	BusList::List* tempNode1 = new List();
	BusList::List* tempNode2 = begin;
	tempNode1->next = tempNode2;

	//	���� ������ ����
	if (!begin) {
		return;
	}
	else {
		if (begin->data.number == n) {
			begin = begin->next;
			return;
		}
		while (tempNode2->data.number != n) {
			tempNode1 = tempNode2;
			tempNode2 = tempNode2->next;
		}
		tempNode1->next = tempNode2->next;
		delete tempNode2;
	}
};

//����� ��������
bool BusList::searchNode(int _number) {
	bool result = true;
	BusList::List* tempNode1 = begin;

	//	���� ������ ����
	if (!tempNode1) {
		result = false;
	}
	else {
		while (tempNode1->data.number != _number) {
			if (!tempNode1->next) {
				result = false;
				break;
			}
			tempNode1 = tempNode1->next;
		}
	}
	return result;
}

//����� ������ � �������
void BusList::printList() {
	BusList::List* tempNode = begin;

	if (begin == nullptr) {
		std::cout << "������ ����\n";
	}
	else {
		while (tempNode) {
			std::cout << "������� �" << tempNode->data.number
				<< "\t��������� �����: " << tempNode->data.start
				<< "\t�������� �����: " << tempNode->data.final << std::endl;
			tempNode = tempNode->next;
		}
	}
}

//�������� ������� �� �����
void BusList::loadFromFile(std::ifstream& file) {
	clear();
	int number = 0;
	while (!file.eof()) {
		std::string line;
		std::string lineCut = "";
		getline(file, line, '\n');
		if (line.length() != 0) {
			std::vector<std::string> data = split(line, ';');
			number = atoi((data[0]).c_str());
			for (int i(1); i < 3; i++) {
				if (data[i].length() > stringSize) {	//	�������� ����� ������
					lineCut = data[i];
					for (int j(0); j < stringSize; j++) {
						data[i][j] = lineCut[j];
					}
					data[i][stringSize] = '\0';
				}
			}
			if (number < 1 || number > 999 || searchNode(number)) continue;	//	�������� ������ ��������
			addNode(number, data[1], data[2]);
		}
	}
}

//���������� ������� � ����
void BusList::saveToFile(std::ofstream& file) {
	BusList::List* tempNode = begin;
	while (tempNode) {
		std::string line;
		line = std::to_string(tempNode->data.number) + ';' + tempNode->data.start + ';' + tempNode->data.final + '\n';
		file << line;
		tempNode = tempNode->next;
	}
}

//�������� ������� ��������
bool BusList::popFront() {
	//	���� ������ �� ����
	if (begin) {
		if (!begin->next) {	//	���� � ������ ���� �������
			delete begin;
			begin = nullptr;
		}
		else {
			BusList::List* temp = begin;
			begin = begin->next;
			delete temp;
		}
		return true;
	}
	else return false;
}

//�������� ������
void BusList::clear() {
	bool keka = true;
	while (keka) {
		keka = popFront();
	}
}

//���������� �������
BusList::List* BusList::sortBySelection() {
	BusList::List* pHead = begin;

	BusList::List* a = nullptr,
		* b = nullptr,
		* p = nullptr,
		* pHeaderNode = nullptr;

	for (BusList::List* pCurrentNode = pHead; pCurrentNode != nullptr; )
	{
		a = pCurrentNode;
		pCurrentNode = pCurrentNode->next;
		b = pHeaderNode;

		for (p = nullptr; (b != nullptr) && (b->data.number < a->data.number);)
		{
			p = b;
			b = b->next;
		}

		if (p == nullptr)
		{
			a->next = pHeaderNode;
			pHeaderNode = a;
		}
		else
		{
			a->next = b;
			p->next = a;
		}
	}

	if (pHeaderNode != nullptr)
	{
		return pHeaderNode;
		//BusList::List* m_pHead = pHeaderNode;
	}
	else
	{
		return nullptr;
	}
}

//�������������� ��������
void BusList::change(int _number, std::string start, std::string finish) {
	BusList::List* tempNode1 = begin;

	while (tempNode1->data.number != _number) {
		tempNode1 = tempNode1->next;
	}
	tempNode1->data.start = start;
	tempNode1->data.final = finish;
}