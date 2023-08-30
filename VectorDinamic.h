#pragma once
#include "IteratorVectorDinamic.h"

template <typename Type>
class IteratorVectorDinamic;

template<typename Type>
class VectorDinamic {
friend IteratorVectorDinamic<Type>;
private:
	Type* elementList;
	size_t vectorSize;
	size_t vectorCapacity;
public:
	VectorDinamic(size_t _capacity) noexcept;
	VectorDinamic() noexcept;
	size_t size() const noexcept;
	size_t capacity() const noexcept;
	void redim();
	void push_back(const Type element);
	void erase(IteratorVectorDinamic<Type>& where);
	void erase(const size_t index);
	Type& operator[](const size_t index);
	Type& operator[](const size_t index) const;

	IteratorVectorDinamic<Type> begin();
	IteratorVectorDinamic<Type> end();
};




template<typename Type>
VectorDinamic<Type>::VectorDinamic(size_t _capacity) noexcept {
	this->vectorSize = 0;
	this->vectorCapacity = _capacity;
	this->elementList = new Type[this->vectorCapacity];
}

template<typename Type>
VectorDinamic<Type>::VectorDinamic() noexcept {
	this->vectorSize = 0;
	this->vectorCapacity = 8;
	this->elementList = new Type[this->vectorCapacity];
}

template<typename Type>
size_t VectorDinamic<Type>::size() const noexcept {
	return this->vectorSize;
}

template<typename Type>
size_t VectorDinamic<Type>::capacity() const noexcept {
	return this->vectorCapacity;
}

template<typename Type>
void VectorDinamic<Type>::redim() {
	this->vectorCapacity *= 2;
	Type* newElementList = new Type[this->vectorCapacity];
	for (int i = 0; i < this->vectorSize; i++)
		newElementList[i] = this->elementList[i];
	delete[] this->elementList;
	this->elementList = newElementList;
}

template<typename Type>
void VectorDinamic<Type>::push_back(const Type element) {
	if (this->vectorSize == this->vectorCapacity)
		this->redim();
	this->elementList[this->vectorSize++] = element;
}

template<typename Type>
void VectorDinamic<Type>::erase(IteratorVectorDinamic<Type>& where) {
	while (where < this->end()) {
		*where = *(where + 1);
		++where;
	}
	this->vectorSize--;
}

template<typename Type>
void VectorDinamic<Type>::erase(const size_t index) {
	for (size_t i = index; i < this->vectorSize; i++)
		this->elementList[i] = this->elementList[i + 1];
	this->vectorSize--;
}

template<typename Type>
Type& VectorDinamic<Type>::operator[](const size_t index) {
	return this->elementList[index];
}

template<typename Type>
Type& VectorDinamic<Type>::operator[](const size_t index) const {
	return this->elementList[index];
}

template<typename Type>
IteratorVectorDinamic<Type> VectorDinamic<Type>::begin() {
	return IteratorVectorDinamic<Type>(*this, 0);
}

template<typename Type>
IteratorVectorDinamic<Type> VectorDinamic<Type>::end() {
	return IteratorVectorDinamic<Type>(*this, this->vectorSize);
}
