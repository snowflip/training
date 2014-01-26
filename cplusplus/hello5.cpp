#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	cout << "Hello, " << name << "!" << endl;

	cout << "Please enter midterm and final: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter all your homework grades";
	
	vector<double> homework;
	double x;
	while (cin >> x)
		homework.push_back(x);

	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "try again" << endl;
		return 1;
	}
	sort(homework.begin(), homework.end());
	
	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
			       : homework[mid];
	streamsize prec = cout.precision();
	cout << "final grade is " << setprecision(3)
	     << 0.2 * midterm + 0.4 * final + 0.4 * median
	     << setprecision(prec) << endl;
	return 0;
}
