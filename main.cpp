#include <iostream>
#include <ring.h>
#include <array>
#include <utility>

int main()
{
	using namespace std::rel_ops;
	std::array< int, 3 > baseArray;

	sg14::ring_span< int > ringBuffer( baseArray.begin(), baseArray.end() );

	ringBuffer.push_back( 1 );
	ringBuffer.push_back( 2 );
	ringBuffer.push_back( 3 );
	ringBuffer.push_back( 5 );

	assert( ringBuffer.front() == 2 );

	for ( const auto& value : ringBuffer )
	{
		std::cout << value << " ";
	}
	std::cout << '\n';
}
