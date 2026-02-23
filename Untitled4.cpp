#include <iostream>
#include <cstring>

class String
{
private:
	char* str;
	int length;
	
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();
	
	String& operator=(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	String operator+(const String& s);
	
	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);
};

String::String()
{
	length = 0;
	str = NULL;
}

String::String(const char* s)
{
	length = strlen(s) + 1;
	
	str = new char[length];
	
	strcpy(str, s);
}

String::String(const String& s)
{
	length = s.length;
	
	str = new char[length];
	
	strcpy(str, s.str);
}

String::~String()
{
	if (str != NULL)
	{
		delete []str;
	}
}
	
String& String::operator=(const String& s)
{
	if (str != NULL)
	{
		delete []str;
	}
	
	length = s.length;
	
	str = new char[length];
	
	strcpy(str, s.str);
	
	return *this;
}

String& String::operator+=(const String& s)
{
	length += (s.length - 1);
	
	char* temp = new char[length];
	
	strcpy(temp, str);
	strcat(temp, s.str);
	
	if (str != NULL)
	{
		delete []str;
	}
	
	str = temp;
	
	return *this;
}

bool String::operator==(const String& s)
{
	return strcmp(str, s.str) ? false : true;
}

String String::operator+(const String& s)
{
	char* temp = new char[length + s.length - 1];
	
	strcpy(temp, str);
	strcat(temp, s.str);
	
	String tempStr(temp);
	
	delete []temp;
	
	return tempStr;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.str;
	
	return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
	char input[128];
	
	is >> input;
	
	s = String(input);
	
	return is;
}

int main()
{
	String str1 = "I'am ";
	String str2 = "Happy";
	String str3 = str1 + str2;
	String str4;
	
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;
	
	str1 += str2;
	
	if (str1 == str3)
	{
		std::cout << "str1 == str3" << std::endl;
	}
	else
	{
		std::cout << "str1 != str3" << std::endl;
	}
	
	std::cout << "Input : ";
	std::cin >> str4;
	std::cout << str4 << std::endl;
	
	return 0;
}
