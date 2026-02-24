/* Taha Waseem L1F24BSCS0466
Fall 2025 OOP Section C20 Assignment TWO
File: ClassName.cpp (Contains Some helper functions ad class functions definition)
 Write a complete program that reads a complete sentence from a text (get file path from the user) in a 
one-dimensional array and does some processing on the sentence. The program should provide the 
following menu option to utilize various functions of the program: 
R - Read Sentence from a test file 
D – Display Sentence (store in an array) on Screen 
W – Write Sentence (store in an array) in a text file (get the file path from the user) 
U – Convert all characters of the Sentence to UPPERCASE and display on screen 
L – Convert all characters of the Sentence to lowercase and display on screen 
S – Search is a given word is in the sentence or not (get the word from user) 
F – Calculate Frequencies of Each word in the Sentence and display on screen 
C – Compare 2 Sentences store in 2 text files and display common and uncommon words 
T – Concatenate 2 Sentences store in 2 text files, display the concatenated Sentence on screen and write 
in a file (get file path from user) 
E – Exit the program 
In any other option is selected repeat the menu 
*/
#include<iostream>
#include"ClassName.h"
using namespace std;
// These functions assist us the inside working of class functions 
static void myCopy(char dest[], const char src[], int size)
{
    int i = 0;
    while (i < size - 1 && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
static char Upper(char c)
{
    if (c >= 'a' && c <= 'z') 
        return c - 'a' + 'A';
    return c;
}
static char Lower(char c)
{
    if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    return c;
}
static bool isBreak(char c)
{
    if (c == ' ' || c == '\t' || c == '\n') 
        return true;

    char p[] = ".,;:!?\"()[]{}<>/-_";
    for (int i = 0; p[i] != '\0'; i++)
        if (p[i] == c)
            return true;

    return false;
}
static int myCmp(const char a[], const char b[])
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i]) return a[i] - b[i];
        i++;
    }
    return a[i] - b[i];
}

// Class functions Definitions
Sentence::Sentence()      // default constructor
{
    text[0] = '\0';
    length = 0;
    wordCount = 0;
}
Sentence::Sentence(const char src[])  // Parametrized constructor
{
    int i = 0;
    while (src[i] != '\0' && i < MaxChars - 1)
    {
        text[i] = src[i];
        i++;
    }
    text[i] = '\0';
    length = i;
    wordCount = 0;
}


Sentence::Sentence(const Sentence& obj)     // deep copy of private attributes of class
{
    myCopy(text, obj.text, MaxChars);
    length = obj.length;
    wordCount = obj.wordCount;

    for (int i = 0; i < wordCount; i++)
        myCopy(words[i], obj.words[i], MaxWordLen);
}


void Sentence::setText(const char src[])
{
    int i = 0;
    while (src[i] != '\0' && i < MaxChars - 1)
    {
        text[i] = src[i];
        i++;
    }
    text[i] = '\0';
    length = i;
    wordCount = 0; 
}

void Sentence::getText(char dest[]) const
{
    myCopy(dest, text, MaxChars);
}

int Sentence::getLength() const
{ 
    return length; 
}

int Sentence::getWordCount() const 
{
    return wordCount; 
}

void Sentence::convertUpper()
{
    for (int i = 0; i < length; i++)
        text[i] = Upper(text[i]);
}

void Sentence::convertLower()
{
    for (int i = 0; i < length; i++)
        text[i] = Lower(text[i]);
}

void Sentence::splitWords()
{
   wordCount = 0;

  int i = 0;
  while (i < length && wordCount < MaxWords)
    {
      while (i < length && isBreak(text[i]))
      {
            i++;
        }
      if (i >= length)
      {
          break;
      }

        int j = 0;
        while (i < length && !isBreak(text[i]) && j < MaxWordLen - 1)
        {
            words[wordCount][j++] = Lower(text[i++]);
        }
        words[wordCount][j] = '\0';
        wordCount++;
    }
}
bool Sentence::searchWord(const char target[], int& index) const
{
    char t[MaxWordLen];
    int i = 0;

    while (target[i] != '\0' && i < MaxWordLen - 1)
    {
      t[i] = Lower(target[i]);
     i++;

}
   t[i] = '\0';

  for (int w = 0; w < wordCount; w++)
         if (myCmp(words[w], t) == 0)
            {
                index = w;
                return true;
            }

        index = 0;  
        return false;
    }


 void Sentence::calculateFrequencies(int freq[]) const
    {
     for (int i = 0; i < wordCount; i++)
     {
         freq[i] = 0;
     }

        for (int i = 0; i < wordCount; i++)
        {
            if (freq[i] != 0) continue;

            int count = 1;

            for (int j = i + 1; j < wordCount; j++)
                if (myCmp(words[i], words[j]) == 0)
                    count++, freq[j] = -1;

            freq[i] = count;
        }
    }

    void Sentence::getWord(int index, char dest[]) const
    {
        if (index < 0 || index >= wordCount)
            dest[0] = '\0';
        else
            myCopy(dest, words[index], MaxWordLen);
    }
