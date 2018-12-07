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

void test_array_access()
{
	MallocArray<int> arr;
	arr.push(1);
	arr.push(2);
	arr.push(3);
	TEST_CHECK_ALL(arr[0] == 1 && arr[1] == 2, failureCount);
}

void test_array_expand()
{
	int i;
	MallocArray<int> arr(10);
	for(i = 0; i < 12; i++)
	{
		arr.push(i);
	}
	TEST_CHECK_ALL(arr.getCap() > 10, failureCount);
	TEST_CHECK_ALL(arr.getLen() == 12, failureCount);
}

void test_array_exc()
{
	int sum = 0;
	MallocArray<int> arr(5);
	arr.push(8);
	try 
	{
		sum += arr[4];
	}
	catch(const MallocArrayException& exc)
	{
		TEST_CHECK_ALL(exc.code == MallocArrayException::OUT_OF_BOUNDS, failureCount);
		return;
	}
}

void test_array_shrink()
{
	MallocArray<long> arr(15);
	arr.push(10);
	arr.push(20);
	arr.push(80);
	arr.shrink(1);
	TEST_CHECK_ALL(arr.getLen() == 1, failureCount);
}

int main(int argc, char const *argv[])
{
	test_array_init();
	test_array_push();
	test_array_access();
	test_array_expand();
	test_array_exc();
	test_array_shrink();
	if(failureCount > 0) {
		std::cout << "TESTS FAILED\n";
		return 3;
	} else {
		std::cout << "TESTS PASSED\n";
		return 0;
	}
}
