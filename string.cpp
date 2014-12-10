//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "string.h"




//############################################################################
//                                                                           #
//                           Class string                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
size_t string::MAX_SIZE=100;

string::string(void)
{
	character = NULL;
	//character[0]='T';
	//character[1]='O';
	//character[2]='T';
	//character[3]='O';
	//length=4;
	//capacity=4;
	length_=0;
	capacity_=0;
}

string::string(const string& str)  //Build copy constructor
{
  character = new char[str.get_length_()+1];  
  length_ =  str.get_length_();
  capacity_ = str.get_capacity_();
  size_t i;
  for (i=0; i<str.get_length_(); i++)
  {
	character[i]=str.character[i];
  }
  character[i+1]='\0';
}

//-----------------------------------------------------------
//                 CONSTRUCTOR WITH A C-STRING
//-----------------------------------------------------------
//if the input c-string is too long, copy only the MAX_SIZE
//first characters, and print an error message

string::string(const char* sentence)
{
	size_t i=0;

//Calculate the number of character in sentence
	while(sentence[i]!='\0' && i<(MAX_SIZE-1))
	{
		i++;
	}

//If sentence is too long: error message
	if(i==(MAX_SIZE-1))
	{
		printf("Your string is too long, MAX_SIZE=%ld, only %ld characters\n", MAX_SIZE, (MAX_SIZE-1));
	}
// length is equal to the number of apparent characters (without \0) 
// capacity is equal to the actually allocated memory 
	character=new char[i+1];
	length_= i;
	capacity_= i+1;

//Copy characters of sentence into character
	for(i=0;i<=length_;i++)
	{
		character[i]=sentence[i];
	}

//Add '\0' at the end of the string
	character[i+1]='\0';
}



// ===========================================================================
//                                  Destructor
// ===========================================================================
string::~string(void)
{
	delete character;
	character = NULL;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================


// test if string is empty or not
int string::empty(size_t strlength)
{
	int isempty = 1;
	if(strlength == 0)
	{
		isempty= 0;
	} 
	return isempty;
}


const char* string::c_str() const
{
  char* char_return = new char[length_ +1];
  size_t i;
  for (i=0; i<length_; i++)
  {
	char_return[i]=character[i];
  }
  char_return[i+1]='\0';
  return char_return;
}
//-----------------------------------------------------------
//                       DISPLAY
//-----------------------------------------------------------

void string::display(void)
{
	 size_t i=0;
	 for(i=0;i<length_;i++)
	 {
	 	printf("%c", character[i]);
	 }
	 printf("\n");
}

char* string::get_character(void) const
{
	return character;
}

size_t string::get_length_(void) const
{
    return length_;
}

size_t string::get_capacity_(void) const
{
	return capacity_;
}

size_t string::length() const 
{
	size_t i=0;
	while(character[i]!='\0')
	{
		i++;
	}

	if(i>=MAX_SIZE)
	{
		printf("Your string is too long, MAX_SIZE= %ld\n", MAX_SIZE);
	}

	return i;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
