#include "DNA.h"

DNA::DNA(){}//default constructor

DNA::DNA(char * Seq, DNA_Type atype)  //parameter constructor
{
    length=getSize(Seq);
    seq=new char [length];
    for(int i=0;i<length;i++)
        seq[i]=Seq[i];
    type=atype;
}

DNA::DNA(const DNA& rhs) //copy constructor
{
     length=rhs.length;
     seq=new char[length];
     for(int i=0;i<length;i++)
        seq[i]=rhs.seq[i];
     type=rhs.type;
}

DNA::~DNA(){}//destructor
///Setter and Getter for startIndex and endIndex, taken from user
int  DNA :: getStartIndex()          {return startIndex; }
int  DNA :: getEndIndex()            {return endIndex; }
void DNA :: setStartIndex(int start) {startIndex = start; }
void DNA :: setEndIndex(int endI)    {endIndex = endI; }

void DNA::Print()// function printing DNA sequence information to user
{
    cout << "\nDNA Sequence is: ";
    cout << "\nDNA Sequence is: ";
    for(int i=0;i<length;i++)
            cout<<seq[i];
    if(this->type == 0)
    {
        cout<<" \nThe type of DNA is Promoter." << endl;
    }
    else if(this->type == 1)
    {
        cout<<" \nThe type of DNA is Motif." << endl;
    }
    else if(this->type == 2)
    {
        cout<<" \nThe type of DNA is Tail." << endl;
    }
    else if(this->type == 3)
    {
        cout<<" \nThe type of DNA is Noncoding." << endl;
    }
    else
    {
        cout<<" \nThis type is undefined." << endl;
    }
}

/**
* function to convert the DNA sequence to RNA sequence
* It starts by building the complementary_strand of the current
* DNA sequence (starting from the startIndex to the endIndex), then,
* it builds the RNA corresponding to that complementary_strand.
**/
RNA DNA::ConvertToRNA()
{
   /* if ((endIndex - startIndex) != 0)
    {
        length = endIndex - startIndex;
    }*/

    char* temp=new char[length];
    for(int i=0;i<length;i++)
        temp[i]=seq[i];
    for (int i=0; i<length; i++)
    {
        if (temp[i] == 'A')
        {
            temp[i] = 'U';
        }
        else if (temp[i] == 'T')
        {
            temp[i] = 'A';
        }
        else if (temp[i] == 'G')
        {
            temp[i] = 'C';
        }
        else if (temp[i] == 'C')
        {
            temp[i] = 'G';
        }
    }

    char *temp1=new char[1];
    for (int i=0; i<length/2; i++)
    {
        temp1[0] = temp[i];
        temp[i] = temp[length-i-1];
        temp[length-i-1] = temp1[0];
    }

    RNA obj(temp,mRNA);
    delete temp1;
    delete temp;
    return obj;
}
/**
*function to build the second strand/pair of DNA sequence
*To build a complementary_strand (starting from the startIndex to
*the endIndex), convert each A to T, each T to A, each C to G, and
* each G to C. Then reverse the resulting sequence.
**/
void DNA::BuildComplementaryStrand()
{
    char*temp=new char[length];
    for(int i=0;i<length;i++)
        temp[i]=seq[i];
    for (int i=0; i<length; i++)
    {

        if (temp[i] == 'A')
        {
            temp[i] = 'T';
        }
        else if (temp[i] == 'T')
        {
            temp[i] = 'A';
        }
        else if (temp[i] == 'G')
        {
            temp[i] = 'C';
        }
        else if (temp[i] == 'C')
        {
            temp[i] = 'G';
        }

    }
    char *temp1=new char[1];
    for (int i=0; i<length/2; i++)
    {
        temp1[0] = temp[i];
        temp[i] = temp[length-i-1];
        temp[length-i-1] = temp1[0];
    }

    complementary_strand = new DNA(temp,type);
    cout << "Complementary strand is: " << *complementary_strand << endl;
  //  cout << temp << endl;
    delete temp1;
    delete temp;
}
DNA DNA::operator+(DNA obj)
{
     char *temp=new char[length];

     for(int i=0;i<length;i++)
     {
         temp[i]=seq[i];
     }
     seq=new char[length+obj.length];

     for(int i=0;i<length;i++)
     {
         seq[i]=temp[i];
     }
     int index=0;

     for(int i=length;i<(length+obj.length);i++)
     {
        seq[i]=obj.seq[index];
        index++;
     }
     length+=obj.length;

     return *this;
}

bool DNA::operator!=(DNA obj)
{
    if(length!=obj.length){return true;}
    else
    {
        for(int i=0;i<length;i++)
        {
            if(seq[i]!=obj.seq[i])
            return true;
        }
        return false;
    }
}

bool DNA::operator==(DNA obj)
{
    if(length!=obj.length){return false;}
    else
    {
        for(int i=0;i<length;i++)
        {
            if(seq[i]!=obj.seq[i])
            return false;
        }
    return true;
    }
}

DNA DNA::operator= (DNA object)
{
    length = object.length;
    seq = new char [length];
    for(int i=0;i<length;i++)
    {
        seq[i]=object.seq[i];
    }
    type=object.type;

    return *this;
}

istream& operator>> (istream& in,DNA obj)
{
    cout<<"Enter the DNA sequence: ";
    for(int i=0; i<obj.length; i++)
        in >> obj.seq[i];
    return in;
}

ostream& operator<< (ostream& out,DNA obj)
{
   // out<<"DNA Sequence: ";
    for(int i=0;i<obj.length;i++)
        out<<obj.seq[i];
    if(obj.type == 0)
    {
        out << " \nThe type of DNA is Promoter." << endl;
    }
    else if(obj.type == 1)
    {
        out << " \nThe type of DNA is Motif." << endl;
    }
    else if(obj.type == 2)
    {
        out << " \nThe type of DNA is Tail." << endl;
    }
    else if(obj.type == 3)
    {
        out << " \nThe type of DNA is Noncoding." << endl;
    }
    else
    {
        out << " \nThis type is undefined." << endl;
    }
    return out;
}
