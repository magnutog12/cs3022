#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

struct Song { 
    string title;
    string time;  // could also be a string
};

struct Album {
    map <int, Song > songs;
    string name;
    int time;
    int nsongs;  // optional variable but makes it easier
};

struct Artist {
    map <string, Album > albums;
    string name;
    int time;
    int nsongs;
};

int main() {
    ifstream fin;
    string line;
    fin.open("Small.txt");

    Artist artist;
    Album album;
    Song song;

    while(getline(fin, line)) {
        for(char& c : line) {
            if(c == '_'){
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
        for(char& c : artistname) {
            if(c == '0'){
                c = ' ';
            }
        }
        for(char& c : title) {
            if(c == '0'){
                c = ' ';
            }
        }
        for(char& c : albumname) {
            if(c == '0'){
                c = ' ';
            }
        } 

        album.songs.clear();
        album.songs[track] = {title, time};

        cout << artistname << ": " << nsongs << ", " << time << endl;
        cout << albumname << " " << nsongs << " " << time << endl;
        for(map<int, Song>::iterator it = album.songs.begin(); it != album.songs.end(); it++){
            cout << it->first << ". " << it->second.title << " " << time << endl;
        }
    
        
    }
    fin.close();
    
    
    
}