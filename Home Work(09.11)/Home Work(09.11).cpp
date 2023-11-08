#include <iostream>
#include <ctime> 
using namespace std;

void  AddColumn(int**& ar, int columns, int rows, int symbol, int id) {
    int** temp = new int* [columns];
    for (int y = 0; y < columns; y++)
    {
        temp[y] = new int[rows + 1];
        for (int x = 0; x < rows + 1; x++)
        {
            if (x == id)
            {
                temp[y][x] = symbol;
            }
            else if (x > id) {
                temp[y][x] = ar[y][x - 1];
            }
            else {
                temp[y][x] = ar[y][x];
            }
        }
    }
    for (int y = 0; y < columns; y++) {
        delete[] ar[y];
    }
    delete[] ar;

    ar = temp;
}

void AddRow(int**& ar, int columns, int rows, int symbol, int id) {
    int** temp = new int* [columns + 1];
    for (int y = 0; y < columns + 1; y++)
    {
        temp[y] = new int[rows];
        if (y < id) {
            for (int x = 0; x < rows; x++)
            {
                temp[y][x] = ar[y][x];
            }
        }
        else if (y == id) {
            for (int x = 0; x < rows; x++)
            {
                temp[y][x] = symbol;
            }
        }
        else {
            for (int x = 0; x < rows; x++)
            {
                temp[y][x] = ar[y - 1][x];
            }
        }
    }
    for (int y = 0; y < columns; y++) {
        delete[] ar[y];
    }
    delete[] ar;

    ar = temp;
}

int main()
{
    srand(time(NULL));

    unsigned int rows;
    unsigned int columns;
    unsigned int id;
    cout << "Enter rows";
    cin >> rows;
    cout << "Enter columns";
    cin >> columns;
    cout << "Enter position";
    cin >> id;
    int** ar = new int* [columns];

    for (int y = 0; y < columns; y++) {
        ar[y] = new int[rows];
        for (int x = 0; x < rows; x++) {
            ar[y][x] = rand() % 5;
            cout << ar[y][x] << " ";  
        }
        cout << "\n";
    }
    cout << "\n\n\n";

    AddRow(ar, columns, rows, 0, id);

    for (int y = 0; y < columns + 1; y++) {
        for (int x = 0; x < rows; x++) {
            cout << ar[y][x] << " ";
        }
        cout << "\n";
    }

    cout<<"\n\n\n\n\n";
    AddColumn(ar, columns +1, rows, 0, id);

    for (int y = 0; y < columns +1; y++) {
        for (int x = 0; x < rows +1; x++) {
            cout << ar[y][x] << " ";
        }
        cout << "\n";
    }
    for (int y = 0; y < columns + 1; y++) {
        delete[] ar[y];
    }
    delete[] ar;

}