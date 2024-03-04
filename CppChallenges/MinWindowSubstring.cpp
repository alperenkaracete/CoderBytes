#include <iostream>
#include <string>
using namespace std;

void findMinMax(int& min, int& max,int length,int pos[]){

  for (int i=0;i<length;i++){
    if (pos[i]>max)
      max = pos[i];

    if (pos[i]<min){
      min = pos[i];  
    }
  }
}

void searchSubstring(string strArr[],int pos[],int& min,int& max){

  int length;

  length = strArr[1].length();

  int tempNum = strArr[1].find(strArr[0][min]);

  for (int i=min+1;i<max;i++){
    for (int j=0;j<length;j++){
      if (strArr[0][i]==strArr[1][tempNum]){
        if (max - min > max - i)
          pos[tempNum]=i;
          min = 999999;
          i=max;
      }
    }
  }

  findMinMax(min,max,length,pos);
}

string MinWindowSubstring(string strArr[], int arrLength) {
  
  int length = strArr[1].length();
  int pos[length];
  int count=0;
  string temp;
  int min=999999,
    max=0;
  for (int i=0;i<length;i++){

    for (int j=0;j<strArr[0].length();j++){

      if (strArr[0][j]==strArr[1][i]){

        pos[i]=j;
        for (int k=0;k<i;k++){

          if(pos[k]==j){

            count++;
          }
        }
        if (count == 0){
          
          break;
        }
        count = 0;
        
      }
      count = 0;

    }
  }
  for (int i=0;i<length;i++){

    if (pos[i]>max)
      max = pos[i];

    if (pos[i]<min)
      min = pos[i];  
  }
  if (strArr[0][0]==strArr[0][1] && strArr[1].find(strArr[0][0] >= 0)){
    int tempCount = 0;
    for (int i=0;i<length;i++){

      if (strArr[1][strArr[1].find(strArr[0][0])]==strArr[1][i])
        tempCount++;
    }
    if (tempCount == 1){
      min=1;
      temp = strArr[0].substr(min,max);
      strArr[0] = temp;
      string test;
      do {
        test = temp;
        searchSubstring(strArr,pos,min,max);
        temp = strArr[0].substr(min,max+1);
      }while(test!=temp);
      return temp;
    }  
  }

  temp = strArr[0].substr(min,max+1);
  strArr[0] = temp;
  string test;
  do {
    test = temp;
    searchSubstring(strArr,pos,min,max);
    temp = strArr[0].substr(min,max+1);
  }while(test!=temp);

  // code goes here  
  return temp;

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << MinWindowSubstring(A, arrLength);
  return 0;
    
}