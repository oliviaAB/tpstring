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
	character =new char[4];
	character[0]='T';
	character[1]='O';
	character[2]='T';
	character[3]='O';
	length_=4;
	capacity_=4;
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

//If sentence is too long: error message
	if(i==(MAX_SIZE-1))
	{
		printf("Your string is too long, MAX_SIZE=%d, only %d characters\n", MAX_SIZE, (MAX_SIZE-1));
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

int string::length() const 
{
	int i=0;
	while(character[i]!='\0')
	{
		i++;
	}

	i++;

	if(i>=MAX_SIZE)
	{
		printf("Your string is too long, MAX_SIZE= %d\n", MAX_SIZE);
	}

	return i;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
