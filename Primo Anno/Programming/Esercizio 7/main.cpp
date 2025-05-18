#include "Date.h"
#include "Task.h"
#include <iostream>
#include <map>

int main() {
  Date d1(2018, Months::Apr, 23);
  Date d2(2018, Months::May, 7);
  Date d3(2018, Months::May, 11);
  Date d4(2018, Months::Jun, 10);
  Task t1{"Lezione Template", true, d1};
  Task t2{"Lezione Eccezioni", true, d2};
  Task t3{"Esercitazione Eccezioni+STL", false, d3};
  Task t4{"Lezione coding style guidelines", false, d3};

  // @see http://en.cppreference.com/w/cpp/container/multimap/multimap
  // default comparator:
  // http://en.cppreference.com/w/cpp/utility/functional/less
  // DONE create a multimap (called agendaM) that associates tasks using their
  // deadline
  std::multimap<Date, Task, DateComparator> agendaM;

  // TODO insert pairs of Dates/Tasks (t1-t4) using make_pair or creating a pair
  // with its constructor
  agendaM.insert(std::make_pair(t1.deadline, t1));

  // @see http://en.cppreference.com/w/cpp/container/multimap/find
  // XXX compare with http://en.cppreference.com/w/cpp/algorithm/find
  // TODO find if on Date d4 there's any activity in the agenda and print it's
  auto const position = agendaM.find(d4);
  if (position != agendaM.end())
    std::cout << position->first << " - " << position->second.description
              << std::endl;
  // description or std::cout << "Non ho niente da fare il giorno: " << d4 <<
  // std::endl;

  // @see http://en.cppreference.com/w/cpp/container/multimap/equal_range
  // TODO find all tasks on Date d2 and print their description
  auto const positions = agendaM.equal_range(d2);
  for (auto it = positions.first; it != positions.second; ++it)
    std::cout << it->first << " - " << it->second.description << std::endl;

  std::cout << "Tutte le attivita'" << std::endl;

  // TODO write a for cycle to print all activities, printing the date and
  // description
}