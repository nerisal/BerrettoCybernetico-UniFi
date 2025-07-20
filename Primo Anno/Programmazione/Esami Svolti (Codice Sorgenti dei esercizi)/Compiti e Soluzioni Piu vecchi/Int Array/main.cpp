/*
 * main.cpp
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#include <iostream>
#include "IntArray.h"
using namespace std;

int main(){
	IntArray primo(13);
	cout<<"primo"<<primo.capacity()<<endl;
	IntArray cioppo = primo;
	cout<<"cioppo"<<cioppo.capacity()<<endl;
	cioppo[13];
}
