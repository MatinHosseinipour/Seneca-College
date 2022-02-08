#include <iostream> 
#include <fstream>
#include <string>
using namespace std; 

namespace sdds{
class StringSet{
  private:
    int numberOfWords;
    char* words;
  public:
  StringSet();
  StringSet(char* name);
  size_t size();
  char operator[](size_t index);
  StringSet(StringSet&&);
  StringSet(StringSet&);
  StringSet& operator=(StringSet& obj);
  StringSet& operator=(StringSet&&);
  };
}