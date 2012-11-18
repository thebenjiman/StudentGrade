//
//  main.cpp
//  StudentGrade
//
//  Created by Benjamin DOMERGUE on 22/10/12.
//  Copyright (c) 2012 Benjamin DOMERGUE. All rights reserved.
//

#include <iostream>
#include <iomanip>

#include "grade.h"
#include "StudentInfo.h"

using namespace std;

typedef vector<StudentInfo> StudentInfoContainer;

bool failing_grade(const StudentInfo& s)
{
	return grade(s) < 60;
}

bool successing_grade(const StudentInfo& s)
{
	return !failing_grade(s);
}

StudentInfoContainer extract_fails(StudentInfoContainer& students)
{
	StudentInfoContainer::iterator iterator = stable_partition(students.begin(), students.end(), successing_grade);
	StudentInfoContainer output(iterator, students.end());
	students.erase(iterator, students.end());
	return output;
}

void print_results(const StudentInfoContainer students, const string::size_type& maxlength)
{
	for(StudentInfoContainer::size_type i = 0; i < students.size(); ++i)
	{
		StudentInfo student = students[i];
		cout << student.name << string(maxlength + 1 - student.name.size(), ' ');
		
		try
		{
			double total = grade(student);
			
			streamsize precision = cout.precision();
			cout << setprecision(3) << total << setprecision((int)precision);
		}
		catch(domain_error e)
		{
			cout << e.what();
		}
		cout << endl;
	}
}

int main(int argc, const char * argv[])
{
	StudentInfo record;
	StudentInfoContainer students;
	string::size_type maxlength = 0;
	
	while(read_student(cin, record))
	{
		cout << "Successfully read information for " << record.name << endl;
		maxlength = max(maxlength, record.name.size());
		students.push_back(record);
	}
	
	sort(students.begin(), students.end(), compare);
	StudentInfoContainer failed = extract_fails(students);
	
	cout << "Passed students: " << endl;
	print_results(students, maxlength);
	
	cout << endl << "Failed students: " << endl;
	print_results(failed, maxlength);
	 
	return 0;
}

