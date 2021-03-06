
/* 
 * File:   main.cpp
 * Author: Bhaskar
 *
 * Created on December 24, 2015, 6:30 PM
 */

#include <cstdlib>
#include<climits>
#include<bits/stdc++.h>
using namespace std;


class Bignum{
    string s;
    int chunk_size;
    int getchunksize(){
        int chunk_size=0;
        int max=INT_MAX;
        while(max > 0){
            max/=10;
            chunk_size++;
        }
        return chunk_size;
    }
    int clean(){
        int i,j;
        for(i=0,j=0;i<s.length();i++){
            if(s[i]<'0' || s[i]>'9')continue;
            else s[j++]=s[i];
        }
        s.erase(j,s.length());
    }
    bool negative;
public:
    Bignum(string &s){
        this->s=s;
        chunk_size=getchunksize();
        clean();
        
    }
    Bignum():s("0"){
        chunk_size=getchunksize();
    }
    
 Bignum operator+ ( Bignum &num){
        string &A=this->s;
        string &B=num.s;
        
        int carry=0,i,j;
        string ans;
        for(i=A.length()-1,j=B.length()-1;i>=0&&j>=0;i--,j--)
            {
                int temp=A[i]-'0'+B[j]-'0'+carry;
                int digit=temp %10;
                carry= temp/10;
                ans.insert(ans.begin(),digit+'0');
            }   
        for(;i>=0;i--)
        {
            int temp= carry+A[i]-'0';
            int digit=temp%10;
            carry=temp/10;
            ans.insert(ans.begin(),digit+'0');
        }
        for(;j>=0;j--)
        {
            int temp=carry+B[j]-'0';
            int digit=temp%10;
            carry=temp/10;
            ans.insert(ans.begin(),digit+'0');
        }
        while(carry>0){
            int digit= carry%10;
            carry/=10;
            ans.insert(ans.begin(),digit+'0');
        
        }
        return Bignum(ans);
    }
 Bignum operator* ( Bignum &num){
     
 }
    friend ostream & operator<<( ostream &, const Bignum&); 
    friend istream & operator>>(istream &,Bignum&);
};

ostream& operator<<(ostream & output, const Bignum& num){
    output<< num.s;
    return output;
}

istream& operator>>(istream & input , Bignum & num ){
    input>>num.s ;
    num.clean();
    return input;
}


int main(int argc, char** argv) {
  
#define DEBUG
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        Bignum A,B;
        cin>>A>>B;
        Bignum C=A+B;
        cout<<C<<endl;
    }
    
    return 0;
}