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

// ----
// MAIN
// ----
int main()
{
    BinaryDiagnostic();
}