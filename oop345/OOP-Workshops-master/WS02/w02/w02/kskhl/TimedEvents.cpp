#include "TimedEvents.h"
#define _CRT_SECURE_NO_WARNINGS

sdds::TimedEvents::TimedEvents(){
  count=0;
}
void sdds::TimedEvents::startClock(){
  t1=steady_clock::now();
}
void sdds::TimedEvents::stopClock(){
  t2 = steady_clock::now();
}
void sdds::TimedEvents::addEvent(string name){
  eve[count].eventName="";
  eve[count].eventName=name;
  eve[count].dur = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
  eve[count].uot="nanoseconds";
  count++;
}
 
