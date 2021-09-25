/*
 * Author: Eli Lewis: etl3
 * Date: 9/5/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "SongTest.h"
#include "Song.h"
#include <iostream>
#include <fstream>
#include <cassert>


SongTest::SongTest() {
	// TODO Auto-generated constructor stub

}

void SongTest::runTests(){

	std::cout << "Testing class Song..." << std::endl;
	testConstructors();
	testReadFrom();
	testWriteTo();
	testEqualsTo();
	std::cout << "All tests passed!" << std::endl;
}

void SongTest::testConstructors(){
	std::cout << "- constructors... " << std::flush;

	Song s;
	assert(s.getTitle() == "");
	assert(s.getArtist() == "");
	assert(s.getYear() == 0);
	std::cout << " 0 " << std::flush;

	Song s1("G.O.A.T.", "Polythia", 2018); // @suppress("Ambiguous problem")
	assert(s1.getTitle() == "G.O.A.T.");
	assert(s1.getArtist() == "Polythia");
	assert(s1.getYear() == 2018);
	std::cout << " 1 " << std::flush;

	std::cout << "Passed!" << std::endl;

}

/*
 * tests the read from function by making sure some predetirmined songs are equal to what is read
 */

void SongTest::testReadFrom(){
	std::cout << "- readFrom()... " << std::flush;

	std::ifstream inFile("testsongs.txt");
	assert(inFile.is_open());
	std::string separator;

	Song s;

	// read first song and separator in test playlist
	s.readFrom(inFile);
	std::getline(inFile, separator);
	assert( s.getTitle() == "Call Me Maybe" );
	assert( s.getArtist() == "Carly Rae Jepsen" );
	assert( s.getYear() == 2012 );
	std::cout << 0 << std::flush;

	// read second song and separator in test playlist
	s.readFrom(inFile);
	std::getline(inFile, separator);
	assert( s.getTitle() == "Let It Be" );
	assert( s.getArtist() == "The Beatles" );
	assert( s.getYear() == 1967 );
	std::cout << " 1 " << std::flush;

	// read third song and separator in test playlist
	s.readFrom(inFile);
	std::getline(inFile, separator);
	assert( s.getTitle() == "Let It Be" );
	assert( s.getArtist() == "Joan Baez" );
	assert( s.getYear() == 1971 );
	std::cout << " 2 " << std::flush;

	s.readFrom(inFile);
	std::getline(inFile, separator);
	assert( s.getTitle() == "Penny Lane" );
	assert( s.getArtist() == "The Beatles" );
	assert( s.getYear() == 1967 );
	std::cout << " 3 " << std::flush;

	inFile.close();
	std::cout << "Passed!" << std::endl;

}

/*
 * tests writing a song to a playlist
 */

void SongTest::testWriteTo() {
	std::cout << "- writeTo()... " << std::flush;


	// declare three songs
	Song s1("Badge", "Cream", 1969); // @suppress("Ambiguous problem")
	Song s2("Godzilla", "Blue Oyster Cult", 1977); // @suppress("Ambiguous problem")
	Song s3("Behind Blue Eyes", "The Who", 1971); // @suppress("Ambiguous problem")

	// write the three songs to an output file
	std::ofstream fout("testSongOutput.txt");
	assert( fout.is_open() );
	s1.writeTo(fout);
	fout << "---\n";
	s2.writeTo(fout);
	fout << "---\n";
	s3.writeTo(fout);
	fout << "---\n";
	fout.close();

	// use readFrom() to see if writeTo() worked
	std::ifstream fin("testSongOutput.txt");
	assert( fin.is_open() );
	Song s4, s5, s6;
	std::string separator;

	// read and check the first song
	s4.readFrom(fin);
	getline(fin, separator);
	assert( s4.getTitle() == "Badge" );
	assert( s4.getArtist() == "Cream" );
	assert( s4.getYear() == 1969 );
	std::cout << " 0 " << std::flush;

	// read and check the second song
	s5.readFrom(fin);
	getline(fin, separator);
	assert( s5.getTitle() == "Godzilla" );
	assert( s5.getArtist() == "Blue Oyster Cult" );
	assert( s5.getYear() == 1977 );
	std::cout << " 1 " << std::flush;

	// read and check the third song
	s6.readFrom(fin);
	getline(fin, separator);
	assert( s6.getTitle() == "Behind Blue Eyes" );
	assert( s6.getArtist() == "The Who" );
	assert( s6.getYear() == 1971 );
	std::cout << " 2 " << std::flush;

	fin.close();
	std::cout << " Passed!" << std::endl;

}

/*
 * tests that the equals function works
 */

void SongTest::testEqualsTo(){
	std::cout << "- eqaulsTo()... " << std::flush;

	Song s1("Badge", "Cream", 1969); // @suppress("Ambiguous problem")
	Song s2("Badge", "Blue Oyster Cult", 1969); // @suppress("Ambiguous problem")
	Song s3("Behind Blue Eyes", "Cream", 1969); // @suppress("Ambiguous problem")
	Song s4("Badge", "Cream", 1999); // @suppress("Ambiguous problem")
	Song s5("Badge", "Cream", 1969); // @suppress("Ambiguous problem")


	assert(!(s1 == s2)); //differs only in artist
	std::cout << " " << 0 << " " << std::flush;
	assert(!(s1 == s3)); //differs only in title
	std::cout << 1 << " " << std::flush;
	assert(!(s1 == s4)); //differs only in year
	std::cout << 2 << " " << std::flush;
	assert(s1 == s5); //the same
	std::cout << 3 << " " << std::flush;

	std::cout << " Passed!" << std::endl;

}

