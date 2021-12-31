#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <string>
#include <unistd.h>
//#include "list.h"
using namespace std;

extern string login();
extern void welcome(string);
extern void learnMessage();
extern string askQuestion(string, string w="x", int lastPlace=-1);
extern void insertWord(string);
extern void giveHints(char);

int main()
{
    initscr();
    
    //welcome(login());
    //learnMessage();


   // cout << askQuestion("How are you feeling today? "
    insertWord(askQuestion("How are you feeling today? "));
    insertWord(askQuestion("Your best friend? "));
    insertWord(askQuestion("Your favorite food? "));
    insertWord(askQuestion("Your favorite subject? "));
    insertWord(askQuestion("Your hobby? "));
    //string ans = "Sad";
    //insertWord(ans);
    //ans = "Hello";
    //insertWord(ans);
    endwin();
    //cout << ans << endl;

    return 0;
}