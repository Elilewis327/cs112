/* Vec.h provides a simple vector class named Vec.
 * Student Name: Eli Lewis etl3
 * Date: 9/21
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <stdexcept>
#include <fstream>
#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned int);
	Vec(const Vec& original);
	virtual ~Vec();
	Vec& operator=(const Vec& original);
	unsigned getSize() const {return mySize;};
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec &v2) const;
	void writeTo(ostream &out) const;
	void readFrom(istream &in);
	Item& operator[](int index);
	const Item& operator[](int index)const;
	Vec operator+(const Vec &rhs);
	Vec operator-(const Vec &rhs);
	bool operator!=(const Vec &rhs);
	Item operator*(const Vec &rhs);
	void writeTo(const string &out) const;
	void readFrom(const string &in);
	
private:
	unsigned mySize;
	Item *   myArray;

	void deepCopy(const Vec &original);

	friend class VecTester;
};

#endif /*VEC_H_*/
