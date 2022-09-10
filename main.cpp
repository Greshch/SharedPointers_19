#include <iostream>
#include "SharedPtr.h"

int main()
{
	// Test 1 for copy ct-r
	/*SharedPtr<int> sh_1(new int);
	SharedPtr<int> sh_2(sh_1);
	SharedPtr<int> sh_3(new int);*/

	// Test 2 for operator=
	/*SharedPtr<int> sh_1(new int);
	SharedPtr<int> sh_2(new int);
	sh_2 = sh_1;*/

	/*int* i = new int;
	*i = 123;

	double* d = new double;
	*d = 321.67;
	SharedPtr<int> iPt(i);
	SharedPtr<double> dPt(d);*/

	SharedPtr<int> iPt1(new int{ 10 });
	SharedPtr<int> iPt1Copy(iPt1);

	SharedPtr<int> iPt2(new int{ 20 });
	iPt2 = iPt1;
	return 0;
}