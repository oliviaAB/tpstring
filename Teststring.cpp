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

  //Test for copy constructor (student 1)
  printf("Test copy constructor (student 1)\n");
  string test1=string("Hello");
  string test2=string(test1);
  test2.display();
  printf("\n");

  //Test of c_str (student 1)
  printf("Test function c_str (student 1)\n");
  test1.c_str();
  test1.display();
  printf("\n");

  //Test of size (student 1)
  printf("Test function size (student 1)\n");
  printf("test1 size %ld\n", test1.size());
  printf("\n");

  //test function clear (student 1)
  printf("Test function clear (student 1)\n");
  test1.clear(); 
  test1.display(); 
  printf("\n");

  //test function operator= (student 1)
  printf("Test function operator= (student 1)\n");
  string test3=string("World");
  test3=test2;  
  test3.display(); 
  printf("\n");

  //Test operator+ (student 1)
  printf("Test function operator+ (student 1)\n");
  test3=test2+'a';
  test3.display(); 
  printf("\n");

  //Test for constructor with a c-string (student 2)
  printf("Test copy constructor (student 1)\n");
  string my_string1=string("Hello");
  my_string1.display();
  printf("\n");

  //Test of size (student 2)
  printf("Test function length (student 2)\n");
  printf("my_string1 length %ld\n", my_string1.length());
  printf("\n");

  //Test of max_size (student 2)
  printf("Test function max_size (student 2)\n");
  printf("my_size %ld\n", my_string1.max_size());
  printf("\n");

  //Test of resize (student 2)
  printf("Test function resize (student 2)\n");
  my_string1.resize(2);
  my_string1.display();
  my_string1.resize(7);
  my_string1.display();
  printf("\n");

  //Test of at (student 2)
  printf("Test function at (student 2)\n");
  string my_string2=string("Google");
  printf("char 3 at Google %c\n", my_string2.at(3));
  printf("\n");

  //test function operator= (student 2)
  printf("Test function operator= (student 2)\n");
  my_string2='c';  
  my_string2.display(); 
  printf("\n");

  //Test operator+ (student 2)
  printf("Test function operator+ (student 2)\n");
  my_string2=my_string2+" world";
  my_string2.display(); 
  printf("\n");

  //Test destructor (student 3)
  printf("Test destructor (student 3)\n");
  string* my_string3=new string("to trash");
  delete my_string3;
  printf("\n");

  //test function capacity (student 3)
  printf("Test function capacity (student 3)\n");
  my_string2.display();
  printf("capacity: %ld\n", my_string2.capacity());
  printf("\n");

  // test method empty (student 3)
  printf("Test function empty (strudent 3)\n");
  bool emptyornot = my_string2.empty();
  printf("%d\n",emptyornot);
  printf("\n");

  // Test reserve (student3)
   printf("Test function reserve\n");
  my_string2.reserve(30);
  printf("capacity: %ld\n", my_string2.capacity());
  printf("\n");

  //Test operator+ (student 3)
  printf("Test function operator+ (student 3)\n");
  my_string2=test1+test1;
  my_string2.display(); 
  printf("\n");


  //test operator=(char*) (student 3)
  printf("Test operator= (student 3)\n");
  char* sentence = "ok";
  my_string2 =sentence;
  my_string2.display();
  printf("\n");


  //test operator+ (student 3)
  printf("Test operator= (student 3)\n");
  my_string2=my_string2+" Google";
  my_string2.display();
  printf("\n");

  //test operator[] (student 3)
  printf("Test operator[] (student 3)\n");
  my_string2.display();
  printf("character 1 in ok Google %c\n", my_string2[1]);
  printf("\n");

  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

