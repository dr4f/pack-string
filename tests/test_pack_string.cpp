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

void test_write_object_2()
{
	PackString a;
	long b = 4000;
	a.writeObject(b);
	a.writeObject(b);
	TEST_CHECK_ALL(a.dataSize() == (sizeof(long) * 2), failCount);
	const MallocArray<size_t>& idx = a.getIndexes();
	TEST_CHECK_ALL(idx[0] == 0, failCount);
	// Next long is one offset of long size off from first item.
	TEST_CHECK_ALL(idx[1] == sizeof(long), failCount);
}


int main(int argc, char const *argv[])
{
	test_write_object_1();
	test_write_object_2();
	if(failCount > 0) {
		std::cout << "\nTESTS FAILED\n";
		return 3;
	} else {
		std::cout << "\nTESTS PASSED\n";
		return 0;
	}
}
