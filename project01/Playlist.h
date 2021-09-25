/*
 * Author: Eli Lewis: etl3
 * Date: 9/5/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include <iostream>
#include <vector>
#include "Song.h"

class Playlist {
public:
	Playlist();
	Playlist(const std::string& file_name);
	unsigned getNumSongs() const;
	std::vector<Song> searchByArtist(const std::string& artist ) const;
	std::vector<Song> searchByYear(unsigned year ) const;
	std::vector<Song> searchByTitlePhrase(const std::string& phrase) const;
	void addSong(const Song& newSong);
	void removeSong(const Song& song);
	void save(std::string fileName = "New Playlist.txt");
	const std::vector<Song> getSongs() const;
	bool operator==(const Playlist &other) const;


private:
	std::vector<Song> Songs;
};

#endif /* PLAYLIST_H_ */
