class AudioTrack {
private:
	std::string title;
	std::string cover_file;
	int duration;
public:
	AudioTrack(std::string t, std::string c, int d) : title(t), cover_file(c), duration(d) {}
	~AudioTrack() {}
	
	void play() {
		std::cout << title << " is now playing. Lasting: " << duration << " " << cover_file << std::endl;	
	}
	
	std::string getTrackTitle() {
		return title;
	}
};

class Playlist {
private:
	std::map<std::string, std::shared_ptr<AudioTrack>> playlist;
	std::string p_name;
	
public:
	Playlist(std::string p) : p_name(p) {}
	~Playlist() {};
	
	std::string getPlaylistName() {
		return p_name;
	}
	
	void addTrack(const std::shared_ptr<AudioTrack> track) {
		playlist.insert(std::make_pair(track->getTrackTitle(), track));
	}
	
	void removeTrack(const std::string title) {
		playlist.erase(title);
	}
	
	void playTrack(const std::string title) {
		if(playlist.find(title) != playlist.end())
			playlist[title]->play();	
	}
	
	void play() {
		for(const auto& tracks : playlist) {
			tracks.second->play();
		}
	}
};

class MusicLibrary {
private:
	std::map<std::string, Playlist> library;
public:
	void play(std::string name) {
		if(library.find(name) != library.end())
			library[name].play();
	}
	
	void insert(Playlist& p) {
		library.insert(std::make_pair(p->getName(), p}));
	}
	
	bool find(std::string name) {
		if(library.find(name) != library.end()){
			std::cout << "Playlist trovata: " << library[name]->getName();
			return true;
	}
	else 
		return false;
		}

};
