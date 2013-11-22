#include <stdio.h>

int daytab[][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap_year(int year)
{
	return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100) != 0));
}

int day_of_year(int year, int month, int day)
{
	int i, yearday;
	yearday = 0;
	int leap = is_leap_year(year);
	for (i = 1; i < month; i++)
		yearday += daytab[leap][i];
	yearday += day;

	return yearday;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap = is_leap_year(year);
	int i = 1;
	while (yearday > daytab[leap][i]) {
		yearday -= daytab[leap][i];
		i++;
	}
	*pmonth = i;
	*pday = yearday;
}


int main()
{
	int day = day_of_year(2001, 3, 5);
	printf("day is %d\n", day);
	
	int month;
	month_day(2002, 65, &month, &day);
	printf("month %d day %d\n", month, day);

	return 0;
}
