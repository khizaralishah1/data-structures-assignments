#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <unistd.h>
using namespace std;

extern void showString(int, int, string);
extern void spaces(int, int, int);

void insertWord(string val)
{
    fstream myFile("words.txt", ios::in | ios::out);
    //fstream freqFile("frequencies.txt", ios::in | ios::out);
    //ofstream seek2("words.txt", ios::out | ios::app);

    // string word;
    // int count;
    // int before = 0, after = 0;
    //if(myFile.eof()) cout << "Good";
    // while ( ! myFile.eof() )
    // {
    //     before = myFile.tellg();//0
    //     // if(before != 0)
    //     //     ++before;
    //     myFile >> word;
    //     //freqFile >> count;
    //     //cout << before << endl;
    //     after = myFile.tellg();//7

    //     if(myFile.fail())
    //     {
    //         myFile.clear();
    //         myFile << "\r" << val << "\n";
    //         //freqFile << "\r 1\n";
    //         break;
    //     }
    //     else if(word == val)
    //     {
            
    //         myFile.seekp(before - after, ios::cur);
    //         myFile  << word << " " << ++count << " ";
    //         myFile.close();
    //         return;
    //     }
    //     else if ( word == "l" && count == 0 ) 
    //     {
    //         myFile.clear();
    //         myFile.seekp(before, ios::beg);
    //         myFile << val << " 1 ";
    //         myFile.close();
    //         return;
    //     }
    // }
    // if(after == -1)
    // {
    //     cout << myFile.tellg();
    // }
    // myFile.seekg(before, ios::beg);
    // char a = myFile.tellg();
    // a -= 48;
    // addch(a);
    // int lst = myFile.tellg();
    //myFile.seekg(before - lst, ios::end);
    //myFile.seekg(before - after, ios::cur);
    
    //myFile << myFile.tellg() << endl;
    //myFile << 1;
    //mymyFilee << "l 0" << endl;

    string w; int x;
    //myFile << val << " 3";
    //cout << myFile.eof() << endl;
    while(!myFile.eof())
    {
        int bef = myFile.tellp();
        cout << bef << ": ";
        myFile >> w >> x;
        int aft = myFile.tellp();
        cout << aft << " -> " << w << " " << x << endl;
       
        if(w == val)
        {   //2 extra are read
            if(bef != 0)
            {
                myFile.seekg( bef - aft + 1 , ios::cur);
            }
            else
            {
                myFile.seekg( bef - aft , ios::cur);
            }
            myFile << w << " " << ++x << "\n";
            break;
        }
        else if(myFile.fail())
        {
            myFile.clear();
            myFile << val << " 1\n";
            break;
        }
        //cout << endl << fil.tellp() << " -> " << endl;
    }



    myFile.close();

    // move(8,8);
    // addch('k');
    // refresh();
    //usleep(10000000);
}

void showFrequentWords(char ch, int place, string ans, string freqWords[])
{
    //clear();
    //string freqWords[3] = {" - ", " - ", " - "};
    int highest1=3, highest2=2, highest3=1;
    int totalFound = 0;
    string word; int count;

    fstream myFile("words.txt", ios::in);
    bool runAgain = false;
    bool locked1, locked2, locked3;
    locked1 = locked2 = locked3 = false;
    // int minCount = 99999;
    // int maxCount = 0;
    // int minIndex = 0;
    int i = 1;

    while( !myFile.eof() )//&& //totalFound < 3 )
    {
        if(myFile.fail())
            return;
        runAgain = false;
        myFile >> word >> count;
        if(word[place] == ch)
        {
            for(int i=0; i<place; ++i)
            {
                if(word[i] != ans[i])
                {
                    runAgain = true;
                    break;
                }
            }

            if(runAgain)
                continue;
                //khizar 8 kamran 3 kaisar 9

            if(count > highest1)// && !locked1)//16
            {
                //locked1 = true;
                if(freqWords[0] != "-")
                {
                    //string temp = freqWords[1];
                    if(freqWords[1] != "-")
                    {
                        highest3 = highest2;
                        freqWords[2] = freqWords[1];  
                    }
                    highest2 = highest1;
                    freqWords[1] = freqWords[0];
                }
                freqWords[0] = word;
                highest1 = count; // 8
            }
            else if(count > highest2)// && !locked2)//2
            {
                //harris      
                // 6                      
                //locked2 = true;
                if(freqWords[1] != "-")
                {
                    //string temp = freqWords[1];
                    highest3 = highest2;
                    freqWords[2] = freqWords[1];
                }
                freqWords[1] = word;
                highest2 = count;  // 3
            }
            else if(count >= highest3)// && !locked3)//1
            {
                //locked3 = true;
                freqWords[2] = word;
                highest3 = count;
            }
            // for(int i=0; i<3; ++i)
            // {
            //     if(freqWords[i] == "-")
            //     {
            //         if(count < minCount)
            //         {
            //             freqWords[i] = word;
            //             break;
            //         }
            //     }
            // }
            //++totalFound;
            
            if(myFile.eof())
            {
                showString(1,1+i, "1");
                i += 5;
            }
            else
            {
                showString(1,1+i, "0");
                i += 5;
            }

            
        }
    }

    myFile.close();

    string fullStr = freqWords[0]+"\t"+freqWords[1]+"\t"+freqWords[2];

    refresh();
    spaces(20, 20, 100);
    showString(20, 20, fullStr);
    //clear();
    refresh();
}

