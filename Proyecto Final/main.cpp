#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std; 

#include "LinkedListTGP.h"

int main(void)
{
    LinkedListTGP<string> citiesTrain;
    LinkedListTGP<string> citiesCar;

    ifstream fin; 
    // ofstream fout; 

    string links[2], line, word, hour;
    int count1 = 0, count2 = 0, timeTrain[2], timeCar[2], distanceTrain, distanceCar; 

    fin.open("EuropeCities.csv");

// ocupo tener una lista para la hora de los trenes, una lista para la hora de los carros,
// distancia para trenes, distancia para carros

    while(getline(fin, line))
    {
        stringstream streamLine(line);
        while(count1 < 6)
        {
            getline(streamLine, word, ',');
            if(count1 < 2)
            {
                links[count1] = word;
            }
            else if(count1 == 2)
            {
                stringstream streamWord(word);
                while(count2 < 2)
                {
                    getline(streamWord, hour, ':');
                    if(count2 < 2)
                    {
                        timeTrain[count2] = stoi(hour); 
                    }
                    else
                    {
                        timeTrain[count2] = stoi(hour);
                    }
                    count2++;
                }
                count2 = 0; 
            }
            else if(count1 == 4)
            {
                stringstream streamWord(word);
                while(count2 < 2)
                {
                    getline(streamWord, hour, ':');
                    if(count2 < 2)
                    {
                        timeCar[count2] = stoi(hour); 
                    }
                    else
                    {
                        timeCar[count2] = stoi(hour);
                    }
                    count2++;
                }
                count2 = 0; 
            }
            else
            {
                if(count1 == 3)
                {
                    distanceTrain = stoi(word);
                } 
                else
                {
                    distanceCar = stoi(word);
                }
            }
            count1++;
        }
        
        // citiesTrain.insertAdj(links[0], links[1], timeTrain[0]*60 + timeTrain[1], distanceTrain);
        // citiesCar.insertAdj(links[0], links[1], timeCar[0]*60 + timeCar[1], distanceCar);
        count1 = 0; 
    }

    fin.close();
    return 0; 
}