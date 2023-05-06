#include "iostream"
#include "vector"
#include "string"
#include "fstream"
#include "algorithm"

using namespace std;

#define n_between 96 /* Code difference between half-width and full-width numbers　*/
#define c_between 85 /* Code difference between half-width and full-width conmma　*/
#define p_between 84 /* Code difference between half-width and full-width period */

string format_number(string s)
{

    for (size_t i = 0; i < s.size(); i++)
    {
        if ((int)(unsigned char)s[i] == 239)
        {
            s.erase(i, 2);
            s[i] -= n_between;
        }
    }
    return s;
}

string format_character(string s)
{

    for (size_t i = 0; i < s.size(); i++)
    {
        if ((int)(unsigned char)s[i] == 227)
        {
            if ((int)(unsigned char)s[i + 1] == 128)
            {
                if ((int)(unsigned char)s[i + 2] == 129)
                {
                    s.erase(i, 2);
                    s[i] -= c_between;
                }
                else if ((int)(unsigned char)s[i + 2] == 130)
                {
                    s.erase(i, 2);
                    s[i] -= p_between;
                }
            }
        }
    }
    return s;
}

string format_blank(string s)
{

    string tmp;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ',')
        {
            tmp += s[i];
            tmp += " ";
        }
        else
        {
            tmp += s[i];
        }
    }

    return tmp;
}

int main(int argc, char *argv[])
{

    // reading file from command line
    ifstream reading_file;
    reading_file.open(argv[1], ios::in);
    if (!reading_file)
    {
        cout << "Could not open file" << endl;
        cin.get();
        return 0;
    }

    // writing file
    ofstream writing_file("output.tex");
    if (!writing_file)
    {
        cout << "Could not open file" << endl;
        cin.get();
        return 0;
    }

    int number_flag = atoi(argv[2]);
    int character_flag = atoi(argv[3]);

    // reading per lines
    string reading_line;
    while (getline(reading_file, reading_line))
    {
        if(number_flag) reading_line = format_number(reading_line);
        if(character_flag) reading_line = format_character(reading_line);
        reading_line = format_blank(reading_line);

        writing_file << reading_line << endl;
    }

    cout << "Complete Conversion!" << endl;
}