#include <iostream>

using namespace std;

//class AbstractEmployee{
//	virtual void askForPromotion()=0;
//};


class Employee{
    private:
	string Company;
	int Age;
	protected:
	string Name;

    
   	public:
    void setName(string name){
    	Name = name;
	}
	
	string getName(){
		return Name;
	}
	void setCompany(string company){
		Company = company;
	}
	string getCompany(){
		return Company;
	}
	void setAge(int age){
		if(age>=18)
		Age = age;
	}
	int getAge(){
		return Age;
	}

	void IntroduceYourself(){
		cout<<"Name - "<<Name<<endl;
		cout<<"Company - "<<Company<<endl;
		cout<<"Age - "<<Age<<endl;
	}	
	
	Employee(string name, string company, int age){
		Name = name;
		Company = company;
		Age = age;
	}
	
	void AskForPromotion(){
		if(Age>30){
			cout<<Name<<" got promoted!"<<endl;
		}else{
			cout<<Name<<", sorry NO promotion for yout!"<<endl;
		}
	}
	
	virtual void Work(){
		cout<<Name<<" is checking email, tack backlog, performing..."<<endl;
	}
};

class Developer:public Employee{
	public:
		string FavProgrammingLanguage;
		Developer(string name, string company, int age, string favProgrammingLanguage)
	    :Employee(name, company, age)
		{
			FavProgrammingLanguage = favProgrammingLanguage;
		}
		void FixBug(){
			cout<<getName()<<" fixed bug using "<<FavProgrammingLanguage<<endl;
		}
		void Work(){
			cout<<Name<<" is writting "<<FavProgrammingLanguage<<" code."<<endl;
		}
}; 

class Teacher:public Employee{
	public:
	string Subject;
	void PrepareLesson(){
		cout<<Name<<" is preparing "<<Subject<<" lesson"<<endl;
	}
	Teacher(string name, string company, int age, string subject)
	:Employee(name, company, age)
	{
		Subject = subject;
	}
	void Work(){
		cout<<Name<<" is teaching "<<Subject<<endl;
	}
};

int main(){
	
	Employee employee1 = Employee("Nedzma", "CodingSchool", 19);
	
	Employee employee2 = Employee("Lamija", "Lamko", 31);

    employee1.AskForPromotion();
    employee2.AskForPromotion();
	
	Developer d = Developer("Nedzma", "Coding School", 19, "C++");
	d.FixBug();
	d.AskForPromotion();
	
	Teacher t = Teacher("Jack", "Cool School", 35, "History");
	t.PrepareLesson();
	t.AskForPromotion();
	d.Work();
	t.Work();
	
	Employee* e1 = &d;
	Employee* e2 = &t;
	
	e1->Work();
	e2->Work();
	
	
	return 0;
}
