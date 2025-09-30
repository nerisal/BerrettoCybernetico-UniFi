/*
 * IntArray.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef INTARRAY_H_
#define INTARRAY_H_

class IntArray {
public:
	IntArray(unsigned int size = 10) :
			_capacity(size) {
		if (size == 0)
			size = 1;
		_buffer = new int[1];

	}
	IntArray(const IntArray& ra) {
		copyInto(ra);
	}
	~IntArray() {
		delete[] _buffer;
	}

	int& operator[](unsigned i) {
		if (i >= _capacity) {
			this->resize(2 * _capacity);
		}
		return _buffer[i];
	}
	IntArray& operator=(const IntArray& ra) {
		if (this != &ra) {
			delete[] _buffer;
			copyInto(ra);
		}
		return *this;
	}
	unsigned size() const {
		return _used;
	}
	unsigned capacity() const {
		return _capacity;
	}
private:
	int* _buffer;
	unsigned _capacity;
	unsigned _used;

	void copyInto(const IntArray& b) {
		_capacity = b._capacity;
		_used = b._used;
		_buffer = new int[_capacity];
		for (int i = 0; i < _capacity; i++)
			_buffer[i] = b._buffer[i];
	}

	void resize(unsigned int s) {
		IntArray tmp(s);
		tmp._used = _used;
		for (int i = 0; i < _capacity; i++)
			tmp._buffer[i] = _buffer[i];
		*this = tmp;
	}
};

#endif /* INTARRAY_H_ */
