/*
 * Playlist.h
 *
 *  Created on: Sep 5, 2021
 *      Author: jan
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include <iostream>
#include <vector>
#include "Song.h"

class Playlist {
public:
	Playlist(const std::string& file_name);
	unsigned getNumSongs() const;
	std::vector<Song> searchByArtist(const std::string& artist ) const;


private:
	std::vector<Song> Songs;
};

#endif /* PLAYLIST_H_ */
