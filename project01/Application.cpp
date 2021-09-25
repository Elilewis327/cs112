/*
 * Application.cpp
 *
 *  Created on: Feb 14, 2020
 *      Author: vtn2
 */

#include "Application.h"

#include <iostream>
#include <vector>
#include "Song.h"
#include "Playlist.h"
using namespace std;



Application::Application() {
	string fname;
	cout << "Welcome to the PlayList Manager" << endl << endl;
	cout << "Please enter a file containing a play list: " << flush;
	getline(cin, fname);
	myPlayList = Playlist(fname);
}

/*
 * Run the application.
 */
void Application::run() {
	while (true) {
		displayMenu();
		char choice = getChoice();
		// cout << "got choice " << choice << endl;
		if (choice == 'q') {
			break;
		}
		processChoice(choice);
	}
}

void Application::displayMenu() const {
	cout << "Please enter:" << endl;
	cout << "a - to add a new song to the playlist" << endl;
	cout << "r - to remove a song from the playlist" << endl;
	cout << "s - to save the playlist" << endl;
	cout << "A - to search the playlist for songs by a given artist" << endl;
	cout << "Y - to search the playlist for songs in a given year" << endl;
	cout << "P - to search the playlist for songs with a given phrase in the title" << endl;
	cout << "q - to quit" << endl;
}

char Application::getChoice() const {
	cout << endl << "Please enter your choice: " << flush;
	char choice;
	cin >> choice;
	cin.get();
	return choice;
}

Song Application::getSong() {
	string artist;
	string title;
	unsigned year;
	string yearStr;

	cout << "  Enter artist: ";
	getline(cin, artist);
	cout << "  Enter title: ";
	getline(cin, title);
	cout << "  Enter year: ";
	cin >> year;
	cin.get();
	return Song(title, artist, year);
}

/*Processes the choice of the user with a case statement;
 *
 */

void Application::processChoice(char choice) {
	switch(choice) {

	case 'a': {
		unsigned year;
		string title, artist;
		cout << "Add an song to the playlist..." << endl;

		cout << "Enter title: ";
		cin >> title;

		cout << "Enter artist: ";
		cin >> artist;

		cout << "Enter year: ";
		cin >> year;
		cin.get();
		Song s(title, artist, year);
		myPlayList.addSong(s);

		break;
	}

	case 's': {
		string fileName;
		cout << "Please enter a file name for your playlist: ";
		cin >> fileName;
		myPlayList.save(fileName);
		break;
	}

	case 'r': {


		cout << "Remove a song from the playlist..." << endl;
		//this kinda sucks: it should search for a song based on title phrase or author and then let you choose one;
		//i had this implemented but this is probably what you actually want;
		displaySongs(myPlayList.getSongs());
		Song s = getSong();

		myPlayList.removeSong(s);


		break;
	}
	case 'Y': {
		cout << "Searching playlist by year..." << endl;
		unsigned year;
		cout << "Enter year: ";
		cin >> year;
		cin.get();

		vector<Song> songs = myPlayList.searchByYear(year);

		displaySongs(songs);
		break;
	}
	case 'P': {
		cout << "Searching playlist by title phrase..." << endl;
		string phrase;
		cout << "Enter phrase: ";
		cin >> phrase;
		vector<Song> songs = myPlayList.searchByTitlePhrase(phrase);

		displaySongs(songs);
		break;
	}
	case 'A': {
		cout << "Searching playlist by artist..." << endl;
		string artist;
		cout << "Enter artist: ";
		cin >> artist;
		vector<Song> songs = myPlayList.searchByArtist(artist);

		displaySongs(songs);
		break;
	}

	//this fixes some chars causing infintite loops of the prompt printing
	default : {
		break;
	}

	}
}
//loops over songs and prints them all to output
void Application::displaySongs(vector<Song> songs) const {
	for (unsigned i = 0; i < songs.size(); i++){
		songs[i].writeTo(std::cout);
	}

}

