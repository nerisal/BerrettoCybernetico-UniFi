/*
 * main.cpp
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#include <iostream>
#include <vector>
#include "Player.h"
#include "Elf.h"
#include "Dwarf.h"
using namespace std;
int main() {
	vector<Player*> playerGroup;
	Elf* aElf = new Elf("Legolas");
	Dwarf* aDwarf = new Dwarf("Gimli");
	playerGroup.push_back(aElf);
	playerGroup.push_back(aDwarf);
	vector<Player *>::const_iterator itr;
	for (itr = playerGroup.begin(); itr != playerGroup.end(); itr++) {
		cout << (*itr)->getName() << endl; // FIXME: stampare il nome del personaggio
		(*itr)->fight(); // FIXME: come invoco questo fight ?
	}
	return 0;
}
