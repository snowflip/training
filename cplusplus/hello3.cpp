#include <iostream>
#include <string>

using namespace std;

int main() 
{
   string name;

   {
      const string s = "a";
   {
      const string s = "b";
   }
   }
   const string hello = "hello";
   const string message = hello + "!";

   cout << "Please enter your first name:";
   cin >> name;
   cout << "first " << name << endl;
   cin >> name;  
   cout << "second " << name << endl;

   return 0;
}


