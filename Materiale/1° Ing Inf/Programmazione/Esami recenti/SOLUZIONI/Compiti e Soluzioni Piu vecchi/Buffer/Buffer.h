/*
 * Buffer.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef BUFFER_H_
#define BUFFER_H_

class Buffer {
public:
	Buffer(int size) {
		_size = size;
		_buffer = new char[_size];
	}


	virtual ~Buffer() {
		delete[] _buffer;
	}

	void setCharAt(int pos, char value) {
		if (pos >= 0 && pos < _size)
			_buffer[pos] = value;
	}

	char getCharAt(int pos) {
		if (pos >= 0 && pos < _size)
			return _buffer[pos];
		else
			return '\0';
	}

	int getSize() {
		return _size;
	}

	Buffer(const Buffer& c){
			this->_size=c._size;
			_buffer=new char*[_size];
			for (int i=0;i<_size;i++)
				_buffer[i]=c._buffer[i];
		}

private:
	char* _buffer;
	int _size;
};
#endif /* BUFFER_H_ */
