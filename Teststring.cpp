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
  string my_string2=string("");
  string my_string= string("Google");

/*  
  bool emptyornot;
  //test method at (student 2)
  printf("Test function at\n");
  printf("%c, %c\n", my_string.at(1), my_string.at(7));
  printf("\n");

  // test method empty (student 3)
   printf("Test function empty\n");
  emptyornot = my_string.empty();
  printf("%d\n",emptyornot);
  string my_string_copy=string(my_string);
  my_string_copy.display();
  printf("\n");

  //Test for resize (student 2)
   printf("Test function resize\n");
  printf("Length of my_string_copy: %ld\n", my_string.length());
  my_string_copy.resize(4);
  my_string_copy.display();
  printf("Length of my_string_copy: %ld\n", my_string_copy.length());
  printf("\n");

  // Test reserve and capacity (student3)
   printf("Test function capacity\n");
  printf("la capacité de départ est %ld\n", my_string.capacity());
  my_string.reserve(30);
  printf("la capacité après reservation est de  %ld\n",      	my_string.capacity());
  printf("la lettre demandé est %c\n",my_string[8]);
  printf("\n");

  //test operator= (student2)
  printf("Test function operator= (student 2)\n");
  string my_string="Hello";
  string my_string2="World";

  string my_string3="Hello"+my_string2;
  my_string3.display();

  my_string2=my_string;
  my_string2.display();
  printf("\n");
  
*/

  //test function operator= (student 1)
  printf("Test function operator= (student 1)\n");
  my_string2=(my_string);  
  my_string2.display(); 
  printf("\n");

  //Test operator+ (student 1)
  printf("Test function operator+ (student 1)\n");
  my_string2=my_string+'a';
  my_string2.display(); 
  printf("\n");

  //Test operator+ (student 1)
  printf("Test function operator+ (student 2)\n");
  my_string2=my_string+my_string;
  my_string2.display(); 
  printf("\n");

  //test function clear (student 1)
  printf("Test function clear\n");
  my_string.clear(); 
  my_string.display(); 
  printf("\n");


  //test operator=(char*)
  char* sentences = "gogole";
  string operat =(sentences);
  operat.display();
  printf(" capacity is %ld and length is %ld\n", operat.length(), operat.capacity());



  //test operato+(string string)
  string truc= string("Gogogle");
  string myo_string= string("Google");
  string string_operat;
  truc.display();
  my_string.display();
  string test= truc + myo_string;
  test.display(); 
  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

