#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
int board[4][4];

int moveRow[] = {1, 0, -1, 0};
int moveCol[] = {0, 1, 0, -1};

pair<int, int> generateUnOccupiedPosition()
{
    int occupied = 1, line, col;

    while (occupied)
    {
        line = rand() % 4;
        col = rand() % 4;
        if (board[line][col] == 0)
            occupied = 0;
    }
    return make_pair(line, col);
}
void addPiece()
{
    pair<int, int> pos = generateUnOccupiedPosition();
    board[pos.first][pos.second] = 2;
}
void newGame()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = 0;
        }
    }
    addPiece();
}
void printUI()
{
    system("cls");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                cout << setw(4) << ".";
            }
            else
            {
                cout << setw(4) << board[i][j] << "";
            }
        }
        cout << endl;
    }
    cout << "n: new game " << endl
         << "w: up, s: down, d: right, a: left" << endl
         << "q: quit" << endl;
}

bool canDoMove(int line, int col, int nextLine, int nextColumn)
{
    if (nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4 ||
        (board[line][col] != board[nextLine][nextColumn] && board[nextLine][nextColumn] != 0))
        return false;
    return true;
}
 
 
void applyMove(int direction)
{
    int startLine = 0, startCol = 0, lineStep = 1, colStep = 1;
    if (direction == 0)
    {
        startLine = 3;
        lineStep = -1;
    }
    if (direction == 1)
    {
        startCol = 3;
        colStep = -1;
    }
    int movePossible, canAddPiece = 0;
    do
    {
        movePossible = 0;
        for (int i = startLine; i >= 0 && i < 4; i += lineStep)
        {
            for (int j = startCol; j >= 0 && j < 4; j += colStep)
            {
                int nextI = i + moveRow[direction], nextJ = j + moveCol[direction];
                // cout << i << "  " << j << "  " << nextI << "  " << nextJ << endl;
                if (board[i][j] && canDoMove(i, j, nextI, nextJ))
                {
                    board[nextI][nextJ] += board[i][j];
                    board[i][j] = 0;
                    movePossible = 1;
                    canAddPiece = 1;
                }
            }
        }
        printUI();
    } while (movePossible);
    if (canAddPiece)
    {
        addPiece();
    }
}

int main()
{
    srand(time(NULL));
    char commandtoDir[128];
    commandtoDir['s'] = 0;
    commandtoDir['d'] = 1;
    commandtoDir['w'] = 2;
    commandtoDir['a'] = 3;
    while (true)
    {
        printUI();
        char command;
        cin >> command;
        if (command == 'n')
        {
            newGame();
        }
        else if (command == 'q')
        {
            break;
        }
        else
        {
            int currentDirection = commandtoDir[command];
            cout << currentDirection << endl;
            applyMove(currentDirection);
        }
    }
}