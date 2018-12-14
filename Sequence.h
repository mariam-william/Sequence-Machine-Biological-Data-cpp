#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
class Sequence
{
protected:
    char * seq;
    int length;
public:
    Sequence();
    Sequence(int length);//change name
    Sequence(const Sequence& rhs);//cpy constructor
    char* GetSeq();//getter lel seq arr h7tago fel getdnastrandencodingme function
    int GetLength();//getter lel length h7tago fel getdnastrandencodingme function
    virtual ~Sequence();
    virtual void Print() = 0;
    friend char* Align(Sequence * s1, Sequence * s2, int& length);//lsa
    int getSize(char *p);// we use this function to get the size of the seq arr
    void setLength(int l);
};
#endif // SEQUENCE_H

/*#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

class Sequence
{
    protected:
        char * seq;
        int length;

    public:
        // constructors and destructor
        Sequence();
        Sequence(int length);
        Sequence(const Sequence& rhs);
        virtual ~Sequence();
        char* GetSeq();
        virtual void Print()=0;
            // pure virtual function that should be overridden because every
            // type of sequence has its own details to be printed
        char* Align(Sequence * s1, Sequence * s2);
            // friend function that will find the LCS (longest common
            // subsequence) between 2 sequences of any type, according to
            // polymorphism
        int getSize(char *p);

};

#endif // SEQUENCE_H*/
