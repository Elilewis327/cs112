/*
 * Author: Eli Lewis: etl3
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
	testSearchByTitlePhrase();
	testSearchByYear();
	testAddSong();
	testEqualsTo();
	testSave();
	std::cout << "All tests passed!" << std::endl;
}

/*Tests the default construtors of Playlist
 *
 */

void PlaylistTest::testConstructors() {
	std::cout << "- constructors..." << std::flush;

	Playlist pList("testsongs.txt"); // @suppress("Ambiguous problem")

	assert( pList.getNumSongs() == 6 );
	std::cout << " 0 " << std::flush;

	std::cout << " Passed!" << std::endl;
}

/*
 * tests the search by artist function by using a known playlist and then searching for known artists in that playlist
 */

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

/*
 * tests the search by titlephrase function by using a known playlist and then searching for known titles in that playlist
 */

void PlaylistTest::testSearchByTitlePhrase(){
	std::cout << "- searchByTitlePhrase()... " << std::flush;

	Playlist pList("testsongs.txt"); // @suppress("Ambiguous problem")
	std::vector<Song> searchResult = pList.searchByTitlePhrase("G.O.A.T.");

	//case of 0 songs
	assert( searchResult.size() == 0 );
	std::cout << " 0 " << std::flush;

	// case of 1 song
	searchResult = pList.searchByTitlePhrase("Call Me Maybe");
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getArtist() == "Carly Rae Jepsen" );
	std::cout << " 1 " << std::flush;

	// case of 2 songs
	searchResult = pList.searchByTitlePhrase("repeat title");
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getArtist() == "1" );
	assert( searchResult[1].getArtist() == "2" );
	std::cout << " 2 "  << std::flush;


	std::cout << " Passed!" << std::endl;
}

/*
 * tests the search by year function by using a known playlist and then searching for known years of songs in that playlist
 */

void PlaylistTest::testSearchByYear(){
	std::cout << "- searchByYear()... " << std::flush;

	Playlist pList("testsongs.txt"); // @suppress("Ambiguous problem")
	std::vector<Song> searchResult = pList.searchByYear(2001);

	//case of 0 songs
	assert( searchResult.size() == 0 );
	std::cout << " 0 " << std::flush;

	// case of 1 song
	searchResult = pList.searchByYear(2012);
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getArtist() == "Carly Rae Jepsen" );
	std::cout << " 1 " << std::flush;

	// case of 2 songs
	searchResult = pList.searchByYear(1967);
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getArtist() == searchResult[1].getArtist() );
	std::cout << " 2 "  << std::flush;


	std::cout << " Passed!" << std::endl;
}

/*
 * tests adding a song to a playlist
 */

void PlaylistTest::testAddSong(){
	std::cout << "- addSong()... " << std::flush;

	Playlist pList("testsongs.txt"); // @suppress("Ambiguous problem")
	std::vector<Song> searchResult = pList.searchByTitlePhrase("G.O.A.T.");

	assert( searchResult.size() == 0 );

	std::cout << " 0 " << std::flush;

	Song s("G.O.A.T.", "polythia",  2018);

	pList.addSong(s);

	searchResult = pList.searchByTitlePhrase("G.O.A.T");

	assert( searchResult.size() == 1 );

	std::cout << " 1 " << std::flush;

	std::cout << " Passed!" << std::endl;

	std::cout << "- removeSong()... " << std::flush;

	pList.removeSong(s);

	searchResult = pList.searchByTitlePhrase("G.O.A.T");

	assert( searchResult.size() == 0 );

	std::cout << " 0 " << std::flush;

	std::cout << " Passed!" << std::endl;


}

/*
 * tests that every song in the two playlists are equal to each other
 */

void PlaylistTest::testEqualsTo(){
	std::cout << "- equalsTo()... " << std::flush;

	Playlist pList("testsongs.txt");
	Playlist pList2("testsongs.txt");
	assert(pList == pList2);

	std::cout << " 0 " << std::flush;

	Song s1("G.O.A.T.", "polythia",  2018);
	pList.addSong(s1);

	assert(!(pList == pList2));

	std::cout << " 1 " << std::flush;

	Song s2("G.O.A.T.", "other",  2018);
	pList2.addSong(s2);

	assert(!(pList == pList2));

	std::cout << " 2 " << std::flush;


	std::cout << " Passed!" << std::endl;

}
/*
 * tests saving a song to an exterior file.
 */

void PlaylistTest::testSave(){
	std::cout << "- save()... " << std::flush;

	Playlist pList("testsongs.txt");

	pList.save("new.txt");

	Playlist pList2("new.txt");

	assert(pList2 == pList);

	std::cout << " 0 " << std::flush;

	std::cout << " Passed!" << std::endl;
}
