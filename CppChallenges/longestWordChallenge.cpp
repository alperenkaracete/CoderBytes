#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string LongestWord(string sen) {
  
  string longWord;
  string temp;
  stringstream X(sen);
  while (getline(X,temp,' ')){

    string cleanWord;
    for (char c : temp) {
        if (isalpha(c)) { 
            cleanWord += c;
        }
    }    
    if (longWord.length()< cleanWord.length()){

      longWord = cleanWord;
    }  
  }
  sen = longWord;
  // code goes here  
  return sen;

}

int main(void) { 
   
  // keep this function call here
  cout << LongestWord(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}