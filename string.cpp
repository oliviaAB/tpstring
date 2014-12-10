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
int string::MAX_SIZE=100;

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
  int i;
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
	int i=0;

//Calculate the number of character in sentence
	while(sentence[i]!='\0' && i<(MAX_SIZE-1))
	{
		i++;
	}

//If sentence uis too long: error message
	if(i==(MAX_SIZE-1))
	{
		printf("Your string is too long, MAX_SIZE=%d, only %d characters\n", MAX_SIZE, (MAX_SIZE-1));
	}

	character=new char[i];
	length_=i;
	capacity_=i;

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
int string::empty(int strlength)
{
	int isempty = 1;
	if(strlength == 0)
	{
		isempty= 0;
	} 
	return isempty;
}

//-----------------------------------------------------------
//                       DISPLAY
//-----------------------------------------------------------

void string::display(void)
{
	 int i=0;
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

int string::get_length_(void) const
{
    return length_;
}

int string::get_capacity_(void) const
{
	return capacity_;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
