#include <iostream>

class MyString
{
public:
	MyString()
	{
		str = nullptr;
	}
	MyString(const char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}

	MyString(const MyString& other)
	{

		int length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	MyString& operator=(const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}
		this->length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';

		return *this;
	}

	MyString operator+(const MyString& other)
	{
		MyString newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);
		newStr.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++,i++)
		{
			newStr.str[i] = other.str[j];
		}
		newStr.str[thisLength + otherLength] = '\0';

		return newStr;
	}
	void Print()
	{
		std::cout << str;
	}
	~MyString()
	{
		delete[] str;
	}

private:
	char* str;
	int length;
};



int main(int argc, char* argv[])
{
	MyString str("Hello");
	MyString str1("World");
	MyString a;
	a = str + str1;
	a.Print();
	return 0;
	std::cin.get();
}