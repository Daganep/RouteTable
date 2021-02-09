///Курсовой проект. Группа z8432k, Пенкин О.А.
///Вариант №10
///Предметная область – «Маршруты». Данные о маршруте хранятся в структуре с именем MARSH, содержащей следующие поля:
/// - название начального пункта маршрута;
/// - название конечного пункта маршрута;
/// - номер маршрута.
///Задание на поиск : найти маршруты, которые начинаются или оканчиваются в пункте, название которого введено с клавиатуры.

#include "BusList.h"
#include <vector>
#include <sstream>

BusList::List* begin;		//	Указатель на начало списка
BusList::Marsh newData;		//	Структура для добавления нового элемента
bool newNumb;				//	Индикатор наличия маршрута в списке
const int stringSize = 20;	//	Максимальная длина строк

//разделитель слов (как split в java)
std::vector<std::string> split(const std::string& s, const char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

//контруктор списка
BusList::BusList() {
	BusList::List* begin = nullptr;		//	Указатель на начало списка
	BusList::Marsh newData;				//	Структура для добавления нового элемента
	bool newNumb = true;				//	Индикатор наличия маршрута в списке
}

//деструктор списка
BusList::~BusList() {
	clear();
}

//конструктор структуры данных
BusList::Marsh::Marsh() {
	int number = 0;			//	номер маршрута
	std::string start = "";	//	начальный пункт маршрута
	std::string final = "";	//	конечный пункт маршрута
}

//конструктор узла
BusList::List::List() {
	Marsh data;				//	Структура данных
	List* next = nullptr;	//	Указатель на следующий элемент
}

//добваление элемента в список
void BusList::addNode(int number, std::string start, std::string finish) {
	BusList::List* newNode = new List();	//	Объявляем новый элемент для вставки
	BusList::List* tempNode = begin;		//	Объявляем временный вспомогательный элемент

	newNode->data.number = number;			//	Присваеваем новому элементу введённые данные
	newNode->data.start = start;
	newNode->data.final = finish;
	newNode->next = nullptr;

	//	Если список пуст
	if (begin == nullptr) {
		begin = newNode;
	}
	//	Если не пуст, вставка в конец списка
	else {
		while (tempNode->next) {		//	Находим крайний элемент
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;		//	В поле next карйнего элемента записываем адрес нового элемента
	}
}

//получить данные начала списка
BusList::Marsh BusList::getData() {
	return begin->data;
};

//получить номер последнего элемента
int BusList::getLastNumber() {
	BusList::List* tempNode1 = begin;
	int result = 0;
	//	Если список пуст
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

//получить указатель на начало списка
BusList::List* BusList::getBegin() {
	return begin;
};

//удаление элемента из списка
void BusList::deleteNode(int n) {//, BusList::List* _begin

	int delNum = 0;
	BusList::List* tempNode1 = new List();
	BusList::List* tempNode2 = begin;
	tempNode1->next = tempNode2;

	//	Если список пуст
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

//поиск элемента
bool BusList::searchNode(int _number) {
	bool result = true;
	BusList::List* tempNode1 = begin;

	//	Если список пуст
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

//вывод списка в консоль
void BusList::printList() {
	BusList::List* tempNode = begin;

	if (begin == nullptr) {
		std::cout << "Список пуст\n";
	}
	else {
		while (tempNode) {
			std::cout << "Маршрут №" << tempNode->data.number
				<< "\tНачальный пункт: " << tempNode->data.start
				<< "\tКонечный пункт: " << tempNode->data.final << std::endl;
			tempNode = tempNode->next;
		}
	}
}

//загрузка таблицы из файла
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
				if (data[i].length() > stringSize) {	//	Проверка длины строки
					lineCut = data[i];
					for (int j(0); j < stringSize; j++) {
						data[i][j] = lineCut[j];
					}
					data[i][stringSize] = '\0';
				}
			}
			if (number < 1 || number > 999 || searchNode(number)) continue;	//	Проверка номера маршрута
			addNode(number, data[1], data[2]);
		}
	}
}

//сохранение таблицы в файл
void BusList::saveToFile(std::ofstream& file) {
	BusList::List* tempNode = begin;
	while (tempNode) {
		std::string line;
		line = std::to_string(tempNode->data.number) + ';' + tempNode->data.start + ';' + tempNode->data.final + '\n';
		file << line;
		tempNode = tempNode->next;
	}
}

//удаление первого элемента
bool BusList::popFront() {
	//	Если список не пуст
	if (begin) {
		if (!begin->next) {	//	Если в списке один элемент
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

//очистить список
void BusList::clear() {
	bool keka = true;
	while (keka) {
		keka = popFront();
	}
}

//сортировка выбором
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

//редактирование элемента
void BusList::change(int _number, std::string start, std::string finish) {
	BusList::List* tempNode1 = begin;

	while (tempNode1->data.number != _number) {
		tempNode1 = tempNode1->next;
	}
	tempNode1->data.start = start;
	tempNode1->data.final = finish;
}