#ifndef SONG_H_
#define SONG_H_

#include "string"
#include "ostream"

// memory is being free in main.cpp on 169, 248
class Song
{
private:
    std::string title;
    std::string firstLine;
    int playsCount;

public:
    Song(const std::string&, const std::string&);
    ~Song();

    std::string getTitle() const;
    void display(std::ostream&) const;

    void play(std::ostream&);
};

#endif//SONG_H_