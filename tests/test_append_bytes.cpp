#include "test-helpers.h"
#include "PackString.h"

#include <cstdlib>
#include <ctime>

// Failure count tracker
static unsigned failCount = 0;

/* @file Tests the interface of PackString.
 * @detail Tests the implementation of multiple append_bytes()
 *         functions that are called when the write() or operator <<
 *         of the pack string is called.
 */

#define TEST_OBJECT_DATA_LEN 10

class TestObject
{
public:
	TestObject(){}
	~TestObject(){}
private:
	char _text[TEST_OBJECT_DATA_LEN];
	int _nums[TEST_OBJECT_DATA_LEN];
	long _counts[TEST_OBJECT_DATA_LEN];
public:
	friend void makeTestObject(TestObject& obj);
	friend void append_bytes(PackString& pstring, const TestObject& obj);
};

void makeTestObject(TestObject& obj)
{
	time_t seeder;
	std::time(&seeder);
	std::srand(seeder);
	for(unsigned i = 0; i < TEST_OBJECT_DATA_LEN; i++)
	{
		obj._nums[i] = std::rand() % 127;
		obj._counts[i] = std::rand() % 127;
		obj._text[i] = static_cast<char>(std::rand() % 127);
	}
}

void append_bytes(PackString& pstring, const TestObject& obj)
{
	for(unsigned i = 0; i < TEST_OBJECT_DATA_LEN; i++)
	{
		pstring.writeObject(obj._nums[i]);
	}

	for(unsigned j = 0; j < TEST_OBJECT_DATA_LEN; j++)
	{
		pstring.pushByte(static_cast<unsigned char>(obj._text[j]));
	}
}

int main(int argc, char const *argv[])
{
	if(failCount > 0) {
		std::cout << "\nTESTS FAILED\n";
		return 3;
	} else {
		std::cout << "\nTESTS PASSED\n";
		return 0;
	}
}
