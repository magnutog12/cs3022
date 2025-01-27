/*
Magnus Terry, Tony Caldwell
01/26/2025
This program sorts music files using maps 
and prints in the desired format. 
Compile command: g++ -o lib_info lib_info.cpp
Github repo URL: https://github.com/magnutog12/cs3022.git
*/
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
    map<string, Artist> singers;
    string name;
    int time;
    int nsongs;
};
// used C++ reference strings to explain .substr as well as how to format the time from a string to int and back
int time_to_seconds(const string& time){
    char divider = ':';
    size_t position = time.find(divider);
    string sec = time.substr(position + 1);
    string min = time.substr(0, position);
    int convert_minutes = stoi(min);
    int convert_seconds = stoi(sec);

    int total = (convert_minutes * 60) + convert_seconds;
    return total;
}
// For formatting the time collected from seconds back into minutes
string time_coversion(int total){
    
    int total_min = total / 60;
    int total_sec = total % 60;
    
    ostringstream formatted_time;
    formatted_time << total_min << ":" << setw(2) << setfill('0') << total_sec;
    return formatted_time.str();

}

int main(int argc, char* argv[]){
    ifstream fin;
    string line;
    // open file from argv for gradescripts
    fin.open(argv[1]);

    // make struct objects
    Artist artist;
    Album album;
    Song song;

    string title, artistname, albumname, genre, time;
    int track = 0, nsongs = 0;

    // replace underscores with spaces
    while (getline(fin, line)){
        for (char &c : line)
        {
            if (c == '_')
            {
                c = '~';
            }
        }

        // used stringstream to gather data in its given position
        stringstream ss(line);
        ss >> title >> time >> artistname >> albumname >> genre >> track;

        // Had trouble replacing directly / somehow this works
        for (char &c : artistname)
        {
            if (c == '~')
            {
                c = ' ';
            }
        }
        for (char &c : title)
        {
            if (c == '~')
            {
                c = ' ';
            }
        }
        for (char &c : albumname)
        {
            if (c == '~')
            {
                c = ' ';
            }
        }

        // populate maps
        artist.singers[artistname].albums[albumname].songs[track] = {title, time};
    
    }

    // loop to perform time and nsongs calculations
    for (map<string, Artist>::iterator iq = artist.singers.begin(); iq != artist.singers.end(); iq++){
        iq->second.time = 0; // reset artist time
        for (map<string, Album>::iterator is = iq->second.albums.begin(); is != iq->second.albums.end(); is++){
            is->second.time = 0; // reset album time
            for (map<int, Song>::iterator it = is->second.songs.begin(); it != is->second.songs.end(); it++){
                // increment album and artist nsongs
                iq->second.nsongs++;
                is->second.nsongs++;
                // made method to calculate seconds to get this arithmetic to work
                int song_time = time_to_seconds(it->second.time);
                is->second.time += song_time; // add song times to album total
            }
            iq->second.time += is->second.time; // add ablum times to artist total
        }
    }

    // print loop
    for (map<string, Artist>::iterator iq = artist.singers.begin(); iq != artist.singers.end(); iq++){
        cout << iq->first << ": " << iq->second.nsongs << ", " << time_coversion(iq->second.time) << endl;
        for (map<string, Album>::iterator is = iq->second.albums.begin(); is != iq->second.albums.end(); is++){
            cout << "        " << is->first << ": " << is->second.nsongs << ", " << time_coversion(is->second.time) << endl;
            for (map<int, Song>::iterator it = is->second.songs.begin(); it != is->second.songs.end(); it++){
                cout << "                " << it->first << ". " << it->second.title << ": " << it->second.time << endl;
            }
        }
    }


fin.close();
}
