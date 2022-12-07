#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
//#include <cstdlib>
//#include <iostream>
#include <time.h>


/*Xavier Vaughn
@02928026
*/
void ChildProcess(int);
void ParentProcess(void);
int cProcComplete = 0;

int main(){

    pid_t pid1;

    srand(time(NULL));

    for(int i = 0; i < 2; i++){
        pid1 = fork();
        if(pid1 == 0){
            ChildProcess(i);
        }
    }
    ParentProcess();
}
    
void ChildProcess(int ppid){
    int loopI = random()%30;
    int childID = getpid();
    int parentID = getppid();

    while(loopI != 0){
        printf("Child Pid: %d is going to sleep!\n", childID);
        sleep(rand()%10);
        
        printf("Child %i is awake!\nWhere is my Parent: %d ?\n", childID, parentID);
        loopI--;
    }
 cProcComplete++;
    exit(0);
}

void ParentProcess(){
    int i;
    int cID;
    int status;

    for(int i = 0; i < 2; i++){
        cID = wait(&status);
        printf("Child Pid: %d has completed\n", cID);
    }
}
