#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in("input1.txt", ios::in);
    ofstream out("output.txt", ios::out);

    if (in)
    {
        in.seekg(0, ios::end);
        int size = in.tellg();
        char *input = new char [size + 1];
        in.seekg(0, ios::beg);
        in.read(input, size);
        input[size] = 0;
        in.close();
  
        char *it = input;

        int len_row {31};

        cout << len_row << endl;

        it = input;
        int trees {};
        int x {2};

        it += len_row + 3;
        int skip {len_row / 3};
        int skips {0};
        cout << skip << endl;
        int i {1};

        while (*it)
        {
            if (*it == '#') ++trees;
            *it = 'O';

            if (i == skip)
            {
                ++skips;
                it += 3;
                if (skips == 3) 
                { 
                    i = 0; 
                    skips = 0;
                }
                else 
                    i = 1;
            }
            else
            {
                it += len_row + 3;
                ++i;
            }
        }
        
        cout << trees << endl;
        if (out)
        {
            out.write(input, size);
        }
    }
    else
    {
        cout << "I/O Error: couldnt open file" << endl;
    }


  return 0;
}
