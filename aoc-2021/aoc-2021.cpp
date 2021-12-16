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
#include <vector>

using std::cin;
using std::cout;
using std::list;
using std::string;
using std::stoi;
using std::vector;

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

// -----
// day 4
// -----
void FindResults(list<int>& results)
{
    std::ifstream infile("C:\\Users\\paver\\Desktop\\data-bingo-results.txt");

    for (string line; getline(infile, line);)
    {
        std::stringstream ss(line);

        int num = 0;

        vector<string> enrolled;
        for (string course; std::getline(ss, course, ',');)
        {
            enrolled.push_back(course);
           
            num = stoi(course);
            results.push_back(num);
        }
    }
}

void FindBoards(list<vector<vector<int>>>& boards, list<vector<vector<int>>>& boardsMarkers, list<int>& winners)
{
    std::ifstream infile("C:\\Users\\paver\\Desktop\\data-bingo-boards.txt");

    int listCounter = 0;
    int x = 0;
    int y = 0;
    int num = 0;
    vector<vector<int>> board(5, vector<int>(5, 0));
    vector<vector<int>> boardMarker(5, vector<int>(5, 0));

    for (string line; getline(infile, line);)
    {
        if (line != "")
        {
            std::stringstream ss(line);
            
            vector<string> enrolled;
            for (string course; std::getline(ss >> std::ws, course, ' ');)
            {
                enrolled.push_back(course);

                num = stoi(course);
                
                board[x][y] = num;
                boardMarker[x][y] = 0;

                x++;
            }
            x = 0;
            y++;
        }
        else {
            y = 0;
            boards.push_back(board);
            boardsMarkers.push_back(boardMarker);
            winners.push_back(0);
        }
    }
    // ingresar ultimo tablero
    boards.push_back(board);
    boardsMarkers.push_back(boardMarker);
    winners.push_back(0);
}

void LookForAWinner(
    list<int>& results, 
    list<vector<vector<int>>>& boards, 
    list<vector<vector<int>>>& boardsMarkers, 
    vector<vector<int>>& winnerBoard, 
    vector<vector<int>>& winnerMarkers,
    vector<vector<int>>& lastWinnerBoard,
    vector<vector<int>>& lastWinnerMarkers,
    int& winningNumber,
    int& lastWinningNumber,
    list<int>& winners,
    list<vector<vector<int>>>& winnerBoards)
{
    bool firstWinnerFound = false;
    int winnerCount = 0;

    // loop por resultados
    for (auto it = results.begin(); it != results.end(); it++)
    {
        int currentNumber = *it;

        // loop por tableros
        list<vector<vector<int>>>::iterator it1 = boards.begin();
        list<vector<vector<int>>>::iterator it2 = boardsMarkers.begin();
        list<int>::iterator it3 = winners.begin();

        while (it1 != boards.end() && it2 != boardsMarkers.end() && it3 != winners.end()) {
            // loop en los numeros del tablero
            vector<vector<int>>& board = *it1;
            vector<vector<int>>& boardMarker = *it2;
            int& boardCondition = *it3;

            // si es que el tablero no se ha declarado ganador
            if (boardCondition != 1)
            {
                // marcar numeros de bingo
                for (int y = 0; y < 5; y++)
                {
                    for (int x = 0; x < 5; x++)
                    {
                        int boardNumber = board[x][y];
                    
                        // revisar si el número del tablero corresponde al numero sorteado
                        if (board[x][y] == currentNumber)
                        {
                            boardMarker[x][y] = 1;
                        }
                    }
                }

                // revisar si hay un ganador
                int rowCount = 0;
                int colCount = 0;

                // revisar fila
                for (int y = 0; y < 5; y++)
                {
                    for (int x = 0; x < 5; x++)
                    {
                        if (boardMarker[x][y] == 1)
                        {
                            rowCount += 1;
                            if (rowCount > 4)
                            {
                                if (!firstWinnerFound)
                                {
                                    cout << "First winner found" << "\n";
                                    winnerBoard = board;
                                    winnerMarkers = boardMarker;
                                    winningNumber = currentNumber;
                                    firstWinnerFound = true;
                                    boardCondition = 1;
                                    winnerCount++;
                                    winnerBoards.push_back(board);
                                    lastWinnerMarkers = boardMarker;
                                    lastWinningNumber = currentNumber;
                                }
                                else
                                {
                                    boardCondition = 1;
                                    winnerCount++;
                                    winnerBoards.push_back(board);
                                    lastWinnerMarkers = boardMarker;
                                    lastWinningNumber = currentNumber;
                                }
                            }
                        }
                    }
                    rowCount = 0;
                }

                if (boardCondition != 1)
                {
                    // revisar columna
                    for (int x = 0; x < 5; x++)
                    {
                        for (int y = 0; y < 5; y++)
                        {
                            if (boardMarker[x][y] == 1)
                            {
                                colCount += 1;
                                if (colCount > 4)
                                {
                                    if (!firstWinnerFound)
                                    {
                                        cout << "First winner found" << "\n";
                                        winnerBoard = board;
                                        winnerMarkers = boardMarker;
                                        winningNumber = currentNumber;
                                        firstWinnerFound = true;
                                        boardCondition = 1;
                                        winnerCount++;
                                        winnerBoards.push_back(board);
                                        lastWinnerMarkers = boardMarker;
                                        lastWinningNumber = currentNumber;
                                    }
                                    else
                                    {
                                        boardCondition = 1;
                                        winnerCount++;
                                        winnerBoards.push_back(board);
                                        lastWinnerMarkers = boardMarker;
                                        lastWinningNumber = currentNumber;
                                    }
                                }
                            }
                        }
                        colCount = 0;
                    }
                }
            }

            it1++;
            it2++;
            it3++;
        }
    }
    cout << "WINNER COUNT: " << winnerCount << "\n";
}

void Bingo()
{
    list <int> results;
    list<vector<vector<int>>> boards;
    list<vector<vector<int>>> boardsMarkers;
    list<int> winners;
    list<vector<vector<int>>> winnerBoards;
    vector<vector<int>> winnerBoard(5, vector<int>(5, 0));
    vector<vector<int>> winnerMarkers(5, vector<int>(5, 0));
    vector<vector<int>> lastWinnerBoard(5, vector<int>(5, 0));
    vector<vector<int>> lastWinnerMarkers(5, vector<int>(5, 0));
    int winningNumber = 0;
    int lastWinningNumber = 0;

    FindResults(results);
    FindBoards(boards, boardsMarkers, winners);
    LookForAWinner(results, boards, boardsMarkers, winnerBoard, winnerMarkers, lastWinnerBoard, lastWinnerMarkers, winningNumber, lastWinningNumber, winners, winnerBoards);

    int bcount = 0;
    for (auto it = boards.begin(); it != boards.end(); it++) {        
        vector<vector<int>> board = *it;

        cout << " board: " << bcount << "\n";
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                cout << board[x][y] << " ";
            }

            cout << "\n";
        }

        bcount++;
        cout << " -------------- " << "\n";
    }

    int count = 0;
    for (auto it = boardsMarkers.begin(); it != boardsMarkers.end(); it++) {
        vector<vector<int>> boardMarker = *it;

        cout << " board: " << count << "\n";
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                cout << boardMarker[x][y] << " ";
            }

            cout << "\n";
        }
        count++;

        cout << " -------------- " << "\n";
    }

    int wbcount = 0;
    for (auto it = winnerBoards.begin(); it != winnerBoards.end(); it++) {
        vector<vector<int>> board = *it;

        cout << " board: " << wbcount << "\n";
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                cout << board[x][y] << " ";
            }

            cout << "\n";
        }

        wbcount++;
        cout << " -------------- " << "\n";
    }
    lastWinnerBoard = winnerBoards.back();

    // encontrar puntaje final primer tablero
    cout << "\n";
    cout << "- FIRST WINNER BOARD -" << "\n";
    double firstScore = 0;
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            cout << winnerBoard[x][y] << " ";

            if (winnerMarkers[x][y] == 0)
            {
                firstScore += winnerBoard[x][y];
            }
        }
        cout << "\n";
    }
    cout << " ---------------- " << "\n";
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            cout << winnerMarkers[x][y] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "FIRST SCORE: " << firstScore << "\n";
    cout << "FIRST WINNING NUMBER: " << winningNumber << "\n";
    cout << "FIRST FINAL SCORE: " << firstScore * winningNumber << "\n";

    // encontrar puntaje final ultimo tablero
    cout << "\n";
    cout << "- LAST WINNER BOARD -" << "\n";
    double lastScore = 0;
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            cout << lastWinnerBoard[x][y] << " ";

            if (lastWinnerMarkers[x][y] == 0)
            {
                lastScore += lastWinnerBoard[x][y];
            }
        }
        cout << "\n";
    }
    cout << " ---------------- " << "\n";
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            cout << lastWinnerMarkers[x][y] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "LAST SCORE: " << lastScore << "\n";
    cout << "LAST WINNING NUMBER: " << lastWinningNumber << "\n";
    cout << "LAST FINAL SCORE: " << lastScore * lastWinningNumber << "\n";
}

// ----
// MAIN
// ----
int main()
{
    Bingo();
}