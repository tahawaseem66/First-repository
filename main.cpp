/*
Taha Waseem L1F24BSCS0466
Fall 2025 OOP Section C20 Assignment TWO
File : main.cpp(Contains main code  Only)
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
#include <iostream>
#include <fstream>
#include"ClassName.h"
#include"functions.h"
using namespace std;
void showMenu()
{
    cout << "\n===== MENU =====\n";
    cout << "R - Read sentence from file\n";
    cout << "D - Display sentence\n";
    cout << "W - Write sentence to file\n";
    cout << "U - Convert to UPPERCASE\n";
    cout << "L - Convert to lowercase\n";
    cout << "S - Search word\n";
    cout << "F - Word frequencies\n";
    cout << "C - Compare two sentences\n";
    cout << "T - Concatenate two sentences\n";
    cout << "E - Exit\n";
    cout << "=================\n";
}
int main()
{
     Sentence s;
    char option;
  bool running = true;
 while (running)
  {
      showMenu();
        cout << "Choose option: ";
        cin >> option;
       cin.ignore(1000, '\n');

  if (option == 'R' || option == 'r')
     {
           char path[260];
           cout << "Enter file path: ";
        readLineFromStdin(path, 260);

        if (!ReadSentenceFromFile(s, path))
        {
            cout << "Could not read file.\n";
        }
             else
                {
                  s.splitWords();   
                 cout << "File loaded.\n";
                }
            }

            else if (option == 'D' || option == 'd')
            {
                DisplaySentence(s);
            }

            else if (option == 'W' || option == 'w')
            {
                char path[260];
                cout << "Enter output file path: ";
                readLineFromStdin(path, 260);

                if (!WriteSentenceToFile(s, path))
                    cout << "Could not write file.\n";
                else
                    cout << "Sentence saved.\n";
            }

            else if (option == 'U' || option == 'u')
            {
                s.convertUpper();
                s.splitWords();
                DisplaySentence(s);
            }

            else if (option == 'L' || option == 'l')
            {
                s.convertLower();
                s.splitWords();     
                DisplaySentence(s);
            }

            else if (option == 'S' || option == 's')
            {
                char w[MaxWordLen];
                cout << "Enter word: ";
                cin >> w;

                int index = 0;     
                bool found = s.searchWord(w, index);

                if (found)
                    cout << "Found at index: " << index << endl;
                else
                    cout << "Word not found.\n";
            }

            else if (option == 'F' || option == 'f')
            {
                int freq[MaxWords];
                s.calculateFrequencies(freq);

                cout << "\nWord frequencies:\n";
                for (int i = 0; i < s.getWordCount(); i++)
                {
                    if (freq[i] > 0)
                    {
                        char w[MaxWordLen];
                        s.getWord(i, w);
                        cout << w << " : " << freq[i] << endl;
                    }
                }
            }

            else if (option == 'C' || option == 'c')
            {
                char p1[260], p2[260];
                cout << "Enter first file: ";
                readLineFromStdin(p1, 260);
                cout << "Enter second file: ";
                readLineFromStdin(p2, 260);

                Sentence s1, s2;
                if (ReadSentenceFromFile(s1, p1) && ReadSentenceFromFile(s2, p2))
                {
                    s1.splitWords();   
                    s2.splitWords();   
                    CompareSentences(s1, s2);
                }
                else
                    cout << "Error reading files.\n";
            }

            else if (option == 'T' || option == 't')
            {
                char p1[260], p2[260], out[260];
                cout << "Enter first file: ";
                readLineFromStdin(p1, 260);
                cout << "Enter second file: ";
                readLineFromStdin(p2, 260);

                Sentence s1, s2, r;
                if (ReadSentenceFromFile(s1, p1) && ReadSentenceFromFile(s2, p2))
                {
                    s1.splitWords();     
                    s2.splitWords();   
                    ConcatSentences(s1, s2, r);
                    r.splitWords();      

                    cout << "Concatenated:\n";
                    DisplaySentence(r);

                    cout << "Save to file: ";
                    readLineFromStdin(out, 260);
                    WriteSentenceToFile(r, out);
                }
                else
                    cout << "Error reading files.\n";
            }

            else if (option == 'E' || option == 'e')
            {
                running = false;
            }

            else
            {
                cout << "Invalid option.\n";
            }
        }

        return 0;
    }
