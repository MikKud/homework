#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class ComFile
{
public:
	friend ostream& operator<<(ostream &, const ComFile &);
	friend istream& operator>>(istream &, ComFile &);
	ComFile();
	ComFile(string, int);
	int getData();
	void setData(int);
	void reName(string);
	string getName();
	~ComFile();
private:
	string name;
	int data;
};

ComFile::ComFile() :name("dafault"), data(0)
{}

ComFile::ComFile(string iname, int idata) : name(iname), data(idata)
{}

int ComFile::getData() {
	return data;
}

void ComFile::setData(int idata) {
	data = idata;
}

void ComFile::reName(string iname) {
	name = iname;
}

string ComFile::getName() {
	return name;
}


ComFile::~ComFile() {
}
