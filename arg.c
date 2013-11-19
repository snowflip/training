#include <stdio.h>

int main(int argc, char *argv[])
{
	char *v;
	char c;
	while (--argc > 0) {
		v = *++argv;		
		if (*v == '-') {
			while ((c = *++v) != '\0') {
				switch (c) {
					case 'n':
						printf("print num\n");
						break;
					case 'x':
						printf("print except\n");
						break;
					default:
						printf("not legal option\n");
						return -1;
				}
			}
		} else 
			break;
	}
	if (argc !=  1)
		printf("usage:%s -option pattern\n", argv[0]);
	else 
		printf("pattern is %s\n", v);

	return 0;
}
/*
{
	if (argc < 2)
		printf("usage:%s -option pattern\n", argv[0]);
	
	char *v;
	char c;
	int has_pattern = 0;
	while (--argc > 0) {
		v = *++argv;		
		if (*v == '-') {
			while ((c = *++v) != '\0') {
				switch (c) {
					case 'n':
						printf("print num\n");
						break;
					case 'x':
						printf("print except\n");
						break;
					default:
						printf("not legal option\n");
						break;
				}
			}
		} else {
			has_pattern = 1;
			printf("pattern is %s\n", v);		
			break;
		}
	}
	if (!has_pattern) {
		printf("error:need pattern\n");
	}

	return 0;
}*/
