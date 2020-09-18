    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    struct data
    {
        int talent;
        int tech;
    };
    bool cmp(data d1,data d2){
        return d1.talent>d2.talent;
    }
    int main(){
        int n;
        cin>>n;
        int talent,tech;
        vector<data> vec(n);
        data vaule;
        for(int i=0;i<n;i++){
            cin>>talent>>tech;
            vaule.talent=talent;
            vaule.tech=tech;
            vec[i]=vaule;
        }

        sort(vec.begin(),vec.end(),cmp);
        vector<int> flag(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(vec[i].tech<vec[j].tech){
                    flag[i]=1;
                    break;
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(flag[i]==0){
                res++;
            }
        }
        cout<<res<<endl;
        return 0;

    }