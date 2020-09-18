#include<iostream>
#include<cmath>
using namespace std;

struct point{
    int x;
    int y;
};


bool isOrth(point p0,point p1,point p2){
    int dx=(p1.x-p0.x)*(p1.x-p2.x);
    int dy=(p1.y-p0.y)*(p1.y-p2.y);
    if((dx+dy)==0){
        return true;
    }else{
        return false;
    }
}
bool isRect1(point p0,point p1,point p2,point p3){
    return isOrth(p0,p1,p2) &&  isOrth(p1,p2,p3) && isOrth(p2,p3,p0);
}

bool isRect2(point p0,point p1,point p2,point p3){
    return isRect1(p0,p1,p2,p3) || isRect1(p1,p2,p0,p3) || isRect1(p0,p2,p1,p3);
}
int main(){
    int N;
    cin>>N;
    int x0,y0,x1,y1,x2,y2,x3,y3;
    point p0,p1,p2,p3;
    for(int i=0;i<N;i++){
        cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3;
        p0.x=x0;
        p0.y=y0;
        p1.x=x1;
        p1.y=y1;
        p2.x=x2;
        p2.y=y2;
        p3.x=x3;
        p3.y=y3;
        if(true){
            cout<<"1"<<endl;
        }else{
            cout<<"0"<<endl;
        }
    }

    return 0;
    
}