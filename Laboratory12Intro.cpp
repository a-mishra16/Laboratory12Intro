// Laboratory 13 Part 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void pressEnterToContinue();
bool readFromFile(string filename);
bool readFromCSVFile(string filename);


int main()
{
    string datafile;
    cout << "Lab 12 Intro to Text Files!\n";
    cout << "Enter filename: ";
    getline(cin, datafile);
    bool status = readFromCSVFile(datafile);
    if (status)
    {
        cout << "Success!\n";
    }
    else
    {
        cout << "Failure.\n";
    }
    pressEnterToContinue();
}

//Keeps Terminal Open
void pressEnterToContinue()
{
    cout << "\nPress enter to continue... \n";
    cin.clear();
    while (cin.get() != '\n') continue;
}

//Reads in the text
bool readFromFile(string filename)
{
    ifstream inFile;        //Input filestream to read in data
    string movieTitle;
    int year;
    inFile.open(filename); //Attempts to open specified file

    if (inFile.fail()) //In case a problem occurs
    {
        cout << "Read error - sorry\n";
        return false;
    }

    //Here it reads data until done
    while (true)
    {
        inFile >> movieTitle >> year;
        if (inFile.fail())
        {
            break; //No more data to read
        }

        cout << movieTitle << ": " << year << endl;
    }

    //Close file and return
    inFile.close();
    return true;
}

bool readFromCSVFile(string filename)
{
    ifstream inFile;
    istringstream thisLine;
    string movieInfo;
    string movieTitle;
    string year;
    string director;

    inFile.open(filename);
    if (inFile.fail())
    {
        cout << "Read error - sorry!\n";
        return false;
    }

    while (true)
    {
        getline(inFile, movieInfo);
        if (inFile.fail())
        {
            break;
        }
        thisLine.clear();
        thisLine.str(movieInfo);
        getline(thisLine, movieTitle, ',');
        getline(thisLine, year, ',');

        vector <string> directorList;
        string dir;
        while (getline(thisLine, dir, ','))
        {
            directorList.push_back(dir);
        }
        director = directorList[0];
        for (int i = 1; i < directorList.size(); i++)
        {
            director = director + " and " + directorList[i];
        }

        cout << movieTitle << " is a " << year << " film directed by " << director << endl;
    }

    //Close the file and return
    inFile.close();
    return true;
}
