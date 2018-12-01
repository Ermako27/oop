//
//  my_set.hpp
//  tass_lab_2
//
//  Created by Nikita on 08.04.18.
//  Copyright © 2018 RIT. All rights reserved.
//
// clear
// shared.delete
// exception
//

#ifndef my_set_hpp
#define my_set_hpp


#include <initializer_list>
#include <experimental/optional>
#include <memory>
#include <algorithm>

template <typename T>
class Set{
public:
    /// Constructors
    Set();
    Set(const Set &);
    Set(Set &&);
    Set(const std::initializer_list<T> &);
    
    
    // Iterators
    
    
    // Capacity
    bool is_empty() const;
    size_t size() const;
    size_t max_size() const;
    
    
    // Modifiers
    bool insert(const T &);
    void insert(const std::initializer_list<T> &);
    bool erase(const T &);
    template <typename... Arguments>
    bool emplace(Arguments&&...);
    
    void clear();
    
    
    // Operations
    bool count(const T &) const;
    size_t find(const T &) const;
    
    
    // Operators
    const T &operator[](size_t index) const;
    bool operator==(const Set &) const;
    bool operator!=(const Set &) const;
    bool operator<(const Set &) const;
    bool operator<=(const Set &) const;
    bool operator>(const Set &) const;
    bool operator>=(const Set &) const;
    Set &operator=(const Set &);
    Set &operator=(Set &&);
    Set &operator=(const std::initializer_list<T> &);
    
    
    
private:
    // Allocator
    void realloc();
    
    static bool is_values_equal(const T &, const T &);
    
    static constexpr size_t DEFAULT_CAPACITY = 4;
    
    std::unique_ptr<std::shared_ptr<T>[]> data;
    size_t container_size;
    size_t capacity;
    const size_t max_set_size = INT16_MAX;
};


// Constructors
template <typename T>
Set<T>::Set()
: data(new std::shared_ptr<T>[DEFAULT_CAPACITY]),
container_size(0),
capacity(DEFAULT_CAPACITY)
{}


template <typename T>
Set<T>::Set(const Set &other)
: data(new std::shared_ptr<T>[other.capacity]),
container_size(other.container_size),
capacity(other.capacity)
{
    std::copy(other.data.get(), other.data.get() + other.container_size, data.get());
}


template <typename T>
Set<T>::Set(Set &&other)
: data(std::move(other.data)), container_size(other.capacity), capacity(other.capacity)
{}


template <typename T>
Set<T>::Set(const std::initializer_list<T> &list)
: Set()
{
    insert(list);
}


// Capacity
template <typename T>
bool Set<T>::is_empty() const
{
    return container_size == 0;
}


template <typename T>
size_t Set<T>::size() const
{
    return container_size;
}


template <typename T>
size_t Set<T>::max_size() const
{
    return max_set_size;
}


// Modifiers
template <typename T>
bool Set<T>::insert(const T &element)
{
    return emplace(element);
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
    for (size_t i = 0; i < container_size && !is_found; ++i)
        if(is_values_equal(value, (*this)[i]))
        {
            std::remove(data.get(), data.get() + container_size, data.get()[i]);
            --container_size;
            is_found = true;
        }
    
    return is_found;
}


template <typename T>
template <typename... Arguments>
bool Set<T>::emplace(Arguments&&... arguments)
{
    if (capacity == container_size)
        realloc();
    
    std::shared_ptr<T> new_value(new T(std::forward<Arguments>(arguments)...));
    
    bool is_found = count(*new_value);
    if (!is_found)
        data.get()[container_size++] = new_value;
    
    return is_found;
}


template <typename T>
void Set<T>::clear()
{
    std::unique_ptr<std::shared_ptr<T>[]> new_data(new std::shared_ptr<T>[capacity]);
    data = std::move(new_data);
    container_size = 0;
    delete new_data.get();
}


// Observers


// Operations
template <typename T>
bool Set<T>::count(const T &value) const
{
    std::shared_ptr<T> stored;
    bool is_found = false;
    for(size_t i = 0; i < container_size && !is_found; ++i)
        if(is_values_equal(value, (*this)[i]))
            is_found = true;
    
    return is_found;
}


template <typename T>
size_t Set<T>::find(const T &value) const
{
    std::shared_ptr<T> stored;
    for(size_t i = 0; i < container_size; ++i)
        if(is_values_equal(value, (*this)[i]))
            return i;
    
    throw std::range_error("Set index is out of range");
}


// Operators
template <typename T>
const T &Set<T>::operator[](size_t index) const
{
    if ((index >= container_size) || (index < 0))
        throw std::range_error("Set index is out of range");
    
    return *data.get()[index];
}


template <typename T>
bool Set<T>::operator==(const Set &rhs) const
{
    bool result = (size() == rhs.size());
    
    if(result && this != &rhs)
    {
        for(size_t i = 0; i < container_size && result; ++i)
            if (!is_values_equal((*this)[i], rhs[i]))
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
     data.get() + container_size,
     rhs.data.get(),
     rhs.data.get() + rhs.container_size
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


template <typename T>
Set<T> &Set<T>::operator=(const Set &rhs)
{
    if (this == &rhs)
        return *this;
    
    Set copy(rhs);
    data           = std::move(copy.data);
    container_size = copy.container_size;
    capacity       = copy.capacity;
    
    return *this;
}


template <typename T>
Set<T> &Set<T>::operator=(Set &&rhs)
{
    data           = std::move(rhs.data);
    container_size = rhs.container_size;
    capacity       = rhs.capacity;
    return *this;
}


template <typename T>
Set<T> &Set<T>::operator=(const std::initializer_list<T> &list)
{
    clear();
    for(auto &&value : list)
        insert(value);
    
    return *this;
}


// Private
template <typename T>
void Set<T>::realloc()
{
    size_t new_capacity = capacity * 2;
    std::unique_ptr<std::shared_ptr<T>[]> new_data(new std::shared_ptr<T>[new_capacity]);
    
    std::copy(data.get(), data.get() + container_size, new_data.get());
    data = std::move(new_data);
    capacity = new_capacity;
    delete new_data.get();
}


template <typename T>
bool Set<T>::is_values_equal(const T &lhs, const T &rhs)
{
    return rhs == lhs;
}


template <typename T>
std::ostream &operator<<(std::ostream &stream, const Set<T> &set)
{
    
    stream << '{';
    if(!set.is_empty())
        stream << set[0];
    for(size_t i = 1; i < set.size(); ++i)
        stream << ", " << set[i];
    return stream << '}';
}

#endif /* my_set_hpp */
