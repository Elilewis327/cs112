/*
 * Author: Eli Lewis: etl3
 * Date: 9/5/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
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

//checks if all 4 aspects of a song are equal to each other
bool Song::operator==(const Song& song2) const{
	if (Artist != song2.getArtist()){return false;};
	if (Title != song2.getTitle()) {return false;};
	if (Year != song2.getYear()) {return false;};
	return true;
}

