#include <stdio.h>
#include <pthread.h>
#define N 4
int reading[N] = {72, 98, 37, 110}; // HR, SpO2, Temp, BP
void* device(void* arg) {
    int id = *(int*)arg;
    printf("Device %d reading: %d\n", id, reading[id]);
}
int main() {
    pthread_t t[N]; int id[N];
    for (int i=0;i<N;i++){ id[i]=i; pthread_create(&t[i],NULL,device,&id[i]); }
    for (int i=0;i<N;i++) pthread_join(t[i],NULL);
    return 0;
}


// This is
// Part A single process multi threading .