#include<bits/stdc++.h>


using namespace std;

void swap (vector<int> &arr ,int i,int j){
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}
void quickSort(vector<int> &arr,int i,int j){
    if(i>=j) return;
    int tmp=arr[i];
    int s=i;
    // while(s<e){
    //     while (arr[e] > tmp)
    //     {
    //         e--;
    //     }
    //     if(s<e){
    //         swap(arr[s],arr[e]);
    //     }
    //     while(arr[s]<tmp){
    //         s++;
    //     }
    //     if(s<e){
    //         swap(arr[s],arr[e]);
    //     }
        
    // }
    
    for(int k=i+1;k<=j;k++){
        if(arr[k]<tmp){
            s++;
            swap(arr,s,k);
        }
    }
    swap(arr,s,i);
    quickSort(arr,i,s-1);
    quickSort(arr,s+1,j);
}

void func(int x){
    cout<<x<<",";
}

int main(){
    vector<int> data({3,4,5,1,5,1,3,123,51,422});
    for_each(data.begin(),data.end(),[&](int x){
        cout<<x<<",";
    });
    cout<<endl;
    quickSort(data,0,data.size()-1);
    for_each(data.begin(),data.end(),[&](int x){
        cout<<x<<",";
    });
    cout<<endl;
    return 0;
}