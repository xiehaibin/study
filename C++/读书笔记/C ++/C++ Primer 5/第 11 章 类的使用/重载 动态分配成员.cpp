#include <cstring>
#include <string>
#include <iostream>
using namespace std;

namespace stdCbox
{
}

namespace stdCbox
{
	class Cbox
	{
	public :
		char *pstr;
		string str;

	public :
		Cbox(char *p = "null");
		void Get(void) const;

		void GetString(void) const
		{
			cout<< str <<endl;
		}

		Cbox& operator=(const Cbox& box);
		Cbox& operator+(const Cbox& box);
		Cbox& operator+=(const Cbox& box);

		~Cbox(void);
	};
}

namespace stdCbox
{
	Cbox::Cbox(char *p)
	{
		pstr = new char[strlen(p)+1];
		strcpy(pstr, p);
		pstr[strlen(p)] = '\0';

		cout<< pstr <<endl;
	}

	Cbox& Cbox::operator=(const Cbox& box)
	{
		if (this == &box)
		{
			return *this;
		}
		delete [] pstr;

		pstr = new char[strlen(box.pstr)+1];
		strcpy(this->pstr, box.pstr);
		pstr[strlen(box.pstr)] = '\0';

		return *this;
	}

	Cbox& Cbox::operator+(const Cbox& box)
	{
		str = box.pstr;
		str += pstr;

		return *this;
	}

	Cbox& Cbox::operator+=(const Cbox& box)
	{
		this->str += box.str;
		cout<<"-------------------------------"<<endl;
		return *this;
	}

	void Cbox::Get(void) const
	{
		cout<< pstr <<endl;
	}
	Cbox::~Cbox(void)
	{
		delete [] pstr;
	}
}

int main (void)
{
	using stdCbox::Cbox;
	using namespace std;


    Cbox box("xie hai bin ");

	Cbox box1;
	Cbox box2;

	box2 = box1 = box;

    box2 += (box + box1);

	box.Get();

	return 0;
}