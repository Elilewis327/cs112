/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Eli Lewis etl3
 * Date: 9/21
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include "Vec.h"

Vec::Vec() {
	mySize = 0;
	myArray = nullptr;
}

Vec::Vec(unsigned int size) {
	mySize = size;
	if (size){
		myArray = new Item[size]();
	}else{
	myArray = nullptr;
	}
}

void Vec::deepCopy(const Vec &original) {

	mySize = original.mySize;
	if (mySize) {

		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}else {
		myArray = nullptr;
	}
}

Vec::Vec(const Vec& original) {
	deepCopy(original);
}

Vec::~Vec() {
	delete [] myArray;
	mySize = 0;
	myArray = nullptr;
}

Vec& Vec::operator=(const Vec& original) {
	if (original.myArray == myArray)
		return *this;

	delete []myArray;
	deepCopy(original);

    return *this;
}

void Vec::setItem(unsigned index, const Item& it) {
	if (index >= mySize)
		throw range_error("Index Out of Range");
	myArray[index] = it;
}

Item Vec::getItem(unsigned index) const {
	if (index >= mySize)
		throw range_error("Index Out of Range");
	return myArray[index];
}

void Vec::setSize(unsigned newSize) {
	if (newSize == mySize)
		return;

	if (newSize == 0){
		mySize = newSize;
		delete []myArray;
		myArray = nullptr;
		return;
	}

	Item *myTmpArray = new Item[newSize]();
	if (myArray != nullptr){
		for (unsigned i = 0; i < newSize; i++) {
			if (i >= mySize)
				break;
			myTmpArray[i] = myArray[i];
		}
		delete []myArray;
	}
	mySize = newSize;
	myArray = myTmpArray;
}

bool Vec::operator==(const Vec& v2) const {
	if (mySize != v2.getSize())
		return false;
	for (unsigned i = 0; i < mySize; i++){
		if (myArray[i] != v2.getItem(i))
			return false;
	}

	return true;
}

void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++)
			out << myArray[i] <<  endl;
}

void Vec::readFrom(istream& in) {
	unsigned i = 0;
	while(in){
		in >> myArray[i];
		i++;
	}

}
