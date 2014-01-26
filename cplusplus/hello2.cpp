#include <iostream>
#include <string>

using namespace std;

int main() 
{
   string name;
   cout << "Please enter your first name:";
   cin >> name;
   
//   cout << "*********************" << endl;
//   cout << "*                   *" << endl;
//   cout << "* Hello, " << name << "!  *" << endl;
//   cout << "*                   *" << endl;
//   cout << "*********************" << endl;
   const string greeting = "Hello, " + name + " !";
   const string second(greeting.size(), ' ');
   const string first(second.size(), '*');

   cout << "*" << first << "*" << endl;
   cout << "*" << second << "*" << endl;
   cout << "*" << greeting << "*" << endl;
   cout << "*" << second << "*" << endl;
   cout << "*" << first << "*" << endl;

   return 0;
}


