#ifndef RNA_H
#define RNA_H
#include <iostream>
#include "Sequence.h"
#include"Protein.h"
#include"CodonsTable.h"
#include"DNA.h"

using namespace std;

class DNA;
class Protein;
class CodonsTable;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

struct Parts
{
    char p[3];
    char newamino;
};

class RNA : public Sequence
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char * seq, RNA_Type atype);
        RNA(const RNA& rhs);
        ~RNA();

 	 	// function to be overridden to print all the RNA information
        void Print();

 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein ConvertToProtein(CodonsTable  table);

 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();

        //operators start here
        RNA operator+(RNA obj);
        bool operator!=(RNA obj);
        bool operator==(RNA obj);
        friend istream& operator>>(istream& in,RNA obj);
        friend ostream& operator<<(ostream& out,RNA obj);
};

#endif // RNA_H
