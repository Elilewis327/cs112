/*
 * Author: Eli Lewis: etl3
 * Date: 9/5/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "SongTest.h"
#include "PlaylistTest.h"
#include "Playlist.h"
#include "Application.h"


int main() {
	SongTest st;
	st.runTests();
	PlaylistTest pt;
	pt.runTests();
	Application app;
	app.run();

	return 0;
}
