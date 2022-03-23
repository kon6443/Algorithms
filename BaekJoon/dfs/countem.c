#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int countNumber(char *path);
int num = 0; // for saving the result

int main(int argc, char *argv[]) {
    
    char path[1024];
    
    if(argc == 1) {
        printf("No directory argument supplied.\n");
        return 1;
    } else if(argc == 2) { // when the number of parameter is only one.
        strcpy(path, argv[1]);
        printf("Total #: %d\n", countNumber(path));
    } else {    // when the # of parameter is not only one.
        printf("argument must be one.\n");
        return 1;
    }

    return 0;
}

int countNumber(char *path) {
    DIR *d;
    struct dirent *file;
    struct stat fileStat;
    
    if(chdir(path) < 0) {   // change the current directory into path
        printf("error: chdir..\n");
        exit(1);
    }
    if((d = opendir(".")) == NULL) {    //open the current directory
        printf("error: opendir..\n");
        exit(1);
    }
    while((file = readdir(d))) {
            if(file->d_name[0]=='.') continue;  // skip the hidden directories starting with .
            stat(file->d_name, &fileStat);  // get the current status informatiion
            num = num + 1;  // the # of (directories and files) ++
            if(S_ISDIR(fileStat.st_mode)) { // if a file is directory, then run the function again inside of the directory.
                countNumber(file->d_name);
            }
    }
    closedir(d);    // close the directory d
    chdir("..");    // change the current directory into ..(upper level directory);
    return num; // return the # of (directories and files)
}
