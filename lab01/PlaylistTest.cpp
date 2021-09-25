/* PlayListTester.cpp defines the PlayList test-methods.
 *Eli Lewis: etl3
 * Date: 9/5/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "PlaylistTest.h"
#include "Playlist.h"
#include <cassert>
#include <iostream>

PlaylistTest::PlaylistTest() {}

void PlaylistTest::runTests(){
	std::cout << "\nTesting class PlayList..." << std::endl;
	testConstructors();
	testSearchByArtist();
	std::cout << "All tests passed!" << std::endl;
}

void PlaylistTest::testConstructors() {
	std::cout << "- constructors..." << std::flush;

	Playlist pList("testsongs.txt"); // @suppress("Ambiguous problem")

	assert( pList.getNumSongs() == 4 );
	std::cout << " 0 " << std::flush;

	std::cout << " Passed!" << std::endl;
}

void PlaylistTest::testSearchByArtist(){
	std::cout << "- searchByArtist()... " << std::flush;

	Playlist pList("testsongs.txt"); // @suppress("Ambiguous problem")
	std::vector<Song> searchResult = pList.searchByArtist("Cream");

	//case of 0 artists
	assert( searchResult.size() == 0 );
	std::cout << " 0 " << std::flush;

	// case of 1 artist
	searchResult = pList.searchByArtist("Baez");
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	std::cout << " 1 " << std::flush;

	// case of 2 artists
	searchResult = pList.searchByArtist("Beatles");
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	assert( searchResult[1].getTitle() == "Penny Lane" );
	std::cout << " 2 "  << std::flush;


	std::cout << " Passed!" << std::endl;
}
