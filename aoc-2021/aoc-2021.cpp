// ------------------------------------------------------------------------------------------------------------
// Este es mi código para las soliciones del Advent Of Code 2021
// Si por alguna razón quieren correr este código son necesarios los puzzle inputs del advent of code 2021
// Los puzzle inputs se obtienen en https://adventofcode.com y consisten en un monton de datos para cada puzzle
// 
// Gracias a Eric Wastl por estos entretenidos puzzles!
// ------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::list;
using std::string;
using std::stoi;

// -----
// day 1
// -----
void DepthMeasurement()
{
    std::ifstream infile("C:\\Users\\paver\\Desktop\\data.txt");
    std::string line;
    long lastNum = 0;
    long num = 0;
    long increasedAmount = 0;
    std::string text;
    
    for (std::string line; getline(infile, line);)
    {
        std::istringstream iss(line);
        iss >> num;

        if (num == 193) {
            lastNum = num;
            text = "(N / A - no previous measurement)";
        }
        else
        {
            if (num > lastNum) 
            {
                text = "increased";
                increasedAmount += 1;
            }
            else
            {
                text = "decreased";
            }

            lastNum = num;
        }

        std::cout << num << " " << text <<"\n";
    }

    std::cout << increasedAmount << ": de incrementos" << "\n";
}

int LookForNums(int startingLine)
{
    std::ifstream infile("C:\\Users\\paver\\Desktop\\data.txt");
    std::string line;
    long num = 0;
    long vectorSum = 0;
    int vectorCount = 0;
    bool counting = false;
    int countingLine = 0;

    for (std::string line; getline(infile, line);)
    {
        std::istringstream iss(line);
        iss >> num;

        countingLine++;

        if (counting == false)
        {
            if (countingLine == startingLine)
            {
                counting = true;
            }
        }

        if (counting) {
            if (vectorCount <= 2)
            {
                vectorSum += num;
            }
            else 
            {
                break;
            }

            vectorCount += 1;
        }

    }

    return vectorSum;
}

long LineCounting()
{
    std::ifstream infile("C:\\Users\\paver\\Desktop\\data.txt");
    std::string line;
    long lineCount = 0;

    for (std::string line; getline(infile, line);)
    {
        lineCount += 1;
    }

    return lineCount;
}

void ThreeVectorDepthMeasurement()
{
    long amountOfLines = LineCounting();
    long currentLine = 0;

    int currentResults[2] = { 0, 0};
    long startingNum = 193;
    int res;
    list <int> sumList;
    
    do
    {
        currentLine += 1;
        
        res = LookForNums(currentLine);
        sumList.push_back(res);

        /*cout << res << " suma " << "\n";
        cout << currentLine << " current line" << "\n";*/
    } while (currentLine < amountOfLines && currentLine < 1998);


    int lastSum = 0;
    int currentSum = 0;
    string text = "";
    long increasedAmount = 0;
    for (auto it = sumList.begin(); it != sumList.end(); it++) {
        currentSum = *it;

        if (currentSum == 592) {
            lastSum = currentSum;
            text = "(N / A - no previous sum)";
        }
        else
        {
            if (currentSum > lastSum)
            {
                text = "(increased)";
                increasedAmount += 1;
            }
            else
            {
                text = "(decreased)";
            }

            lastSum = currentSum;
        }

        std::cout << currentSum << " " << text << "\n";
    }
    std::cout << increasedAmount << " cantidad de incrementos " << "\n";
}

// -----
// day 2
// -----
void SubMovement()
{
    std::ifstream infile("C:\\Users\\paver\\Desktop\\data-movement.txt");
    int currentPosition[2] = {0, 0};
    int moveAmount = 0;
    string moveDirection = "";
    
    for (string line; getline(infile, line);)
    {
        std::istringstream iss(line);
        moveDirection = line;
        moveAmount = 0;
        int count = 0;

        do
        {
            if (count == 0)
            {
                iss >> moveDirection;
                count++;
            }
            else 
            {
                iss >> moveAmount;
            }
        } while (iss);

        if (moveDirection == "forward")
        {
            currentPosition[0] += moveAmount;
        }
        else if (moveDirection == "up")
        {
            currentPosition[1] -= moveAmount;
        }
        else if (moveDirection == "down")
        {
            currentPosition[1] += moveAmount;
        }

        cout << "HOR: " << currentPosition[0] << ", DEPTH: " << currentPosition[1] << "\n";
    }

    long finalMult = currentPosition[0] * currentPosition[1];
    cout << "Final Multiplication: " << finalMult;
}

void SubMovementWithAim()
{
    std::ifstream infile("C:\\Users\\paver\\Desktop\\data-movement.txt");
    int currentPosition[2] = { 0, 0 };
    int aim = 0;
    int moveAmount = 0;
    string moveDirection = "";

    for (string line; getline(infile, line);)
    {
        std::istringstream iss(line);
        moveDirection = line;
        moveAmount = 0;
        int count = 0;

        do
        {
            if (count == 0)
            {
                iss >> moveDirection;
                count++;
            }
            else
            {
                iss >> moveAmount;
            }
        } while (iss);

        if (moveDirection == "forward")
        {
            currentPosition[0] += moveAmount;
            currentPosition[1] += (aim * moveAmount);
        }
        else if (moveDirection == "up")
        {
            aim -= moveAmount;
        }
        else if (moveDirection == "down")
        {
            aim += moveAmount;
        }

        cout << "HOR: " << currentPosition[0] << ", DEPTH: " << currentPosition[1] << "\n";
    }

    long finalMult = currentPosition[0] * currentPosition[1];
    cout << "Final Multiplication: " << finalMult;
}

// -----
// day 3
// -----
int BinaryToDecimal(long long n)
{
    long long num = n;
    int dec_value = 0;
    int base = 1;
    long long temp = num;

    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

void BinaryDiagnostic()
{
    std::ifstream infile("C:\\Users\\paver\\Desktop\\data-bin-diag.txt");
    string gamma = "";
    string epsilon = "";
    int zeroBits[12] {};
    int oneBits[12]{};
    int zeros = 0;
    int ones = 0;

    for (string line; getline(infile, line);)
    {
        int counter = 0;

        for (auto c : line) {
            if ((c - '0') == 0)
            {
                zeroBits[counter]++;
            }
            else
            {
                oneBits[counter]++;
            }

            counter++;
        }

        cout << "report: " << line << "\n";
    }

    for (int i = 0; i < 12; i++) {
        if (zeroBits[i] > oneBits[i]) 
        {
            gamma += "0";
            epsilon += "1";
        }
        else 
        {
            gamma += "1";
            epsilon += "0";
        }
    }

    int decimalGamma = BinaryToDecimal(stoll(gamma));
    int decimalEpsilon = BinaryToDecimal(stoll(epsilon));
    
    cout << "GAMMA: " << decimalGamma << "\n";
    cout << "EPSILON: " << decimalEpsilon << "\n";

    cout << "MULT: " << (decimalGamma * decimalEpsilon) << "\n";
}

string * FindRatings()
{
    std::ifstream infile("C:\\Users\\paver\\Desktop\\data-bin-diag.txt");
    int oxyBits[2][12]{};
    int co2Bits[2][12]{};

    bool oxyDone = false;

    int oxyZeroBits[12]{};
    int oxyOneBits[12]{};
    int co2ZeroBits[12]{};
    int co2OneBits[12]{};
    int commons[12]{};
    string* results = new string[2];
    list <string> oxyResultList;
    list <string> co2ResultList;

    // recorrer lineas para guardar una lista de resultados
    for (string line; getline(infile, line);)
    {
        oxyResultList.push_back(line);
        co2ResultList.push_back(line);
    }

    // ¿que bit voy a revisar?
    int oxyCounter = 0;

    // ¿quedan mas de un resultados en la lista?
    while (oxyResultList.size() > 1)
    {
        // encontrar bits comunes en la lista actual
        oxyBits[0][oxyCounter] = 0;
        oxyBits[1][oxyCounter] = 0;
        for (auto it = oxyResultList.begin(); it != oxyResultList.end(); it++) {
            string cn = *it;
            int i = 0;

            for (auto c : cn) {
                if ((c - '0') == 0)
                {
                    oxyBits[0][i]++;
                }
                else
                {
                    oxyBits[1][i]++;
                }

                i++;
            }
        }

        if (oxyBits[0][oxyCounter] > oxyBits[1][oxyCounter])
        {
            commons[oxyCounter] = 0;
        }
        if (oxyBits[0][oxyCounter] == oxyBits[1][oxyCounter])
        {
            commons[oxyCounter] = 1;
        }
        if (oxyBits[0][oxyCounter] < oxyBits[1][oxyCounter])
        {
            // uno es comun, en caso de empate tambien
            commons[oxyCounter] = 1;
        }

        cout << " .......... " << "\n";
        cout << " COUNTER: " << oxyCounter << "\n";
        cout << " .......... " << "\n";

        // loop a traves de la lista
        list <string>::iterator itr = oxyResultList.begin();
        while (itr != oxyResultList.end())
        {
            // eliminar los que no cumplen los criterios
            string currentNumber = *itr;
            int cn = currentNumber[oxyCounter] - '0';
            int cc = commons[oxyCounter];

            cout << " O2 NUMBER " << currentNumber << "\n";
            if (cn != cc) {
                itr = oxyResultList.erase(itr);
                cout << " ERASING " << cn << " - " << cc << "\n";
            }            
            else {
                cout << " PASSING " << "\n";
                itr++;
            }
        }

        oxyCounter++;
    }

    // ¿que bit voy a revisar?
    int co2Counter = 0;

    // ¿quedan mas de un resultados en la lista?
    while (co2ResultList.size() > 1)
    {
        // encontrar bits comunes en la lista actual
        co2Bits[0][co2Counter] = 0;
        co2Bits[1][co2Counter] = 0;
        for (auto it = co2ResultList.begin(); it != co2ResultList.end(); it++) {
            string cn = *it;
            int i = 0;

            for (auto c : cn) {
                if ((c - '0') == 0)
                {
                    co2Bits[0][i]++;
                }
                else
                {
                    co2Bits[1][i]++;
                }

                i++;
            }
        }
        
        if (co2Bits[0][co2Counter] > co2Bits[1][co2Counter])
        {
            commons[co2Counter] = 1;
        }
        if (co2Bits[0][co2Counter] == co2Bits[1][co2Counter])
        {
            commons[co2Counter] = 0;
        }
        if (co2Bits[0][co2Counter] < co2Bits[1][co2Counter])
        {
            commons[co2Counter] = 0;
        }

        cout << " .......... " << "\n";
        cout << " COUNTER: " << co2Counter << "\n";
        cout << " .......... " << "\n";

        // loop a traves de la lista
        list <string>::iterator it = co2ResultList.begin();
        while (it != co2ResultList.end())
        {
            // eliminar los que no cumplen los criterios
            string currentNumber = *it;
            int cn = currentNumber[co2Counter] - '0';
            int cc = commons[co2Counter];

            cout << " CO2 NUMBER " << currentNumber << "\n";
            if (cn != cc) {
                it = co2ResultList.erase(it);
                cout << " ERASING " << cn << " - " << cc << "\n";
            }
            else {
                cout << " PASSING " << co2ResultList.size() << "\n";
                it++;
                
            }
        }

        co2Counter++;
    }

    for (auto it = oxyResultList.begin(); it != oxyResultList.end(); it++) {
        string cn = *it;
        cout << "final OXY result: " << cn << "\n";

        results[0] = cn;
    }

    for (auto it = co2ResultList.begin(); it != co2ResultList.end(); it++) {
        std::string cn = *it;
        cout << "final CO2 result: " << cn << "\n";

        results[1] = cn;
    }

    return results;
}

void LifeSupport()
{
    std::ifstream infile("C:\\Users\\paver\\Desktop\\data-bin-diag.txt");
    string oxygenRating = "";
    string co2Rating = "";

    string * ratings = FindRatings();
    oxygenRating = ratings[0];
    co2Rating = ratings[1];

    cout << "oxygen bin: " << ratings[0] << "\n";
    cout << "co2 bin: " << ratings[1] << "\n";

    int decimalOx = BinaryToDecimal(stoll(oxygenRating));
    int decimalCo = BinaryToDecimal(stoll(co2Rating));

    cout << "oxygen decimal: " << decimalOx  << "\n";
    cout << "co2 decimal: " << decimalCo << "\n";

    cout << "MULT: " << (decimalOx * decimalCo) << "\n";
}

// ----
// MAIN
// ----
int main()
{
    LifeSupport();
}