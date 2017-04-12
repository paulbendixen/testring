#include <iostream>
#include <ring.h>
#include <array>

int main()
{
	std::array< int, 3 > a;

	sg14::ring_span< int > r( a.begin(), a.end() );

	r.push_back( 1 );
	r.push_back( 2 );
	r.push_back( 3 );
	r.push_back( 5 );

	assert( r.front() == 2 );

	for ( const auto& v: r )
	{
		std::cout << v << " ";
	}
	std::cout << '\n';
}