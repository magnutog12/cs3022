#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

struct Song
{
    string title;
    string time; // could also be a string
};

struct Album
{
    map<int, Song> songs;
    string name;
    int time;
    int nsongs; // optional variable but makes it easier
};

struct Artist
{
    map<string, Album> albums;
    // Created this since the write up advises to make a map for artists to for adding the artist only once - unsure if needed
    map<string, Artist> singers;
    string name;
    int time;
    int nsongs;
};
// used C++ reference to figure out the substr as well as how to format the time
string time_coversion(const string &time)
{
    if (time.empty())
    {
        cerr << "Listen here pal, you haven't entered a time." << endl;
    }
    char divider = ':';
    size_t position = time.find(divider);
    string sec = time.substr(position + 1);
    string min = time.substr(0, position);
    int convert_minutes = stoi(min);
    int convert_seconds = stoi(sec);

    int total = (convert_minutes * 60) + convert_seconds;

    int total_minutes = (total / 60);
    int total_seconds = (total % 60);
    ostringstream formatted_time;
    formatted_time << time << " = " << total << " = " << total_minutes << ":" << setw(2) << setfill('0') << total_seconds;
    return formatted_time.str();
}
// Map container that has an artist object - value = artist struct - key = artist name.
int main()
{
    ifstream fin;
    string line;
    fin.open("Small.txt");

    Artist artist;
    Album album;
    Song song;

    while (getline(fin, line))
    {
        for (char &c : line)
        {
            if (c == '_')
            {
                c = '0';
            }
        }

        stringstream ss(line);

        string title, artistname, albumname, genre, time;
        int track = 0, nsongs = 0;

        ss >> title >> time >> artistname >> albumname >> genre >> track;

        artist.name = artistname;
        album.name = albumname;
        song.title = title;
        song.time = time;

        // Had trouble replacing directly / somehow this works
        for (char &c : artistname)
        {
            if (c == '0')
            {
                c = ' ';
            }
        }
        for (char &c : title)
        {
            if (c == '0')
            {
                c = ' ';
            }
        }
        for (char &c : albumname)
        {
            if (c == '0')
            {
                c = ' ';
            }
        }

        // album.songs.clear();
        // album.songs[track] = {title, time};
        artist.singers[artistname].albums[albumname].songs[track] = {title, time};

        // TODO: Insert artist into a map, print New Artist, then check to see if it exists, if so print Old Artist.
        //       Then do the same thing for the album map.
        /*
                cout << artistname << ": " << nsongs << ", " << time << endl;
                cout << albumname << " " << nsongs << " " << time_coversion(time) << endl;
                for(map<int, Song>::iterator it = album.songs.begin(); it != album.songs.end(); it++){

                    cout << it->first << ". " << it->second.title << ": " << time << endl;
                }
        */
    }
    for (map<string, Artist>::iterator iq = artist.singers.begin(); iq != artist.singers.end(); iq++)
    {
        cout << iq->first << ": " << iq->second.nsongs << ", " << iq->second.time << endl;
        for (map<string, Album>::iterator is = iq->second.albums.begin(); is != iq->second.albums.end(); is++)
        {
            cout << "       " << is->first << " " << is->second.nsongs << " " << is->second.time << endl;
            for (map<int, Song>::iterator it = is->second.songs.begin(); it != is->second.songs.end(); it++)
            {
                cout << "               " << it->first << ". " << it->second.title << ": " << it->second.time << endl;
            }
        }
    }


fin.close();
}
