
/*
 Vec.h provides a simple Vector class named Vec.
 * Student Names: Eli Lewis, Jay Carlson
 * Date: 09/28/21
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef Vec_H_
#define Vec_H_

#include <iostream>
using namespace std;

template <class Item>
class Vec {
public:
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	const Item& operator[](unsigned index) const;
	Item& operator[](unsigned index);
	Vec<Item> operator+(const Vec<Item>& rhs) const;
	Vec<Item> operator-(const Vec<Item>& rhs) const;
	Item operator*(const Vec<Item>& rhs) const;
	bool operator==(const Vec<Item>& v2) const;
	bool operator!=(const Vec<Item>& rhs) const;
	Vec<Item>& operator=(const Vec<Item>& original);

	Vec();
	Vec(unsigned size);
	Vec(const Vec<Item>& original);
	virtual ~Vec();

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

template <class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

template <class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (index > mySize - 1 || mySize == 0) {
		throw range_error("setItem(): Index is too large or Vec<Item> is empty");
	} else {
		myArray[index] = it;
	}
}

template <class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if (mySize != 0 && index < mySize) return myArray[index];
	else throw range_error("getItem(): Index out of bounds, or Vec<Item> is empty");
}

template <class Item>
void Vec<Item>::setSize(unsigned newSize) {
	if (newSize == 0) {
		// Just reset to defaults
		delete[] myArray;
		mySize = 0;
		myArray = nullptr;
	} else {
		Item * tempArray = new Item[newSize];
		// Assign all values that will fit from old array, or all that are present
		for (unsigned i = 0; i < newSize && i < mySize; ++i) {
			tempArray[i] = myArray[i];
		}
		// Pad the new one with zeroes if necessary
		for (unsigned i = mySize; i < newSize; ++i) {
			tempArray[i] = 0;
		}
		// Prevent leakage
		delete[] myArray;

		mySize = newSize;
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; ++i){
			myArray[i] = tempArray[i];
		}

		// Prevent leakage again
		delete[] tempArray;
	}
}

template <class Item>
// Write full Vec<Item>tor to an ostream
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; ++i) {
		out << myArray[i] << "\n";
	}
}

template <class Item>
// Read a whole Vec<Item>tor from an istream
void Vec<Item>::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; ++i) {
		in >> myArray[i];
	}
}

template <class Item>
// Subscript for assignment
Item& Vec<Item>::operator[](unsigned index) {
	if (index >= mySize) throw range_error("Subscript: Index out of range");
	else return myArray[index];
}

template <class Item>
// Subscript for read-only
const Item& Vec<Item>::operator[](unsigned index) const {
	if (index >= mySize) throw range_error("Subscript: Index out of range");
	else return myArray[index];
}

template <class Item>
// Add the values at each position in the two Vec<Item>tors, if there are the same number of values.
Vec<Item> Vec<Item>::operator+(const Vec<Item>& rhs) const {
	if(mySize != rhs.mySize) throw invalid_argument("+ operator: Vec<Item>s of different sizes");
	Vec<Item> blank;
	if(mySize == 0) return blank;
	Vec<Item> v(mySize);
	for (unsigned i = 0; i < mySize; ++i) {
		v[i] = myArray[i] + rhs.getItem(i);
	}
	return v;
}

template <class Item>
// Same but with subtraction
Vec<Item> Vec<Item>::operator-(const Vec<Item>& rhs) const {
	if(mySize != rhs.mySize) throw invalid_argument("+ operator: Vec<Item>s of different sizes");
	Vec<Item> blank;
	if(mySize == 0) return blank;
	Vec<Item> v(mySize);
	for (unsigned i = 0; i < mySize; ++i) {
		v[i] = myArray[i] - rhs.getItem(i);
	}
	return v;
}

template <class Item>
Item Vec<Item>::operator*(const Vec<Item>& rhs) const {
	if(mySize != rhs.mySize) throw invalid_argument("+ operator: Vec<Item>s of different sizes");
	Item result = 0;
	for (unsigned i = 0; i < mySize; ++i) {
		result += myArray[i] * rhs.getItem(i);
	}
	return result;
}

template <class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
	if(mySize != v2.mySize) return false;
	for (unsigned i = 0; i < mySize; ++i){
		if(myArray[i] != v2.myArray[i]) return false;
	}
	return true;
}

template <class Item>
bool Vec<Item>::operator!=(const Vec<Item>& rhs) const {
	return (!(*this==rhs));
}

template <class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	// Prevent leakage
	mySize = original.mySize;

	// Check that they are not the same (no self-assignment)
	if (myArray != original.myArray) {
		// If array has values
		if (mySize > 0) {
			// Prevent leakage
			delete[] myArray;

			myArray = new Item[mySize];
			// Put the items in the old array into the new one
			for (unsigned i = 0; i < mySize; ++i){
				myArray[i] = original.myArray[i];
			}
		} else {
			// Prevent leakage
			delete[] myArray;
			myArray = nullptr;
		}
	}
	return *this;
}

template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = nullptr;
}

template <class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	//If array has values
	if (size > 0) {
		myArray = new Item[size];
		// Assign 0 to all the indexes
		for (unsigned i = 0; i < size; ++i){
			myArray[i] = 0.0;
		}
	} else {
		myArray = nullptr;
	}
}

template<class Item>
Vec<Item>::Vec(const Vec<Item>& original){
	mySize = original.mySize;
	// If array has values
	if (mySize > 0){
		myArray = new Item[mySize];
		// Assign old array's values to the new one
		for (unsigned i = 0; i < mySize; ++i){
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

template<class Item>
Vec<Item>::~Vec() {
	// Deallocate and then set variables to default values
	delete[] myArray;
	mySize = 0;
	myArray = nullptr;
}



#endif /*Vec_H_*/

