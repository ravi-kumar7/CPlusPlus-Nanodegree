#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;

int main() 
{
    string a("1 2 3");

    istringstream my_stream(a);
    int n;
    
    // Testing to see if the stream was successful and printing results.
    while (my_stream) {
        cout << "That stream was successful: " << n << "\n";
        my_stream >> n;
    }
}