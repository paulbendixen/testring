//
// Created by Paul M. Bendixen on 16-04-17.
//

#ifndef RINGTEST_SIGNALTEST_HPP
#define RINGTEST_SIGNALTEST_HPP

#include <ring.h>
#include <random>

class signalTest
{
	public:
		signalTest( double samplerate = 44100.0 );
		void runTest(double runlength = 1.0 );

	private:
		std::random_device device;
		std::mt19937 generator;
		std::normal_distribution<double> dist;
		const double samplerate;
};


#endif //RINGTEST_SIGNALTEST_HPP
