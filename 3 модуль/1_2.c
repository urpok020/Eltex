#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]){
    if (argc < 2){
	fprintf(stderr, "Length: %s <side_length>\n", argv[0]);
	return 1; 
    }
    int side_lenght = atoi(argv[1]);
    int side_lenght1 = side_lenght/2;
    int fd[2];
    if (pipe(fd)==-1){
        perror("pipe");
        return -1;
    }
    pid_t pid = fork();
    if (pid < 0){
    	perror("fork");
    	return 1;
    }
    if (pid == 0){
    	close (fd[0]);
    	int area = side_lenght * side_lenght1;
    	write (fd[1], &area, sizeof(area));
    	close(fd[1]);
    }
    else{
    	close (fd[1]);
    	int child_area;
    	read(fd[0], &child_area, sizeof(child_area));
    	if (side_lenght%2!=0){
            side_lenght1+=1;
    	}
    	int area = side_lenght * side_lenght1 +  child_area;
    	printf("lenght: %d, res: %d", side_lenght, area);
    	close (fd[0]);
    }
    return 0;
}
