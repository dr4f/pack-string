#include "PackString.h"

MallocArrayException::MallocArrayException(MallocArrayException::ErrType code): code(code)
{
	switch(code)
	{
		case NULL_ON_MALLOC:
		        message = "MallocArrayErr: Got nullptr when calling malloc.";
		        break;
		case NULL_ON_REALLOC:
		        message = "MallocArrayErr: Got nullptr when calling realloc.";
		        break;
		case OUT_OF_BOUNDS:
		        message = "MallocArrayErr: Attempted to access an item out of bounds.";
		        break;

	}
}
