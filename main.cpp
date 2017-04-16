#include <iostream>
#include <ring.h>
#include <array>
#include <utility>
#include <numeric>
#include "signalTest.hpp"

int main()
{
	std::array< double, 3 > baseArray;

	sg14::ring_span< double > ringBuffer( baseArray.begin(), baseArray.end() );

	ringBuffer.push_back( 1 );
	ringBuffer.push_back( 2 );
	ringBuffer.push_back( 3 );
	ringBuffer.push_back( 5 );

	assert( ringBuffer.front() == 2.0 );

	for ( const auto& value : ringBuffer )
	{
		std::cout << value << " ";
	}
	std::cout << '\n';

	std::array< double, 3 > filterCoefficients = {.25, .5, .25 };

	// in interrupt loop or the like
	ringBuffer.push_back( 7 );
	std::cout << std::inner_product( ringBuffer.begin(), ringBuffer.end(), filterCoefficients.begin() , 0.0 );
	std::cout << " ";

	ringBuffer.push_back( 11 );
	std::cout << std::inner_product( ringBuffer.begin(), ringBuffer.end(), filterCoefficients.begin() , 0.0 );
	std::cout << " ";

	ringBuffer.push_back( 13 );
	std::cout << std::inner_product( ringBuffer.begin(), ringBuffer.end(), filterCoefficients.begin() , 0.0 );
	std::cout << " ";

	ringBuffer.push_back( 17 );
	std::cout << std::inner_product( ringBuffer.begin(), ringBuffer.end(), filterCoefficients.begin() , 0.0 );
	std::cout << "\n";

	signalTest t;
	t.runTest();
}
