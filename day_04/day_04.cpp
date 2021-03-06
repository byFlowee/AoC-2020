#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool is_valid(string &passport)
{
    if (passport.find("byr:") == string::npos) return false;
    if (passport.find("iyr:") == string::npos) return false;
    if (passport.find("eyr:") == string::npos) return false;
    if (passport.find("hgt:") == string::npos) return false;
    if (passport.find("hcl:") == string::npos) return false;
    if (passport.find("ecl:") == string::npos) return false;
    if (passport.find("pid:") == string::npos) return false;
           
    return true;
}

int main(int argc, char *argv[])
{
    fstream in("input.txt", ios::in);

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
        char *passport = input;
        vector<string> passports;
        passports.reserve(size);

        while (*it)
        {
            if (*it == '\n' && *(it + 1) == '\n')
            {
                it++;
                *it = '\0';

                passports.push_back(passport);
                it++;
                passport = it;

                continue;
            }

            it++;
        }

        int valid {};
        for (auto p : passports)
        {
            if (is_valid(p)) ++valid;
        }

        delete [] input;

        cout << valid << endl;
    }
    else
    {
        cout << "I/O Error: cannot open input file." << endl;
    }

    return 0;
}
