//
//  Assignment 4.h
//  Assignment 4
//
//  Created by Phoebe ZOU on 11/29/20.
//

#ifndef Assignment4_h
#define Assignment4_h
class Assignment4{
private:
    int moves = 0;  //calculate thr final moves
    int maxCylinders = 5000;  //max cylinders
    int maxRequests = 10;  //max requests
    int head;  //head value
    
public:
    Assignment4(int args, char** argv);
    int getHead(){ return head;}
    void setHead(int a){head = a;}
    int getMaxCylinders() { return maxCylinders;}
    int getMaxRequest() {return maxRequests;}
    int getMoves(){return moves;}
    int fcfs(int[],int,int);  //first come first serve
    int sstf(int[],int,int);  //shortest seek time first
    int scan(int[], int, int);  //elevator algorithm
    int c_scan(int[], int, int);  //reverse elevator algorithm
    int look(int[], int,int);  //reach the max and min bound [0, 4999]
    int c_look(int[], int, int);  //reach the max and min in the queue
    bool comp(int a, int b){return a<b;}
    void sortASE(int[], int);
    void sortASE(int[], int[], int);
    void sortDES(int[], int);
};
#endif /* Assignment_4_h */
