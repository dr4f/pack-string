#include "test-helpers.h"
#include "PackString.h"

static unsigned failureCount = 0;

void test_array_init()
{
	MallocArray<char> arr(10);
	TEST_CHECK_ALL(arr.getCap() == 10, failureCount);
}

void test_array_push()
{
	MallocArray<int> arr;
	arr.push(6);
	arr.push(10);
	TEST_CHECK_ALL(arr.getLen() == 2, failureCount);
}

int main(int argc, char const *argv[])
{
	test_array_init();
	test_array_push();
	if(failureCount > 0) {
		std::cout << "TESTS FAILED\n";
		return 3;
	} else {
		std::cout << "TESTS PASSED\n";
		return 0;
	}
}
