
#include "signalTest.hpp"
#include "basicTest.hpp"

int main()
{
	basicTest b;
	b.runTest();

	signalTest t;
	t.runTest();
}
