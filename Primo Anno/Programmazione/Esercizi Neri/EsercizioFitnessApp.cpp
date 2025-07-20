// File App.h
class App {
public:
  App(int sg, int ag, int cg) : standing_goal(sg), activity_goal(ag), calories_goal(cg) {}
  ~App() {}
  
  void add_activity(std::string name, int mult, int duration);
  
  void update_standing_time(int delta){
    standing_time += delta;
  }
  
  void update_calories(int delta) {
    calories += delta;
  }
  
  void update_duration(int delta) {
    duration += delta;
    
  }
  
  void remove_activity(std::unique_ptr<Activity> activity);
  
  void print() {
    cout << "Calories: " << calories << "/" << calories_goal << "Standing: " << standing_time << "/" << standing_goal << "Activity: " << activity_hours << "/" << activity_goal;
    for(auto itr = activity_list.begin(), 
  }
  
  int get_calories() {
    return calories;
  }
  
  int get_activity_hours() {
    return activity_hours;
  }
  
  int get_standing_time() {
    return standing_time;
  }
  
private:
  std::list<std::unique_ptr<Activity>> activity_list;
  int standing_time;
  int standing_goal;
  int activity_goal;
  int activity_hours;
  int calories;
  int calories_goal;
};

// File App.cpp

#include "App.h"

void App::add_activity(std::string name, int mult, int duration) {
    std::unique_ptr<Activity> activity(new Activity(name, mult, duration));
    if(name == "standing")
      update_standing_time(duration)
      
    update_calories(activity->getCaloriesConsumption();
    
    update_duration(activity->get_duration());
    
    auto activity_list.pushback(std::move(activity);
    
  }
  
void App::remove_activity(std::unique_ptr<Activity> activity) {
    for (auto it = activity_list.begin(); it != activity_list.end(); ++it) {
        if (it->get() == activity) {
            const Activity* act = it->get();
            
            // Aggiorna i valori di tracking sottraendo
            if (act->get_name() == "standing") {
                update_standing_time(-act->get_duration());
            } else {
                update_activity_hours(-act->get_duration());
            }
            update_calories(-act->get_calories_consumption());

            // Rimuovi attività dalla lista
            activity_list.erase(it);
            return;
  }
  
  // Activity.h
  
  class Activity {
  public:
    Activity(std::string name, int mult, int duration) : name(name), mult(mult), duration(duration) {}
    ~Activity() {}
    
    int get_calories_consumption() {
      return duration * mult;
    }
    
    std::string get_name() {
      return name;
    }
    
  private:
    std::string name;
    int mult;
    int duration;
  };
    
