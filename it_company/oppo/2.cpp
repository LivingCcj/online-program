#include<bits/stdc++.h>

using namespace std;

//区间合并 09-23
struct coor{
    int x;
    int y;
};

bool cmp(coor c1,coor c2){
    if(c1.x==c2.x) return c1.y<c2.y;
    return c1.x<c2.x;
}

coor split(string str){
    const char *tmp=",";
    char *p=strtok((char*) str.c_str(),tmp);
    coor c;
    int i=0;
    while(p){
        if(i==0){
            c.x=atoi(p);
            i++;
        }else{
            c.y=atoi(p);
        }
        p=strtok(nullptr,tmp);
        
    }
    return c;
}
int main(){
    string str;
    int n;
    cin>>n;
    vector<coor> data(n);
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cin>>str;
        coor cr=split(str);
        data[i]=cr;
    }

    sort(data.begin(),data.end(),cmp);
    coor cTmp;
    vector<coor> res;
    for(int i=0;i<data.size();){
        cTmp.x=data[i].x;
        cTmp.y=data[i].y;
        while(i<data.size()){
            if (i<data.size()-1 && data[i].y>=data[i+1].x)
            {
            if(data[i].y<data[i+1].y){
                cTmp.y=data[i+1].y;
            }
            i++;
            }else{
                i++;
                break;
            }
           
        }
        res.push_back(cTmp);
    }
    ostringstream oss;
    for(int i=0;i<res.size();i++){
        oss<<res[i].x<<","<<res[i].y;
        if(i!=res.size()-1){
            oss<<" ";
        }
    }
    cout<<oss.str()<<endl;
    return 0;
}
