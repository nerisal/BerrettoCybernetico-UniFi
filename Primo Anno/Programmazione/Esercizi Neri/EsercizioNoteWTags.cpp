class Element {
public:
	virtual ~Element() {}
	virtual void print() = 0;
};

class Text : public Element {
public:
	Text(std::string text) : text(text) {}
	virtual void print() override {
		std::cout << text << std::endl;
	}
	
private:
	std::string text;
};

class Audio : public Element {
public:
	Audio(std::string audioFile) : audioFile(audioFile) {}
	virtual void print() override {
		std::cout << "Audio source: " << audioFile << std::endl;
	}
	
private:
	std::string audioFile;
};

class Image : public Element {
public:
	Image(std::string image) : image(image) {}
	virtual void print() override {
		std::cout << "Image: " << image << std::endl;
	}
private:
	std::string image;
};

class Note {
private:
	std::string noteType;
	std::list<std::string> tags;
	std::shared_ptr<Element> content;
	std::string title;
public:
	Note(std::string title ,std::string nt, std::shared_ptr<Element> c) : title(title), noteType(nt), content(c) {}
	
	void print() const {
		content->print();
	}
	
	void addTag(std::string tag) {
		tags.push_back(tag);
	}
	
	std::string getType() const {
		return noteType;
	}
	
	void getTagList() const {
		std::cout << "List of tags in the note: " << std::endl;
		for(const auto& tag : tags){
			std::cout << tag << std::endl;
		}
	}
	
	bool hasTag(std::string search) const {
		for(const auto& tag : tags){
			if(tag == search) {
				return true;
			}
		}
		
		return false;
	}
	
	std::string getTitle() const {
		return title;
	}
};

class Notebook {
private:
	std::list<Note> notebook;
public:
	void addNote(std::string t, std::string nt, std::shared_ptr<Element> e) {
		notebook.emplace_front(t, nt, e);
	}
	
	void printAll() const {
		std::cout << "Notes in notebook: " << std::endl;
		for(const auto& note : notebook)
			std::cout << note.getTitle() << ": "<< note.print() << std::endl;
	}
	
	void searchByTag(std::string tag) {
		std::list<Note> found;
		
		for(const auto& note : notebook){
			if(note.hasTag(tag)){
				found.push_back(note);
			}
		}
		
		std::cout << "Notes with " << tag << " tag: " << std::endl;
		for(const auto& note : found){
			std::cout << note.getTitle() << std::endl;
		}
	}
};
