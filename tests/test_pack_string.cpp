#include "test-helpers.h"
#include "PackString.h"

// Failure count tracker
static unsigned failCount = 0;


void test_one()
{
	TEST_CHECK_ALL(3 == 3, failCount);
}


int main(int argc, char const *argv[])
{
	test_one();
	if(failCount > 0) {
		std::cout << "TESTS FAILED\n";
		return 3;
	} else {
		std::cout << "TESTS PASSED\n";
		return 0;
	}
}
