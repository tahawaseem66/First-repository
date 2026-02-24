/*
Taha Waseem L1F24BSCS0466
Fall 2025 OOP Section C20 Assignment TWO
File : ClassName.h(Contains class member functions prototype)
Write a complete program that reads a complete sentence from a text(get file path from the user) in a
one - dimensional array and does some processing on the sentence.The program should provide the
following menu option to utilize various functions of the program :
R - Read Sentence from a test file
D – Display Sentence(store in an array) on Screen
W – Write Sentence(store in an array) in a text file(get the file path from the user)
U – Convert all characters of the Sentence to UPPERCASE and display on screen
L – Convert all characters of the Sentence to lowercase and display on screen
S – Search is a given word is in the sentence or not (get the word from user)
F – Calculate Frequencies of Each word in the Sentence and display on screen
C – Compare 2 Sentences store in 2 text files and display common and uncommon words
T – Concatenate 2 Sentences store in 2 text files, display the concatenated Sentence on screen and write
in a file(get file path from user)
E – Exit the program
In any other option is selected repeat the menu
*/
#pragma once
const int MaxChars = 1000;    // These constants are used to intilize the size . It should be ajustable  
const int MaxWords = 200;    
const int MaxWordLen = 80;


class Sentence 
{
private:

    char text[MaxChars];

    int length;

    char words[MaxWords][MaxWordLen];

    int wordCount;


public:

    Sentence();                         // default constructor
    Sentence(const char src[]);         // parameterized constructor
    Sentence(const Sentence& other);    // copy constructor

    void setText(const char src[]);
    void getText(char dest[]) const;

    void convertUpper();
    void convertLower();

    void splitWords();
    bool searchWord(const char target[],int &index) const;
    void calculateFrequencies(int freq[]) const;

    void getWord(int index, char dest[]) const;
    int getWordCount() const;
    int getLength() const;



};
