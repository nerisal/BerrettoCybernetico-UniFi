/*
 * MyString.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_

class MyString {
public:
	MyString(int size) {
		_size = size;
		_st = new char[_size];
	}

	MyString(const MyString& sd) {
		copier(sd);
	}

	virtual ~MyString() {
		delete[] _st;
	}

	MyString& operator=(const MyString& sd) {
		if (this != &sd) {
			delete[] _st;
			copier(sd);
		}
		return *this;
	}

	void setChar(int pos, char value) {
		if (pos >= 0 && pos < _size)
			_st[pos] = value;
	}

	char getChar(int pos) {
		if (pos >= 0 && pos < _size)
			return _st[pos];
		else
			return '\0';
	}

	int getSize() {
		return _size;
	}
	;

	void copier(const MyString& sd) {
		_size = sd._size;
		_st = new char[_size];
		for (int i = 0; i < _size; i++)
			_st[i] = sd._st[i];
	}

private:
	char* _st;
	int _size;
};

#endif /* MYSTRING_H_ */
