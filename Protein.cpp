#include "Protein.h"
#include<fstream>
using namespace std;

Protein::Protein()
{
	seq = new char[0];
	length = 0;
}

Protein::Protein(char * p, Protein_Type atype)
{
	length = getSize(p);
	seq = new char[length];
	for (int i = 0; i < length; i++)
		seq[i] = p[i];
	type = atype;
}

Protein::Protein(const Protein & obj)
{
	length = obj.length;
	for (int i = 0; i < length; i++)
		seq[i] = obj.seq[i];
}

Protein::~Protein()
{
	length = 0;
	seq = new char[0];
}

void Protein::Print()
{
	cout << "The Protein sequence: ";
	for (int i = 0; i < length; i++)
		cout << seq[i];
	cout << endl;
	if (type == 0)
	{
		cout << "The type of Protein is Hormon " << endl;
	}
	else if (this->type == 1)
	{
		cout << "The type of Protein is Enzyme " << endl;
	}
	else if (this->type == 2)
	{
		cout << "The type of Protein is TF " << endl;
	}
	else if (this->type == 3)
	{
		cout << "The type of Protein is Cellular_Function " << endl;
	}
	else
	{
		cout << "This type is undefined " << endl;
	}
}

DNA* Protein::GetDNAStrandsEncodingMe(DNA & bigDNA, int &container)
{
	char *CutDNA = new char[length * 3];
	DNA *Collection=new DNA[5];
	char *DNA_Seq = bigDNA.GetSeq();
	int DNA_Length = bigDNA.GetLength();
	int index = 0; int identifier = 0;
	CodonsTable table;
	while (index < DNA_Length)
	{
		if ((index + length * 3 - 1) >= DNA_Length)
			break;
		for (int i = 0; i < length * 3; i++)
		{
			CutDNA[i] = DNA_Seq[index];
			index++;
		}
		DNA object1(CutDNA, promoter);
		object1.Print(); cout << endl;
		RNA object2(object1.ConvertToRNA());
		object2.Print(); cout << endl;
        Protein object3(object2.ConvertToProtein(table));
		object3.Print(); cout << endl;
		if (*this == object3)
		{

			Collection[identifier]=object1;
			identifier++;
		}
		else
		{

			if (index > length * 3)
				index -= length * 3 - 2;
		}
	}
	for (int i = 0; i < identifier; i++)
	{
		cout << "number " << i + 1 << ": ";
		Collection[i].Print();
	}
	container = identifier;
	cout << container << " thats the size.";
	delete[] CutDNA; delete[] DNA_Seq;
	return Collection;
}

Protein Protein::operator=(Protein obj)
{

	for (int i = 0; i < obj.length; i++)
	{
		seq[i] = obj.seq[i];
	}
	return *this;
}

Protein Protein::operator+(Protein obj)
{
	char *temp = new char[length];
	for (int i = 0; i < length; i++)
		temp[i] = seq[i];
	seq = new char[length + obj.length];
	for (int i = 0; i < length; i++)
		seq[i] = temp[i];
	int index = 0;
	for (int i = length; i < (length + obj.length); i++)
	{
		seq[i] = obj.seq[index];
		index++;
	}
	length += obj.length;
	return *this;
}

bool Protein::operator!=(Protein obj)
{
	if (length != obj.length) { return true; }
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (seq[i] != obj.seq[i])
				return true;
		}
		return false;
	}
}

bool Protein::operator==(Protein obj)
{
	if (length != obj.length) { return false; }
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (seq[i] != obj.seq[i])
				return false;
		}
		return true;
	}
}
istream& operator>>(istream& in, Protein obj)
{
	cout << "enter the Protein sequence: ";
	for (int i = 0; i < obj.length; i++)
		in >> obj.seq[i];
	return in;
}
ostream& operator<<(ostream& out, Protein obj)
{
	out << "the Protein sequence: ";
	for (int i = 0; i < obj.length; i++)
		out << obj.seq[i];
	out << "the type of Protein: " << obj.type;
	return out;
}


void Protein::LoadSequenceFromFile(char* fileName)

{
	ifstream datafile;
	datafile.open(fileName);

	char temp[20];

	datafile.getline(temp, 20, ':');

	if (temp == "hormon")

	{

		type = Hormon;

	}

	else if (temp == "enzyme")

	{

		type = Enzyme;

	}

	else if (temp == "TF")

	{

		type = TF;

	}

	else if (temp == "cellular_function")

	{

		type = Cellular_Function;

	}

	char Arr[100];

	datafile.getline(Arr, 100, '.');

	seq = new char[strlen(Arr)];

	for (int i = 0; i < (strlen(Arr)); i++)

	{

		seq[i] = Arr[i];

	}

	length = strlen(Arr);

	datafile.close();
}

void Protein::SaveSequenceToFile(char* fileName)

{
	ofstream datafile;
	datafile.open(fileName);
	if (!datafile.is_open())
	{
		datafile.open(fileName, ios::out);
	}


	if (type = Hormon)

	{

		datafile << "hormon";

	}

	else if (type = Enzyme)

	{

		datafile << "enzyme";

	}

	else if (type = TF)

	{

		datafile << "TF";

	}

	else if (type = Cellular_Function)

	{

		datafile << "cellular_function";

	}

	datafile << ":";

	for (int i = 0; i < length; i++)
	{
		datafile << seq[i];
	}

	datafile << ".";

	datafile.close();
}
