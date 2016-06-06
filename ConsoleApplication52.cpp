#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "ComFile.h"
#include "ComDir.h"
using namespace std;

int main()
{
	cout << "Name of first directory is <d1> " << endl << "in <d1> there are <d1_2> directory and files <f1> and <f2> and <f3>" << endl;
	cout << "In <d1_2> file <f3>"<<endl<<endl;
	ComDir d1("d1");
	ComDir d1_2("d1_2");
	ComDir d1_3("d1_3");
	ComFile f1("f1", 1);
	ComFile f2("f2", 2);
	ComFile f3("f3", 3);
	ComFile f4("f3", 4);
	d1.addFile(f1);
	d1.addFile(f2);
	d1.addFile(f3);
	d1_2.addFile(f3);
	d1_2.addFile(f4);
	d1.addDir(d1_2);

	d1.addDir(d1_3);
	cout << "after using seatch <f3> in <d1> direcroty and lower programm found ";
	d1.search(d1, "f3");
	cout << "files" << endl;
	cout << "after using seatch <f1> in <d1> direcroty and lower programm found ";
	d1.search(d1, "f1");
	cout << "files" << endl;
	cout << "checking d1.getname and f1.getdata" << endl;
	cout << d1.getName() << endl;
	cout << f1.getData() << endl;
	system("pause");
	return 0;
}