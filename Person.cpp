#include <iostream>
#include <cstring>

class Person
{
private:
	int age;
	char* name;
	
public:
	Person(int age, char* name);
	~Person();
	void ShowName();
	void ShowAge();
	void ShowAll();
};

Person::Person(int age, char* name)
{
	this->age = age;
	
	this->name = new char[strlen(name) + 1];
	
	strcpy(this->name, name);
}

Person::~Person()
{
	delete []name;
}

void Person::ShowName()
{
	std::cout << name << std::endl;
}

void Person::ShowAge()
{
	std::cout << age << std::endl;
}

void Person::ShowAll()
{
	Person::ShowName();
	Person::ShowAge();
}

int main()
{
	Person p1(14, "Àå°æÇõ");
	Person p2(32, "·ÖÁ¤ÀÎ");
	
	p1.ShowAge();
	p1.ShowName();
	
	std::cout << std::endl;
	
	p2.ShowName();
	p2.ShowAge();
	
	std::cout << std::endl;
	
	p1.ShowAll();
	
	std::cout << std::endl;
	
	p2.ShowAll();
	
	return 0;
}
