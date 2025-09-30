#include <iostream>
#include <list>
#include <string>
#include <memory>

using namespace std;

class MediaElement {
public:
	virtual void play() const = 0;
	virtual float getDuration() const = 0;
	virtual ~MediaElement() {}
};

class ImageElement : public MediaElement {
private:
	float duration;
	string name;
	int resolution;
public:
	explicit ImageElement(string name, int resolution)
		: duration(5), resolution(resolution), name(name) {}

	virtual void play() const override {
		cout << "Now playing Image: " << name
		     << " Resolution: " << resolution
		     << " Duration: " << duration << " sec" << endl;
	}

	virtual float getDuration() const override {
		return duration;
	}
};

class VideoElement : public MediaElement {
private:
	float duration;
	string name;
	int resolution;
public:
	VideoElement(string name, float duration, int resolution)
		: name(name), duration(duration), resolution(resolution) {}

	virtual void play() const override {
		cout << "Now playing Video: " << name
		     << " Resolution: " << resolution
		     << " Duration: " << duration << " sec" << endl;
	}

	virtual float getDuration() const override {
		return duration;
	}
};

class TrackElement : public MediaElement {
private:
	list<shared_ptr<MediaElement>> track;
	string name;
public:
	explicit TrackElement(string name) : name(name) {}

	virtual float getDuration() const override {
		float duration = 0;
		for (const auto& entry : track) {
			duration += entry->getDuration();
		}
		return duration;
	}

	virtual void play() const override {
		cout << "Now playing Track: " << name << endl;
		for (const auto& entry : track) {
			entry->play();
		}
	}

	void addElement(shared_ptr<MediaElement> newElement) {
		track.push_back(newElement);
	}
};
