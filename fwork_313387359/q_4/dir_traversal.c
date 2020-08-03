#include <ftw.h> 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
int isDirectory(const char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}

int AnalizeDirectoryElement (const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf) {
    struct stat fileStat;
    int fd=0;
    FILE *filename = fpath;

    if ( ( fd = open (filename , O_RDONLY) ) == -1){
        perror ( "open " );
        system("pause");
        exit (1) ;
    }

    if(fstat(fd, &fileStat)<0) return 1;

    printf("Information for %s\n",filename);
if(!isDirectory(fpath))
	printf("type:file \n");
else
	printf("type:dir \n");

    printf("File inode: \t\t%d\n",fileStat.st_ino);
       printf("---------------------------\n");
return 0; }
 void WalkDirectoryTree (const char * pchFileName) {
 int nFlags = 0;
 if (nftw(pchFileName, AnalizeDirectoryElement, 20, nFlags) == -1) { 
perror("nftw"); } }


main(int argc, char *argv[]) { 
char*   pid=argv[1];
printf(pid);
WalkDirectoryTree(pid);
 }


