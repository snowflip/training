#include <stdio.h>

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

int  main() {
     //char s[] = " c  aaa bbb d   ";
     char s[] = "      a       ";
     //char d[10];
     //trim(s, d);
     //printf("%s\n", d);
     
     trim_single(s);
     printf("%s\n", s);
     return 0;
}
