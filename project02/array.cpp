/* array.cpp defines "C style" array operations
 * Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */
 
#include "array.h"

void initialize(double *a, unsigned size) {
	for (unsigned i = 0; i < size; ++i) {
		a[i] = i+1;

	}
}
 
void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; ++i) {
		cout << *a << '\t';
		a++;
	}
}		

double average(double *a, unsigned size) {

	return (sum(a, size) / size);
}

double sum(double *a, unsigned size){
	double total = 0;

	for (unsigned i = 0; i < size; i++) {
		total = *a + total; //add the value of the pointer to the total
		a++; // increment the pointer
	}

	return total;
}

void read(istream& in, double *a, unsigned size){
	for (unsigned i = 0; i < size; i++){
		in >> a[i];
	}
}

void fill(const string& fileName, double *&a, unsigned &numValues){

	ifstream fin(fileName.c_str());
	assert(fin.is_open());

	fin >> numValues;

	a = new double [numValues];

	read(fin, a, numValues);

	fin.close();

}

void resize(double *&a, unsigned oldSize, unsigned newSize){

	double * newArray = new double[newSize]();

	if (newSize > oldSize){
		for (unsigned i = 0; i < oldSize; i++){
		newArray[i] = a[i];
		}
	}

	else {
		for (unsigned i = 0; i < newSize; i++){
			newArray[i] = a[i];
		}
	}

	delete [] a;
	a = newArray;

}

void concat(double *a1, unsigned size1, double *a2, unsigned size2, double *&a3, unsigned &size3){

	delete [] a3;

	size3 = size1 + size2;
	a3 = new double [size3];

	for (unsigned i = 0; i < size1; i++){
		a3[i] = a1[i];
	}
	for (unsigned i = 0; i < size2; i++){
		a3[size1+i] = a2[i];
	}

	//deleting a1 and a2 here causes a double free runtime error : cleanup() in arr tester should already deal with the extra memory;

}

