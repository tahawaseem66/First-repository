/*
Taha Waseem L1F24BSCS0466
Fall 2025 OOP Section C20 Assignment TWO
File: functions.cpp (Contains global functions definition)
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

#include <iostream>
#include <fstream>
#include"ClassName.h"
#include"functions.h"
using namespace std;

static bool readWholeFile(const char path[], char dest[], int max)  // Read the whole file
{
    ifstream fin(path);
    if (!fin) return false;

    int i = 0;
    char ch;
    while (fin.get(ch) && i < max - 1)
    {
        if (ch == '\r')
            continue;
        if (ch == '\n')
            ch = ' ';
        dest[i++] = ch;
    }
    dest[i] = '\0';
    return true;
}

// write to file
static bool writeFile(const char path[], const char buffer[])
{
    ofstream fout(path);
    if (!fout) 
        return false;

    int i = 0;
    while (buffer[i] != '\0')
        fout.put(buffer[i++]);

    return true;
}

void readLineFromStdin(char dest[], int max) 
{
    int i = 0;
    char ch;
    while (i < max - 1 && cin.get(ch))
    {
        if (ch == '\n') break;
        dest[i++] = ch;
    }
    dest[i] = '\0';
}

bool ReadSentenceFromFile(Sentence& s, const char filepath[])
{
    char buffer[MaxChars];
    if (!readWholeFile(filepath, buffer, MaxChars)) 
    {
        return false;
    }

    s.setText(buffer);
    return true;
}

void DisplaySentence(const Sentence& s)
{
    char buffer[MaxChars];
    s.getText(buffer);
    cout << buffer << endl;
}

bool WriteSentenceToFile(const Sentence& s, const char filepath[])
{
    char buffer[MaxChars];
    s.getText(buffer);
    return writeFile(filepath, buffer);
}

void CompareSentences(const Sentence& s1, const Sentence& s2)    // Compare the similarities
{
    int w1 = s1.getWordCount();
    int w2 = s2.getWordCount();

    cout << "\nCommon Words:\n";
    bool found = false;

    for (int i = 0; i < w1; i++)
    {
        char a[MaxWordLen];
        s1.getWord(i, a);

        for (int j = 0; j < w2; j++)
        {
            char b[MaxWordLen];
            s2.getWord(j, b);

            int k = 0;
            bool same = true;
            while (a[k] != '\0' || b[k] != '\0')
            {
                if (a[k] != b[k]) { same = false; break; }
                k++;
            }
            if (same)
            {
                cout << "- " << a << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) cout << "None\n";

    cout << "\nWords only in first sentence:\n";
    bool only1 = false;

    for (int i = 0; i < w1; i++)
    {
        char a[MaxWordLen];
        s1.getWord(i, a);
        bool exists = false;

        for (int j = 0; j < w2; j++)
        {
            char b[MaxWordLen];
            s2.getWord(j, b);

            int k = 0;
            bool same = true;
            while (a[k] != '\0' || b[k] != '\0')
            {
                if (a[k] != b[k]) 
                {
                    same = false; 
                    break;
                }
                k++;
            }
            if (same) 
            { 
                exists = true; break;
            }
        }

        if (!exists)
        {
            cout << "- " << a << endl;
            only1 = true;
        }
    }

    if (!only1) cout << "None\n";

    cout << "\nWords only in second sentence:\n";
    bool only2 = false;

    for (int j = 0; j < w2; j++)
    {
        char b[MaxWordLen];
        s2.getWord(j, b);
        bool exists = false;

        for (int i = 0; i < w1; i++)
        {
            char a[MaxWordLen];
            s1.getWord(i, a);

            int k = 0;
            bool same = true;
            while (a[k] != '\0' || b[k] != '\0')
            {
                if (a[k] != b[k]) { same = false; break; }
                k++;
            }
            if (same)
            { 
                exists = true; 
                break;
            }
        }

        if (!exists)
        {
            cout << "- " << b << endl;
            only2 = true;
        }
    }
    if (!only2) 
        cout << "None\n";
}

void ConcatSentences(const Sentence& s1, const Sentence& s2, Sentence& dest)
{
    char a[MaxChars], b[MaxChars], r[MaxChars];
    s1.getText(a);
    s2.getText(b);

    int i = 0, j = 0;

    while (a[j] != '\0' && i < MaxChars - 1)
        r[i++] = a[j++];

    if (i > 0 && r[i - 1] != ' ')
        r[i++] = ' ';

    j = 0;
    while (b[j] != '\0' && i < MaxChars - 1)
        r[i++] = b[j++];

    r[i] = '\0';
    dest.setText(r);
}