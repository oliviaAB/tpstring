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

//Constructs an empty string, with a length of zero characters.
string::string(void)
{
	character = NULL;
	length_=0;
	capacity_=0;
}

//Constructs a copy of str.
string::string(const string& str) 
{
  character = new char[str.get_length_()+1];  
  length_ =  str.get_length_();
  capacity_ = str.capacity();
  size_t i;
  for (i=0; i<str.get_length_(); i++)
  {
	character[i]=str.character[i];
  }
  character[i+1]='\0';
}


//Copies the null-terminated character sequence (C-string) pointed by s.
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

//-----------------------------------------------------------
//                       EMPTY
//-----------------------------------------------------------
// Test if string is empty or not
bool string::empty(void) const
{
	bool isempty = 1;
	if(length_ == 0)
	{
		isempty= 0;
	} 
	return isempty;
}

//-----------------------------------------------------------
//                       C_STR
//-----------------------------------------------------------

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
//display the character chain
void string::display(void)
{
	 size_t i=0;
	 for(i=0;i<length_;i++)
	 {
	 	printf("%c", character[i]);
	 }
	 printf("\n");
}
//-----------------------------------------------------------
//                       GETTERS
//-----------------------------------------------------------
char* string::get_character(void) const
{
	return character;
}

size_t string::get_length_(void) const
{
    return length_;
}



//-----------------------------------------------------------
//                       CAPACITY
//-----------------------------------------------------------
// Return size of allocated storage
size_t string::capacity(void) const
{
	return capacity_;
}

//-----------------------------------------------------------
//                       LENGTH
//-----------------------------------------------------------
// Return length of string
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

//-----------------------------------------------------------
//                       RESERVE
//-----------------------------------------------------------
//Request a change in capacity
void string::reserve (size_t n)
{
	if(capacity_<n)
	{
		char* new_char=new char[n];
		size_t i=0;
		for(i=0;i<=length_;i++)
		{
			new_char[i]=character[i];
		}
		delete character;
		character=new_char;
		capacity_ = n;
	}
}

//-----------------------------------------------------------
//                       SIZE
//-----------------------------------------------------------
//Return length of string

size_t string::size() const 
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

//-----------------------------------------------------------
//                       CLEAR
//-----------------------------------------------------------
// Clear string

void string::clear() 
{
  character = NULL;
  length_=0;
  capacity_=0;
}

//-----------------------------------------------------------
//                       MAX_SIZE
//-----------------------------------------------------------
// Returns the maximum length the string can reach

size_t string::max_size() const
{
	return MAX_SIZE;
}

//-----------------------------------------------------------
//                       OPERATOR []
//-----------------------------------------------------------
//Returns a reference to the character at position pos in the string.

char& string::operator[] (size_t pos)
{
	if(pos>length_)
	{
		printf("position superior to length_.\n");
	}  
	return character[pos-1];
}

//-----------------------------------------------------------
//                       OPERATOR=
//-----------------------------------------------------------
//Assigns a new value to the string, replacing its current contents.
string& string::operator=(const string& str)
{

	character=NULL;
	if(str.length()<MAX_SIZE)
	{
		character= new char[str.get_length_()+1];  
		length_ =  str.get_length_();
		capacity_ = str.capacity();
		size_t i;
		for (i=0; i<str.get_length_(); i++)
		{
			character[i]=str.character[i];	
  		}
  		character[i+1]='\0';
	}else
	{
		character= new char[MAX_SIZE];  
		length_ =MAX_SIZE-1;
		capacity_ = MAX_SIZE;
		size_t i;
		for (i=0; i<(MAX_SIZE-1); i++)
		{
			character[i]=str.character[i];	
  		}
  		character[i+1]='\0';
	}



  	return *this;
}

//-----------------------------------------------------------


string& string::operator= (const char* s)
{
  string* my_string=new string(s);
  *this=*my_string;  
  return *this;
}

//-----------------------------------------------------------


string& string::operator= (char c)	
{

  string* my_string=new string(&c);
  *this=*my_string;  
  return *this;
}

//-----------------------------------------------------------
//                       OPERATOR+
//-----------------------------------------------------------
//Returns a newly constructed string object with its value
//being the concatenation of the characters in lhs followed by those of rhs.


string& string::operator+ (char c)
{
   size_t totalLength= length_ + 2;
   size_t i;
   char* my_chain= new char[totalLength]; 

  for(i=0; i<length_; i++)
  {
	my_chain[i]=character[i];	
  }
   
  my_chain[length_]=c; 
  my_chain[length_ + 1]='\0';
  string* my_string =new string(my_chain);
  //my_string.display();
  //printf("operateur +%ld\n",my_string.length());
  return *my_string;
}

//-----------------------------------------------------------

string& string::operator+ (const string& str)
{
	printf("Balise\n");
	char* tab = new char;
	size_t o;
	o=0;

	for(o=0;o<length_;o++)
	{
		tab[o]=character[o];
	}

	size_t i;

	for(i=0;i<str.length();i++)
	{
		tab[o]=str.get_character()[i];
		o++;
	}


	tab[o]='\0';
	string* my_string =new string(tab);
	delete tab;
	my_string->display();
	return *my_string;
}

//-----------------------------------------------------------

string& string::operator+ (const char* s)
{
	size_t s_size=0;

	while(s[s_size]!='\0')
	{
		s_size++;
	}

	char* new_char=new char[s_size+length_+1];

	size_t i=0;
	size_t o=0;
	
	for(o=0;o<length_;o++)
	{
		new_char[o]=character[o];
	}


	for(i=0;i<s_size;i++)
	{
		new_char[o]=s[i];
		o++;
	}
	new_char[o]='\0';
	string* string_return=new string(new_char);
	//string_return.display();

	return *string_return;
}

//-----------------------------------------------------------
/*
string operator+(const string& lhs, char rhs)
{
   size_t totalLength;
   totalLength = lhs.length() + 1;
   size_t i;
   char* my_chain= new char[totalLength+1]; 
   for(i=0; i<lhs.length(); i++)	
  {
	my_chain[i]=lhs.get_character()[i];
  }
   
  my_chain[lhs.length()]=rhs; 
  my_chain[lhs.length() + 1]='\0';
  string my_string = string(my_chain);
  return my_string;
  
}

//-----------------------------------------------------------

string operator+ (const char*   lhs, const string& rhs)
{
	size_t lhs_size=0;
	while(lhs[lhs_size]!='\0')
	{
		lhs_size++;
	}


	char* new_char=new char[lhs_size+rhs.length()];

	size_t i=0;

	for(i=0;i<lhs_size;i++)
	{
		new_char[i]=lhs[i];
	}

	size_t o=0;
	printf("%ld\n",rhs.length());
	for(o=0;o<rhs.length();o++)
	{
		new_char[i]=rhs.get_character()[o];
		i++;
		printf("%c\n",new_char[i]);
	}

	new_char[i+1]='\0';

	string string_return=string(new_char);
	string_return.display();

	return string_return;
}

//-----------------------------------------------------------

string operator+( string& lhs,  string& rhs)
{
	char* tab = new char;
	size_t o;
	o=0;
	while(lhs.get_character()[o] != '\0')
	{
		tab[o] = lhs.get_character()[o];
		o++;
	}
	size_t i = 0;
	while(rhs.get_character()[i] != '\0')
	{
		tab[o] = rhs.get_character()[i];
		o++;
		i++;
	}

	tab[o+1]='\0';
	string my_string = string(tab);
	delete tab;
	return my_string;
}

*/
//-----------------------------------------------------------
//                       RESIZE
//-----------------------------------------------------------
//Resizes the string to a length of n characters.
//If n is smaller than the current string length, the current value
//is shortened to its first n character, removing the characters beyond the nth.
//If n is greater than the current string length, the current
//content is extended by inserting at the end as many characters as
//needed to reach a size of n. If c is specified, the new elements are initialized 
//as copies of c, otherwise, they are value-initialized characters (null characters).

void string::resize (size_t n)
{
	if(n<=length_)
	{	
		character[n]='\0';
		length_=n;
	}
	else
	{
		if(capacity_<n)
		{
			char* char_new=new char[n];
			size_t i=0;
			for(i=0;i<=length_;i++)
			{
				char_new[i]=character[i];
			}
			for(i=length_+1;i<n;i++)
			{
				char_new[i]=' ';
			}

			capacity_=n;
			delete character;
			character=char_new;
		}

	}
}


//-----------------------------------------------------------
//                       AT
//-----------------------------------------------------------
//Returns a reference to the character at position pos in the string.

char& string::at (size_t pos)
{

	if(pos>length_)
	{
		printf("position superior to length_.\n");
	}  
	return character[pos-1];
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================

	
