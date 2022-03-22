#include<iostream>
#include<string>
using namespace std;
class father
{
protected:
	string name;
	string day;
	int months;
public:
	void nhap()
	{
		while (getchar() != '\n');
		cout << "\n\tthe name is: ";
		getline(cin, name);
		cout << "\n\ttime boring: ";
		getline(cin, day);
		cout << "\n\ttotal month: ";
		cin >> months;
	}
	void xuat()
	{
		cout << "\n\tName: " << name << "\n\tday: " << day << "\n\tmonths: " << months;
	}
	
};
class children : public father
{
private:
	string parentName;
public:
	void nhapchild()
	{
		father::nhap();
		while (getchar() != '\n');
		cout << "\n\ttype his/her parent name: ";
		getline(cin, parentName);
	}
	void xuatchild()
	{
		father::xuat();
		cout << "\n\this/her parent name: " << parentName;
	}
	float tinh()
	{
		float money;
		return money = months * 5000;
	}
};
class notchild : public father
{
private:
	string cmnd;
public:
	void nhapnotchild()
	{
		father::nhap();
		while (getchar() != '\n');
		cout << "\n\ttype cmnd number: ";
		getline(cin, cmnd);
	}
	void xuatnotchild()
	{
		father::xuat();
		cout << "\n\tIdentity Card number: " << cmnd;
	}
	float tinh()
	{
		float bigmoney;
		return bigmoney = 10000 * months;
	}
};
void arrange(children* a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i]->tinh() > a[j]->tinh())
			{
				children tam = *a[j];
				*a[j] = *a[i];
				*a[i] = tam;
			}
		}
	}

}
void menu(children *listchildren[], notchild *listnotchild[], int n, int m)
{
	int g;
	do
	{
		system("cls");
		cout << " " << " \n\  Hello! Please choose what you want!" << " \n\nA-Children" << "\n\t1: Add a litle guys hiring books" << "\n\t2: Arrange the list" <<
			"\n\t3: Show the litle guys list"
			<< " \n\nB-Grown-up people" << "\n\t4: Add a grown-up hiring books" << "\n\t5: Arrange the list" << "\n\t6: Show the grown-up list" <<
			"\n\n0: EXIT." << "\n\n\ Yeah i'm waiting, and so happy to serve you: " << "\t";
		cin >> g;

		//CHILDREN
		if (g == 1)
		{
			children* a_children = new children();
			a_children->nhapchild();
			listchildren[n] = a_children;
			n++;
		}
		if (g == 2)
		{
			arrange(listchildren, n);
		}
		if (g == 3)
		{
			cout << "\n\tInformation of listchildren:";
			for (int l = 0; l < n; l++)
			{
				cout << "\n\t" << l + 1 << ".";
				listchildren[l]->xuatchild();
			}
			system("pause");
		}

		//NOT CHILD
		if (g == 4)
		{
			notchild* a_notchild = new notchild();
			a_notchild->nhapnotchild();
			listnotchild[m] = a_notchild;
			m++;
		}
		if (g == 6)
		{
			cout << "\n\tInformation of list not child:";
			for (int k = 0; k < m; k++)
			{
				cout << "\n\t" << k + 1 << ".";
				listnotchild[k]->xuatnotchild();
			}
			system("pause");
		}
	} while (g != 0);
	//for (int l = 0; l < n; l++) delete listchildren[l];
	//for (int l = 0; l < m; l++) delete listnotchild[l];
}
int main()
{
	int n = 0, m = 0;
	children* listchildren[100];
	notchild* listnotchild[100];
	menu(listchildren, listnotchild, n, m);
	system("pause");
	return 0;
}