class MediaAdapter : public AudioPlayer {
public:
	virtual void play(std::string audioType, std::string filename) override {
		if(audiotype == "aac") {
			mediaplayer = std::make_unique<AACMediaPlayer>();
			mediaplayer->play(filename, true);
		}
		else if(audioType == "mp3") {
			mediaplayer = std::make_unique<MP3MediaPlayer>();
			mediaplayer->play(filename, true);
		}
		else if(audioType == "wav") {
			AudioPlayer::play(audioType, filename);
		}
		else
			cout << "Unknown file format: " << audioType << endl;

	}
	
private:
	std::unique_ptr<AdvancedMediaPlayer> mediaplayer;
};
