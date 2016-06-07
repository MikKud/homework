#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include "ComFile.h"
using namespace std;

class ComDir
{
	friend class ComFile;
	friend ostream& operator<<(ostream &, const ComDir &);
	friend istream& operator>>(istream &, ComDir &);

public:
	ComDir();
	ComDir(string);
	string getName();
	void setName(string);
	void addFile(ComFile &);
	void addDir(ComDir &);
	void ListAll();
	void ListDir(ComDir &);
	void LSR(ComDir &);
	void delFile(string);
	void delDir(string);
	void search(ComDir &, string);
	void ComDir::delDir(ComDir &);
	ComFile* open();
	ComDir* cd();
	~ComDir();
private:
	string name;
	vector<ComDir> dirList;
	vector<ComFile> fileList;
};
ComDir* ptr = new ComDir;
ComFile* Fptr = new ComFile;


ComFile* ComDir::open()
{
    int	count = 0;
	string name;
	cin >> name;
	for (int i = 0; i < fileList.size(); i++)
	{
		if (fileList[i].getName() == name)
		{
			Fptr = &(fileList[i]);
			count++;
		}
	}
	if (!count)
	{
		throw invalid_argument("There is no File with such name");
	}
	return Fptr;
}

ComDir* ComDir::cd()
{
	int count = 0;
	string name;
	cin >> name;
	for (int i = 0; i < dirList.size(); i++)
	{
		if (dirList[i].getName() == name)
		{
			ptr = &(dirList[i]);
			count++;
		}
	}
	if (!count)
	{
		throw invalid_argument("There is no Directory with such name");
	}
	return ptr;
}
void ComDir::setName(string n)
{
	name = n;
}
void ComDir::LSR(ComDir &dir1)
{
	cout << dir1.getName() << endl << endl;

	for (int i = 0; i<dir1.fileList.size(); i++) {
		 {
			cout << dir1.fileList[i].getName() << "  " << endl ;
		}

	}
	for (int i = 0; i < dir1.dirList.size(); i++)
	{

		LSR(dir1.dirList[i]);
	}
	
}

void ComDir::ListDir(ComDir &dir1)
{
	for (int i = 0; i<dir1.fileList.size(); i++)
	{
		cout << "Files" << endl;
		cout << dir1.fileList[i].getName() << endl;
	}
	cout << endl;
	for (int i = 0; i<dir1.dirList.size(); i++)
	{
		cout << "Directories" << endl;
		cout << dir1.dirList[i].getName() << endl;
	}
}


int j = 0;
void ComDir::search(ComDir &dir1, string iname)
{
	
	for (int i = 0; i<dir1.fileList.size(); i++) {
		if (dir1.fileList[i].getName() == iname) {
			cout << dir1.getName() << "  " << iname << endl;
		}

	}
	for (int i = 0; i < dir1.dirList.size(); i++)
	{
		
		search(dir1.dirList[i], iname);
		
	}

}

ComDir::ComDir() :name("Default") {
}

ComDir::ComDir(string iname) : name(iname) {
}

void ComDir::addFile(ComFile &iFile) {
	for (int i = 0; i < fileList.size(); i++)
	{
		if(fileList[i].getName()==iFile.getName())
			{
				throw invalid_argument("There is a file with such name already");
			}
	}
	fileList.push_back(iFile);
}

void ComDir::delFile(string iname) {
	int count = 0;
	for (int i = 0; i<fileList.size(); i++)
	{
		if (fileList[i].getName() == iname)
		{
			count++;
			fileList.erase(fileList.begin() + i);
			break;
		}
	}
	if (!count)
	{
		throw invalid_argument("There is no File with such name");
	}
}

void ComDir::addDir(ComDir &iDir) {
	for (int i = 0; i < dirList.size(); i++)
	{
		if (dirList[i].getName() == iDir.getName())
		{
			throw invalid_argument("There is a dir with such name already");
		}
	}
	dirList.push_back(iDir);
}

void ComDir::delDir(ComDir &dir1) {
	for (int i = 0; i<dirList.size(); i++)
		delDir(dirList[i]);
	fileList.clear();
	dirList.clear();
}

void ComDir::delDir(string iname) {
	for (int i = 0; i<dirList.size(); i++)
	{
		if (dirList[i].getName() == iname)
		{
			delDir(dirList[i]);
			break;
		}
	}
}

string ComDir::getName() {
	return name;
}

void ComDir::ListAll() {
	for (int i = 0; i<fileList.size(); i++)
	{
		cout << "Files "<<endl;
		cout << fileList[i].getName()<<endl;
	}
	cout << endl;
	for (int i = 0; i<dirList.size(); i++)
	{
		cout << "Directories"<<endl;
		cout << dirList[i].getName()<<endl;
	}
}

ComDir::~ComDir() {
	dirList.clear();
	fileList.clear();
}
