//Author:Athira Lekshmi C V
//Date:6-6-2014
//ls command implementation in C
#include <sys/types.h>
#include<stdio.h>
#include<dirent.h>
int main(int argc,char* argv[]){
    DIR *dp;            //Represents the directory stream
    struct dirent *dirp;//To list the directory name
    if(argc!=2)
        perror("usage:./a.out directory name\n");
    if((dp=opendir(argv[1]))==NULL)
            perror("No such file or directory\n");

    while((dirp=readdir(dp))!=NULL)
            printf("%s\n",dirp->d_name);
    return 0;
}
