#include "Playlist.h"

#include "algorithm"

#include "Song.h"

Playlist::Playlist(const std::string &title)
{
    this->title = title;
}

Playlist::~Playlist()
{

}

std::string Playlist::getTitle() const
{
    return title;
}

const std::vector<Song*> &Playlist::getSongs() const
{
    return songs;
}


void Playlist::play(std::ostream &os) const
{
    os << "Playing first lines of playlist: " << title << "\n";

    for(auto song : songs)
    {
        song->play(os);
    }
}

void Playlist::addSong(Song *song)
{
    songs.push_back(song);
}

void Playlist::removeSong(Song *song)
{
    auto songIt = std::find(songs.begin(), songs.end(), song);

    if(songIt != songs.end())
    {
        songs.erase(songIt);
    }
}

void Playlist::removeSong(int index)
{
    songs.erase(songs.begin() + index);
}