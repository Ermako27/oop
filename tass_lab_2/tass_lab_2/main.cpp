//
//  main.cpp
//  tass_lab_2
//
//  Created by Nikita on 08.04.18.
//  Copyright © 2018 RIT. All rights reserved.
//

#include <iostream>
#include "my_set.hpp"



void test_construct()
{
    Set<int> tmp1;
    tmp1.insert(1);
    Set<int> tmp2(tmp1);
    if ((tmp1 != tmp2))
        std::cout<< "test_construct Failed\n";
    
    Set<int> tmp3;
    tmp3.insert(6);
    Set<int> tmp4;
    tmp4.insert(-1);
    Set<int> tmp5;
    tmp5 = tmp1;
    
    if (!(tmp1 == tmp2))
        std::cout<< "test_comp0 Failed\n";
    
    if (!(tmp1 == tmp5))
        std::cout<< "test_comp1 Failed\n";
    
    if (!(tmp1 <= tmp1))
        std::cout<< "test_comp2 Failed\n";
    
    if (!(tmp1 >= tmp1))
        std::cout<< "test_comp3 Failed\n";
    
    if (!(tmp1 >= tmp4))
        std::cout<< "test_comp4 Failed\n";
   
    if ((tmp1 <= tmp3))
        std::cout<< "test_comp5 Failed\n" << tmp1 << tmp3;
    
    if (!(tmp1 > tmp4))
        std::cout<< "test_comp6 Failed\n";
}


void test_capacity()
{
    Set<int> tmp1;
    tmp1.insert(1);
    tmp1.insert(2);
    Set<int> tmp2;
    if (tmp1.is_empty() != false && tmp2.is_empty() != true)
        std::cout<< "test_is_empty Failed\n";
    if (tmp1.size() != 2 && tmp2.size() != 0)
        std::cout<< "test_size Failed\n";
}


void test_modifiers()
{
    Set<int> tmp1;
    tmp1.insert(1);
    tmp1.insert(2);
    auto ret_2 = tmp1.emplace(2);
    auto ret_3 = tmp1.emplace(3);
    
    if (tmp1.count(1) != true)
        std::cout<< "test_count Failed\n";
    if (ret_2 != true)
        std::cout<< "test_emplace Failed\n";
    if (ret_3 != false)
        std::cout<< "test_emplace Failed\n";
    tmp1.erase(2);
    if (tmp1.count(2) != false)
        std::cout<< "test_erase Failed\n";
    tmp1.clear();
    if (tmp1.is_empty() != true)
        std::cout<< "test_clear Failed\n";
}


void test_operations()
{
    Set<float> tmp1;
    tmp1.insert(4.4);
    tmp1.insert(1);
    tmp1.insert(2);
    tmp1.insert(3);
    tmp1.insert(2);
    size_t ind = tmp1.find(2);
    
    if (ind != 2)
        std::cout<< "test_operations Failed\n";
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout<< "Testing...\n";
    test_construct();
    test_capacity();
    test_modifiers();
    test_operations();
    return 0;
}

