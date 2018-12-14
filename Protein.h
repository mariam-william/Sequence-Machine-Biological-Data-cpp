#ifndef PROTEIN_H
#define PROTEIN_H

#include"Sequence.h"
#include"DNA.h"

class DNA;
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
      private:
        Protein_Type type;
      public:
          // constructors and destructor
          Protein();
          Protein(char * p,Protein_Type atype);
          Protein(const Protein & obj);
          void LoadSequenceFromFile(char* fileName);
        void SaveSequenceToFile(char* fileName);
        DNA* GetDNAStrandsEncodingMe(DNA & bigDNA,int &size);
          ~Protein();
          void Print();
          // return an array of DNA sequences that can possibly
                // generate that protein sequence
        Protein operator=(Protein obj);
        Protein operator+(Protein obj);
        bool operator!=(Protein obj);
        bool operator==(Protein obj);
        friend istream& operator>>(istream& in,Protein obj);
        friend ostream& operator<<(ostream& out,Protein obj);
};

#endif // PROTEIN_H
