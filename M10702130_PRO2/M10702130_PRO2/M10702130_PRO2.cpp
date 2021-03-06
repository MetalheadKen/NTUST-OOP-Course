#include <iostream>
#include "project2_starter.h"

using namespace std;

int main()
{
	Course math("math", 1);
	Course eng("english", 2);
	Course chinese("chinese", 3);
	Course science("science", 500);
	Course algorithm("algorithm", 600);

	cout << "Course class testing" << endl;
	Course test1(math);
	Course test2;
	
	test2 = test1;
	test2.setCourseName("test2");
	test2.setCourseId(2);
	cout << "Course test2 = " << test2;

	cout << endl;

	cout << "Person class testing" << endl;
	Person p1;
	Person p2("p2", 123456, Date(1, 2, 2019), "abcd");
	Person p3(p2);
	Person pp;
	
	pp = p3;
	pp.setName("pp");
	pp.setIdentification(654321);
	pp.setAddress("dcba");
	//pp.print();

	cout << endl;

	cout << "Student class testing" << endl;
	Student s1;
	Student s2("s2", 123456, Date(1, 3, 2019), "abcd", FullTime, Accounting, HighSchool);
	Student s3(s2);
	Student ss;

	ss = s3;
	ss.setStatus(Exchange);
	ss.setDepartment(Business);
	ss.enrollForCourse(math);
	ss.enrollForCourse(eng);
	ss.enrollForCourse(chinese);
	ss.dropFromCourse(eng);
	ss.listCoursesRegisteredFor();
	ss.setStudentQualification(Undergraduate);
	//ss.print();

	cout << endl;

	cout << "Teacher class testing" << endl;
	Teacher t1;
	Teacher t2("t2", 123456, Date(1, 4, 2019), "abcd", AssocProf, Mathematics, 150.0, Graduate, Date(1, 8, 2019));
	Teacher t3(t2);
	Teacher tt;

	tt = t3;
	tt.setDepartment(Arts);
	tt.setRank(Professor);
	tt.setSalary(152.0);
	tt.offerCourse(math);
	tt.offerCourse(eng);
	tt.dropCourse(eng);
	tt.listCoursesTaught();
	tt.assignGrader("g1");
	tt.assignGrader("g2");
	tt.dropGrader("g1");
	tt.listGraders();
	tt.listCoursesQualifiedToTeach();
	tt.setYearOfExperience(Date(1, 12, 2019));
	tt.setHighestDegree(Doctorate);
	//tt.print();

	cout << endl;

	cout << "GraduateStudent class testing" << endl;
	GraduateStudent g1;
	GraduateStudent g2("g2", 123456, Date(1, 5, 2019), "abcd", PartTime, Chemistry, tt);
	GraduateStudent g3(g2);
	GraduateStudent gg;

	gg = g3;
	gg.enrollForCourse(math);
	gg.enrollForCourse(science);
	gg.enrollForCourse(algorithm);
	gg.changeAdvisor(t2);
	//gg.print();

	cout << endl;

	cout << "GradTeachAsst class testing" << endl;
	GradTeachAsst ta1;
	GradTeachAsst ta2;
	GradTeachAsst ta3("ta3", 123456, Date(1, 6, 2019), "abcd", FullTime, Physics, tt, Arts, Date(1, 10, 2019));
	GradTeachAsst taa;

	taa = ta3;
	taa.setStudentDepartment(Engineering);
	taa.setTeachingDepartment(Engineering);
	taa.setRank(Instructor);
	taa.offerCourse(math);
	taa.offerCourse(algorithm);
	taa.offerCourse(science);
	taa.dropCourse(science);
	taa.offerCourse(math);
	taa.listCoursesTaught();
	taa.listCoursesQualifiedToTeach();
	//taa.print();

	cout << endl;

	cout << "Polymorphism testing" << endl;
	Person *pptr[5] = { &pp, &ss, &tt, &gg, &taa };
	for (int i = 0; i < 5; i++) {
		cout << "--------------------" << endl;
		pptr[i]->print();
	}
}
