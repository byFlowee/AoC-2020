#include <iostream>
#include "tools.h"

int main(int argc, char *argv[])
{
    ifstream in("input1.txt", ios::in);

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
        int valid_counter {};
        char target {}; 

        while (*it)
        {
            int l {}, h {};
            char *v_start = it;
            while (*it != '-')
            {
                ++it;
            }
            *it = '\0';
            //cout << v_start << "-";
            l = stoi(v_start);

            ++it;
            v_start = it;

            while (*it != ' ')
            {
                ++it;
            }
            *it = '\0';
            //cout << v_start << " ";
            h = stoi(v_start);

            // next character is our target
            target = *(it + 1);
            //cout << target << " : ";

            //advance to first character of the password
            it += 4;
            v_start = it;

            int occurrences {};
            while (*it != '\n')
            {
                if (target == *it)
                {
                    ++occurrences;
                }
                ++it;
            }
            *it = '\0';
            //cout << v_start << endl;
            if (occurrences >= l && occurrences <= h) ++valid_counter; 

            ++it;
        }

        cout << valid_counter << endl; 
    }
    else
    {
        cout << "IO Error" << endl;
    }

    return 0;
}
