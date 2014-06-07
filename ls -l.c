/**************************
 Author:Athira Lekshmi C V
Date:6-6-2014
Implementing ls-l
*************************/
#include <sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define MAXLENGTH 64
#define MAXTIME   300
char file_type(mode_t);
char* file_perms(mode_t);
int main(int argc,char* argv[]){
    DIR *dp;
    struct dirent *dirp;
    struct passwd *user;
    struct group *grp;
    struct tm *tmp;
    struct stat filestat;
    char buf[MAXLENGTH];
    char timebuf[MAXTIME];
    
    if(argc!=2)
         perror("usage:./a.out directory name\n");
    
    if((dp=opendir(argv[1]))==NULL)
         perror("No such file or directory\n");

    while(dirp=(readdir(dp))!=NULL){
            lstat(dirp->d_name,&filestat);
            user = getpwuid(filestat.st_uid);
            //grp = getgruid(filestat.st_gid);
            tmp = localtime(&filestat.st_mtime);
            strftime(timebuf,sizeof(timebuf),"%H:%M:%S",tmp);
            printf("%d  %s %s %s\n",filestat.st_nlink,user->pw_name,timebuf,dirp->d_name);
            printf("%s",file_perms(filestat.st_mode));
    }

    return 0;
}
char* file_perms(mode_t mode){
        char f;
        if(S_ISREG(mode)) f='-';
        if(S_ISDIR(mode)) f='d';
        char perms_buff[30];
        sprintf(perms_buff,"%c%c%c%c%c%c%c%c%c%c",f,
        mode & S_IRUSR ? 'r' : '-',
        mode & S_IWUSR ? 'w' : '-',
        mode & S_IXUSR ? 'x' : '-',
        mode & S_IRGRP ? 'r' : '-',
        mode & S_IWGRP ? 'w' : '-',
        mode & S_IXGRP ? 'x' : '-',
        mode & S_IROTH ? 'r' : '-',
        mode & S_IWOTH ? 'w' : '-',
        mode & S_IXOTH ? 'x' : '-');
        return perms_buff;

}


