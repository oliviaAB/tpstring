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
  string my_string= string("Google");
  my_string.display();

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

  


  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

