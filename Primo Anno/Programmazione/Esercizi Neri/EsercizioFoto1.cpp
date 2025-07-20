class Photo {
private:
	int width, int height;
	std::string position;
	bool is_starred;
	std::list<std::string> people;
public:
  Photo(int w, int h, std::string p, std::list<std::string> ppl) : width(w), height(h), position(p), is_starred(false), people(ppl) {}
  ~Photo();
  
  bool isStarred();
  void setStarred(bool s);
  
  std::list<std::string> getPeople();
  
  std::string getPosition();
  
};

// .cpp
bool Photo::isStarred(){
  return is_starred;
}

void Photo::setStarred(bool s){
  is_starred = s;
}

std::list<std::string> Photo::getPeople() {
  return people;
}

std::string Photo::getPosition() {
  return position;
}

class Collection {
private:
  std::unordered_map<std::string id, Photo photo> collection;
  
public:
  void addPhoto(const std::string id, const Photo& p) {
    collection.insert(id, p);
}

void removePhoto(const std::string id) {
  collection.erase(id);
}

void toggleFavourite(const std::string id) {
  if(collection[id].isStarred())
    collection[id].setStarred(false);
  else
    collection[id].setStarred(true);
}

std::list<Photo> getFavourite() {
  std::list<Photo> result;
  for(const auto& [id, photo] : collection) {
    if(photo.isStarred())
      result.push_back(photo);
  }
  
  return result;
  }
  
std::list<Photo> getPhotoTakenIn(const std::string pos) {
  std::list<Photo> result;

  for(const auto& [id, photo] : collection) {
    if(photo.getPosition() == pos)
      {
        result.push_back(photo);
      }
      
     
  }
  
  return result;
}

std::list<Photo> getPhotosWith(const std::string name)  {
  std::list<Photo> result;
  
  for(const auto& [id, photo] : collection){
    for(const auto& person : photo.getPeople()){
      if(name == person){
        result.push_back(photo);
}  
    }
  }
  
  return result;
}
};
