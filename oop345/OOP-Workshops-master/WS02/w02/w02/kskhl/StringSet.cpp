#include "StringSet.h"

sdds::StringSet::StringSet(){
  numberOfWords=0;
}
sdds::StringSet::StringSet(char* name){
  numberOfWords=0;
  char abc;
  ifstream ifile(name);
  while(!ifile.eof()){
    ifile>>abc;
    numberOfWords++;
  }
  ifile.close();

  words=new char[numberOfWords];
  int i=0;
  ifstream ile(name);
  while(!ile.eof()){
    words[i]='\0';
    ile>>words[i];
    i++;
  }
  ile.close();
}

size_t sdds::StringSet::size(){
  return numberOfWords;
}

char sdds::StringSet::operator[](size_t index){
    char ab{};
  if(index<numberOfWords){
    ab=words[index];
  }
  return ab;
}

sdds::StringSet::StringSet(StringSet&& obj){
  this->numberOfWords= obj.size();
  this->words=obj.words;
  obj.words=nullptr;
  obj.numberOfWords=0;
}

sdds::StringSet& sdds::StringSet::operator=(StringSet&& obj)
{
	if (&obj == this)
		{return *this;}
  this->numberOfWords= obj.size();
  this->words=obj.words;
  obj.words=nullptr;
  obj.numberOfWords=0;
	return *this;
}
sdds::StringSet& sdds::StringSet::operator=(StringSet& obj)
{
	if (&obj == this)
		{return *this;}
  this->numberOfWords= obj.numberOfWords;
  this->words=new char[numberOfWords];
  for(int i=0;i<obj.numberOfWords;i++){
      words[i]=obj.words[i];
  }
	return *this;
}
sdds::StringSet::StringSet(StringSet& obj){
  this->numberOfWords= obj.numberOfWords;
  this->words=new char[numberOfWords];
  for(int i=0;i<obj.numberOfWords;i++){
      this->words[i]=obj.words[i];
  }
}