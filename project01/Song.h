/*
 * Author: Eli Lewis: etl3
 * Date: 9/5/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */
#ifndef SONG_H_
#define SONG_H_

#include <iostream>
#include <fstream>

class Song {
public:
	Song(const std::string& title = "", const std::string& artist = "", unsigned year = 0);
	std::string getTitle() const ;
	std::string getArtist() const;
	unsigned getYear() const;
	void readFrom(std::istream&);
	void writeTo(std::ostream& out) const;
	bool operator==(const Song& song2) const;

private:
	std::string Title;
	std::string Artist;
	unsigned Year;
};

#endif /* SONG_H_ */
