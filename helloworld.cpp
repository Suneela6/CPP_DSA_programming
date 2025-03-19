#include <iostream>  
#include <fstream>  
using namespace std;  
  
int main() {  
ofstream outputFile("output.txt");  
if (outputFile.is_open()) {  
outputFile << "Hello, File I/O!";  
outputFile.close();  
cout << "File is written successfully." << endl;  
} else {  
cout << "Failed to open the file." << endl;  
}  
return 0;  
}  