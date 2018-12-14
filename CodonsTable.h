#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include"Sequence.h"

#include <string>

using namespace std;

struct Codon
{
  	char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

// need to create one object of that class to load the AminoAcids table
// into memory
class CodonsTable
{
  	private:
        Codon codons[64];
   	public:
 	 	// constructors and destructor
        CodonsTable();
        ~CodonsTable();
 	 	// function to load all codons from the given text file
        void LoadCodonsFromFile(char* codonsFileName);
        Codon getAminoAcid(char * value);
        void setCodon(char * value, char AminoAcid, int index);
        Codon getCodon(int index);

};

#endif // CODONSTABLE_H
