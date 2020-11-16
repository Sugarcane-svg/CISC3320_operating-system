//
//  main.cpp
//  pid
//
//  Created by Phoebe ZOU on 9/17/20.
//  Copyright © 2020 Phoebe ZOU. All rights reserved.
//

#include <iostream>
#include <unistd.h>

using namespace std;

int allocate_pid(int a[], int size); //assign pid into location
int allocate_map(int a[], int size); //use array to store pid
void release_pid(int a[], int pid, int size); //reset location

const int MIN_PID = 300;
const int MAX_PID = 5000;
int main(int argc, const char * argv[]) {
   
    int size = MAX_PID-MIN_PID;
    int pidArr[size];
    
    //make sure the location is created
    printf("*allocate map state ----\n");
    int map = allocate_map(pidArr, size);
    if(map == -1){
        cout<<"map failed\n\n";
        exit(1);
    }else{
        cout<<"map succeed\n\n";
    }
    
    //check the pid
    printf("*pid assign state ----\n");
    int pid = allocate_pid(pidArr,size);
    if(pid == -1){
        cout<<"pid is not assigned"<<endl<<endl;
        exit(1);
    }else{
        cout<<"pid: "<<pid<<endl<<endl;
    }
    
    
    //make location avaliable for next pid
    printf("*release a pid? enter the pid\n");
    int key;
    //read in the required pid
    cin>>key;
    release_pid(pidArr, key, size);
    
    
    return 0;
}

//populate an array, succeed=1, failed = -1
int allocate_map(int a[], int size){
    
    for(int i = 0; i<size; i++){
        a[i]=0;
        if(i == size-1) return 1;
    }
    return -1;
}

//assign pid with avaliable space
int allocate_pid(int a[], int size){
    for(int i = 0; i<size; i++){
        if(a[i]==0){
            //1 indicates this location is in used
            a[i]=1;
            return MIN_PID+i;
        }
        
    }
    return -1;
}

//search whole array to find the required pid and release it
void release_pid(int a[], int pid, int size){
    if(a[pid-MIN_PID]==1){
        a[pid-MIN_PID]=0;
        cout<<"pid: "<<pid<<" is release from position "<<pid-MIN_PID+1<<endl;
    }else{
        cout<<"pid not found"<<endl;
    }
}










