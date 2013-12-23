#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_PATH 1024

struct dirent *readdir_1(DIR *dp)
{
    struct direct dirbuf;
    static struct dirent d;

    while (read(dp->__dd_fd, (char *) &dirbuf, sizeof(dirbuf))
	    == sizeof(dirbuf)) {
	if (dirbuf.d_ino == 0)
	    continue;
	d.d_ino = dirbuf.d_ino;
	strncpy(d.d_name, dirbuf.d_name, MAXNAMLEN);
	d.d_name[MAXNAMLEN] = '\0';
	return &d;
    }
    return NULL;
}

void closedir_1(DIR *dp)
{
    if (dp) {
	close(dp->__dd_fd);
	free(dp);
    }
}

DIR *opendir_1(char *dirname)
{
    int fd;
    struct stat stbuf;
    DIR *dp;

    if ((fd = open(dirname, O_RDONLY, 0)) == -1
	    || fstat(fd, &stbuf) == -1
	    || (stbuf.st_mode & S_IFMT) != S_IFDIR
	    || (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
	return NULL;
    dp->__dd_fd = fd;
    return dp;
}

void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL)
	return;

    while ((dp = readdir(dfd)) != NULL) {
	if (strcmp(dp->d_name, ".") == 0
	  ||strcmp(dp->d_name, "..") == 0)
	    continue;
	if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(name)) {
	}
	else {
	    (*fcn)(name);
	}
    }
    closedir(dfd);
}

void fsize(char *name)
{
    struct stat stbuf;
    if (stat(name, &stbuf) == -1)
	return;
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
	dirwalk(name, fsize);
    printf("%8lld %s\n", stbuf.st_size, name);
}


int main(int argc, char *argv[])
{
    /*
    char buf[BUFSIZ];
    int n;

    while ((n = read(0, buf, BUFSIZ)) > 0)
	write(1, buf, n);
    */
   if (argc == 1)
       fsize(".");
   else
       while (--argc > 0)
	   fsize(*++argv);

    return 0;
}

