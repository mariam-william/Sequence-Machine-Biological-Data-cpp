#include "Sequence.h"


// constructors and destructor
Sequence::Sequence(){length=0;seq=new char[0];}// default constructor

Sequence::Sequence(int length)//parameter constructor
{
    seq=new char [length];
    this->length=length;
}

Sequence::Sequence(const Sequence& rhs)//copy constructor
{
 seq=new char[rhs.length];
 length=rhs.length;
 for(int i=0;i<rhs.length;i++)
    {
      rhs.seq[i]=seq[i];
    }
}

Sequence::~Sequence() //destructor 3shan lma el object ye5las y3ml erase lel memory
{
delete[] seq;
}

char* Sequence::GetSeq() { return seq; }

void Sequence::Print(){} //this will do nothing here just prevents making objects of this class

char* Align(Sequence * s1, Sequence * s2){}//lsa deh shwia

int Sequence::getSize(char *p)
{
    int len=0;
    int index=0;
    while(p[index]!='\0')
    {
        len++;
        index++;
    }
    return len;
}
