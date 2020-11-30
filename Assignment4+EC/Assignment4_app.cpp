//
//  Assignment4_app.cpp
//  Assignment 4
//
//  Created by Phoebe ZOU on 11/29/20.
//

#include <stdio.h>
#include "Assignment4.h"
#include <stdlib.h>

int main(int arg, char** argv){
    Assignment4 a = Assignment4(arg,argv);
    
    
    int arr[a.getMaxRequest()];
    int temp[a.getMaxRequest()];
    
    for(int i = 0; i<a.getMaxRequest(); i++){
        arr[i]=rand()%5000;
        temp[i] = arr[i];
        //printf("%d \n",temp[i]);
    }
    if(a.getHead()==0){
        a.setHead(arr[0]);
    }
    printf("head: %d\n", a.getHead());
    
    printf("using FCFS: \n\tthe total moves = %d\n", a.fcfs(temp,a.getMaxRequest(),a.getHead()));
    printf("using SSTF: \n\tthe total moves = %d\n", a.sstf(temp,a.getMaxRequest(),a.getHead()));
    printf("using SCAN: \n\tthe total moves = %d\n", a.scan(temp,a.getMaxRequest(),a.getHead()));
    printf("using C-SCAN: \n\tthe total moves = %d\n", a.c_scan(temp,a.getMaxRequest(),a.getHead()));
    printf("using LOOK: \n\tthe total moves = %d\n", a.look(temp,a.getMaxRequest(),a.getHead()));
    printf("using C-LOOK: \n\tthe total moves = %d\n", a.c_look(temp,a.getMaxRequest(),a.getHead()));

    return 0;
}
