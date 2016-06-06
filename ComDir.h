#pragma once
#include <string>
#include <vector>
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
	void addFile(ComFile &);
	void addDir(ComDir &);
	void ListAll();
	void delFile(string);
	void delDir(string);
	void search(ComDir &, string);
	void ComDir::delDir(ComDir &);
	~ComDir();
private:
	string name;
	vector<ComDir> dirList;
	vector<ComFile> fileList;
};

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
	fileList.push_back(iFile);
}

void ComDir::delFile(string iname) {
	for (int i = 0; i<fileList.size(); i++)
	{
		if (fileList[i].getName() == iname)
		{
			fileList.erase(fileList.begin() + i);
			break;
		}
	}
}

void ComDir::addDir(ComDir &iFile) {
	dirList.push_back(iFile);
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
		cout << "Files /n";
		cout << fileList[i].getName();
	}
	cout << endl;
	for (int i = 0; i<dirList.size(); i++)
	{
		cout << "Directories /n";
		cout << dirList[i].getName();
	}
}

ComDir::~ComDir() {
	dirList.clear();
	fileList.clear();
}