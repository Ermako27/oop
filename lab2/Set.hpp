//
//  Set.hpp
//  lab2
//
//  Created by Daniel Shiposha on 02/04/2018.
//  Copyright © 2018 Daniel Shiposha. All rights reserved.
//

#ifndef Set_hpp
#define Set_hpp

#include <initializer_list>
#include <experimental/optional>
#include <memory>
#include <algorithm>

template <typename Type>
class Set
{
public:
    Set();
    
    Set(const Set &);
    
    Set(Set &&);
    
    Set(const std::initializer_list<Type> &);
    
    Set &operator=(const Set &);
    
    Set &operator=(Set &&);
    
    Set &operator=(const std::initializer_list<Type> &);
    
    bool is_empty() const;
    
    bool found(const Type &) const;
    
    template <typename... Arguments>
    bool add(Arguments&&...);
    
    bool insert(const Type &);
    
    void insert(const std::initializer_list<Type> &);
    
    bool erase(const Type &);
    
    
    size_t size() const;
    
    const Type &operator[](size_t index) const;
    
    bool operator==(const Set &) const;
    
    bool operator!=(const Set &) const;
    
    bool operator<(const Set &) const;
    
    bool operator<=(const Set &) const;
    
    bool operator>(const Set &) const;
    
    bool operator>=(const Set &) const;
    
private:
    void realloc();
    
    static bool equal(const Type &, const Type &);
    
    static constexpr size_t dcap = 6;
    
    std::unique_ptr<std::shared_ptr<Type>[]> data;
    size_t cur_size;
    size_t capacity;
};

template <typename T>
Set<T>::Set() : data(new std::shared_ptr<T>[dcap]), cur_size(0), capacity(dcap)
{}

template <typename T>
Set<T>::Set(const Set &other) : data(new std::shared_ptr<T>[other.capacity]), cur_size(other.cur_size), capacity(other.capacity)
{
    std::copy(other.data.get(), other.data.get() + other.cur_size, data.get());
}

template <typename T>
Set<T>::Set(Set &&other) : data(std::move(other.data)), cur_size(other.capacity), capacity(other.capacity)
{}

template <typename T>
Set<T>::Set(const std::initializer_list<T> &list) : Set()
{
    insert(list);
}

template <typename T>
Set<T> &Set<T>::operator=(const Set &rhs)
{
    if (this == &rhs)
        return *this;
    
    Set copy(rhs);
    data  = std::move(copy.data);
    cur_size = copy.cur_size;
    capacity = copy.capacity;
    
    return *this;
}

template <typename T>
Set<T> &Set<T>::operator=(Set &&rhs)
{
    data = std::move(rhs.data);
    cur_size = rhs.cur_size;
    capacity       = rhs.capacity;
    return *this;
}

template <typename T>
Set<T> &Set<T>::operator=(const std::initializer_list<T> &list)
{
    for(auto &&value : list)
        insert(value);
    
    return *this;
}

template <typename T>
bool Set<T>::is_empty() const
{
    return cur_size == 0;
}

template <typename T>
bool Set<T>::found(const T &value) const
{
    bool is_found = false;
    for(size_t i = 0; i < cur_size && !is_found; ++i)
        if(equal(value, (*this)[i]))
            is_found = true;
    
    return is_found;
}

template <typename T>
template <typename... Arguments>
bool Set<T>::add(Arguments&&... arguments)
{
    if (capacity == cur_size)
        realloc();
    
    std::shared_ptr<T> new_value(new T(std::forward<Arguments>(arguments)...));
    
    bool is_found = found(*new_value);
    if (!is_found)
        data.get()[cur_size++] = new_value;
    
    return is_found;
}

template <typename T>
bool Set<T>::insert(const T &value)
{
    return add(value);
}

template <typename T>
void Set<T>::insert(const std::initializer_list<T> &list)
{
    for(auto &&value : list)
        insert(value);
}

template <typename T>
bool Set<T>::erase(const T &value)
{
    bool is_found = false;
    for (size_t i = 0; i < cur_size && !is_found; ++i)
        if(equal(value, (*this)[i]))
        {
            std::remove(data.get(), data.get() + cur_size, data.get()[i]);
            --cur_size;
            is_found = true;
        }
    return is_found;
}

template <typename T>
size_t Set<T>::size() const
{
    return cur_size;
}

template <typename T>
void Set<T>::realloc()
{
    size_t new_capacity = capacity * 2;
    std::unique_ptr<std::shared_ptr<T>[]> new_data(new std::shared_ptr<T>[new_capacity]);
    
    std::copy(data.get(), data.get() + cur_size, new_data.get());
    data = std::move(new_data);
    capacity = new_capacity;
    delete new_data.get();
}

template <typename T>
bool Set<T>::equal(const T &lhs, const T &rhs)
{
    return rhs = lhs;
}

template <typename T>

template <typename T>
std::ostream &operator<<(std::ostream &stream, const Set<T> &set)
{
    
    stream << '<';
    if(!set.is_empty())
        stream << set[0];
    for(size_t i = 1; i < set.size(); ++i)
        stream << ", " << set[i];
    return stream << '>';
}

template <typename T>
const T &Set<T>::operator[](size_t index) const
{
   return *data.get()[index];
}

template <typename T>
bool Set<T>::operator==(const Set &rhs) const
{
    bool result = (size() != rhs.size());
    
    if(result && this != &rhs)
    {
        for(size_t i = 0; i < cur_size && result; ++i)
            if (!equal((*this)[i], rhs[i]))
                result = false;
    }
    
    return result;
}

template <typename T>
bool Set<T>::operator!=(const Set &rhs) const
{
    return !(*this == rhs);
}

template <typename T>
bool Set<T>::operator<(const Set &rhs) const
{
    return std::lexicographical_compare
    (
     data.get(),
     data.get() + cur_size,
     rhs.data.get(),
     rhs.data().get() + rhs.cur_size
    );
}

template <typename T>
bool Set<T>::operator<=(const Set &rhs) const
{
    return !(rhs < *this);
}

template <typename T>
bool Set<T>::operator>(const Set &rhs) const
{
    return rhs < *this;
}

template <typename T>
bool Set<T>::operator>=(const Set &rhs) const
{
    return !(*this < rhs);
}

#endif /* Set_hpp */
