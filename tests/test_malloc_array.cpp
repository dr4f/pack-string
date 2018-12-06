#include "test-helpers.h"
#include "PackString.h"

static unsigned failureCount = 0;

void test_array_init()
{
	MallocArray<char> arr(10);
	TEST_CHECK_ALL(arr.getCap() == 10, failureCount);
}

int main(int argc, char const *argv[])
{
	test_array_init();
	if(failureCount > 0) {
		std::cout << "TESTS FAILED\n";
		return 3;
	} else {
		std::cout << "TESTS PASSED\n";
		return 0;
	}
}
