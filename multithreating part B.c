#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
void* dev(void* a){ printf("PID %d Device %d\n", getpid(), *(int*)a); }
int main() {
    for (int s=0; s<2; s++) {
        if (fork()==0) {
            pthread_t t[2]; int id[2]={0,1};
            for(int i=0;i<2;i++) pthread_create(&t[i],NULL,dev,&id[i]);
            for(int i=0;i<2;i++) pthread_join(t[i],NULL);
            _exit(0);
        }
    }
    for (int s=0; s<2; s++) wait(NULL);
    return 0;
}

// This is 
// Part B multi process and multi threading mam
