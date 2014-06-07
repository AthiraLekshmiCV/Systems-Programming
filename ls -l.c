/******************************
Author:Athira Lekshmi C V
Date:6-6-2014
ls -l command implementation
*****************************/
#include <stdio.h>
#include <dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
    struct dirent *de;          // Pointer for directory entry
    char *ptr;
    struct stat buf;
    struct passwd * usr;
    struct  group *grp;
    struct tm *tme;
    char tmbuf[256];

    DIR *dr = opendir(argv[1]);   // opendir() returns a pointer of DIR type.

    if (dr == NULL)            // opendir returns NULL if couldn't open directory
    {
        printf("Could not opendir current directory" );
        return 0;
    }

    usr=getpwuid(buf.st_uid);
    grp=getgrgid(buf.st_gid);

    while ((de = readdir(dr)) != NULL){
	if(stat(argv[1],&buf)<0){
	    perror("error");
        }
	tme=localtime(&buf.st_mtime);
    strftime(tmbuf,sizeof(tmbuf),"%A %B %H:%M:%S",tme);
    switch (buf.st_mode & S_IFMT) {
        case S_IFDIR:  printf("d ");            break;
        case S_IFREG:  printf("r ");            break;
        default:       printf("- ");            break;
    }
    printf("%s ",usr->pw_name);
    printf("%s ",grp->gr_name);
    printf("%d ",buf.st_nlink);
    printf("%s ",tmbuf);
    printf("%s\n", de->d_name);
    }
    closedir(dr);
    return 0;
}


