#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct canary{
    int index;
    int num;
};

bool cmp(canary c1,canary c2){
    if(c1.num==c2.num){
        return c1.index>c2.index;
    }
    return c1.num>c2.num;
}
int main(){
    int n;
    cin>>n;
    vector<canary> red;
    vector<canary> blue;
    int num,color;
    canary tmp;
    for(int i=1;i<=n;i++){
        cin>>num>>color;
        if(color==1){
            tmp.index=i;
            tmp.num=num;
            red.push_back(tmp);
        }else{
            tmp.index=i;
            tmp.num=num;
            blue.push_back(tmp);
        }
    }

    int rednum=red.size();
    int bluenum=blue.size();
    if(rednum<3 && bluenum <3){
        cout<<"null"<<endl;
        return 0;
    }
    sort(red.begin(),red.end(),cmp);
    sort(blue.begin(),blue.end(),cmp);

    int sumR=0;
    int sumB=0;
    int badB=0;
    int badR=0;
    if (rednum >= 3)
    {
        for (int i = 0; i < 3; i++)
        {
            sumR += red[i].num;
        }
    }else
    {
        for(int i=0;i<red.size();i++){
            badR+=red[i].num;
        }
    }
    

    if (bluenum >= 3)
    {
        for (int i = 0; i < 3; i++)
        {
            sumB += blue[i].num;
        }
    }else{
        for(int i=0;i<blue.size();i++){
            badB+=blue[i].num;
        }
    }
    
    if(badB!=0 && badB>sumR){
        cout<<"null"<<endl;
        return 0;
    }
    if(badR!=0 && badR>sumB){
        cout<<"null"<<endl;
        return 0;
    }
    int resC=1;
    int resS=0;

    vector<int> resVecR;
    vector<int> resVec;
    vector<int> resVecB;
    if(sumB>sumR){
        resC=2;
        resS=sumB;
        for(int i=0;i<3;i++){
            resVec.push_back(blue[i].index);
        }
    }else if(sumB<sumR){
        resC=1;
        resS=sumR;
        for(int i=0;i<3;i++){
            resVec.push_back(red[i].index);
        }
    }else{
        for(int i=0;i<3;i++){
            resVecR.push_back(red[i].index);
        }
        for(int i=0;i<3;i++){
            resVecB.push_back(blue[i].index);
        }
    }

    if(sumB!=sumR){
        sort(resVec.begin(),resVec.end(),less<int>());
        cout<<resVec[0]<<" "<<resVec[1]<<" "<<resVec[2]<<endl;
    }else{
        sort(resVecR.begin(),resVecR.end(),less<int>());
        sort(resVecB.begin(),resVecB.end(),less<int>());
        if(resVecB[0]>resVecR[0]){
            cout<<resVecR[0]<<" "<<resVecR[1]<<" "<<resVecR[2]<<endl;
            resC=1;
        }else
        {
            cout<<resVecB[0]<<" "<<resVecB[1]<<" "<<resVecB[2]<<endl;
            resC=2;
        }
    }
    
    cout<<resC<<endl;
    cout<<resS<<endl;
    return 0;

}
