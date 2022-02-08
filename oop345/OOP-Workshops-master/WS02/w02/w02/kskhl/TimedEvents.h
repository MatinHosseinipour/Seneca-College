#include <iostream> 
#include <chrono>
#include <iomanip>
#include <utility>
using namespace std; 
using namespace std::chrono;
namespace sdds{
  struct Event{
    string eventName;
    string uot;
    steady_clock::duration dur;
  };
  class TimedEvents{
  private:
    steady_clock::time_point t1;
    steady_clock::time_point t2;
    struct Event eve[10];
    int count;
  public:
    TimedEvents();
    void startClock();
    void stopClock();
    void addEvent(string name);
    friend ostream & operator << (ostream &out, TimedEvents &t){
      out<<"--------------------------"<<endl;
      out<<"Execution Times:\n--------------------------"<<endl;
      for(int i=0;i<t.count;i++){
        out<<setw(21)<<left<<t.eve[i].eventName<<setw(13)<<right<<t.eve[i].dur.count()<<" "<<t.eve[i].uot<<endl;
      }
      out<<"--------------------------"<<endl;
      return out;
    }
  };
}