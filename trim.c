#include <stdio.h>

int strlen(char *s)
{
/*
	char *d = s;
	while (*d != '\0') {
		d++;
	}
*/
	char *d;
	for (d = s; *d != '\0'; d++);
	return d - s;
}

void reverse(char *s)
{
/*
	char c;
	int l = strlen(s);
	int i;
	for (i = 0; i < l / 2; i++)
	{
		c = *(s + i);
		*(s + i) = *(s + l - i - 1);
		*(s + l - i - 1) = c;
	}
*/
	char c;
	int i, j;
	int l = strlen(s);
	for (i = 0, j = l; i < j; i++, j--) {
		c = *(s + i);
		*(s + i) = *(s + j - 1);
		*(s + j - 1) = c;
	}
}

int trim_right(char *s)
{
	char *end;
	char c;
	
	for (end = s + strlen(s); end != s; end--) {
		if (((c = *(end -1)) != ' ') && (c != '\t') && (c != '\n')) break;
	}

	*end = '\0';
        return end - s;
}

int trim_left(char *s)
{
	int l = strlen(s);
	char *index;
	char c;
	int count = 0;
	for (index = s; *index != '\0'; index++) {
		if (((c = *index) != ' ') && (c != '\t') && (c != '\n')) break;	
		count++;
	}
	if (index != s) {
	/*
		while (*index != '\0') {
			*s = *index;
			index++;
			s++;
		}
		*s = '\0';
	*/
		while (*s++ = *index++);
	}
	return l - count;
}

void trim_single(char *s) {
	char *index = s;
	char *temp;
	char c;

	while((c = *index) == ' ') {
		index++;
	}
	while ((c = *index) != '\0') {
		if (c != ' ') {
		    *s++ = *index++;
		    continue;
		} else {
	            for (temp = index+1; *temp != '\0'; temp++) {
			if (*temp != ' ') {
			    *s++ = *index++;
			    break;
			}
		    }
	            if (*temp == '\0') break; 	    
		}
	} 
	*s = '\0';
}

void trim(char *s, char *d)
{
        char *t;
	char c;
	while ((c = *s) == ' ') {
		s++;
	}
	while ((c = *s) != '\0') {
		if (c != ' ') {
                    //printf("%c\n", c);
		    *d++ = *s++;
		    continue;
		} else {
                    for (t = s+1; *t != '\0'; t++) {
			if (*t != ' ') {
                           //printf("space need %c\n", *t);
                           *d++ = *s++;
			   break;
			} 
		    }
		    if (*t == '\0') break; 
		}
	}
        *d = '\0';
}

char *strstr(char *s, char *d)
{
	char *i;
	char *p;
	while (*s != '\0') {
		p = s;
		i = d;
		if (strlen(p) < strlen(i)) return NULL;
		while (*i != '\0') {
			if (*i != *p) break;
			i++;
			p++;
		}		
		if (*i == '\0') return s;
		s++;
	}

	return NULL;
}

int  main() {
     char s[] = "abcd";
     //char d[] = "aaa";
     //char *p;
     //char s[] = " c  aaa bbb d   ";
     //char s[] = "      a       ";
     //char d[10];
     reverse(s);
     //printf("%s\n", d);
     //p = strstr(s, d);     
     //trim_single(s);
     printf("%s\n", s);
     return 0;
}
