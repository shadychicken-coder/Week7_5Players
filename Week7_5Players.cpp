#include <iostream>

#include <iomanip>

#include <fstream>

using namespace std;

// Defining global constants
#define NUMPLAYERS 10
#define GAMESPLAYED 5

struct person
{
    string name = "";
    int scores[GAMESPLAYED]{};
    int average{};
};

// Function for getting BowlingData
bool getBowlingData(person& players, int n)
{
    ifstream in("BowlingScores.txt");
    // Creating loop to read BowlingScores.txt and import data to the one-dimensional and two-dimensional array
    //  Trying to read in the correct row by using trash values to skip data. Kept getting duplicates or not reading all data with old code
    if (!in.fail())
    {
        int row = 0;
        string trashName = "";
        string trashNum = "";
        while (!in.eof())
        {
            if (row == n)
            {
                in >> players.name >> players.scores[0] >> players.scores[1] >> players.scores[2] >> players.scores[3] >> players.scores[4];
                break;
            }

            // Trash data to skip
            in >> trashName >> trashNum >> trashNum >> trashNum >> trashNum >> trashNum;

            row++;
        }
        return true;
    }
    return false;
}

// Function for calculating the average scores for each player
void getAverageScore(person& player)
{
    // Grabs the four scores for each player, adds them up, and divides by GAMESPLAYED
    int sum = 0;
    for (int i = 0; i < GAMESPLAYED; i++)
    {
        sum += player.scores[i];
    }

    player.average = sum / GAMESPLAYED;
}

/*void prettyPrintResults(person player) OLD CODE OLD CODE - Could not get to work, so I just restarted
{
    // Welcome Letter
    cout << string(55, '*') << endl;
    cout << string(10, '*') << " Justin's Bowling League " << string(20, '*') << endl;
    cout << string(55, '*') << endl;

    // Bowling League Results
    cout << left << setw(10) << "Name"
         << "Score1\tScore2\tScore3\tScore4\tScore5\tAvg_Score" << endl;

    // loop for printing player name & score
    int n = GAMESPLAYED;
    for (int i = 0; i < n; i++)
    {
        cout << player.name[i];
        // cout << left << setw(10) << player.name[i] << "\t";
    }
    // nested loop for printing scores/averages
    // for (int j = 0; j < GAMESPLAYED; j++)
    // cout << player.scores[j] << "\t";
    // cout << player.average[i] << endl;
}*/

void prettyPrintResults(person players[])
{
    cout << left << setw(10) << "Name\t" << "Score1\tScore2\tScore3\tScore4\tScore5\tAvg_Score" << endl;
    for (int i = 0; i < NUMPLAYERS; i++) {
        cout << left << setw(10) << players[i].name << "\t";
        for (int score : players[i].scores) {
            cout << score << "\t";

        }
        cout << players[i].average << endl;
    }





}

int main()
{


    person players[100];
    int i = 0;
    //int counter = 10;old code
    // Loop to run functions per player
    for (i = 0; i < NUMPLAYERS; i++)
    {
        getBowlingData(players[i], i);
        getAverageScore(players[i]);
    }

    // Print function
    prettyPrintResults(players);
}