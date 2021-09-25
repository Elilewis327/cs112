/*
 * Author: Eli Lewis: etl3
 * Date: 9/5/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef PLAYLISTTEST_H_
#define PLAYLISTTEST_H_

class PlaylistTest {
public:
	PlaylistTest();
	void runTests();
	void testConstructors();
	void testSearchByArtist();
	void testSearchByTitlePhrase();
	void testSearchByYear();
	void testAddSong();
	void testEqualsTo();
	void testSave();
};

#endif /* PLAYLISTTEST_H_ */
