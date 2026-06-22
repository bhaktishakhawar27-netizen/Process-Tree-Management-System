#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX 50

struct ProcessInfo {
    int pid;
    int ppid;
};

struct ProcessInfo processList[MAX];
int processCount = 0;

// store process info (only parent will use this)
void storeProcess(int pid, int ppid) {
    processList[processCount].pid = pid;
    processList[processCount].ppid = ppid;
    processCount++;
}

// display table
void displayTable() {
    if (processCount == 0) {
        printf("\nNo data available!\n");
        return;
    }

    printf("\nPID\tPPID\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t%d\n", processList[i].pid, processList[i].ppid);
    }
}

// create processes (chain type)
void createProcesses(int level, int maxLevel) {

    if (level > maxLevel)
        return;

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    }

    if (pid == 0) {
        // child
        printf("Level %d -> PID=%d PPID=%d\n",
               level, getpid(), getppid());

        sleep(15);  // so we can see in pstree

        createProcesses(level + 1, maxLevel);

        exit(0);
    } else {
        // parent
        storeProcess(pid, getpid());
        wait(NULL);
    }
}

// show simple tree
void showTree(int levels) {
    if (levels == 0) {
        printf("\nNo tree yet\n");
        return;
    }

    printf("\nParent\n");
    for (int i = 1; i <= levels; i++) {
        for (int j = 1; j < i; j++)
            printf("   ");
        printf("|-- Level %d\n", i);
    }
}

// reset
void resetData() {
    processCount = 0;
    printf("\nData cleared\n");
}

int main() {

    int choice, levels = 0;

   do{
            printf("\n*******PROCESS TREE MENU******\n1.Create\n2.Table\n3.Tree\n4.Reset\n5.Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
    
            switch (choice) {
    
            case 1:
                printf("Enter levels (1-5): ");
                scanf("%d", &levels);
    
                if (levels <= 0 || levels > 5) {
                    printf("Invalid input\n");
                    break;
                }
    
                printf("\nParent PID=%d\n", getpid());
                storeProcess(getpid(), getppid());
    
                createProcesses(1, levels);
    
                printf("\nRun in another terminal:\n");
                printf("pstree -p %d\n", getpid());
    
                sleep(20);  // keep alive for pstree
                break;
    
            case 2:
                displayTable();
                break;
    
            case 3:
                showTree(levels);
                break;
    
            case 4:
                resetData();
                break;
    
            case 5:printf("\nThanks for using our software");
                    break;
    
            default:
                printf("Wrong choice\n");
            }
    }while(choice!=5);

    return 0;
}