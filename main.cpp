#include <iostream>
#include <conio.h>

#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"

using namespace std;

int bigDNA_length=0, otherDNA_length=0, seqLength=0, choice=0, typeChoice;
bool resume = true;
bool resume2 = true;
bool resume3 = true;
bool resume4 = true;
bool resume5 = true;
bool resume6 = true;
bool overallResume = true;

string bigDNA, otherDNA, seqRNA, seqProtein;
CodonsTable table;

char *dna=new char[bigDNA_length];
char *dna2=new char[otherDNA_length];
DNA Dna(dna, promoter);
DNA Dna2(dna2, promoter);

char *rna=new char[seqLength];
char *rna2=new char[seqLength];
RNA Rna(rna, mRNA);
RNA Rna2(rna2, mRNA);


  /** for(int i=0;i<bigDNA_length;i++)
        dna[i] = bigDNA[i];

    DNA Dna(dna, promoter);
    Dna.ConvertToRNA();**/
//char  *dna=new char[bigDNA_length];
//char *dna2=new char[bigDNA_length];
//DNA* Dna;
//DNA* Dna2;

string strangeDNAchecker(string inputSeq);
string strangeRNAchecker(string inputSeq);
int  DisplayGlobalMenu();
int DisplayDNAmenu();
int DisplayDNAsubmenu();
int DisplayRNAmenu();
int DisplayRNAsubmenu();
int DisplayProteinMenu();
int DisplayProteinSubmenu();

int main()
{
    cout << "\t\t\tWelcome to Sequencing Machine! :) \n\n" << endl;

    bool invalid = true;
    while (invalid)
    {
        cout << "\nPlease enter your DNA Sequence: ";
       // cin.ignore();
       // cin.getline(bigDNA,80,'\n');
        cin  >> bigDNA;

        try
        {
            strangeDNAchecker(bigDNA);
            invalid = false;
        }
        catch (int)
        {
            cout << "\nInvalid input, please enter a valid sequence." << endl;
        }

    }

    cout << "\nType of the DNA strand is: " << endl
         <<  "1- Promoter." << endl
         <<  "2- Motif. " << endl
         <<  "3- Tail. " << endl
         <<  "4- Noncoding." << endl
         <<  "\nType: ";
    cin  >> typeChoice;
    while (typeChoice<1 || typeChoice>4)
    {
        cout << "\nInvalid type, please choose a valid one. "
             << "\nChoice: ";
        cin  >> typeChoice;
    }

    bigDNA_length = bigDNA.size();

    char *dna=new char[bigDNA_length];
    for(int i=0;i<bigDNA_length;i++)
        dna[i] = bigDNA[i];
    //Dna = new DNA(dna, DNA_Type(typeChoice-1));
    DNA Dna(dna, DNA_Type(typeChoice-1));

   // DisplayGlobalMenu();

    while (overallResume)
    {
        DisplayGlobalMenu();

        if (choice == 1)   ///All this Choice for DNA properties.
        {
            while (resume)
            {
                DisplayDNAmenu();
                if (choice == 2)
                {
                    ///Load Data from file
                }
                else if (choice == 0)
                {
                    resume = false;
                }
                else if (choice != 1)
                    resume = false;
                    //return 0;
                while (resume2)
                {
                    DisplayDNAsubmenu();
                    if (choice == 0)
                        resume2 = false;
                    else if (choice == 1)
                    {
                        invalid = true;
                        while (invalid)
                        {
                            cout << "\nPlease enter your DNA Sequence: ";
                            cin  >> otherDNA;
                            try
                            {
                                strangeDNAchecker(otherDNA);
                                invalid = false;
                            }
                            catch (int)
                            {
                                cout << "\nInvalid input, please enter a valid sequence." << endl;
                            }
                        }
                        bigDNA_length = otherDNA.size();
                        //bigDNA_length++;
                        char *dna2=new char[bigDNA_length];
                        for(int i=0;i<bigDNA_length;i++)
                            dna2[i] = bigDNA[i];
                        //Dna2 = new DNA(dna2, DNA_Type(typeChoice-1));
                        DNA Dna2(dna2, DNA_Type(typeChoice-1));

                        //Alignment Function
                    }
                    else if (choice == 2) //build complementary strand
                    {
                        Dna.BuildComplementaryStrand();
                        Dna.Print();
                    }
                    else if (choice == 3)
                    {
                       cout << Dna.ConvertToRNA();
                    }
                    else if (choice == 4)
                    {
                        //Save Data to file
                    }
                    else if (choice == 5)
                    {
                        (Dna==Dna2) == 0?
                        cout << "Two sequences are Identical." :
                        cout << "Sequences are Different.";
                        //cout << (Dna == Dna2);
                        //Compare to another DNA seq using ==
                    }
                    else if (choice == 6)
                    {
                        cout << "New Sequence is: " << (Dna + Dna2);
                        // Join to another DNA seq
                    }
                    else if (choice == 7)
                    {
                        Dna.Print();
                    }
                    else
                        return 0;
                }
            }
        }
        else if (choice == 2)
        {
            while (resume3)
            {
                DisplayRNAmenu();
                if (choice == 0)
                    resume3 = false;
                else if (choice == 1)
                {
                    bool invalid = true;
                    while (invalid)
                    {
                        cout << "\nPlease enter your RNA Sequence: ";
                        cin  >> seqRNA;

                        try
                        {
                            strangeRNAchecker(seqRNA);
                            invalid = false;
                        }
                        catch (int)
                        {
                            cout << "\nInvalid input, please enter a valid sequence." << endl;
                        }
                    }
                    cout << "\nType of the DNA strand is: " << endl
                         <<  "1- mRNA." << endl
                         <<  "2- pre_mRNA. " << endl
                         <<  "3- mRNA_exon. " << endl
                         <<  "4- mRNA_intron." << endl
                         <<  "\nType: ";
                    cin  >> typeChoice;
                    while (typeChoice<1 || typeChoice>4)
                    {
                        cout << "\nInvalid type, please choose a valid one. "
                             << "\nChoice: ";
                        cin  >> typeChoice;
                    }
                    seqLength = seqRNA.size();

                    char *rna=new char[seqLength];
                    for(int i=0;i<seqLength;i++)
                        rna[i] = seqRNA[i];

                    RNA Rna(rna, RNA_Type(typeChoice-1));
                }
                else if (choice == 2)
                {
                    //Load RNA from file and save it in char array
                }
                else
                    return 0;
                while (resume4)
                {
                    DisplayRNAsubmenu();
                    if (choice == 0)
                        resume2 = false;
                    else if (choice == 1)
                    {
                        bool invalid = true;
                        while (invalid)
                        {
                            cout << "\nPlease enter your RNA Sequence: ";
                            cin  >> seqRNA;

                            try
                            {
                                strangeRNAchecker(seqRNA);
                                invalid = false;
                            }
                            catch (int)
                            {
                                cout << "\nInvalid input, please enter a valid sequence." << endl;
                            }
                        }
                        seqLength = seqRNA.size();

                        char *rna2=new char[seqLength];
                        for(int i=0;i<seqLength;i++)
                            rna2[i] = seqRNA[i];
                        //Dna = new DNA(dna, DNA_Type(typeChoice-1));
                        RNA Rna2(rna2, RNA_Type(typeChoice-1));
                    }
                    else if (choice == 2)
                    {
                        cout << Rna.ConvertToDNA();
                    }
                    else if (choice == 3)
                    {
                        //cout << Rna.ConvertToProtein(table);
                    }
                    else if (choice == 4)
                    {

                    }
                    else if (choice == 5)
                    {
                        (Rna != Rna2) == 0?
                        cout << "Sequences are Different." :
                        cout << "Sequences are Identical.";
                    }
                }
            }
        }






    }

    return 0;
}

string strangeDNAchecker(string inputSeq)
{
    for (int i=0; i<inputSeq.size(); i++)
    {
        if (inputSeq[i]!='A' && inputSeq[i]!='C' && inputSeq[i]!='G' && inputSeq[i]!='T')
        {
            throw 1;
        }
    }

    return inputSeq;
}
string strangeRNAchecker(string inputSeq)
{
    for (int i=0; i<inputSeq.size(); i++)
    {
        if (inputSeq[i]!='A' && inputSeq[i]!='C' && inputSeq[i]!='G' && inputSeq[i]!='U')
        {
            throw 1;
        }
    }
    return inputSeq;
}


int DisplayGlobalMenu()
{
    cout << "\nChoose the process you want to do. "
         << "\n 1- Enter a DNA Sequence."
         << "\n 2- Enter an RNA Sequence."
         << "\n 3- Enter a Protein Sequence."
         << "\n Any Key to Exit."
         << "\n\n I Choose: ";
    cin  >> choice;

    while (choice<0 || choice>3) //While loop to check the choice the user entered.
    {
        cout << "\nInvalid Choice, please check and enter a valid one! " << endl
             << "Choice: ";
        cin  >> choice;
    }
    return choice;
}
int DisplayDNAmenu()
{
    cout << "\n Please choose the process you want to do."
         << "\n 1- Use DNA strand to convert it."
         << "\n 2- Load data form file."
         << "\n 0- Back."
         //<< "\n any key to exit."
         << "\n\nProcess: ";
    cin  >> choice;
    while (choice<0 || choice>2) //While loop to check the choice the user entered.
    {
        cout << "\nInvalid Choice, please check and enter a valid one! " << endl
             << "Choice: ";
        cin  >> choice;
    }
    return choice;
}
int DisplayDNAsubmenu()
{
    cout << "\nChoose the DNA process you want to do."
         << "\n 1- Add another DNA sequence of same type."
         << "\n 2- Build complementary strand."
         << "\n 3- Convert DNA to RNA (Transcription Process)."
         //<< "\n 4- Convert DNA to Protein. (Transcription & Translation Process)"
         << "\n 4- Save data to file."
         << "\n 5- Compare to another DNA sequence."   //Compares using == an != operators
         << "\n 6- Join two sequences of the same type together. " // Join using + operator
         << "\n 7- Print DNA data."
         << "\n 0- Back."
         << "\n any key to exit."
         << "\n\n Process: ";
    cin  >> choice;

    while (choice<0 || choice>7) //While loop to check the choice the user entered.
    {
        cout << "\nInvalid Choice, please check and enter a valid one! " << endl
             << "Choice: ";
        cin  >> choice;
    }

    return choice;
}
int DisplayRNAmenu()
{
    cout << "\n Please choose the process you want to do."
         << "\n 1- Enter RNA Sequence and type."
         << "\n 2- Load data form file."
         << "\n 0- Back."
         << "\n any key to exit."
         << "\n\nProcess: ";
    cin  >> choice;
    while (choice<0 || choice>2) //While loop to check the choice the user entered.
    {
        cout << "\nInvalid Choice, please check and enter a valid one! " << endl
             << "Choice: ";
        cin  >> choice;
    }
    return choice;
}
int DisplayRNAsubmenu()
{
    cout << "\nChoose the RNA process you want to do."
         << "\n 1- Add another RNA sequence of same type."
         << "\n 2- Convert RNA to DNA (Reverse Transcription Process)."
         << "\n 3- Convert RNA to Protein. (Translation Process)"
         << "\n 4- Save data to file."
         << "\n 5- Compare to another RNA sequence."   //Compares using == an != operators
         << "\n 6- Join two sequences of the same type together. " // Join using + operator
         << "\n 7- Print RNA data."
         << "\n 0- Back."
         << "\n any key to exit."
         << "\n\n Process: ";
    cin  >> choice;

    while (choice<0 || choice>7) //While loop to check the choice the user entered.
    {
        cout << "\nInvalid Choice, please check and enter a valid one! " << endl
             << "\n\nChoice: ";
        cin  >> choice;
    }

    return choice;
}
int DisplayProteinMenu()
{
    cout << "\n Please choose the process you want to do."
         << "\n 1- Enter Protein Sequence and type."
         << "\n 2- Load data form file."
         << "\n 0- Back."
         << "\n any key to exit."
         << "\n\nProcess: ";
    cin  >> choice;
    while (choice<0 || choice>2) //While loop to check the choice the user entered.
    {
        cout << "Invalid Choice, please check and enter a valid one! " << endl
             << "Choice: ";
        cin  >> choice;
    }
    return choice;
}
int DisplayProteinSubmenu()
{
    cout << "\nChoose the RNA process you want to do."
         << "\n 1- Add another Protein sequence of same type."
         << "\n 2- Convert Protein to DNA (Reverse Translation & Transcription Process)."
         << "\n 3- Save data to file."
         << "\n 4- Compare to another Protein sequence."   //Compares using == an != operators
         << "\n 5- Join two sequences of the same type together. " // Join using + operator
         << "\n 6- Print Protein data."
         << "\n 0- Back."
         << "\n any key to exit."
         << "\n\n Process: ";
    cin  >> choice;

    while (choice<0 || choice>6) //While loop to check the choice the user entered.
    {
        cout << "\nInvalid Choice, please check and enter a valid one! " << endl
             << "\n\nChoice: ";
        cin  >> choice;
    }

    return choice;
}
