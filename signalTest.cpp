//
// Created by expert on 16-04-17.
//

#include "signalTest.hpp"
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>

void signalTest::runTest( double runlength )
{
	// generate a signal
	std::vector< double > signal;
	signal.resize( static_cast< unsigned long >( std::round( runlength * this->samplerate ) ) );
	int t = 0;
	std::generate( signal.begin(), signal.end(), [&t](){ return std::sin( 2 * M_PI * 440.0 * t++ / 44.1e3 );});
	// add some noise
	std::transform( signal.begin(), signal.end(), signal.begin(), [this](double s ){ return s + this->dist
				(this->generator); } );
	// filter it
	constexpr std::array< double, 3 > filterCoefficients = { .25, .5, .25 };

	std::array< double, 3 > buffer;
	sg14::ring_span< double > delayline( buffer.begin(), buffer.end() );

	double time = 0.0;
	std::ofstream myfile;
	myfile.open( "testresults.csv", std::ios::out );
	for ( auto& value: signal )
	{
		myfile << time << ',';
		time += 1/this->samplerate;
		myfile << value << ',';
		delayline.push_back(value);
		value = std::inner_product( delayline.begin(), delayline.end(), filterCoefficients.begin(), 0.0 );
		myfile << value << '\n';
	}

	// plot it (use gplot)
}

signalTest::signalTest( double samplerate )
	:generator( device() ), dist(0, .5 ), samplerate( samplerate )
{
}
