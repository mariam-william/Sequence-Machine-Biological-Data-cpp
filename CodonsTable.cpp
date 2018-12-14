#include "CodonsTable.h"
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

      // function to load all codons from the given text file
void CodonsTable::LoadCodonsFromFile(char *codonsFileName)
{
    fstream datafile;
    datafile.open(codonsFileName);
    if(!datafile.is_open())
    {
      cout<<"No file with that name exists.";
    }
    for (int i=0; i<64; i++)
    {
        datafile >> codons[i].value;
        if ((codons[i].value[0] == 'U' && codons[i].value[1] == 'A' && codons[i].value[2] == 'A' )
          ||(codons[i].value[0] == 'U' && codons[i].value[1] == 'A' && codons[i].value[2] == 'G' )
          ||(codons[i].value[0] == 'U' && codons[i].value[1] == 'G' && codons[i].value[2] == 'A' ))
        {
            codons[i].AminoAcid = ' ';
        }
        else
            datafile >> codons[i].AminoAcid;
            //cout << codons[i].value << " " << codons[i].AminoAcid << endl;
    }
}
Codon CodonsTable::getAminoAcid(char * value)
{
Codon obj;
for(int i=0;i<64;i++)
 {
    bool found=true;
    for(int j=0;j<3;j++)
    {
      if(codons[i].value[j]!=value[j])
        found=false;
    }
    if(found==true)
    {
      break;
    }
    obj.AminoAcid=codons[i].AminoAcid;
 }
return obj;
}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
for(int i=0;i<3;i++)
 codons[index].value[i]=value[i];
codons[index].AminoAcid=AminoAcid;
}
Codon CodonsTable::getCodon(int index)
{
    Codon res;

    res.value[0] = codons[index].value[0];

    res.value[1] = codons[index].value[1];

    res.value[2] = codons[index].value[2];

    res.AminoAcid = codons[index].AminoAcid;

    return res;

}
/*#include "CodonsTable.h"

CodonsTable::CodonsTable(){}

CodonsTable::~CodonsTable(){}

// function to load all codons from the given text file
void CodonsTable::LoadCodonsFromFile(char *codonsFileName)
{
    fstream datafile;
    datafile.open(codonsFileName);
    if(!datafile.is_open())
    {
        cout<<"No file with that name exists.";
    }

    for (int i=0; i<64; i++)
    {
        datafile >> codons[i].value;
        if ((codons[i].value[0] == 'U' && codons[i].value[1] == 'A' && codons[i].value[2] == 'A' )
          ||(codons[i].value[0] == 'U' && codons[i].value[1] == 'A' && codons[i].value[2] == 'G' )
          ||(codons[i].value[0] == 'U' && codons[i].value[1] == 'G' && codons[i].value[2] == 'A' ))
        {
            codons[i].AminoAcid = ' ';
        }
        else
         datafile >> codons[i].AminoAcid;
       // cout << codons[i].value << " " << codons[i].AminoAcid << endl;
    }
}

Codon CodonsTable::getAminoAcid(char * value)
{
    Codon obj;
    for(int i=0; i<64; i++)
    {
        bool found = true;
        for(int j=0; j<3; j++)
        {
            if(codons[i].value[j] != value[j])
            found = false;
        }
        if(found == true)
        {
            break;
        }
        obj.AminoAcid = codons[i].AminoAcid;
    }
    return obj;
}

void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    for(int i=0; i<3; i++)
        codons[index].value[i] = value[i];
    codons[index].AminoAcid = AminoAcid;
}
*/
