#include<iostream>

#include<vector>

using namespace std;


vector<int> add;
vector<int> mius;

//最大公倍数
int gcb(int a,int b){
    return b==0?a:gcb(b,a%b);
}

void getFactor(vector<int> data){
    int len=data.size();

    int max;
    for(int i=0;i<data.size();i++){
        int tmp=1;
        add.push_back(data[i]);
        int k=i+1;
        for(int j=k;j<len;j++){
            tmp*=data[j];
            if(i==0 && j==len){
                max=tmp*data[i]/gcb(tmp,data[i]);
                continue;
            }
            int ans=tmp*data[i]/gcb(tmp,data[i]);
            mius.push_back(ans);
            k++;
        }
    }
    add.push_back(max);
    
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> data(m);
    for(int i=0;i<m;i++){
        cin>>data[i];
    }

    int res=0;
    if(m==2){
        int x=n/data[0];
        int y=n/data[1];
        int tmp=data[0]*data[1]/gcb(data[0],data[1]);
        int xy=n/tmp;
        // cout<<x<<" "<<y<<" "<<xy<<endl;
        res=x+y-xy;
    }

    // if(m==3){
    //     int x=n/data[0];
    //     int y=n/data[1];
    //     int z=n/data[2];
    //     int tmp1=data[0]*data[1]/gcb(data[0],data[1]);
    //     int tmp2=data[2]*data[1]/gcb(data[2],data[1]);
    //     int tmp3=data[0]*data[2]/gcb(data[0],data[2]);
    //     int xy=n/tmp1;
    //     int yz=n/tmp2;
    //     int zx=n/tmp3;
    //     int tmp4=data[0]*data[2]*data[1]/gcb(data[0],data[1]*data[2]);
    //     int xyz=n/tmp4;
    //     // cout<<x<<" "<<y<<" "<<z<<" "<<xy<<" "<<yz<<" "<<zx<<" "<<xyz<<endl;
    //     res=x+y+z-xy-yz-zx+xyz;
    // }
    getFactor(data); 
    long long ret=0;
    for(int i=0;i<add.size();i++){
        ret+=n/add[i];
        cout<<add[i]<<" "<<ret<<endl;
    }
    for(int j=0;j<mius.size();j++){
        ret-=n/mius[j];
        cout<<mius[j]<<" "<<ret<<endl;
    }
    
    cout<<ret<<endl;
    return 0;
}
