#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

struct words{
    int m;
    int n;
    string word;
};
//大 -》 小
bool cmp(words w1,words w2){
    return w1.n<w2.n;
}
int main(){
    int P;
    int N;
    cin>>P;
    cin>>N;
    vector<words> data(N);
    for(int i=0;i<N;i++){
        string word;
        int n,m;
        cin>>data[i].word>>data[i].n>>data[i].m;
        // cout<<data[i].word<<data[i].n<<data[i].m<<endl;
    }

    sort(data.begin(),data.end(),cmp);

    // for_each(data.begin(),data.end(),[](words w){
    //     cout<<w.n<<endl;
    // });
    string res(P,0);
    int flag=0;
    // while(){
        for(int i=0;i<N;i++){
        string tmp1=data[i].word;
        for(int j=0;j<N;j++){
            if(j==i){
                continue;
            }
            string tmp2=data[j].word;
            if(data[i].n==1 && data[j].n>=1){
                for(int k=0;k<P;k++){
                    if(tmp2[k]==tmp1[k]){
                        res[k]=tmp1[k];
                        data[i].n--;
                        data[j].n--;
                        flag++;
                        cout<<res[k]<<endl;
                        break;
                    }
                }
            }
        }
    }
    // }
    

    if (flag==P){
        cout<<res<<endl;
    }else{
        // for(int i=0;i<N;i++){
        //     string tmp=data[i].word;
        //     for()

        // }
        cout<<"ok"<<endl;
    }

    return 0;
}   