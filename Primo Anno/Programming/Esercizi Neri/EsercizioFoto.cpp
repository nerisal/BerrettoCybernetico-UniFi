#include <iostream>
#include <string>
#include <list>
#include <unordered_map>

class Photo {
private:
    int width, height;
    std::string position; // "NULL" se non nota
    bool is_starred;
    std::list<std::string> peoples;

public:
    Photo(int w, int h, const std::string& p, bool s)
        : width(w), height(h), position(p), is_starred(s) {}

    ~Photo() = default;

    void setStarred(bool s) {
        is_starred = s;
    }

    void setPosition(const std::string& p) {
        position = p;
    }

    bool isStarred() const {
        return is_starred;
    }

    std::string getPosition() const {
        return position;
    }

    void setPeople(const std::list<std::string>& p) {
        peoples = p;
    }

    const std::list<std::string>& getPeople() const {
        return peoples;
    }
};

class Collection {
private:
    std::unordered_map<std::string, Photo> collection;

public:
    Collection() = default;
    ~Collection() = default;

    void addPhoto(const Photo& p, const std::string& id) {
        collection.insert({id, p});
    }

    void removePhoto(const std::string& id) {
        collection.erase(id);
    }

    void setStarred(const std::string& id) {
        if (collection.find(id) != collection.end()) {
            bool current = collection[id].isStarred();
            collection[id].setStarred(!current);
        }
    }

    std::list<Photo> getFavourite() const {
        std::list<Photo> result;
        for (const auto& [id, photo] : collection) {
            if (photo.isStarred()) {
                result.push_back(photo);
            }
        }
        return result;
    }

    std::list<Photo> getByLocation(const std::string& loc) const {
        std::list<Photo> result;
        for (const auto& [id, photo] : collection) {
            if (photo.getPosition() == loc) {
                result.push_back(photo);
            }
        }
        return result;
    }

    std::list<Photo> getByPerson(const std::string& name) const {
        std::list<Photo> result;
        for (const auto& [id, photo] : collection) {
            for (const auto& person : photo.getPeople()) {
                if (person == name) {
                    result.push_back(photo);
                    break;
                }
            }
        }
        return result;
    }
};

