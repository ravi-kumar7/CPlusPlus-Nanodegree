#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::ifstream;
using std::string;

void ReadBoardFile(string path)
{
    ifstream myfile;
    myfile.open(path);
    if(myfile)
    {
        cout<<"The file stream is opened!\n";
        string line;
        while(getline(myfile,line)){
            cout<<line<<"\n";
        }
    }
    else
    cout<<"Unable to open";
}

int main()
{
    ReadBoardFile("files/1.board");
}