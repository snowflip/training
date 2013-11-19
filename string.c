#include <stdio.h>

int strlen(char *s)
{
/*
	char *d = s;
	while (*d != '\0') {
		d++;
	}
*/
/*
	char *d;
	for (d = s; *d != '\0'; d++);
	return d - s;
*/
	char *p = s;
	while (*p != '\0') 
		p++;
	return p - s;
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
	//char c;
	int i, j, c;
	int l = strlen(s);
	for (i = 0, j = l - 1; i < j; i++, j--) {
		c = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = c;
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

void squeeze(char *s, int c)
{
	char *p, *q;
	while (*s != '\0') {
		if (*s == c) {
		    for (q = s, p = s + 1; *p != '\0'; p++)
			if (*p != c) break;
/*		    q = s;
		    p = s + 1;
		    while (*p != '\0') {
			if (*p != c) break;
			p++;
		    } */
		    while ((*q++ = *p++) != '\0');
		} else s++;
	}	
}

void squeeze_only_one(char *s, int c)
{
//	int ch;    
	char *q, *p;
	while (*s != '\0') {
		if (*s == c) {
		    /*p = s + 1;
		    q = p;
		    while ((ch = *p) != '\0') { 
			if (ch != c) break;
			p++;
		    }*/
		    for (p = s + 1, q = p; *p != '\0'; p++)
			if (*p != c) break;
		    if (p != q)
			while ((*q++ = *p++) != '\0');
		}
		s++;
	}
}

char *strchr(char *s, int c)
{
	while (*s != '\0') {
		if (*s == c) return s;
		s++;
	}
	return NULL;
}

char *strrchr(char *s, int c)
{
	int l = strlen(s);
	while (l > 0) {
		if (*(s + l - 1) == c) return s + l - 1;
		l--;	
	}
	return NULL;
}

int  main() {
     char s[] = "aaabaabaa";
     //char d[] = "aaa";
     //char *p;
     //char s[] = " c  aaa bbb d   ";
     //char s[] = "      a       ";
     //char d[10];
     //reverse(s);
 //    squeeze_only_one(s, 'a');
//     squeeze(s, 'a');
     //printf("%s\n", d);
     //p = strstr(s, d);     
     //trim_single(s);
     printf("s is %s\n", s);
     char *q = strchr(s, 'a');
     printf("strchr is %s\n", q);
     char *p = strrchr(s, 'a');
     printf("strrchr is %s\n", p);
     return 0;
}
