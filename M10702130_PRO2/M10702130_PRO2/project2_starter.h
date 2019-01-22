#ifndef __PROJECT2__
#define __PROJECT2__

#include <iostream>
#include <string>

using namespace std;

//starter for project 1

//////// enumerations for symbolic data members //////////

enum StudentStatus {
	FullTime, PartTime, Exchange, sUnknown
};

static const string statusLabels[] = {
	"full-time", "part-time", "exchange", "unknown"
};

enum Department {
	Accounting, Business, Engineering, Mathematics,
	Physics, Arts, Chemistry, dUnknown
};

static const string departmentNames[] = {
	"Accounting",
	"Business",
    "Engineering",
    "Mathematics",
    "Physics",
    "Arts",
    "Chemistry",
    "Unknown"
};

enum Rank {
	Instructor,GradTeachingAsst,AsstProf,
	AssocProf,Professor,ResScientist,Dean,rUnknown
};

static string rankNames[] = {
	"Instructor",
    "GradTeachingAsst",
    "AsstProf",
    "AssocProf",
    "Professor",
    "ResScientist",
    "Dean"
    "Unknown"
};

/////////////     mixin classes for project 2      ///////////////

//another enum type for project 2
enum Qualification {
	NoSchooling, HighSchool, Undergraduate, Graduate, Doctorate
};

static string qualificationNames[] = {
	"NoSchooling", 
	"HighSchool",
	"Undergraduate",
	"Graduate",
	"Doctorate"
};

///////////////   utility class Date   ////////////////

class Date {
public:
	int d, m, y;
	static Date today;

	Date (int dd = 0, int mm = 0, int yy = 0)
	{
		dd ? d = dd : today.d;
		mm ? m = mm : today.m;
		yy ? y = yy : today.y;
	}

	friend ostream& operator<<( ostream&, Date );
};

ostream& operator<<( ostream& os, Date dt )
{
	os << dt.m << "-" << dt.d << "-" << dt.y;
	return os;
}

Date Date::today( 12, 25, 2003 );

/////////////     utility class Course      ///////////////

class Course {
	string courseName;
	long   courseId;

public:
	Course();                                  // no-arg constructor
	Course( const string, long );              // constructor
	Course( const Course& );                   // copy constructor
	Course& operator=( const Course& other );  // copy assignment op  
	~Course();                                 // destructor

	// comparison operators:
	bool operator==( const Course& );
	bool operator!=( const Course& );

	string getCourseName() const;
	void setCourseName( const string );
	long getCourseId() const;
	void setCourseId( long );

	friend ostream& operator<<( ostream& os, Course aCourse )
	{
		os << aCourse.courseName << "  "  << aCourse.courseId << endl;
		return os;
	}
};

Course::Course()
{
	this->courseName = "";
	this->courseId = 0;
}

Course::Course(const string courseName, long courseId)
{
	this->courseName = courseName;
	this->courseId = courseId;
}

Course::Course(const Course& course)
{
	this->courseName = course.courseName;
	this->courseId = course.courseId;
}

Course& Course::operator=(const Course& other)
{
	this->courseName = other.courseName;
	this->courseId = other.courseId;

	return *this;
}

Course::~Course()
{
}

bool Course::operator==(const Course& other)
{
	return ((this->courseName == other.courseName) && (this->courseId == other.courseId));
}

bool Course::operator!=(const Course& other)
{
	return ((this->courseName != other.courseName) && (this->courseId != other.courseId));
}

string Course::getCourseName() const
{
	return this->courseName;
}

void Course::setCourseName(const string courseName)
{
	this->courseName = courseName;
}

long Course::getCourseId() const
{
	return this->courseId;
}

void Course::setCourseId(long courseId)
{
	this->courseId = courseId;
}

class M_QualifiedToTeach {
public:
	virtual void setDepartment(Department dept) = 0;
	virtual Department getDepartment() const = 0;

	virtual void listCoursesQualifiedToTeach() const = 0;
	virtual Date getYearOfExperience() const = 0;

	virtual Qualification getHighestDegree() const = 0;
	virtual double getSalary() const = 0;
};

class M_CanBecomestudent {
public:
	virtual void setDepartment(Department dept) = 0;
	virtual Department getDepartment() const = 0;

	virtual bool enrollForCourse(Course& aCourse) = 0;
	virtual bool dropFromCourse(const Course& theCourse) = 0;
	virtual void listCoursesRegisteredFor() const = 0;
	
	virtual Qualification getStudentQualification() const = 0;
};

/////////////     base class Person      ///////////////

class Person {
	string name;
	string address;
	unsigned long ssn;
	Date birthdate;
  
public:
    
	Person();
	// constructor:
	Person( const string theName, unsigned long theSSN, Date theBday, const string theAddress );

	// copy constructor:
	Person( const Person& );
  
	// copy assignment operator:
	Person& operator=( const Person& );

	// destructor:
	~Person();

	void setName( const string theName );
	string getName() const;
	void setAddress( const string theAddress );
	string getAddress() const;
	Date getBirthDate() const;
	unsigned long getIdentification() const;
	void setIdentification( unsigned long newID );
  
	virtual void print() const;
};

Person::Person()
{
	this->name = "";
	this->address = "";
	this->ssn = 0;
	this->birthdate = Date::today;
}

Person::Person(const string theName, unsigned long theSSN, Date theBday, const string theAddress)
{
	this->name = theName;
	this->address = theAddress;
	this->ssn = theSSN;
	this->birthdate = theBday;
}

Person::Person(const Person& person)
{
	this->name = person.name;
	this->address = person.address;
	this->ssn = person.ssn;
	this->birthdate = person.birthdate;
}

Person& Person::operator=(const Person& other)
{
	this->name = other.name;
	this->address = other.address;
	this->ssn = other.ssn;
	this->birthdate = other.birthdate;

	return *this;
}

Person::~Person()
{
}

void Person::setName(const string theName)
{
	this->name = theName;
}

string Person::getName() const
{
	return this->name;
}

void Person::setAddress(const string theAddress)
{
	this->address = theAddress;
}

string Person::getAddress() const
{
	return this->address;
}

Date Person::getBirthDate() const
{
	return this->birthdate;
}

void Person::setIdentification(unsigned long newID)
{
	this->ssn = newID;
}

unsigned long Person::getIdentification() const
{
	return this->ssn;
}

void Person::print() const
{
	cout << "name = " << this->name << endl;
	cout << "address = " << this->address << endl;
	cout << "birthdate = " << this->birthdate << endl;
	cout << "ssn = " << this->ssn << endl;
}

///////////////// derived class Student //////////////

const int MaxCoursesForStudent = 4;

class Student : public Person, public M_CanBecomestudent {
	StudentStatus status;
	Department    department;
	Qualification qualification;
	Course*       enrolled[ MaxCoursesForStudent ];
	int           numCourses; 
  
public:
	Student();

	// constructor:
	Student( const string	theName, 
			 unsigned long	theSSN, 
			 const Date		theBirthDate,
			 const string	theAddress, 
			 StudentStatus	theStatus,
			 Department		theDepartment,
			 Qualification	theQualification );

	// copy constructor, assignment operator, destructor:
	Student( const Student& );
	Student& operator=( const Student& );
	~Student();

	void setStatus( StudentStatus aStatus );
	StudentStatus getStatus() const;
	void setDepartment( Department dept );
	Department getDepartment() const;
	void setStudentQualification( Qualification qauls );
	Qualification getStudentQualification() const;

	bool enrollForCourse(Course& aCourse);
	bool dropFromCourse(const Course& theCourse);
	void listCoursesRegisteredFor() const;

	void print() const;
};

Student::Student()
{
	Person::Person();
	this->status = sUnknown;
	this->department = dUnknown;
	this->qualification = Undergraduate;
	this->numCourses = 0;
}

Student::Student(const string	theName, 
				 unsigned long	theSSN, 
				 const Date		theBirthDate,
				 const string	theAddress,
				 StudentStatus	theStatus,
				 Department		theDepartment,
				 Qualification	theQualification) : Person(theName, theSSN, theBirthDate, theAddress)
{
	this->status = theStatus;
	this->department = theDepartment;
	this->qualification = theQualification;
	this->numCourses = 0;
}

Student::Student(const Student& obj) : Person(obj)
{
	this->status = obj.status;
	this->department = obj.department;
	this->qualification = obj.qualification;
	this->numCourses = obj.numCourses;

	for (int i = 0; i < obj.numCourses; i++) {
		this->enrolled[i] = obj.enrolled[i];
	}
}

Student& Student::operator=(const Student& obj)
{
	Person::operator=(obj);
	this->status = obj.status;
	this->department = obj.department;
	this->qualification = obj.qualification;
	this->numCourses = obj.numCourses;

	for (int i = 0; i < obj.numCourses; i++) {
		this->enrolled[i] = obj.enrolled[i];
	}

	return *this;
}

Student::~Student()
{
}

void Student::setStatus(StudentStatus aStatus)
{
	this->status = aStatus;
}

StudentStatus Student::getStatus() const
{
	return this->status;
}

void Student::setDepartment(Department dept)
{
	this->department = dept;
}

Department Student::getDepartment() const
{
	return this->department;
}

void Student::setStudentQualification(Qualification quals)
{
	this->qualification = quals;
}

Qualification Student::getStudentQualification() const
{
	return this->qualification;
}

bool Student::enrollForCourse(Course& aCourse)
{
	if (numCourses < MaxCoursesForStudent) {
		enrolled[numCourses++] = &aCourse;
		return true;
	} else {
		cout << "The number of courses is already full" <<endl;
		return false;
	}
}

bool Student::dropFromCourse(const Course& theCourse)
{
	if (numCourses > 0) {
		for (int i = 0; i < numCourses; i++) {
			if (*enrolled[i] == theCourse) {
				if (numCourses == 1) {
					enrolled[--numCourses] = nullptr;
				} else {
					enrolled[i] = enrolled[--numCourses];
				}
				return true;
			}
		}
		
		cout << "The student didn't enroll this course" << endl;
		return false;
	} else {
		cout << "The number of courses is empty" << endl;
		return false;
	}
}

void Student::listCoursesRegisteredFor() const
{
	cout << getName() << "'s courses list : ";
	for (int i = 0; i < numCourses; i++) {
		cout << enrolled[i]->getCourseName() << ", ";
	}
	cout << endl;
}

void Student::print() const
{
	Person::print();
	cout << "status = " << statusLabels[this->status] << endl;
	cout << "department = " << departmentNames[this->department] << endl;
	cout << "qualification = " << qualificationNames[this->qualification] << endl;
	listCoursesRegisteredFor();
	cout << "numCourses = " << this->numCourses << endl;
}

//////////// derived class Teacher /////////////

const int MaxCoursesForTeacher = 2;
const int MaxGraders = 2;

const unsigned GradCourseLevel = 400;

class Teacher : public Person, public M_QualifiedToTeach {
	Rank             rank;
	double           salary;
	Department       department;
	Qualification	 qualification;
	Date			 yearOfExperience;
	int              numCourses;   // num of courses taught currently
	int              numGraders;
	Course*          coursesOffered[ MaxCoursesForTeacher ];
	string           graders[ MaxGraders ]; 
  
public:
	Teacher();
	Teacher( const string theName, long theSSN, const Date theBirthDate,
			 const string theAddress, Rank theRank, Department theDepartment, double theSalary,
			 Qualification theQualification, Date theYearOfExperience );
	Teacher( const Teacher& other );
	Teacher& operator=( const Teacher& other );
	~Teacher();

	void setDepartment( Department dept );
	Department getDepartment() const;

	// change rank when the teacher is promoted
	void setRank( Rank newRank );
	Rank getRank() const;

	void listCoursesTaught() const;
	// offer this course
	bool offerCourse( Course& aCourse );
	// cancel this course
	bool dropCourse( const Course& theCourse);

	bool assignGrader( string newGrader );
	bool dropGrader(const string grader);
	void listGraders() const;

	double getSalary() const;
	void setSalary( double theSalary );

	void listCoursesQualifiedToTeach() const;
	void setYearOfExperience( Date newYearOfExperience );
	Date getYearOfExperience() const;
	void setHighestDegree( Qualification newHighestDegree );
	Qualification getHighestDegree() const;

	void print() const;
};

Teacher::Teacher() : Person()
{
	this->rank = rUnknown;
	this->salary = 0.0;
	this->department = dUnknown;
	this->qualification = Doctorate;
	this->yearOfExperience = Date::today;
	this->numCourses = 0;
	this->numGraders = 0;
}

Teacher::Teacher(const string theName, long theSSN, const Date theBirthDate, 
				 const string theAddress, Rank theRank, Department theDepartment, double theSalary,
				 Qualification theQualification, Date theYearOfExperience) :
	Person(theName, theSSN, theBirthDate, theAddress)
{
	this->rank = theRank;
	this->department = theDepartment;
	this->salary = theSalary;
	this->qualification = theQualification;
	this->yearOfExperience = theYearOfExperience;
	this->numCourses = 0;
	this->numGraders = 0;
}

Teacher::Teacher(const Teacher& other) : Person(other)
{
	this->rank = other.rank;
	this->salary = other.salary;
	this->department = other.department;
	this->qualification = other.qualification;
	this->yearOfExperience = other.yearOfExperience;
	this->numCourses = other.numCourses;
	this->numGraders = other.numGraders;

	for (int i = 0; i < other.numCourses; i++) {
		this->coursesOffered[i] = other.coursesOffered[i];
	}
	for (int i = 0; i < other.numGraders; i++) {
		this->graders[i] = other.graders[i];
	}
}

Teacher& Teacher::operator=(const Teacher& other)
{
	Person::operator=(other);
	this->rank = other.rank;
	this->salary = other.salary;
	this->department = other.department;
	this->qualification = other.qualification;
	this->yearOfExperience = other.yearOfExperience;
	this->numCourses = other.numCourses;
	this->numGraders = other.numGraders;

	for (int i = 0; i < other.numCourses; i++) {
		this->coursesOffered[i] = other.coursesOffered[i];
	}
	for (int i = 0; i < other.numGraders; i++) {
		this->graders[i] = other.graders[i];
	}

	return *this;
}

Teacher::~Teacher()
{
}

void Teacher::setDepartment(Department dept)
{
	this->department = dept;
}

Department Teacher::getDepartment() const
{
	return this->department;
}

void Teacher::setRank(Rank newRank)
{
	this->rank = newRank;
}

Rank Teacher::getRank() const
{
	return this->rank;
}

void Teacher::listCoursesTaught() const
{
	cout <<  getName() << "'s courses taught list : ";
	for (int i = 0; i < numCourses; i++) {
		cout << coursesOffered[i]->getCourseName() << ", ";
	}
	cout << endl;
}

bool Teacher::offerCourse(Course& aCourse)
{
	if (numCourses < MaxCoursesForTeacher) {
		coursesOffered[numCourses++] = &aCourse;
		return true;
	} else {
		cout << "The number of courses taught is already full" << endl;
		return false;
	}
}

bool Teacher::dropCourse(const Course& theCourse)
{
	if (numCourses > 0) {
		for (int i = 0; i < numCourses; i++) {
			if (*coursesOffered[i] == theCourse) {
				if (numCourses == 1) {
					coursesOffered[--numCourses] = nullptr;
				} else {
					coursesOffered[i] = coursesOffered[--numCourses];
				}
				return true;
			}
		}

		cout << "The teacher didn't offer this courses" << endl;
		return false;
	} else {
		cout << "The number of courses taught is empty" << endl;
		return false;
	}
}
bool Teacher::assignGrader(string newGrader)
{
	if (numGraders < MaxGraders) {
		graders[numGraders++] = newGrader;
		return true;
	} else {
		cout << "The number of grader is already full" << endl;
		return false;
	}
}

bool Teacher::dropGrader(const string grader)
{
	if (numGraders > 0) {
		for (int i = 0; i < numGraders; i++) {
			if (graders[i] == grader) {
				if (numGraders == 1) {
					graders[--numGraders] = "";
				} else {
					graders[i] = graders[--numGraders];
				}
				return true;
			}
		}

		cout << "The teacher didn't assign this grader" << endl;
		return false;
	} else {
		cout << "The number of grader is empty" << endl;
		return false;
	}
}

void Teacher::listGraders() const
{
	cout << getName() << "'s grader list : ";
	for (int i = 0; i < numGraders; i++) {
		cout << graders[i] << ", ";
	}
	cout << endl;
}

void Teacher::setSalary(double theSalary)
{
	this->salary = theSalary;
}

double Teacher::getSalary() const
{
	return this->salary;
}

void Teacher::listCoursesQualifiedToTeach() const
{
	cout << getName() << "'s courses qualified list : ";
	for (int i = 0; i < numCourses; i++) {
		if (coursesOffered[i]->getCourseId() < GradCourseLevel) {
			cout << coursesOffered[i]->getCourseName() << " is for " << qualificationNames[Undergraduate] << ", ";
		} else {
			cout << coursesOffered[i]->getCourseName() << " is for " << qualificationNames[Graduate] << ", ";
		}
	}
	cout << endl;
}

void Teacher::setYearOfExperience(Date newYearOfExperience)
{
	this->yearOfExperience = newYearOfExperience;
}

Date Teacher::getYearOfExperience() const
{
	return this->yearOfExperience;
}

void Teacher::setHighestDegree(Qualification newHighestDegree)
{
	this->qualification = newHighestDegree;
}

Qualification Teacher::getHighestDegree() const
{
	return this->qualification;
}

void Teacher::print() const
{
	Person::print();
	cout << "rank = " << rankNames[this->rank] << endl;
	cout << "salary = " << this->salary << endl;
	cout << "department = " << departmentNames[this->department] << endl;
	cout << "qualification = " << qualificationNames[this->qualification] << endl;
	cout << "yearOfExperience = " << this->yearOfExperience << endl;
	cout << "numCourses = " << this->numCourses << endl;
	cout << "numGraders = " << this->numGraders << endl;
	listCoursesTaught();
	listGraders();
	listCoursesQualifiedToTeach();
}

////////// derived class GraduateStudent /////////////

const unsigned MaxCoursesForGradStudent = 4;

class GraduateStudent : public Student {  
	Teacher *advisor;
	unsigned short numCourses;

public:
	//constructor:
	GraduateStudent();
	GraduateStudent( const string theName,
					 unsigned long theSSN,
					 const Date theBirthDate,
					 const string theAddress,
					 StudentStatus theStatus,
					 Department theDepartment,
					 Teacher& theAdvisor,
					 Qualification theQualification = Graduate );
  
	GraduateStudent( const GraduateStudent& other );
	GraduateStudent&  operator=( const GraduateStudent& other );
	~GraduateStudent();

	//need to override the following method inherited from 
	//Student class because a grad students cannot enroll in 
	//low-level courses
	bool enrollForCourse( Course& aCourse );

	void changeAdvisor( Teacher& newAdvisor );

	Teacher getAdvisor() const;

	void print() const;
};

GraduateStudent::GraduateStudent() : Student()
{
	this->advisor = nullptr;
}

GraduateStudent::GraduateStudent(const string	theName,
								 unsigned long	theSSN,
								 const Date		theBirthDate,
								 const string	theAddress,
								 StudentStatus	theStatus,
								 Department		theDepartment,
								 Teacher&		theAdvisor,
								 Qualification	theQualification) :
	Student(theName, theSSN, theBirthDate, theAddress, theStatus, theDepartment, theQualification)
{
	this->advisor = &theAdvisor;
}

GraduateStudent::GraduateStudent(const GraduateStudent& other) : Student(other)
{
	this->advisor = other.advisor;
}

GraduateStudent& GraduateStudent::operator=(const GraduateStudent& other)
{
	Student::operator=(other);
	this->advisor = other.advisor;
	
	return *this;
}

GraduateStudent::~GraduateStudent()
{
}

bool GraduateStudent::enrollForCourse(Course& aCourse)
{
	if (aCourse.getCourseId() > GradCourseLevel) {
		return Student::enrollForCourse(aCourse);
	} else {
		cout << "The graduate student cannot enroll in low-level courses" << endl;
		return false;
	}
}

void GraduateStudent::changeAdvisor(Teacher& newAdvisor)
{
	this->advisor = &newAdvisor;
}

Teacher GraduateStudent::getAdvisor() const
{
	return *advisor;
}

void GraduateStudent::print() const
{
	Student::print();
	cout << "advisor = " << advisor->getName() << endl;
}

//////////// derived class GradTeachAsst ///////////////

class GradTeachAsst : public GraduateStudent, public M_QualifiedToTeach {
	Department	teachingDepartment;
	Rank		rank;
	Date		yearOfExperience;
	double		salary;
	Course*		coursesOffered[ MaxCoursesForTeacher ];
	int			numCourses;

public:
	// constructor:
	GradTeachAsst();
	GradTeachAsst( const string theName,
				   unsigned long theSSN,
				   const Date theBirthDate,
				   const string theAddress,
				   StudentStatus theStatus,
				   Department studentDepartment,    // (A)
				   Teacher& theAdvisor,
				   Department teachingDepartment,    // compare to A
				   Date theYearOfExperience, 
				   double theSalary = 0.0, 
				   Rank theRank = GradTeachingAsst );

	
	GradTeachAsst( const GradTeachAsst& other );
	GradTeachAsst& operator=( const GradTeachAsst& other );
	~GradTeachAsst();
	
	void setStudentDepartment( Department dept );
	Department getStudentDepartment() const;
  
	void setTeachingDepartment( Department dept );
	Department getTeachingDepartment() const;
  
	// this method must be overridden because for a GradTeachAsst
	// the rank cannot be changed
	bool setRank( Rank newRank );
	Rank getRank() const;

	bool offerCourse(Course &aCourse);
	bool dropCourse(const Course& theCourse);
	void listCoursesTaught() const;

	void setDepartment( Department dept );
	Department getDepartment() const;
	void listCoursesQualifiedToTeach() const;
	Date getYearOfExperience() const;
	Qualification getHighestDegree() const;
	double getSalary() const;

	// this method must be overridden because of name conflict
	// from two different bases  
	void print() const;
};

GradTeachAsst::GradTeachAsst() : GraduateStudent()
{
	this->teachingDepartment = dUnknown;
	this->rank = rUnknown;
	this->yearOfExperience = Date::today;
	this->salary = 0.0;
	this->numCourses = 0;
}

GradTeachAsst::GradTeachAsst(const string	theName, 
							 unsigned long	theSSN,
							 const Date		theBirthDate,
							 const string	theAddress, 
							 StudentStatus	theStatus,
							 Department		studentDepartment,
							 Teacher&		theAdvisor,
							 Department		teachingDepartment,
							 Date			theYearOfExperience,
							 double			theSalary,
							 Rank			theRank) :
	GraduateStudent(theName, theSSN, theBirthDate, theAddress, theStatus, studentDepartment, theAdvisor)
{
	this->teachingDepartment = teachingDepartment;
	this->rank = theRank;
	this->yearOfExperience = theYearOfExperience;
	this->salary = theSalary;
	this->numCourses = 0;
}

GradTeachAsst::GradTeachAsst(const GradTeachAsst& other) : GraduateStudent(other)
{
	this->teachingDepartment = other.teachingDepartment;
	this->rank = other.rank;
	this->yearOfExperience = other.yearOfExperience;
	this->salary = other.salary;
	this->numCourses = other.numCourses;

	for (int i = 0; i < other.numCourses; i++) {
		this->coursesOffered[i] = other.coursesOffered[i];
	}
}

GradTeachAsst& GradTeachAsst::operator=(const GradTeachAsst& other)
{
	GraduateStudent::operator=(other);
	this->teachingDepartment = other.teachingDepartment;
	this->rank = other.rank;
	this->yearOfExperience = other.yearOfExperience;
	this->salary = other.salary;
	this->numCourses = other.numCourses;

	for (int i = 0; i < other.numCourses; i++) {
		this->coursesOffered[i] = this->coursesOffered[i];
	}

	return *this;
}

GradTeachAsst::~GradTeachAsst()
{
}

void GradTeachAsst::setStudentDepartment(Department dept)
{
	GraduateStudent::setDepartment(dept);
}

Department GradTeachAsst::getStudentDepartment() const
{
	return GraduateStudent::getDepartment();
}

void GradTeachAsst::setTeachingDepartment(Department dept)
{
	this->teachingDepartment = dept;
}

Department GradTeachAsst::getTeachingDepartment() const
{
	return this->teachingDepartment;
}

bool GradTeachAsst::setRank(Rank newRank)
{
	cout << "The graduate teaching assistant's rank cannot be changed" << endl;
	return false;
}

Rank GradTeachAsst::getRank() const
{
	return this->rank;
}

bool GradTeachAsst::offerCourse(Course& aCourse)
{
	if (numCourses < MaxCoursesForTeacher) {
		coursesOffered[numCourses++] = &aCourse;
		return true;
	} else {
		cout << "The number of courses taught is already full" << endl;
		return false;
	}
}

bool GradTeachAsst::dropCourse(const Course& theCourse)
{
	if (numCourses > 0) {
		for (int i = 0; i < numCourses; i++) {
			if (*coursesOffered[i] == theCourse) {
				if (numCourses == 1) {
					coursesOffered[--numCourses] = nullptr;
				} else {
					coursesOffered[i] = coursesOffered[--numCourses];
				}
				return true;
			}
		}

		cout << "The teacher didn't offer this courses" << endl;
		return false;
	} else {
		cout << "The number of courses taught is empty" << endl;
		return false;
	}
}

void GradTeachAsst::listCoursesTaught() const
{
	cout << getName() << "'s courses taught list :" << endl;
	for (int i = 0; i < numCourses; i++) {
		cout << coursesOffered[i]->getCourseName() << ", ";
	}
	cout << endl;
}

void GradTeachAsst::setDepartment(Department dept)
{
	Student::setDepartment(dept);
}

Department GradTeachAsst::getDepartment() const
{
	return Student::getDepartment();
}

void GradTeachAsst::listCoursesQualifiedToTeach() const
{
	cout << getName() << "'s courses qualified list : " << endl;

	for (int i = 0; i < numCourses; i++) {
		cout << coursesOffered[i]->getCourseName() << " is for ";

		if (coursesOffered[i]->getCourseId() < GradCourseLevel) {
			cout << qualificationNames[Undergraduate];
		} else {
			cout << qualificationNames[Graduate];
		}
		cout << endl;
	}
}

Date GradTeachAsst::getYearOfExperience() const
{
	return this->yearOfExperience;
}

Qualification GradTeachAsst::getHighestDegree() const
{
	return Student::getStudentQualification();
}

double GradTeachAsst::getSalary() const
{
	return this->salary;
}

void GradTeachAsst::print() const
{
	GraduateStudent::print();
	cout << "teachingDepartment = " << departmentNames[this->teachingDepartment] << endl;
	cout << "rank = "<< rankNames[getRank()] << endl;
	cout << "yearOfExperience = " << this->yearOfExperience << endl;
	cout << "salary = " << getSalary() << endl;
	cout << "numCourses = " << this->numCourses << endl;
	listCoursesTaught();
	listCoursesQualifiedToTeach();
}

#endif /* __PROJECT2__ */
