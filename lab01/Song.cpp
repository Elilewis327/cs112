/*
 * Song.cpp
 *
 *  Created on: Sep 5, 2021
 *      Author: jan
 */

#include "Song.h"

Song::Song(const std::string& title, const std::string& artist, unsigned year) {
	Title = title;
	Artist = artist;
	Year = year;
}

std::string Song::getArtist() const{
	return Artist;
}
std::string Song::getTitle() const{
	return Title;
}
unsigned Song::getYear() const{
	return Year;
}

void Song::readFrom(std::istream& in){
	getline(in, Title);
	getline(in, Artist);
	std::string yearString;
	getline(in, yearString);
	Year = atoi( yearString.c_str() );
}

void Song::writeTo(std::ostream& out) const {
   out << Title << '\n'
       << Artist << '\n'
       << Year  << '\n';
}
