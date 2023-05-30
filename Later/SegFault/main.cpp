#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#define DEBUG 1

using namespace std;

const int ROW_MAX = 1000;

const int rowInc[] = { 1, -1, 0, 0 };
const int colInc[] = { 0, 0, -1, 1 };

struct Position {
    int row, col;
    Position(int _row = -1, int _col = -1) : row(_row), col(_col) {}
    friend ostream& operator<<(ostream& out, const Position& p) {
        return out << "(" << p.row << ", " << p.col << ")";
    }
};

struct PositionIt : public Position {
    int numRow, numCol;
    char dir;
    PositionIt(int _numRow, int _numCol, char _dir) : numRow(_numRow), numCol(_numCol), dir(_dir) {
        switch (dir) {
        case 'U':
            row = numRow - 1;
            col = numCol - 1;
            break;
        case 'D':
            row = 0;
            col = 0;
            break;
        case 'R':
            row = 0;
            col = 0;
            break;
        case 'L':
            row = numRow - 1;
            col = numCol - 1;
            break;
        default:
            throw "Zezno inicijalizator";
        }

    }

    PositionIt& operator++() {
        switch (dir) {
        case 'U':
            if (row == 0) {
                row = numRow - 1;
                col --;
            } else
                row--;
            break;
        case 'D':
            if (row == numRow - 1) {
                row = 0;
                col ++;
            } else
                row ++;
            break;
        case 'R':
            if (col == numCol - 1) {
                col = 0;
                row ++;
            } else
                col ++;
            break;
        case 'L':
            if (col == 0) {
                col = numCol - 1;
                row --;
            } else
                col --;
            break;
        default:
            throw "Zeznuo si iterator";
        }

        return *this;
    }

    PositionIt operator++(int) {

        switch (dir) {
        case 'U':
            if (row == 0) {
                row = numRow - 1;
                col --;
            } else
                row--;
            break;
        case 'D':
            if (row == numRow - 1) {
                row = 0;
                col ++;
            } else
                row ++;
            break;
        case 'R':
            if (col == numCol - 1) {
                col = 0;
                row ++;
            } else
                col ++;
            break;
        case 'L':
            if (col == 0) {
                col = numCol - 1;
                row --;
            } else
                col --;
            break;
        default:
            throw "Zeznuo iterator";
        }
        PositionIt pIt = *this;
        return pIt;

    }

    bool EndOfLine() const {
        switch (dir) {
        case 'U':
            if (row == 0)
                return true;
            break;
        case 'D':
            if (row == numRow)
                return true;
            break;
        case 'R':
            if (col == numCol - 1)
                return true;
            break;
        case 'L':
            if (col == 0)
                return true;
            break;
        default:
            throw "Zeznuo";

        }
        return false;
    }
};

struct Memory {
    enum Own { PERICA, NIKOLA, COMPUTER, FREE };
    Own Owner;
    set <char> dir;
    int time;
    Memory() : Owner(FREE), time(INT_MAX) {}
    friend ostream& operator<<(ostream& out, const Memory& m) {
        switch (m.Owner) {
        case PERICA:
            out << "Perica";
            break;
        case NIKOLA:
            out << "Nikola";
            break;
        case COMPUTER:
            out << "COMPUTER";
            break;
        case FREE:
            out << "FREE";
            break;
        default:
            out << "SUCK IT";
        }
        out << " " << m.time;
        return out;
    }
};

char ram[ROW_MAX][ROW_MAX] = {0};
Memory x[ROW_MAX][ROW_MAX];


void RamToMemory(char ram[][ROW_MAX], Memory x[][ROW_MAX], int numRow, int numCol) {
    for (int row = 0; row < numRow; row ++)
        for (int col = 0; col < numCol; col ++)
            if (ram[row][col] == '#')
                x[row][col].Owner = Memory::COMPUTER;
            else if (ram[row][col] == 'S') {
                x[row][col].Owner = Memory::PERICA;
                x[row][col].time = 0;
            }
}

Position FindS(Memory x[][ROW_MAX], int numRow, int numCol) {
    for (int row = 0; row < numRow; row++)
        for (int col = 0; col < numCol; col++)
            if (x[row][col].Owner == Memory::PERICA)
                return Position(row, col);
    return Position(-1, -1);
}


// Fill memory in one direction
void FillMemoryDir(Memory x[][ROW_MAX], int numRow, int numCol, char dir) {
    PositionIt it(numRow, numCol, dir); // initialize iterator
    int lastTime = -1;

    for (int idx = 0; idx < numRow * numCol; idx ++) {
        if ( (x[it.row][it.col].Owner == Memory::NIKOLA) &&
            (x[it.row][it.col].dir.find(dir) != x[it.row][it.col].dir.end()) )
            lastTime = 1;

        if ( (x[it.row][it.col].Owner == Memory::FREE) || (x[it.row][it.col].Owner == Memory::NIKOLA) ) {
            if (lastTime != -1) { // free memory will have large time
                if (lastTime < x[it.row][it.col].time) {
                    x[it.row][it.col].Owner = Memory::NIKOLA;
                    x[it.row][it.col].time = lastTime;
                }
                lastTime++;
            }
        } else
            lastTime = -1;

        if (it.EndOfLine())
            lastTime = -1;
        it++;
    }
}

// returns true if PERICA can access memory (not computer, nor Perica)
bool CanAccess(Memory x[][ROW_MAX], int numRow, int numCol, int row, int col) {
    if ( (row < 0) || (row >= numRow) || (col < 0) || (col >= numCol)) // out of bounds
        return false;

    if ( (x[row][col].Owner == Memory::FREE) || (x[row][col].Owner == Memory::NIKOLA) )
        return true;
    return false;
}

void FillMemoryBFS(Memory x[][ROW_MAX], int numRow, int numCol) {
    queue <Position> qPosition;
    queue <int> qTime;

    qPosition.push(FindS(x, numRow, numCol));
    qTime.push(0);

    while (!qPosition.empty()) {
        Position curPos = qPosition.front();
        int curTime = qTime.front();
        qPosition.pop();
        qTime.pop();

        curTime ++;
        for (unsigned int idx = 0; idx < sizeof(rowInc) / sizeof(rowInc[0]); idx ++) {
            int row = curPos.row + rowInc[idx],
                col = curPos.col + colInc[idx];
            if ( (CanAccess(x, numRow, numCol, row, col)) && (curTime < x[row][col].time) ) {
                x[row][col].time = curTime;
                x[row][col].Owner = Memory::PERICA;
                qPosition.push(Position(row, col));
                qTime.push(curTime);
            }
        }
    }
}

void OutputRam(char x[][ROW_MAX], int numRow, int numCol) {
    for (int row = 0; row < numRow; row ++) {
        for (int col = 0; col < numCol; col ++)
            cout << x[row][col] << " ";
        cout << endl;
    }
}

void OutputMemory(Memory x[][ROW_MAX], int numRow, int numCol) {
    for (int row = 0; row < numRow; row ++) {
        for (int col = 0; col < numCol; col ++)
            cout << x[row][col] << " ";
        cout << endl;
    }
}

int main() {
    if (DEBUG) {
        freopen("ulaz.in", "r", stdin);
        freopen("izlaz.out", "w", stdout);
    }

    int numRow, numCol;
    scanf("%d%d\n", &numRow, &numCol);

    for (int row = 0; row < numRow; row++) {
        for (int col = 0; col < numCol; col++)
            scanf("%c", &ram[row][col]);
        scanf("\n");
    }
    RamToMemory(ram, x, numRow, numCol);

    int numTest;
    scanf("%d", &numTest);
    for (int cnt = 0; cnt < numTest; cnt++) {
        int row, col;
        char dir;
        scanf("%d%d %c\n", &row, &col, &dir);
        row--;
        col--;
        if (x[row][col].Owner != Memory::PERICA) {
            x[row][col].Owner = Memory::NIKOLA;
            x[row][col].dir.insert(dir);
        }
    }

    FillMemoryDir(x, numRow, numCol, 'U');
    FillMemoryDir(x, numRow, numCol, 'D');
    FillMemoryDir(x, numRow, numCol, 'R');
    FillMemoryDir(x, numRow, numCol, 'L');

    FillMemoryBFS(x, numRow, numCol);

    int cnt = 0;
    for (int row = 0; row < numRow; row ++)
        for (int col = 0; col < numCol; col ++)
            if (x[row][col].Owner == Memory::PERICA)
                cnt++;
    printf("%d\n", cnt);

    if (DEBUG) {
        OutputRam(ram, numRow, numCol);
        OutputMemory(x, numRow, numCol);
    }
    return 0;
}
