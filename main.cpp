/* Abigail Higham, Section 2, abigail.higham.21@gmail.com
 Lab 9 -- Playlist
 
 */

/* TEST CASES
 
 Test Case 1:
 
 Input:
 
 options
 beef
 quit
 
 Output:
 
 Welcome to the Firstline Player!  Enter options to see menu options.
 
 Enter your selection now:
 
 add      Adds a list of songs to the library
 list     Lists all the songs in the library
 addp     Adds a new playlist
 addsp    Adds a song to a playlist
 listp    Lists all the playlists
 play     Plays a playlist
 delp     Deletes a playlist
 delsp    Deletes a song from a playlist
 delsl    Deletes a song from the library (and all playlists)
 options  Prints this options menu
 quit     Quits the program
 
 Enter your selection now:
 
 add      Adds a list of songs to the library
 list     Lists all the songs in the library
 addp     Adds a new playlist
 addsp    Adds a song to a playlist
 listp    Lists all the playlists
 play     Plays a playlist
 delp     Deletes a playlist
 delsp    Deletes a song from a playlist
 delsl    Deletes a song from the library (and all playlists)
 options  Prints this options menu
 quit     Quits the program
 
 Enter your selection now:
 Goodbye!
 
 CORRECT!
 
 Test Case 2:
 
 Input:
 
 add
 Penny Lane
 In Penny Lane there is a barber showing photographs
 Hello, Goodbye
 You say yes, I say no
 Let It Be
 When I find myself in times of trouble
 Wild World
 Now that I've lost everything to you
 Summer Breeze
 See the curtains hangin' in the window
 STOP
 list
 quit
 
 Output:
 
 Welcome to the Firstline Player!  Enter options to see menu options.
 
 Enter your selection now:
 Read in Song names and first lines (type "STOP" when done):
 Song Name:
 Song's first line:
 Song Name:
 Song's first line:
 Song Name:
 Song's first line:
 Song Name:
 Song's first line:
 Song Name:
 Song's first line:
 Song Name:
 
 Enter your selection now:
 Penny Lane: "In Penny Lane there is a barber showing photographs", 0 play(s).
 Hello, Goodbye: "You say yes, I say no", 0 play(s).
 Let It Be: "When I find myself in times of trouble", 0 play(s).
 Wild World: "Now that I've lost everything to you", 0 play(s).
 Summer Breeze: "See the curtains hangin' in the window", 0 play(s).
 
 Enter your selection now:
 Goodbye!
 
 CORRECT!
 
 Test Case 3:
 
 Input:
 
 addp
 Biking Music
 addp
 142 calm down collection
 listp
 quit
 
 Output:
 
 Welcome to the Firstline Player!  Enter options to see menu options.
 
 Enter your selection now:
 Playlist name:
 
 Enter your selection now:
 Playlist name:
 
 Enter your selection now:
 0: Biking Music
 1: 142 calm down collection
 
 Enter your selection now:
 Goodbye!
 
 CORRECT!
 
 
 */

#include "iostream"
#include "vector"

#include "Playlist.h"
#include "Song.h"

using namespace std;

void printOptions()
{
    cout << "\nadd\tAdds a list of songs to the library\n"
            "list\tLists all the songs in the library\n"
            "addp\tAdds a new playlist\n"
            "addsp\tAdds a song to a playlist\n"
            "listp\tLists all the playlists\n"
            "play\tPlays a playlist\n"
            "delp\tDeletes a playlist\n"
            "delsp\tDeletes a song from a playlist\n"
            "delsl\tDeletes a song from the library (and all playlists)\n"
            "options\tPrints this options menu\n"
            "quit\tQuits the program\n";
}

void addSongs(vector<Song*> &library)
{
    cout << "Read in Song names and first lines (type \"STOP\" when done):\n";

    while( true )
    {
        string title;
        string firstLine;
        cout << "Song Name: ";
        getline(cin, title);

        if(title == "STOP")
        {
            break;
        }

        cout << "Song's first line: ";
        getline(cin, firstLine);

        library.push_back(new Song(title, firstLine));
    }
}

void displaySongs(const vector<Song*> &library)
{
    for(auto song : library)
    {
        song->display(cout);
    }
}

void displaySongsIndex(const vector<Song*> &library)
{
    int index = 0;
    for(auto song : library)
    {
        cout << "\t" << index++ << ": " << song->getTitle() << "\n";
    }
}

void addPlaylist(vector<Playlist*> &playlists)
{
    string name;

    cout << "Playlist name: ";
    getline(cin, name);

    playlists.push_back(new Playlist(name));
}

void displayPlaylistsIndex(const vector<Playlist*> &playlists)
{
    int counter = 0;
    for(auto playlist : playlists)
    {
        cout << "\t" << counter++ << ": " << playlist->getTitle() << "\n";
    }
}

void addSongToPlaylist(vector<Playlist*> &playlists, const vector<Song*> &library)
{
    string buffer; 

    displayPlaylistsIndex(playlists);
    cout << "Pick a playlist index number: ";
    getline(cin, buffer);

    int playlistIndex = stoi(buffer);
    Playlist *playlist = *(playlists.begin() + playlistIndex);

    displaySongsIndex(library);
    cout << "Pick a song index number: ";
    getline(cin, buffer);

    int songIndex = stoi(buffer);
    Song *song = *(library.begin() + songIndex);

    playlist->addSong(song);
}

void playPlaylist(const vector<Playlist*> playlists)
{
    string buffer; 

    displayPlaylistsIndex(playlists);
    cout << "Pick a playlist index number: ";
    getline(cin, buffer);

    int playlistIndex = stoi(buffer);
    Playlist* playlist = *(playlists.begin() + playlistIndex);

    playlist->play(cout);
}

void deletePlaylist(vector<Playlist*> &playlists)
{
    string buffer;

    displayPlaylistsIndex(playlists);
    cout << "Pick a playlist index number to delete: ";
    getline(cin, buffer);

    int playlistIndex = stoi(buffer);

    delete *(playlists.begin() + playlistIndex);
    // free memory after playlist
    playlists.erase(playlists.begin() + playlistIndex);
}

void deleteSongFromPlaylist(vector<Playlist*> &playlists)
{
    string buffer;

    displayPlaylistsIndex(playlists);
    cout << "Pick a playlist index number: ";
    getline(cin, buffer);

    int playlistIndex = stoi(buffer);
    Playlist *playlist = *(playlists.begin() + playlistIndex);

    displaySongsIndex(playlist->getSongs());
    cout << "Pick a song index number to delete: ";
    getline(cin, buffer);

    int songIndex = stoi(buffer);
    playlist->removeSong(songIndex);
}

void deleteSongFromLibrary(vector<Playlist*> &playlists, vector<Song*> &library)
{
    string buffer;

    displaySongsIndex(library);
    cout << "Pick a song index number: ";
    getline(cin, buffer);

    int songIndex = stoi(buffer);
    Song* song = *(library.begin() + songIndex);
    library.erase(library.begin() + songIndex);

    for(auto playlist : playlists)
    {
        playlist->removeSong(song);
    }
    delete song;
    // free memory after song
}

int main()
{
    vector<Song*> library;
    vector<Playlist*> playlists;
    bool isWorking = true;

    cout << "Welcome to the Firstline Player! Enter options to see menu options.\n\n";

    while(isWorking)
    {
        string command;

        cout << "Enter your selection now: ";
        getline(cin, command);

        if(command == "add")
        {
            addSongs(library);
        }
        else if(command == "list")
        {
            displaySongs(library);
        }
        else if(command == "addp")
        {
            addPlaylist(playlists);
        }
        else if(command == "addsp")
        {
            addSongToPlaylist(playlists, library);
        }
        else if(command == "listp")
        {
            displayPlaylistsIndex(playlists);
        }
        else if(command == "play")
        {
            playPlaylist(playlists);
        }
        else if(command == "delp")
        {
            deletePlaylist(playlists);
        }
        else if(command == "delsp")
        {
            deleteSongFromPlaylist(playlists);
        }
        else if(command == "delsl")
        {
            deleteSongFromLibrary(playlists, library);
        }
        else if(command == "options")
        {
            printOptions();
        }
        else if(command == "quit")
        {
            cout << "Goodbye!\n";
            isWorking = false;
        }
        else
        {
            printOptions();
        }
        cout << "\n";
    }

    for(auto playlist : playlists)
    {
        delete playlist;
        // free memory after playlists that wasn't deleted while the program where running
    }

    for(auto song : library)
    {
        delete song;
        // free memory after songs that wasn't deleted while the program where running
    }

    return 0;
}
