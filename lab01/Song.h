/*
 * Song.h
 *
 *  Created on: Sep 5, 2021
 *      Author: jan
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

private:
	std::string Title;
	std::string Artist;
	unsigned Year;
};

#endif /* SONG_H_ */
