#include "Tool.h"

class Inventory {
private:
  std::vector<std::unique_ptr<Tool>> inventory;
  int size;
  
public:
  explicit Inventory(int s = 10) : size(s) {
    inventory.reserve(size);
  }
  ~Inventory() = default;
  
  void addLast(std::unique_ptr<Tool> t) {
    inventory.push_back(std::move(t));
  }
  
  void addInPos(std::unique_ptr<Tool> t, int pos) { 
    if(pos >= inventory.size())
      throw std::out_of_range("Posizione non valida");
    
    inventory.insert(inventory.begin() + pos, std::move(t));
}

std::unique_ptr<Tool> takeInPos(int pos) {
  if(pos >= inventory.size())
    throw std::out_of_range("Posizione non valida");
  
  std::unique_ptr<Tool> result (std::move(*(inventory.begin() + pos)));
  inventory.erase(inventory.begin() + pos);
  return result;
    
}
  
void removeAt(int pos){
  if(pos >= inventory.size())
    throw std::out_of_range("Posizione non valida");
      
    inventory.erase(inventory.begin() + pos);
}
};


