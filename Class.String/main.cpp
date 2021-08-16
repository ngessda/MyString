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
	bool operator ==(const MyString& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator !=(const MyString& other)
	{
		return !(this->operator==(other));
	}

	void Print()
	{
		std::cout << str << std::endl;
	}

	~MyString()
	{
		delete[] str;
	}

	int Length()
	{
		return length;
	}

	char& operator[](int index)
	{
		return this->str[index];
	}


	MyString(MyString&& other)
	{
		this->length = other.length;
		this->str = other.str;

		other.str = nullptr;
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
	std::cout << str.Length() << std::endl;
	std::cout << str1.Length() << std::endl;
	std::cout << a.Length() << std::endl;
	bool equal = str == str1;
	std::cout << "\n" << equal << std::endl;
	bool a_equal = str != str1;
	std::cout << "\n" << a_equal << std::endl;
	str[0] = 'Q';
	str.Print();
	return 0;
	std::cin.get();
}