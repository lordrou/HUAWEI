#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream data("user_behavior_info.csv", ios::in);
    ofstream dataout("processed_behavior.csv", ios::out);
    string LineStr, uid, numstr;
    double functime[7], sum = 0, max_value = 0, cnt = 0;
    int max, count = 0, index = 1;
    while(getline(data, LineStr))
    {
        sum = 0;
        max_value = 0;
        max = 0;
        cnt = 0;
        uid = "";

        int i = 0;
        while (LineStr[i] != ',')
        {
            uid += LineStr[i];
            i++;
            if (i == 7)
            {
                uid += LineStr[i];
                i++;
            }
        }
        i++;
        
        for (int j = 0; j < 7; j++)
        {
            if (i >= LineStr.length())
            {
                break;
            }
            numstr = "";
            while (LineStr[i] != ',')
            {
                numstr += LineStr[i];
                i++;
                if (i >= LineStr.length())
                {
                    break;
                }
            }
            i++;
            functime[j] = stod(numstr);
            sum += functime[j];
            if (j == 0) max_value = functime[j];
            else if (functime[j] > max_value)
            {
                max = j;
                max_value = functime[j];
            }
            if (functime[j] != 0) cnt++;
        }
        dataout << uid << ',' << sum << ',' << max << ',' << cnt << endl;
        count ++;
        if (count == 100)
        {
            cout << "index: " << index << endl;
            index ++;
            count = 0;
        }
    }
    return 0;
}
