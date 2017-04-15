#include <iostream>
#include <ring.h>
#include <array>
#include <utility>
#include <numeric>

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

	std::array< int, 3 > filterCoeff = {1, 2, 1 };

	// in interrupt loop or the like
	ringBuffer.push_back( 7 );
	std::cout << std::inner_product( ringBuffer.begin(), ringBuffer.end(), filterCoeff.begin() , 0 );
}
