/*
here in regular scenario,
the points are 15,15,10,10 to win.
However if both reach 15,15,10,
then the players need to have a
difference of 20 as advantage gives
10 points.
*/

#include<bits/stdc++.h>
using namespace std;

// to make sure the points are 0,10 and 15
bool pointValidityCheck(int arr1[],int arr2[],int size1,int size2){
    int flag=true;
    for(int i=0;i<size1;i++){
        if(!((arr1[i]==0||arr1[i]==15||arr1[i]==10)&&(arr2[i]==0||arr2[i]==15||arr2[i]==10))){
            int column=i;
            cout<<"Invalid Points in column number: "<<column+1<<endl;
            flag=false;
            break;
        }
    }
    if(flag){
        return true;
    }
    else{
        return false;
    }
}

//to make sure the points are equally sized and not of the same score
bool inputValidityCheck(int arr1[],int arr2[],int size1,int size2){
bool flag=true;
if(size1!=size2){
    cout<<"Points are not equally sized.......";
    flag=false;
    return flag;
}

else{
    for(int i=0;i<size1;i++){
    if((arr1[i]==0&&arr2[i]==0)||(arr1[i]>0&&arr2[i]>0)){
        int column=i;
        cout<<"Invalid Points in column number: "<<column+1<<endl;
        flag=false;
        break;
            }
        }
    if(flag){
        return pointValidityCheck(arr1,arr2,size1,size2);
    }
    else{
        return false;
    }
    }
}

int main(){
//advantage gives 10 points
int player1[]={15,0,0,15,0,10,10,0,0,10,10,0,10,0,0,0};
int player2[]={0,15,15,0,10,0,0,10,10,0,0,10,0,10,10,10};
if(inputValidityCheck(player1,player2,sizeof(player1)/sizeof(int),sizeof(player2)/sizeof(int))){
int points1=0;
int points2=0;
bool advantage=false;
for(int i=0;i<sizeof(player1)/sizeof(int);i++){
(player2[i]==0)?cout<<"player 1 scored...":cout<<"player 2 scored...";
points1+=player1[i];
points2+=player2[i];
 if(((points1==50)&&(points2!=40)&&!advantage)||(advantage&&(points1-points2)==20)){
    cout<<"game over... player 1 wins";
    break;
 }
 else if(((points2==50)&&(points1!=40)&&!advantage)||(advantage&&(points2-points1)==20)){
    cout<<"game over... player 2 wins";
    break;
 }
 else if(points1==40&&points2==40){
    advantage=true;
    cout<<"game is still running... advantage game enabled"<<endl;
 }
 else{
    cout<<"game is still running... ";
    advantage?(points1>points2)?cout<<"player 1 advantage":(points2>points1)?cout<<"player 2 advantage":cout<<"Deuce":(points1>points2)?cout<<"player 1 winning":(points2>points1)?cout<<"player 2 winning":cout<<"Tie points";
    cout<<endl;
 }
}
}
}

