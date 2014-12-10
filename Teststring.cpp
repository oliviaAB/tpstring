//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <stdio.h>
#include "string.h"


// ===========================================================================
//                             Include Project Files
// ===========================================================================



// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================








// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  bool emptyornot;
  string my_string2=string("");
  string my_string= string("Google");
  my_string.display();

  //test method at
  printf("%c, %c\n", my_string.at(1), my_string.at(7));

  // test method empty
  emptyornot = my_string.empty();

  printf("%d\n",emptyornot);

  string my_string_copy=string(my_string);
  my_string_copy.display();



//Test for resize
  printf("Length of my_string_copy: %ld\n", my_string.length());
  my_string_copy.resize(4);
  my_string_copy.display();

  printf("Length of my_string_copy: %ld\n", my_string_copy.length());
// Test reserve and capacity 
  printf("la capacité de départ est %ld\n", my_string.capacity());
  my_string.reserve(30);
  printf("la capacité après reservation est de  %ld\n", my_string.capacity());

  printf("la lettre demandé est %c\n",my_string[8]);
  //test function clear
  my_string.clear(); 
  my_string.display(); 

  my_string2=(my_string);  //test function operator=
  my_string2.display();

  my_string.clear(); //test function clear
  my_string.display();  //test function clear

  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

