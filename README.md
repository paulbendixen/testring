# Checking out the ring span
This repo is a test of the ring_span that is being suggested for SG14

The reason the ring_span is interesting to me is because it is a very commonly used tool in signal processing.
This however demands that it is possible to throw items into it and filter it, using the ring buffer as a delay line.

This seems to be not quite working now, hence this repository.

# Instructions
It should be enough to get this to compile to have a cmake installation and the WG21-SG14/SG14 repository chekced out
to the same directory this one is checked out to in order to have it work just using cmake:

	mkdir build
	cd build
	cmake ..
	make
	./ringTest

_enjoy_
