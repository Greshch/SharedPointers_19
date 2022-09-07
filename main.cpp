#include <iostream>
#include "SharedPtr.h"

int main()
{
	// Test 1 for copy ct-r
	/*SharedPtr<int> sh_1(new int);
	SharedPtr<int> sh_2(sh_1);
	SharedPtr<int> sh_3(new int);*/

	// Test 2 for operator=
	SharedPtr<int> sh_1(new int);
	SharedPtr<int> sh_2(new int);
	sh_2 = sh_1;
	return 0;
}