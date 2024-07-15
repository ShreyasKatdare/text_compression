#include "rle.h"

// Constructor
rle::rle(int gamma): gamma(gamma){}

// Convert integer to gamma-bit binary string
string rle::f(int i)
{   string a;
    for(int j=gamma-1;j>=0;j--)
    {   
        int k=i>>j;
        if(k & 1)
        {
            a.push_back('1');
        } 
        else{
            a.push_back('0');
        }
    }
    
    
    return a; }

// Convert gamma-bit binary string to integer
int rle::g(string i)
{   int p=0;
    for(int j=0;j<gamma;j++)
    {   if(i[j]==49)
        {p=p*2+1;}
        else{p=p*2;}
    }
    
    return p; }

// Compress the input file
string rle::compress(string input_string)
{   string c;
    c.push_back(input_string[0]);
    int max=1;
    for(int f=0;f<gamma;f++){max*=2;}
    max=max-1;

    for(int i=0;i<input_string.length()-1;)
    {   
        string k;
        int j=i;
        for(;j<input_string.length()-1 && input_string[j]==input_string[i];j++ );
        int count=j-i;
        if(count>max)
        {   k=f(max);
            for(int z=0;z<gamma;z++)
            {
            c.push_back(k[z]);
            }
            for(int v=0;v<gamma;v++)
            {c.push_back('0');}
        
            k=f(count-max);
            for(int z=0;z<gamma;z++)
            {
            c.push_back(k[z]);
            }
        }


        else{
        k=f(count);
        
        
        for(int z=0;z<gamma;z++)
        {
            c.push_back(k[z]);
        }
        }
        i=j;
    }
    
    
    return c; }

// Decompress the input file
string rle::decompress(string input_string)
{   string d;
    char ans=input_string[0];
    for(int i=1;i<input_string.length()-1;i=i+gamma)
    {   
        string t;
        for(int j=i;j<i+gamma;j++){t.push_back(input_string[j]);}
        int n=g(t);
        if(n==0){
            continue;
        }
        else{
        for(int y=0;y<n;y++){
            d.push_back(ans);
            
        }
            if(ans=='1'){ans='0';}
            else{ans='1';}
        }
        
    }
    
    return d; }