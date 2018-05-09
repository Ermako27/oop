//
// Created by Ermakov Maxim on 15.04.18.
//

#include <iostream>
#include "Set.hpp"

int main()
{
	// тестирование конструкторов

	// 1 - конструктор по умолчанию
	std::cout << "Конструктор по умолчанию: ";
	Set<int> set1;
	std::cout << set1 << "\n\n";
	
	// 2 - конструкторы init_list
	std::cout << "Конструкторы init_list: ";
	Set<int> set2 = {4,1,1,1,5,8,2,3};
	Set<int> set2_1{0,9,5,1,7};
	std::cout << set2 << "\n\n";
	std::cout << set2_1 << "\n\n";

	// 3 - конструктор копирования
	std::cout << "Конструктор копирования: ";
	Set<int> set3(set2);
	
	// проверка методов

	std::cout << "Проверка на пустоту:";
	std::cout << "set1: " << set1 << "\n";
	std::cout << set1.is_empty() << "\n\n";

	std::cout << "Проверка на вхождение элемента:";
	std::cout << "set2: " << set2 << "\n";
	std::cout << set2.found(5) << "\n\n";



	std::cout << "Проверка добавление нескольких элементов: ";
	std::cout << "set1: " << set1 << "\n";
	set1.insert({1,2,3});
	std::cout << set1 << "\n\n";


	std::cout << "Проверка добавление одного элемента 99: ";
	std::cout << "set3: " << set3 << "\n";
	set3.insert(99);
	std::cout << set3 << "\n\n";

	std::cout << "Проверка повторного добавления одного элемента 99: ";
	std::cout << "set3: " << set3 << "\n";
	set3.insert(99);
	std::cout << set3 << "\n\n";


	std::cout << "Проверка удаления элемента: ";
	std::cout << "set3: " << set3 << "\n";
	set3.erase(99);
	std::cout << set3 << "\n\n";


	std::cout << "Проверка удаления несуществующего элемента 99: ";
	std::cout << "set3: " << set3 << "\n";
	set3.erase(99);
	std::cout << set3 << "\n\n";

	return 0;

}
