

#include <iostream>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

class AudioTrack{
public:
    AudioTrack(string t="", int s=0, string ImageName=""):title(t), seconds(s), coverImage(ImageName){}

    int getSeconds()const {
        return seconds;
    }

    string getTitle()const{
        return title;
    }

    string getCoverImage()const {
        return coverImage;
    }

    void play(){
        cout<<"playing "<<title<<" of "<<getSeconds()<<" seconds, with cover image "<<coverImage<<endl;
    };

//    bool operator==(const AudioTrack& track) {
//        return track.title==title;
//    }

private:
    int seconds;
    string title, coverImage;
};


class Playlist{
public:
    Playlist(string n, bool l=false, int loopN=0):name(n),loop(l), loopNumber(loopN){};

    void setLoop(){
        loop = true;
    }

    string getName()const{
        return name;
    }

    int getLoopNumber()const{
        return loopNumber;
    }

    void addTrack(const AudioTrack& track){
        playlist.insert(playlist.end(),make_pair(track.getTitle(), track));
    }

    map<string, AudioTrack>::iterator findTrack(const string& title){
        auto itr=playlist.find(title);
        return itr;
    }

    void removeTrack(const string& title){
        auto it= findTrack(title);
        playlist.erase(it);
    }

    void playTrack(const string& title) {
        auto it = findTrack(title);
        it->second.play();
    }


    void play(){
        for(auto& itr:playlist)
            itr.second.play();
    }

    void loopPlaying(){
        if(loop) {
            for(int i=1; i<=loopNumber; ++i) {
                cout << "Playing another time...." << endl;
                play();
            }
        }
    }

    void displayMap(){
        for(auto&itr: playlist) {
            cout << " Track name: " << itr.first <<  endl;
            cout<< "Track duration: " << itr.second.getSeconds()<<endl;
            cout<<"Cover image: "<<itr.second.getCoverImage()<<endl;
        }
    }

private:
    map<string, AudioTrack> playlist;
    string name;
    bool loop;
    int loopNumber;
};

class MusicLibrary{
public:

    void addPlaylist(const Playlist& list){
        Musiclib.insert(make_pair(list.getName(),list));
    }

    map<string, Playlist>::iterator findPlaylist(const string& name){
        return Musiclib.find(name);
    }

    void playPlaylist(const string& name){
        auto itr=findPlaylist(name);
        itr->second.play();

    }


    void displayMap(){
        for(auto&itr: Musiclib) {
            cout << " Playlist name: " << itr.first <<  endl;
            cout<<"Play for "<< itr.second.getLoopNumber()<< " times"<<endl;
        }
    }
private:
    map<string, Playlist> Musiclib;
};


int main(){
    AudioTrack track("Innocence", 90,"cover");
    track.play();
    cout<<"\n"<<endl;

    Playlist pl("playlist", true, 2);
    pl.addTrack(track);
    pl.displayMap();
    cout<<"\n"<<endl;

    AudioTrack track1("song", 120,"cover1");
    pl.addTrack(track1);
    pl.displayMap();
    cout<<"\n"<<endl;

    pl.removeTrack("song");
    pl.displayMap();
    cout<<"\n"<<endl;

    pl.playTrack("Innocence");
    cout<<"\n"<<endl;

    pl.loopPlaying();
    cout<<"\n"<<endl;

    MusicLibrary lib;
    lib.addPlaylist(pl);
    lib.displayMap();

}