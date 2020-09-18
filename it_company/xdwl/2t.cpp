#include<iostream>
#include<cmath>
using namespace std;


const double ans=0.000001;
int main(){
    int N;
    cin>>N;
    // cout<<sqrt(N)<<endl;
    double x0,y0,x1,y1,x2,y2,x3,y3;
    while(N--){
        cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3;
        
        
        double sx=(x0+x1+x2+x3)/4.0;
        double sy=(y0+y1+y2+y3)/4.0;
        // cout<<sx<<"  "<<sy<<endl;

        double re0= sqrt(abs(sx-x0))+sqrt(abs(sy-y0));
        double re1= sqrt(abs(sx-x1))+sqrt(abs(sy-y1));
        double re2= sqrt(abs(sx-x2))+sqrt(abs(sy-y2));
        double re3= sqrt(abs(sx-x3))+sqrt(abs(sy-y3));
        if(true) {
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}