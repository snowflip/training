#include <stdio.h>

void trim_mid_space(char *s, char *d)
{
	char c;
	char *temp;
	while ((c = *s) != '\0') {
		*d++ = *s++;
		if (c == ' ') {
		   for (temp = s; *temp != '\0'; temp++) {
			if (*temp == ' ') s++;
			else break;
		   }
		   if (*temp == '\0') {
			*d = '\0';
			return;
		   }
		}
	}
	*d = '\0';
}


int main()
{
    char s[] = "a    bc  d  ";
    char d[20];
    trim_mid_space(s,d);

    printf("%s\n", s);
    printf("%s\n", d);
   
    return 0;
}
