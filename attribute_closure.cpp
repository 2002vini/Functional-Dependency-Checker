#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string relation;
    cout<<"enter attributes present in relation(eg:{A,B,C,D} enclose within curly brackets):";
    cin>>relation;
    cout<<"enter no of FD's present in relation:";
    int num;
    cin>>num;
    string fd[num];
    for(int i=0;i<num;i++)
    {
        cout<<"enter fd in form of:{X->Y}:";
        cin>>fd[i];

    }
    cout<<"enter attribute to find closure of:";
    string tofind;
    cin>>tofind;
    set<char>closure;
    for(int i=0;i<tofind.length();i++)
    closure.insert(tofind[i]);
 
    /*set<char>::iterator itr;
    for(itr=closure.begin();itr!=closure.end();itr++)
    cout<<*itr<<" ";
    */
   
    //while loop to iterate through all the fd's
   
    for(int i=0;i<num;i++)
    { int t=0;
    while(t<num)
    {
        //FD:X->Y
        //separate lhs and rhs using character vector 
        //if all elements of lhs are present in closure set
        //then we will add all the attributes of rhs to the closure set
        vector<char>rhs;
        vector<char>lhs;
        int flag=0;
        for(int i=0;i<fd[t].length();i++)
        {
            if((fd[t][i]>='A' && fd[t][i]<='Z') || (fd[t][i]>='a' && fd[t][i]<='z'))
            {
                if(flag!=1)
                lhs.push_back(fd[t][i]);
                else
                rhs.push_back(fd[t][i]);
            }
            else
            flag=1;

        }
        int check=0;
        for(int j=0;j<lhs.size();j++)
        {
            auto it=closure.find(lhs[j]);
            if(it==closure.end())
            {
                check=1;
                break;
            }
        }
        if(check==0)
        {
            for(int i=0;i<rhs.size();i++)
            closure.insert(rhs[i]);
        }
        t++;
    }
    }

    set<char>::iterator it;
    for(it=closure.begin();it!=closure.end();it++)
    cout<<*it<<" ";
    cout<<endl;
    




}