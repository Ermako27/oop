#ifndef MSET_hpp
#define MSET_hpp
#include <initializer_list>
#include <experimental/optional>
#include <memory>
#include <algorithm>


template <typename T>
class Set
{
public:
	Set();

	Set(const Set &);
    
    Set(Set&&);
    
    Set(const std::initializer_list<T> &);
    
    Set &operator=(const Set<T> &);
    
    Set &operator=(Set<T> &&);
    
    Set &operator=(const std::initializer_list<T> &);

    bool is_empty() const;
    
    bool is_contains(const T &) const;
    
    template <typename... Arguments>
    bool emplace(Arguments&&...);
    
    bool insert(const T &);
    
    void insert(const std::initializer_list<T> &);
    
    bool erase(const T&);
    
    void clear();
    
    size_t size() const;
    
    const Type &operator[](size_t index) const;
    
    bool operator==(const Set<T> &) const;
    
    bool operator!=(const Set<T> &) const;
    
    bool operator<(const Set<T> &) const;
    
    bool operator<=(const Set<T> &) const;
    
    bool operator>(const Set<T> &) const;
    
    bool operator>=(const Set<T> &) const;

private:
	T* data
	bool is_equal(const T&, const T&);
	size_t capacity;
};

template <typename T>
Set<T>::Set() : capacity(0) {}

template <typename T>
Set<T>::Set(const Set &other) : capacity(other.capacity){

    std::copy(other.begin(), other.end(), begin());
}

template <typename T>
Set<T>::Set(Set &&other) :  capacity(other.capacity){
	*this = other;
}

template <typename T>
Set<T>::Set(const std::initializer_list<T> &list) : Set(){
    insert(list);
}

template <typename T>
Set<T> &Set<T>::operator=(const Set<T> &other)
{
    if (this == &other)
        return *this;
    
    Set copy(other);
    data = std::move(copy.data);
    capacity = copy.capacity;
    
    return *this;
}


template <typename T>
Set<T> &Set<T>::operator=(const std::initializer_list<T> &list){
	resize(list.capacity);
	std::copy(b.begin(), b.end(), begin());
}

template <typename T>
Set<T> &Set<T>::operator=(Set<T> &&other)
{
    data = std::move(other.data);
    capacity = other.capacity;
    return *this;
}

template <typename T>
bool Set<T>::is_empty() const{
    return capacity == 0;
}


template <typename T>
bool Set<T>::is_contains(const T &value) const
{
    std::shared_ptr<T> stored;
    bool is_found = false;
    for(size_t i = 0; i < container_size && !is_found; ++i)
        if(is_equal(value, (*this)[i]))
            is_found = true;
    
    return is_found;
}


template <typename T>
bool Set<T>::is_equal(const T &lhs, const T &rhs)
{
    // Using only operator<
    return !(rhs < lhs) && !(lhs < rhs);
}


