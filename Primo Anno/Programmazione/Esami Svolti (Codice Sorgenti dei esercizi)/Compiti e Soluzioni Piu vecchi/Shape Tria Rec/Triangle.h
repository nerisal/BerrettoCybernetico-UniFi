/*
 * Triangle.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

class Triangle: public Shape {
public:
	Triangle();
	virtual ~Triangle();
	virtual void draw(){
		//implementare qui draw per triangle
	}


};

#endif /* TRIANGLE_H_ */
