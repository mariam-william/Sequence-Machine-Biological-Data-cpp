#include "RNA.h"


RNA::RNA()
{
    cout<<"invalid sequence" << endl;
}

RNA::RNA(char *Seq, RNA_Type atype)
{     //parameter constructor
    length = getSize(Seq);
    seq = new char [length];
    for(int i = 0 ; i < length ; i++)
    {
        this->seq[i] = Seq[i];
    }
    type = atype;
}
RNA::RNA(const RNA& rhs)
{
    length = rhs.length;
    type = rhs.type;
    seq = new char[length];
    for (int i = 0 ; i < rhs.length ; i++)
    {
        seq[i] =rhs.seq[i];
    }
}

RNA::~RNA()
{
   delete [] seq;
}

void RNA::Print()
{
    cout << "\nThe RNA sequence: ";
    for (int i=0; i<length; i++)
    {
        cout << seq[i];
    }
    cout << endl;
    if(this->type == 0)
    {
      cout<<"The type of RNA is mRNA "<<endl;
    }
    else if(this->type == 1)
    {
      cout<<"The type of RNA is pre_mRNA "<<endl;
    }
    else if(this->type == 2)
    {
      cout<<"The type of RNA is mRNA_exon "<<endl;
    }
    else if(this->type == 3)
    {
      cout<<"The type of RNA is mRNA_intron "<<endl;
    }
    else
    {
      cout<<"This type is undefined "<<endl;
    }
  }
  RNA RNA::operator+(RNA obj)
  {
    char *temp=new char[length];
    for(int i=0;i<length;i++)
        temp[i]=seq[i];
    seq=new char[length+obj.length];
    for(int i=0;i<length;i++)
        seq[i]=temp[i];
    int index=0;
    for(int i=length;i<(length+obj.length);i++)
    {
      seq[i]=obj.seq[index];
      index++;
    }
    length+=obj.length;
    return *this;
  }
  bool RNA::operator!=(RNA obj)
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

  bool RNA::operator==(RNA obj)
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

  istream& operator>>(istream& in,RNA obj)
  {
    cout<<"enter the RNA sequence: ";
    for(int i=0;i<obj.length;i++)
        in>>obj.seq[i];
    return in;
  }
  ostream& operator<<(ostream& out,RNA obj)
  {
    out<<"the RNA sequence: ";
    for(int i=0;i<obj.length;i++)
        out<<obj.seq[i];
    out<<"the type of RNA: "<<obj.type;
    return out;
  }


Protein RNA::ConvertToProtein(CodonsTable  table)
{
    //will substitute the length with start and end index;
    table.LoadCodonsFromFile("RNA_codon_table.txt");
    char temp[length];
    for(int i=0;i<length;i++){temp[i]=seq[i];}
    char *prot = new char[length/3];
    int index=0, identifier=0;
    Codon object;
    char *SmallRna=new char[4];
    while(index < length)
    {
        if(index+2>=length)
             break;
        for(int i=0;i<3;i++)
        {
            SmallRna[i]=temp[index];
            index++;
        }

        if(((SmallRna[0] == 'U' && SmallRna[1] == 'A' && SmallRna[2] == 'A' )
          ||(SmallRna[0] == 'U' && SmallRna[1] == 'A' && SmallRna[2] == 'G' )
          ||(SmallRna[0] == 'U' && SmallRna[1] == 'G' && SmallRna[2] == 'A' )))
            break;
        else
        {
            object=table.getAminoAcid(SmallRna);
            prot[identifier]=object.AminoAcid;
            identifier++;
        }
    }
    char* actual = new char[identifier];
    for(int i=0; i<identifier; i++)
        actual[i] = prot[i];
    Protein final(actual, Hormon);
    delete[]actual;
    delete[]prot;delete[]SmallRna;
    return final;
}

DNA RNA::ConvertToDNA()
{
    char *temp=seq;
    for(int i=0;i<length;i++)
        temp[i]=seq[i];
    for (int i=0; i<length; i++)
    {
        if (temp[i] == 'A')
        {
            temp[i] = 'U';
        }
        else if (temp[i] == 'U')
        {
            temp[i] = 'T';
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
    DNA object(temp, promoter);
    delete[] temp;
    return object;
}

