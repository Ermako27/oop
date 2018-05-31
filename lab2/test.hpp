//
// Created by Ermakov Maxim on 15.04.18.
//

#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include "Set.hpp"

int main()
{
	// тестирование конструкторов

	// 1 - конструктор по умолчанию
	Set<int> set1;
	
	// 2 - конструкторы init_list
	Set<int> set2 = {4,1,5,8,2,3};
	Set<int> set2_1{0,9,5,1,7};

	// 3 - конструктор копирования
	Set<int> set3(set2);
	
	// проверка методов

	set1.is_empty();
	std::cout << set1;

	std::cout << set2.is_contains(5);;

	set1.insert({1,2,3});
	std::cout << set1;

	set3.insert(99);
	std::cout << set3;

	set2.erase(4);
	std::cout << set2;
	
	return 0;

}
