/* Application.h declares the application class for our PlayList class.
 *
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Playlist.h"
#include <vector>


class Application {
public:
	Application();
	void run();

private:
	void displayMenu() const;
	char getChoice() const;
	void processChoice(char choice);
	Song getSong();
	void displaySongs(std::vector<Song> songs) const;

	Playlist myPlayList;
};

#endif /* APPLICATION_H_ */

