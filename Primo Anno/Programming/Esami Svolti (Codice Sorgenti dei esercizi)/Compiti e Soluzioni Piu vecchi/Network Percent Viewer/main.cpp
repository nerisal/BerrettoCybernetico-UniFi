/*
 * main.cpp
 *
 *  Created on: 06/lug/2015
 *      Author: tommasoscarlatti
 */

#include "NetworkOperation.h"
#include "NetworkOperationPercentViewer.h"
#include "NetworkOperationViewer.h"

// PROGRAMMA DI PROVA

int main() {
	NetworkOperation * no = new NetworkOperation(15);
	NetworkOperationViewer * nw = new NetworkOperationViewer(no);
	NetworkOperationPercentViewer * npw = new NetworkOperationPercentViewer(no);

	nw->display();
	npw->display();

	no->updateOperations(3);
	nw->display();
	npw->display();

	no->updateOperations(10);
	nw->display();
	npw->display();

	no->updateOperations(15);
	nw->display();
	npw->display();
}

