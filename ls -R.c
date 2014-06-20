/********************************
Author:Athira Lekshmi C V
Date:20-06-2014
ls -R command implemtation in C
*******************************/
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int i;
int count;
void recursive_path(char * fname){
	DIR  *dr;
	char * temp;
	char ** fpath;
	struct dirent *dir;
	struct  stat mystat;
	printf("\n%s-\n", fname);
	temp = fname + strlen(fname);
	*temp = '/';
	*++temp = 0;
    if ((dr = opendir(fname)) == 0) 
		perror("Can't open this directory");
		  
    (stat(fname, &mystat));
	count = 0;
	fpath = (char **)malloc(1000*sizeof(char *));
	while ((dir = readdir(dr)) != NULL) {
		if(dir->d_name[0]=='.')
		 continue;
		
		printf("%s\n",dir->d_name);
		strcpy(temp,dir->d_name);
		if(stat(fname,&mystat)<0)
			perror("Stat error\n");
		if(S_ISDIR(mystat.st_mode)){
			fpath[count]=(char*)malloc(strlen(fname)*sizeof(char*));
			strcpy(fpath[count],fname);
			count++;
		}
	}

	closedir(dr);

	for(i=0;i<count;i++){
		recursive_path(fpath[i]);
	}
}
	
		
int main(int argc,char * argv[]){
	recursive_path(argv[1]);
	return 0;
}
