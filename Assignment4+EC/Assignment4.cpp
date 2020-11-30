//
//
//  Assignment 4
//
//  Created by Phoebe ZOU on 11/29/20.
//

#include "Assignment4.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <iostream>

Assignment4::Assignment4(int args, char** argv){
    if(args == 0){
        head = 0;
    }else{
        head = atoi(argv[0]);
    }
}


int Assignment4::fcfs(int a[], int size, int head){
    int h = head, moves = 0;
    for(int i = 1; i<size; i++){
        moves+=abs(h-a[i]);
        h=a[i];
    }
    return moves;
}

int Assignment4::sstf(int a[], int size, int head){
    int b1[size], b2[size], index, shortest, moves = 0;
    for(int i = 0; i<size; i++){
        b1[i]=a[i]; //the copy of a[]
    }
       for(int i=0; i<size; i++)
       {
           index = 0;
           shortest = INT_MAX;
    
           for(int k=0; k<size; k++)
           {
               if(abs(head - b1[k]) < shortest && !b2[k])
               {
                   index = k;
                   shortest = abs(head - b1[k]);
               }
           }
    
           b2[index] = true;
           moves += shortest;
           head = b1[index];
       }
    
    return moves;
}

int Assignment4::scan(int a[], int size, int head){
    int b1[size], b2[size],h=head, moves = 0,count1=0, count2=0;
        for(int i = 0; i<size; i++){
            if(h>=a[i]){
                b1[count1]=a[i]; //array smaller than head
                count1++;
            }else{
                b2[count2]=a[i];  //array larger than head
                count2++;
            }
        }
    sortDES(b1, count1);
    sortASE(b2, count2);
    
    //moves = (head -> small) + small + (small -> 0) + ( 0->large) + large
    moves = fcfs(b1,count1,h)+ b1[count1-1]+b2[0]+fcfs(b2,count2,h);
    return moves;
}
    int Assignment4::c_scan(int a[], int size,int head){
        int b1[size], b2[size],h=head, count1=0, count2=0, moves = 0;
        for(int i = 1; i<size; i++){
            if(a[i]<=h){
                b1[count1]=a[i]; //smaller than head
                count1++; //actual size of b1
            }else{
                b2[count2]=a[i];  //larger than head
                count2++;  //actual size of b2
            }
        }
        sortASE(b1, count1);
        sortASE(b2, count2);
        
        //(head->large)+large+(large -> max) + (max -> 0)+ (0->small) + small
        moves = (b2[0]-h) + fcfs(b2, count2,h) + (maxCylinders-b2[count2-1]) + maxCylinders + b1[0]+fcfs(b1, count1,h);
        return moves;
    }
    
    int Assignment4::look(int a[], int size, int head){
        int b1[size], b2[size],h=head, moves = 0;
        int count1=0, count2=0;
            for(int i = 1; i<size; i++){
                if(h>=a[i]){
                    b1[count1]=a[i]; //array smaller than head
                    count1++;
                }else{
                    b2[count2]=a[i];  //array larger than head
                    count2++;
                }
            }
        sortDES(b1, count1);
        sortASE(b2, count2);

        //moves = small + (small->large) + large
        moves = fcfs(b1,count1,h)+ (b2[0]-b1[count1-1])+fcfs(b2,count2,h);
        return moves;
    }
    int Assignment4::c_look(int a[], int size, int head){
        int b1[size], b2[size],h=head, count1=0, count2=0, moves = 0;

        for(int i = 1; i<size; i++){
            if(a[i]<=h){
                b1[count1]=a[i]; //smaller than head
                count1++; //actual size of b1
            }else{
                b2[count2]=a[i];  //larger than head
                count2++;  //actual size of b2
            }
        }
        sortASE(b1, count1);
        sortASE(b2, count2);
        

        //moves=(head -> large)+large+(large->small)+small
        moves =(b2[count2-1]-h)+fcfs(b2,count2,h)+(b2[count2-1]-b1[0])+fcfs(b1, count1,h);
        return moves;
    }
void Assignment4::sortASE(int b[], int size) {
   for(int i = 0; i<size; i++){
        for(int j = i+1; j<size; j++){
            if(b[i]>=b[j]){
                int temp1 = b[i];
                b[i] = b[j];
                b[j] = temp1;
                
            }
            
        }
        
    }
}
void Assignment4::sortASE(int b[], int a[], int size) {
   for(int i = 0; i<size; i++){
        for(int j = i+1; j<size; j++){
            if(b[i]>=b[j]){
                int temp1 = b[i];
                b[i] = b[j];
                b[j] = temp1;
                int temp2 = a[i];
                a[i] = a[j];
                a[j] = temp2;
            }
            
        }
        
    }
}
    void Assignment4::sortDES(int b[], int size) {
       for(int i = 0; i<size; i++){
            for(int j = i+1; j<size; j++){
                if(b[i]<=b[j]){
                    int temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }
                
            }
            
        }
    }

