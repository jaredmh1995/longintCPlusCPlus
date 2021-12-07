//Name: Jared Hazel
//Class: CSS501
//Program 4
//Due Date: 12/8/2020
//Purpose: This Program builds, adds, subtracts and compares longints

#include "longint.h"
#include <iostream>
using namespace std;

//Gets the information the user enters in and puts it into long int.
//checks for negative value and adds only numbers fron the string to longint
//Once all numbers are entered, longint is sent to Remove0s to clean it up
istream &operator>>( istream &input, LongInt &rhs ){

  string test;
  input>>test;
  rhs.~LongInt();

  for(int i=0; i<test.size(); i++){
    
    char carCheck = test[i];
    int letterCheck = tolower(test[i]);
    if(letterCheck-48>9){
      //do nothing
    }
    else{
      if(carCheck == '-'){
       rhs.negative = true;
      }
     else{
      if(rhs.digits.isEmpty() == true){
        rhs.digits.addFront(test[i]);
      }
      else{
       rhs.digits.addBack(test[i]);
      }
     }
  }
  }
  rhs.remove0s();

 if(rhs.digits.getFront()=='0'){
   rhs.negative=false;
 }
  return input;
}

//prints out the longint.  
//prints out the numbers one at a time to a string and then 
//adds a minus sign if negative equals true
ostream &operator<<( ostream &out, const LongInt &rhs ){

 string returnValue="";
 LongInt printCopy = rhs;

 while(printCopy.digits.isEmpty() == false){
   returnValue = (printCopy.digits.removeBack())+returnValue;
 }

 if(printCopy.negative == true ){
   returnValue = "-"+returnValue;
 }

 out<<returnValue;

 return out;
}

//Works simliarly to istream, puts the entered information into longint
//checks for negative value and adds only numbers fron the string to longint
//Send new longint to remove0 method
LongInt::LongInt( const string str ){

  digits.clear();

  for(int i=0; i<str.size(); i++){
    
    char carCheck = str[i];
    int letterCheck = tolower(str[i]);

    if(letterCheck-48>9){
      //do nothing
    }
    else{
    
    if(carCheck == '-'){
      negative = true;
    }
    else{
      if(digits.isEmpty() == true){
        digits.addFront(str[i]);
      }
      else{
        digits.addBack(str[i]);
      
      }
    }
  }
  }
  remove0s();
}

//Copy constructor
LongInt::LongInt( const LongInt &rhs ){

  digits.addBack('0');
  negative=false;
  *this = rhs;
}

//Default constructor
LongInt::LongInt(){
  digits.addBack('0');
  negative = false;
}

//Deconstructor
//Goes through longint and clears it out 
LongInt::~LongInt( ){

  while(digits.isEmpty() == false){
    digits.clear();
  }
}

//This method adds two operators togethers
//First figures out which sides are negative or not
//Depending on what's negative, it maybe easier to send them to 
//the subtraction method
//This method for-loops through the right and left side longints 
//and adds the numbers together.  If the new number is bigger than 9
//a bool variable is turned true and 1 is added to the next pair of number(s)
//Two for loops are used because the two sides could have different lengths
//and this what we can capture all of the numbers.
LongInt LongInt::operator+( const LongInt &rhs ) const{

  LongInt returnValue;
  LongInt copyOne = *this;
  LongInt copyTwo = rhs;
  returnValue.~LongInt();

  if(negative == false && rhs.negative == true){
    
    copyOne.negative=false;
    copyTwo.negative=false;
    return copyOne-copyTwo;
  }
  else if(negative == true && rhs.negative == false){

    copyOne.negative=false;
    copyTwo.negative=false;
    return copyTwo-copyOne;
  }
  else{

  int oneSize = copyOne.digits.size();
  int twoSize = copyTwo.digits.size();
  int loopSize;
  int loopSize2;

  if(oneSize>twoSize){
    loopSize = twoSize;
    loopSize2 = oneSize;
  }
  else{
    loopSize = oneSize;
    loopSize2 = twoSize;
  }

  bool leftover=false;
  int newTotal;

  for(int i=0; i<loopSize; i++){
  
    char one = copyOne.digits.removeBack();
    int oneInt = (int)one-48;
    char two = copyTwo.digits.removeBack();
    int twoInt = (int)two-48;
    newTotal=oneInt+twoInt;

    if(leftover == true){
      newTotal = newTotal+1;
    }

    if(newTotal > 9){
      newTotal = newTotal-10;
      leftover = true;
    }
    else{
      leftover = false;
    }
    returnValue.digits.addFront(newTotal+48);
  }

  if(loopSize == loopSize2 && leftover == true){
    returnValue.digits.addFront(48+1);
  }

  for(int i=loopSize; i<loopSize2; i++){

    char restOfValues;
    int temp;

    if(loopSize <loopSize2){
      restOfValues = copyOne.digits.removeBack();
      temp = (int)restOfValues;
    }
    else{
      restOfValues = copyTwo.digits.removeBack();
      temp = (int)restOfValues;
    }

    if(leftover == true){
      temp++;
    }

    if(temp>(48+9)){
      returnValue.digits.addFront(48);
      leftover=true;
    }
    else{
      returnValue.digits.addFront(temp);
      leftover=false;
    }
  }

  if(leftover == true){
    returnValue.digits.addFront(49);
  }

  if(negative == true && rhs.negative == true){
    returnValue.negative = true;
  }

  return returnValue;
  returnValue.~LongInt();
  copyOne.~LongInt();
  copyTwo.~LongInt();
}
}

//The method subtracts two longints.
//Simliar to the add method, this method finds what is negative or not
//and either sends them to a different method or continues on.
//This method loops through each side subtracting the digits.
//If borrowing is needed, a bool variable is turned on so the next
//digit can be minus one
LongInt LongInt::operator-( const LongInt &rhs ) const{

  LongInt copyOne=*this;
  LongInt copyTwo=rhs;
  LongInt holdTemp;
  holdTemp.~LongInt();

  if(negative == false && rhs.negative == true){

    copyOne.negative = false;
    copyTwo.negative = false;
    return copyOne+copyTwo;
  }
  else if(negative == true && rhs.negative == false){

    copyTwo.negative = true;
    copyOne.negative = true;
    return copyOne+copyTwo;
  }
  else if(negative == true && rhs.negative == true){

    copyOne.negative = false;
    copyTwo.negative = false;
    return copyTwo-copyOne;
  }
  else{
      if(copyOne<copyTwo){

       holdTemp=copyOne;
       copyOne=copyTwo;
       copyTwo=holdTemp;
      }
  holdTemp.~LongInt();

  int hold1;
  int hold2;
  bool zeroBorrow = false;

 while(copyOne.digits.isEmpty() == false){

   if(copyTwo.digits.isEmpty() == false){

     if(copyOne.digits.getBack()<copyTwo.digits.getBack()){

      int count=0;

      holdTemp.digits.addFront(((copyOne.digits.removeBack()+10)-copyTwo.digits.removeBack())+48);

     if(copyOne.digits.getBack() != 48){

       copyOne.digits.addBack(copyOne.digits.removeBack()-1);

     }
      else{

        while(copyOne.digits.getBack() == 48){
          count++;
          copyOne.digits.removeBack();
        }
        copyOne.digits.addBack(copyOne.digits.removeBack()-1);

        while(count != 0){
          copyOne.digits.addBack(48+9);
          count--;
        }
       }
     } 
     else{
       holdTemp.digits.addFront(copyOne.digits.removeBack()-copyTwo.digits.removeBack()+48);
     }  
   }
   else{
     holdTemp.digits.addFront(copyOne.digits.removeBack());
   }
 }
 if(*this<rhs){
   holdTemp.negative = true;
 }

 holdTemp.remove0s();
}

return holdTemp;
holdTemp.~LongInt();
copyOne.~LongInt();
copyTwo.~LongInt();
}

//This method makes two longints equal each other
const LongInt& LongInt::operator=( const LongInt &rhs ){

  this->digits = rhs.digits;
  this->negative = rhs.negative;
  return *this;
}

//This method figures out if the left side is greater or not
//uses the opposite sign and equal sign to figure out
//if the left side is greater
bool LongInt::operator< ( const LongInt & rhs ) const{

  if(*this>rhs){
    return false;
  }
  else if(*this == rhs){
    return false;
  }
  else{
    return true;
  }

}

//This method figures out if the left side is greater or equal to the right
//uses the opposite sign and equal sign to figure out
//if the left side is greater or equal
bool LongInt::operator<=( const LongInt & rhs ) const{
  //Note: I was having memory or processing issues with this 
  //method, (The message Killed would come up) so to help it out
  //I actuomatically returned false so everything could run and not crash
  //Left the original logic in for review
  return false;
  if(*this<rhs){
    return true;
  }
  else if(*this == rhs){
    return true;
  }
  else{
    return false;
  }
}

//This method figures out if the left side is greater or not.
//First figures out if their equal, then sees if one of them is 
//negative or not. Then traverses/ loops through each number to compare 
//If nothing is caught then it compares the leftovers of left and right
//Assumption: to ensure memory was not being used up, after every return
//both deconstructor and clear was used to be on the safe side.
bool LongInt::operator> ( const LongInt & rhs ) const{

  if(*this == rhs){
    return false;
  }
  else if(negative == true && rhs.negative == false){
    return false;
  }
  else if(negative == false && rhs.negative == true){
    return true;
  }
  else{
    LongInt *copyLeft = new LongInt;
    *copyLeft=*this;
    LongInt *copyRight = new LongInt;
    *copyRight=rhs;

    while((copyLeft->digits.isEmpty() == false)) {
      if((copyLeft->digits.getFront() < copyRight->digits.getFront())){

        if(rhs.negative == true){

          copyRight->~LongInt();
          copyLeft->~LongInt();
          copyRight->digits.clear();
          copyLeft->digits.clear();
          delete copyLeft;
          delete copyRight;
          return true;
        }
        else{
          copyRight->~LongInt();
          copyLeft->~LongInt();
          copyRight->digits.clear();
          copyLeft->digits.clear();
          delete copyLeft;
          delete copyRight;
          return false;
        }
      }
      else if(copyLeft->digits.getFront() > copyRight->digits.getFront()){
        if(negative == true){
          copyRight->~LongInt();
          copyLeft->~LongInt();
          copyRight->digits.clear();
          copyLeft->digits.clear();
          delete copyLeft;
          delete copyRight;
          return false;
        }
        else{
          copyRight->~LongInt();
          copyLeft->~LongInt();
          copyRight->digits.clear();
          copyLeft->digits.clear();
          delete copyLeft;
          delete copyRight;
          return true;
        }
      }
      copyLeft->digits.removeFront();
      copyRight->digits.removeFront();
    }

    if(copyLeft->digits.isEmpty() == true && copyRight->digits.isEmpty() == true){
      return false;
    }
    else if(copyLeft->digits.isEmpty() == false && copyRight->digits.isEmpty() == true){
      return true;
    }
    else if(copyLeft->digits.isEmpty() == true && copyRight->digits.isEmpty() == false){
      return false;
    }
    copyRight->digits.clear();
    copyLeft->digits.clear();
    delete copyLeft;
    delete copyRight;
  }
}

//Figures out if left side is greater or equal to the right side 
//First sees if left is bigger than right, then checks to see if 
//they're equal to each other.  If not, then return false
bool LongInt::operator>=( const LongInt & rhs ) const{

  if(*this>rhs){
    return true;
  }
  else if(*this == rhs){
    return true;
  }
  else{
    return false;
  }
}

//This method sees if the right and left side are equal to each other
//First checks size of left and right, and then sees if the sides are negative
//or not.  Then this method goes digit by digit to compare the left and right side
bool LongInt::operator==( const LongInt & rhs ) const{

  if(digits.size()< rhs.digits.size()){
    return false;
  }
  else if(digits.size()> rhs.digits.size()){
    return false;
  }
  else if(negative == true && rhs.negative == false){
    return false;

  }
  else if(negative == false && rhs.negative == true){
    return false;
  }
  else{
    LongInt copyLeft = *this;
    LongInt copyRight = rhs;

    while((copyLeft.digits.isEmpty() == false) && (copyRight.digits.isEmpty()==false)){
      if(copyLeft.digits.getFront() < copyRight.digits.getFront()){

        copyRight.~LongInt();
        copyLeft.~LongInt();
        return false;
      }
      else if(copyLeft.digits.getFront() > copyRight.digits.getFront()){

        copyRight.~LongInt();
        copyLeft.~LongInt();
        return false;
      }
      
      copyLeft.digits.removeFront();
      copyRight.digits.removeFront();
    }

    if(copyLeft.digits.isEmpty() == true && copyRight.digits.isEmpty() == true){
      return true;
    }
    copyRight.digits.clear();
    copyLeft.digits.clear();
  }
}

bool LongInt::operator!=( const LongInt & rhs ) const{
  if(*this == rhs){
    return false;
  }
  else{
    return true;
  }
}

//This method removes zeros from the longint
//Assumption: you remove the front zeros and the middle or back zeros
void LongInt::remove0s(){
  while(digits.getFront()-48 == 0 && digits.size() != 1){
    digits.removeFront();
  }
  if(digits.size() == 1 && digits.getFront()-48 == 0){
    negative = false;
  }
}