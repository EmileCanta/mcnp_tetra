#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void changeinput(const char* filename, const char* text, long unsigned int line_number)
{
    fstream read_file;
    
    read_file.open(filename);
    
    if(read_file.fail())
    {
        cout << "Error opening file." << endl;
    }
    
    vector<string> lines;
    string line;
    
    while(getline(read_file, line))
    {
        lines.push_back(line);
    }
    
    read_file.close();
    
    if(line_number > lines.size())
    {
        cout << "Line " << line_number;
        cout << " not in file." << endl;
        
        cout << "File has " << lines.size();
        cout << " files." << endl;
    }
    
    ofstream write_file;
    
    write_file.open(filename);
    
    if(write_file.fail())
    {
        cout << "Error opening file." << endl;
    }
    
    line_number--;
    for(long unsigned int i=0; i < lines.size(); i++)
    {
        if(i != line_number) write_file << lines[i] << endl;
        
        else write_file << text << endl;
    }
    
    write_file.close();
}

