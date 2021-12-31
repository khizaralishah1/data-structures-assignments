#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <string>
#include <unistd.h>
using namespace std;

string name, greetings;

string login();
void welcome(string);
void learnMessage();
string askQuestion(string q, string w="x", int lastPlace=-1);
void showString(int, int, string);
extern void insertWord(string);
extern void showFrequentWords(char, int, string, string[]);
void spaces(int, int, int);

void spaces(int x, int y, int num)
{
    move(x, y);
    for(int i=0; i<num; ++i)
        printw(" ");
    refresh();
}

void showString(int x, int y, string q)
{
    char tp[q.length()+1];
    strcpy(tp, q.c_str());
    move(x, y);
    printw(tp);
    //refresh();
}

string askQuestion(string q, string w, int lastPlace)
{
    string answer;
    string freqWords[3];
    clear();

    int ch = 65;
    int place = 0;
    bool special = false;
    //bool firstBS = false;

    keypad(stdscr,TRUE);
    //int lastEnded = 0;
    int i = 3;
    while(1)
    {
        special = false;
        showString(5, 5, q);
        
        if(w != "x")
        {
            showString(5, 33, w);
            move(5, 33+lastPlace+1+place);
        }
        else
            move(5, 33+place);
        ch = getch();
        spaces(20, 20, 80);
        if(ch == 10) // 10 is ASCII for RET     RN in MAC !!!
        //                              RET
            break;
        else if(ch == 17)
            break;
        else if(ch == 32)
        {
            insertWord(answer);
            lastPlace += answer.length();
            string newAns = askQuestion(q, answer, lastPlace+1);
            insertWord(newAns);
            return answer;
            //answer = "";
            //return answer;
            //askQuestion(q);
        }
        // else if(firstBS && ch == '\b')
        // {
        //     spaces(5, 33+place-1, 5);
        //     answer.pop_back();
        //     continue;
        // }
        else if(ch == '\b' || ch == 127 || ch == 8)
        {
            //firstBS = true;
            --place;
            if(w!="x")
                spaces(5, 33+place+lastPlace+1, 5);
            else
                spaces(5, 33+place, 5);
            answer.pop_back();
            // char newAns[answer.length() - 1];
            // for(int i=0; i<answer.length()-1; ++i)
            // {

            // }
            //showString(1,1, "Haaa");
            //continue;
            // --place;
            // spaces(5, 33+place, 3);
            // if(place == 0)
            // {
            //     answer = "";
            //     continue;
            // }
            // // answer.pop();
            // answer.erase( answer.end()-1 );

            //--place;
            //move(5, 33+place);
            //--place;
            //continue;
            // --place;
        }
        //    .
        //happ
        //happ    

        switch(ch)
        {
            case KEY_UP:
                //move(5,33);
                special = true;
                showString(5, 33, freqWords[0]);
                answer = freqWords[0];
                refresh();
                break;
            case KEY_DOWN:
                //move(5,33);
                special = true;
                showString(5, 33, freqWords[1]);
                answer = freqWords[1];
                refresh();
                break;
            case KEY_LEFT:
                //move(5,33);
                special = true;
                showString(5, 33, freqWords[2]);
                answer = freqWords[2];
                refresh();
                break;
            //case KEY_DOWN:
        }
        
        if(!(ch == 8 || ch == 127) && !special)
            answer.push_back(ch);
        //addch(ch);
        refresh();
        // move(8, 33+place);
        freqWords[0] = "-";
        freqWords[1] = "-";
        freqWords[2] = "-";
        if((ch == 8 || ch == 127))
        {
            showFrequentWords(answer[place-1], place-1, answer, freqWords);
        }
        else
        {
            showFrequentWords(ch, place, answer, freqWords);
            ++place;
        }
        //showString(3, 3+i, answer);
        //i += 6;
        refresh();
        //usleep(500);
        //clear();
    }

    return answer;
}

void learnMessage()
{
    clear();
    mvprintw(2, 20, "I will learn from your behavior");
    refresh();
    sleep(2);
}

string login()
{
    move(5,20);
    printw("Enter a name: ");
  
    int ch = getch();

    while(ch != '\n')
    {
        name.push_back(ch);
        ch = getch();
    }

    clear();
    greetings = "Welcome, " + name + "!";
    return greetings;
}

void welcome(string greetings)
{
    clear();
    
    int len = greetings.length();
    move(5,20);

    int i = 0;

    while(len)
    {   
        addch(greetings[i++]);
        refresh();
        usleep(100000);
        --len;
    }

    usleep(500000);
    clear();
}
