#include "Song.h"

Song::Song(const std::string &title, const std::string &firstLine)
{
    this->title = title;
    this->firstLine = firstLine;
    this->playsCount = 0;
}

Song::~Song()
{

}

std::string Song::getTitle() const
{
    return title;
}

void Song::display(std::ostream &os) const
{
    os << title << ": \"" << firstLine << "\", " << playsCount << " play(s).\n";
}

void Song::play(std::ostream &os)
{
    os << firstLine << "\n";
    playsCount++;
}