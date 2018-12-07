#include "test-helpers.h"
#include "PackString.h"

// Failure count tracker
static unsigned failCount = 0;


void test_write_object_1()
{
	PackString a;
	long b = 5000;
	a.writeObject(b);
	TEST_CHECK_ALL(a.dataSize() == sizeof(long), failCount);
}


int main(int argc, char const *argv[])
{
	test_write_object_1();
	if(failCount > 0) {
		std::cout << "\nTESTS FAILED\n";
		return 3;
	} else {
		std::cout << "\nTESTS PASSED\n";
		return 0;
	}
}
