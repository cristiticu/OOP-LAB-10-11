#pragma once
#include "VectorDinamic.h"
#include <algorithm>

template <typename Type>
class VectorDinamic;

template <typename Type>
class IteratorVectorDinamic {
	friend VectorDinamic<Type>;
private:
	const VectorDinamic<Type>& vector;
	size_t index;

	IteratorVectorDinamic(const VectorDinamic<Type>& _vector, size_t iteratorPosition) : vector(_vector) {
		this->index = iteratorPosition;
	};
public:
	IteratorVectorDinamic<Type>& operator=(const IteratorVectorDinamic<Type>& other) {
		if (this != &other) {
			this->index = other.index;
		}
		return *this;
	};

	Type& operator*() const {
		return this->vector.elementList[this->index];
	};

	Type& operator*() {
		return this->vector.elementList[this->index];
	};

	IteratorVectorDinamic<Type>& operator++() {
		this->index++;
		return *this;
	};

	IteratorVectorDinamic<Type>& operator--() {
		this->index--;
		return *this;
	};

	friend int operator-(const IteratorVectorDinamic<Type>& lhs, const IteratorVectorDinamic<Type>& rhs) {
		return lhs.index - rhs.index;
	};

	friend IteratorVectorDinamic<Type> operator-(IteratorVectorDinamic<Type>& lhs, const int rhs) {
		return IteratorVectorDinamic<Type>(lhs.vector, lhs.index - rhs);
	};

	friend IteratorVectorDinamic<Type> operator+(IteratorVectorDinamic<Type>& lhs, const int rhs) {
		return IteratorVectorDinamic<Type>(lhs.vector, lhs.index + rhs);
	};

	friend IteratorVectorDinamic<Type> operator+(const int lhs, const IteratorVectorDinamic<Type>& rhs) {
		return IteratorVectorDinamic<Type>(rhs.vector, rhs.index + lhs);
	};

	friend IteratorVectorDinamic<Type>& operator+=(IteratorVectorDinamic<Type>& lhs, const IteratorVectorDinamic<Type>& rhs) {
		lhs.index += rhs.index;
		return lhs;
	};

	friend IteratorVectorDinamic<Type>& operator-=(IteratorVectorDinamic<Type>& lhs, const IteratorVectorDinamic<Type>& rhs) {
		lhs.index -= rhs.index;
		return lhs;
	};

	friend bool operator==(const IteratorVectorDinamic<Type>& lhs, const IteratorVectorDinamic<Type>& rhs) {
		if (rhs.index >= lhs.vector.size())
			return lhs.index == rhs.index;
		return (*lhs) == (*rhs);
	};

	friend bool operator!=(const IteratorVectorDinamic<Type>& lhs, const IteratorVectorDinamic<Type>& rhs) {
		if (rhs.index >= lhs.vector.size())
			return lhs.index != rhs.index;
		return (*lhs) != (*rhs);
	};

	friend bool operator>=(const IteratorVectorDinamic<Type>& lhs, const IteratorVectorDinamic<Type>& rhs) {
		if (rhs.index >= lhs.vector.size())
			return lhs.index >= rhs.index;
		return (*lhs) >= (*rhs);
	};

	friend bool operator<=(const IteratorVectorDinamic<Type>& lhs, const IteratorVectorDinamic<Type>& rhs) {
		if (rhs.index >= lhs.vector.size())
			return lhs.index <= rhs.index;
		return (*lhs) <= (*rhs);
	};

	friend bool operator<(const IteratorVectorDinamic<Type>& lhs, const IteratorVectorDinamic<Type>& rhs) {
		if (rhs.index >= lhs.vector.size())
			return lhs.index < rhs.index;
		return (*lhs) < (*rhs);
	};

	using difference_type = int;
	using value_type = Type;
	using pointer = Type*;
	using reference = Type&;
	using iterator_category = std::random_access_iterator_tag;
};
