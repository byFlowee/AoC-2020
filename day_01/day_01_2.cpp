#include "../tools.h"
#include <functional>
#include <string>
#include <chrono>
#include <algorithm>

int main(int argc, char *argv[])
{
    auto begin = chrono::high_resolution_clock::now();

    vector<int> values;
    parse_file_int("input1.txt", values);

    sort(values.begin(), values.end());

    int v1, v2, v3;
    for (int i = 0; i < values.size(); ++i)
    {
        v1 = values[i];
        if (v1 > 2018)
            continue;

        for (int j = i; j < values.size(); ++j)
        {
            v2 = values[j];
            if ((v1 + v2) > 2019)
                continue;

            int target = 2020 - (v1 + v2);
            
            if (std::binary_search(values.begin(), values.end(), target))
            {
                cout << v1 << endl << v2 << endl << target << endl;
                goto end;
            }
        }
    }

end:

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();
    cout << duration / 1000000.0 << " milliseconds" << endl;

    return 0;
}
