#include <iostream>
#include "SharedPtr.h"

int main()
{
	// Test 1 for copy ct-r
	/*SharedPtr<int> sh_1(new int{ 1 });
	SharedPtr<int> sh_2(sh_1);
	SharedPtr<int> sh_3(new int{ 3 });*/

	// Test 2 for operator=
	/*SharedPtr<int> sh_1(new int{ 1 });
	SharedPtr<int> sh_2(new int{2});
	sh_2 = sh_1;*/

	
	// Test 3
	/*SharedPtr<int> iPt(new int{ 123 });
	SharedPtr<double> dPt(new double{ 321.67 });*/

	// Test 4
	SharedPtr<int> iPt1(new int{ 10 });
	SharedPtr<int> iPt1Copy(iPt1);
	SharedPtr<int> iPt2(new int{ 20 });
	iPt2 = iPt1;
	return 0;
}