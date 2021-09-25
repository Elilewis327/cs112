/*
 * main.cpp tests the classes in our project
 *
 *  Created on: Sep 5, 2021
 *      Author: etl3
 *      Calvin University, CS112, Lab1
 *
 *      Significant Contributions by Joel Adams, for CS 112 at Calvin University.
 */

#include <iostream>
#include "SongTest.h"
#include "PlaylistTest.h"


int main() {
	SongTest sTest;
	sTest.runTests();
	PlaylistTest pt;
	pt.runTests();

	return 0;
}
