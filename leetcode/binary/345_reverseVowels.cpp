#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


bool isornot (char ch){
    return (ch == 'a' ||  ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u' ||ch == 'A' ||ch == 'E' ||ch == 'I' || ch == 'O' ||ch == 'U' );
}

string reverseVowels(string s) {
    string str(s);
    int len=s.size();
    int first=0;
    int last=len-1;
    while(first<last){
        if(str[first]==str[last]){
            first++;
            last--;
            continue;
        }else{

            while(!isornot(str[first])){

                first++;
                if(first>last) break;
            }
            while(!isornot(str[last])){
                last--;
                if(last<first) break;
            }
        }
        if(first<last){
            char tmp=str[last];
            str[last]=str[first];
            str[first]=tmp;
            first++;
            last--;
        }
    }
    return str;
}



string reverseVowels2(string s) {
    vector<char> chars{'a','e','i','o','u','A','E','I','O','U'};
    string str(s);
    int len=s.size();
    int first=0;
    int last=len-1;
    while(first<last){
        if(str[first]==str[last]){
            first++;
            last--;
            continue;
        }else{

            if(find(chars.begin(),chars.end(),str[first])==chars.end()){

                first++;
                continue;
            }
            if(find(chars.begin(),chars.end(),str[last])==chars.end()){
                last--;
                continue;
            }
        }
        if(first<last){
            char tmp=str[last];
            str[last]=str[first];
            str[first]=tmp;
            first++;
            last--;
        }
    }
    return str;
}
int main(){
    string str;
    cin>>str;
    cout<<reverseVowels(str)<<endl;

    return 0;

}