#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error
{
public:
	virtual void what() {}
};
class IndexError : public Error // недопустимый индекс множества
{
protected:
	string msg;
public:
	IndexError() { msg = "Ќедопустимый индекс множества."; }
	virtual void what() { cout << msg; }
};

class SizeError : public Error // недопустимый размер множества
{
protected:
	string msg;
public:
	SizeError() { msg = "Ќедопустимый размер множества."; }
	virtual void what() { cout << msg; }
};

class MaxSizeError : public SizeError
{
protected:
	string msg_;
public:
	MaxSizeError() { SizeError(); msg_ = "ѕревышен максимальный размер."; }
	virtual void what() { cout << msg << msg_; }
};

class NegativeSizeError : public SizeError
{
	string msg_;
public:
	NegativeSizeError() { SizeError(); msg_ = "ќтрицательный размер недопустим."; }
	virtual void what() { cout << msg << msg_; }
};

class  NegativeIndex: public IndexError 
{
	string msg_;
public:
	NegativeIndex() { IndexError(); msg_ = "ќтрицательный индекс недопустим."; }
	virtual void what() { cout << msg << msg_; }
};

class  TooBigIndexError : public IndexError
{
	string msg_;
public:
	TooBigIndexError() { IndexError(); msg_ = "»ндекс больше текущего размера множества."; }
	virtual void what() { cout << msg << msg_; }
};
