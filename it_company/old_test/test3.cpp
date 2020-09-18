#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

typedef struct FOOD{
    int yam;
    int energy;
}FOOD;

bool getSort(FOOD &food1,FOOD &food2){return food1.yam>food2.yam;}

int main(){

    int n,m,t;
    cin >> n>>m >> t;
    if(t==0){
        cout<<t<<endl;
        return 0;
    } 
    vector<FOOD> food_noon;
    vector<FOOD> food_night; 
    int in_1,in_2;
    FOOD food;
    int res=-1;
    while(n--){
        cin>>in_1>>in_2;
        food.energy=in_1;
        food.yam=in_2;
        food_noon.push_back(food);
    }
    while(m--){
        cin>>in_1>>in_2;
        food.energy=in_1;
        food.yam=in_2;
        food_night.push_back(food);
    }


    sort(food_noon.begin(),food_noon.end(),getSort);
    sort(food_night.begin(),food_night.end(),getSort);
    if(food_noon[0].yam+food_night[0].yam < t){
        cout<<res<<endl;
        return 0;
    }
    int diff=0;
    int minEng=INT_MAX;
    int res1=0;
    for(int i=0;i<food_noon.size();i++){
        res=0;
        if(food_noon[i].yam>=t){
            res=food_noon[i].energy;
            if(minEng>res){
                minEng=res;
            }
            continue;
        }else{
            res+=food_noon[i].energy;
        }
        
        diff=t-food_noon[i].yam;
        for(int j=0;j<food_night.size();j++){
            res1=0;
            if(diff<=food_night[j].yam){
                if(t<food_night[j].yaml){
                    res1=food_night[j].energy;
                }else{
                    res1+=food_night[j].energy+res;
                }
                if(minEng>res1){
                    minEng=res1;
                }
            }else{
                break;
            }
            
        }
        
    }
    cout<<minEng<<endl;
    return 0;
}

