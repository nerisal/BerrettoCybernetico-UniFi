using namespace std;

class NotePad {
private:
	map<string, Note> notepad;
public:
	void add(const Note& new_) {
		notepad.emplace(make_pair(new_.getTitle(), new_));
	}

	void remove(const string t) {
		notepad.erase(t);
	}
	
	void show(const string t) {
		if(notepad.find(t) != notepad.end())
			notepad[t].show();
	}
};

class Note {
private:
	string title;
	string content;
	
	list<shared_ptr<Media>> collection;
public:
	Note(string t, string c) : title(t), content(c) {}
	
	string getTitle() {
		return title;
	}
	
	void addMedia(const shared_ptr<Media> m) {
		collection.push_back(m);
	}
	
	void show() {
		cout << "Note title: " << title << " note content: " << content << ". " << endl;
		for(const auto& media : collection)
			media->show();
	}
};

class Media {
protected:
	string path;
public:
	virtual void show() = 0;
	virtual ~Media();
	explicit Media(string p) : path(p)
};

class Image : public Media {
private:
	int resolution;
public:
	Image(int r, string p) : resolution(r), Media(p) {}
	~Image() override {}
	
	void show() override {
		cout << "Image of resolution: " << resolution << " at: " << path;
	}
};

class Video : public Media {
private:
	int resolution;
	int duration;
	
public:
	Video(int r, int d, string p) : resolution(r), duration(r), Media(p) {}
	~Video override {}
	
	void show() override {
		cout << "Video of resolution: " << resolution << " and duration: " << duration << " at: " << path << endl;
	}
};

class Audio : public Media {
private:
	int duration;
public:
	Audio(int d, string p) : duration(d), Media(p) {}
	~Audio override{}
	
	void show() override {
		cout << "Audio of duration " << duration << " at: " << path << endl;
	}

};
