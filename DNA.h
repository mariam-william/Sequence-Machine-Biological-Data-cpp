#ifndef DNA_H
#define DNA_H
#include <iostream>
#include "Sequence.h"
#include "RNA.h"

using namespace std;

class RNA;

enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
private:
    DNA_Type type;
    DNA * complementary_strand;
    int startIndex;
    int endIndex;
public:
    // constructors and destructor
    DNA();
    DNA(char * Seq, DNA_Type atype);
    DNA(const DNA& rhs);
    ~DNA();

    ///Setter and Getter for startIndex and endIndex, taken from user
    int getStartIndex();
    int getEndIndex();
    void setStartIndex(int start);
    void setEndIndex(int endI);

    // function printing DNA sequence information to user
    void Print();
    // function to convert the DNA sequence to RNA sequence
    // It starts by building the complementary_strand of the current
    // DNA sequence (starting from the startIndex to the endIndex), then,
    // it builds the RNA corresponding to that complementary_strand.
    RNA ConvertToRNA();
    // function to build the second strand/pair of DNA sequence
    // To build a complementary_strand (starting from the startIndex to
    // the endIndex), convert each A to T, each T to A, each C to G, and
    // each G to C. Then reverse the resulting sequence.
    void BuildComplementaryStrand();

    /*********** Operators Overloading************/
    DNA operator+(DNA obj);
    DNA operator=(DNA object);
    bool operator!=(DNA obj);
    bool operator==(DNA obj);
    friend istream& operator>>(istream& in,DNA obj);
    friend ostream& operator<<(ostream& out,DNA obj);
};

#endif // DNA_H
