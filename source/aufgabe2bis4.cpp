#include <cstdlib>	//std::rand()
#include <vector>	//std::vector<>
#include <list>		//std::list<>
#include <iostream>	//std::cout
#include <iterator>	//std::ostream_iterator<>
#include <algorithm> //std::reserve, std::generate


int main () {

	std::list<unsigned int> l0(100); //nur + zahlen

	for (std::list<unsigned int>::iterator it = l0.begin(); //v0 mit zufallszahlen
		it != l0.end(); ++it) {
		*it = std::rand() % 101;
	}
	
	std::vector<unsigned int> v0(l0.size());
	std::copy(std::begin(l0), std::end(l0), std::begin(v0));



	std::copy(std::begin(l0), std::end(l0),
	std::ostream_iterator<unsigned int>(std::cout, "\n"));

	std::copy(std::begin(v0), std::end(v0),
	std::ostream_iterator<unsigned int>(std::cout, "\n"));
}