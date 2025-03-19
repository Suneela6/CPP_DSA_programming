// #include <iostream>  
// #include <fstream>  
// using namespace std;  
// int main () {  
//   ofstream filestream("testout.txt");  
//   if (filestream.is_open())  
//   {  
//     filestream << "Welcome to javaTpoint.\n";  
//     filestream << "C++ Tutorial.\n";  
//     filestream.close();  
//   }  
//   else cout <<"File opening is fail.";  
//   return 0;  
// }  


#include <iostream>  
#include <fstream>  
using namespace std;  
int main () {  
  string srg;  
  ifstream filestream("testout.txt");  
  if (filestream.is_open())  
  {  
    while (getline(filestream,srg) )  
    {  
      cout << srg <<endl;  
    }  
    filestream.close();  
  }  
  else {  
      cout << "File opening is fail."<<endl;   
    }  
  return 0;  
}  