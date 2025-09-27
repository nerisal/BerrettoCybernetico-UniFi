/*
 * Player.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
using namespace std;

class Player {
public:
	Player(string name) :
			_name(name) {
	}
	virtual ~Player();
	virtual void fight()=0;
	string& getName(){return _name;}
private:
	string _name;
};
#endif /* PLAYER_H_ */
