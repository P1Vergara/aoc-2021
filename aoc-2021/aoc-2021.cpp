// aoc-2021.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::list;
using std::string;


// day 1
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

// day 2
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

int main()
{
    SubMovementWithAim();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
