//
//  Created by Maxim Ermakov 16.04.18
//

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#endif

template<typename T>
class Iterator
{
public:
	// конструкторы
	Iterator(T* it);
	Iterator(const Iterator<T>& elem);

	T& operator*();
	const T& operator*() const;
	T* operator->();
	const T& operator->() const;

	Iterator<T>& operator=(const Iterator<T>& it);
	Iterator<T>& operator=(T* it);

	Iterator<T>& operator+=(size_t n);
	Iterator<T> operator+(size_t n) const;
	Iterator<T>& operator++();
	Iterator<T> operator++(int);

	Iterator<T>& operator-=(size_t n);
	Iterator<T> operator-(size_t n) const;
	Iterator<T>& operator--();
	Iterator<T> operator--(int);

	bool operator<=(const Iterator<T>& b) const;
	bool operator>=(const Iterator<T>& b) const;
	bool operator<(const Iterator<T>& b) const;
	bool operator>(const Iterator<T>& b) const;
	bool operator==(const Iterator<T>& b) const;
	bool operator!=(const Iterator<T>& b) const;

	size_t operator-(const Iterator<T>& it);

private:
	T* ptr;
};


template<typename T>
Iterator::Iterator(T* it) : ptr(it) {};

template<typename T>
Iterator::Iterator(const Iterator<T>& elem) : Iterator(elem.ptr) {};

template<typename T>
Iterator<T>& Iterator<T>::operator*(){
	return *ptr;
}

template<typename T>
const Iterator<T>& Iterator<T>::operator*() const{
	return *ptr;
}

template<typename T>
Iterator<T>* Iterator<T>::operator->(){
	return ptr;
}

template<typename T>
const Iterator<T>* Iterator<T>::operator->(){
	return ptr;
}

template<typename T>
Iterator<T>& Iterator<T>::operator=(T *it){
	ptr = it;
	return *this;
}


template<typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& it){
	ptr = it.ptr;
	return *this;
}

template<typename T>
Iterator<T>& Iterator::operator+=(size_t n){
	ptr += n;
	return *this;
}

template<typename T>
Iterator<T> Iterator::operator+(size_t n) const {
	auto res = *this;
	res += n;
	return res;
}



// x++
template<typename T>
Iterator<T> Iterator::operator++(int) {
	auto res = *this;
	++res;
	return res;
}

// ++x
template<typename T>
Iterator<T> Iterator::operator++() {
	++ptr;
	return *this;
}


template<typename T>
Iterator<T>& Iterator::operator-=(size_t n){
	ptr -= n;
	return *this;
}

template<typename T>
Iterator<T> Iterator::operator-(size_t n) const {
	auto res = *this;
	res -= n;
	return res;
}


// x--
template<typename T>
Iterator<T> Iterator::operator--(int) {
	auto res = *this;
	--res;
	return res;
}

// --x
template<typename T>
Iterator<T> Iterator::operator--() {
	--ptr;
	return *this;
}


template<typename T>
bool Iterator<T>::operator<=(const Iterator<T>& b) const{
	return ptr <= b.ptr;
}


template<typename T>
bool Iterator<T>::operator>=(const Iterator<T>& b) const{
	return ptr >= b.ptr;
}

template<typename T>
bool Iterator<T>::operator<(const Iterator<T>& b) const{
	return ptr < b.ptr;
}

template<typename T>
bool Iterator<T>::operator>(const Iterator<T>& b) const{
	return ptr > b.ptr;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& b) const{
	return ptr == b.ptr;
}


template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& b) const{
	return ptr != b.ptr;
}


template<typename T>
size_t Iterator::operator-(const Iterator<T>& b) const{
	return ptr - b.ptr;
}
#endif



