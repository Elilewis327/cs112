/*
 * Playlist.cpp
 *
 *  Created on: Sep 5, 2021
 *      Author: jan
 */

#include "Playlist.h"
#include <fstream>
#include <cassert>

Playlist::Playlist(const std::string& fileName) {
	// open a stream to the playlist file
	std::ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	// read each song and append it to mySongs
	Song s;
	std::string separator;
	while (true) {
		s.readFrom(fin);
		if ( !fin ) { break; }
		getline(fin, separator);
		Songs.push_back(s);
	}

	// close the stream
	fin.close();
}

unsigned Playlist::getNumSongs() const{
	return Songs.size();
}

std::vector<Song> Playlist::searchByArtist(const std::string& artist) const{
		std::vector<Song> v;

		for (unsigned int i = 0; i < Songs.size(); i++){
			if ( Songs[i].getArtist().find(artist) != std::string::npos ) {
			         v.push_back( Songs[i] );
			      }
		}

		return v;
}
