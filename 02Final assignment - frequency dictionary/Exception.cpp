#pragma once
#include <exception>
#include <string>


using namespace std;
class Exception:public exception
{
public:
	Exception(string Info)
	{
		Info_ = Info;
	}

	string what()
	{
		return Info_;
	}
private:
	string Info_;
};
