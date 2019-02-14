#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include "vector"
#include "string"
#include "ostream"

class Song;

// Memory is being free in main.cpp on 129, 242 lines
class Playlist
{
private:
    std::string title;
    std::vector<Song*> songs;

public:
    Playlist(const std::string&);
    ~Playlist();

    std::string getTitle() const;
    const std::vector<Song*> &getSongs() const;
    void play(std::ostream &) const;

    void addSong(Song*);
    void removeSong(Song*);
    void removeSong(int);
};

#endif//PLAYLIST_H_