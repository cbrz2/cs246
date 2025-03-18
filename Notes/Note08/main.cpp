#include "Array.h"

int main() 
{
	dsn::Array<int> a(10);

	for(int i = 0;i < a.size();i += 1)
	{
		a[i] = i + 8;
	}

	std::cout << a << "\n";
	return 0;
}
