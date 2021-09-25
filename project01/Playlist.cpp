/*
 * Author: Eli Lewis: etl3
 * Date: 9/5/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Playlist.h"
#include <fstream>
#include <vector>
#include <cassert>

/* PlayList constructor
 * @param: fileName, a string
 * Precondition: fileName contains the name of a playlist file.
 */
Playlist::Playlist(){

}

Playlist::Playlist(const std::string& fileName) {
	// open a stream to the playlist file

	std::ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	// read each song and append it to Songs
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

/* Retrieve length of the playlist
 * Return: the number of songs in the playlist.
 */
unsigned Playlist::getNumSongs() const{
	return Songs.size();
}

/* searchs the playlist by artist
* @param: an artist
* Return: a vector of song objects
*/
std::vector<Song> Playlist::searchByArtist(const std::string& artist) const{
	std::vector<Song> v;

	for (unsigned int i = 0; i < Songs.size(); i++){
		if ( Songs[i].getArtist().find(artist) != std::string::npos ) {
			v.push_back( Songs[i] );
		}
	}

	return v;
}

/* searchs the playlist by year
* @param: a year
* Return: a vector of song objects
*/
std::vector<Song> Playlist::searchByYear(unsigned year) const{
	std::vector<Song> v;

	for (unsigned int i = 0; i < Songs.size(); i++){
		if ( Songs[i].getYear() == year) {
			v.push_back( Songs[i] );
		}
	}

	return v;
}

/* searchs the playlist by a phrase
* @param: string title
* Return: void
*/
std::vector<Song> Playlist::searchByTitlePhrase(const std::string& title) const{
	std::vector<Song> v;

	for (unsigned int i = 0; i < Songs.size(); i++){
		if ( Songs[i].getTitle().find(title) != std::string::npos ) {
			v.push_back( Songs[i] );
		}
	}

	return v;
}

void Playlist::addSong(const Song& newSong){
	Songs.push_back(newSong);
}

/* Remove the first instance of a given song from the play list. If the
* song isn't in the play list, the play list is unchanged.
* @param: song, a Song
* Return: void
*/
void Playlist::removeSong(const Song &song) {
	for (unsigned i = 0; i < Songs.size(); i++) {
		if (Songs[i]==song) {
			Songs.erase(Songs.begin() + i); // @suppress("Invalid arguments")
			break;
		}
	}
}

/* save the playlist to a text file
* @param: string of the filename to save to
* Return: void
*/
void Playlist::save(std::string fileName){
	std::ofstream fout( fileName.c_str() );
	assert( fout.is_open() );

	// read each song and append it to mySongs
	std::string separator = "---";
	for (unsigned i = 0; i < Songs.size(); i++) {
		fout << Songs[i].getTitle() << "\n"
			 << Songs[i].getArtist() << "\n"
			 << Songs[i].getYear() << "\n"
			 << separator << "\n";
	}
	// close the stream
	fout.close();
}

/* returns all the songs in the given playlist in a const vector. only used in playlist == playlist operations
* @param: none
* Return: std::vector<Song>
*/
const std::vector<Song> Playlist::getSongs() const{
	return Songs;
}


/* checks if two playlists are equal to each other
* @param: another playlist
* Return: bool
*/
bool Playlist::operator==(const Playlist &other) const{
	const std::vector<Song> s = other.getSongs(); //is there a better way to do this without getting every song from the other playlist?
	if (Songs.size() != other.getNumSongs())
		return false;
	for (unsigned i = 0; i < Songs.size(); i++){
			if (Songs[i].getTitle() != s[i].getTitle())
				return false;
			if (Songs[i].getArtist() != s[i].getArtist())
				return false;
			if (Songs[i].getYear() != s[i].getYear())
				return false;

		}
	return true;
}
