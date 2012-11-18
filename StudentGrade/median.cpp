//
//  median.cpp
//  StudentGrade
//
//  Created by Benjamin DOMERGUE on 22/10/12.
//  Copyright (c) 2012 Benjamin DOMERGUE. All rights reserved.
//

#include "median.h"

#include <vector>
#include <algorithm>

using namespace std;

typedef vector<double>::size_type double_vector_size;
double vector_median(vector<double> numbers)
{
	double_vector_size size = numbers.size();
	if(size != 0)
	{
		sort(numbers.begin(), numbers.end());
		
		double_vector_size middle = size / 2;
		return size % 2 == 0 ? ((numbers[middle] + numbers[middle - 1]) / 2) : numbers[middle];
	}
	else
	{
		throw domain_error("cannot calculate median of empty vector");
	}
}
