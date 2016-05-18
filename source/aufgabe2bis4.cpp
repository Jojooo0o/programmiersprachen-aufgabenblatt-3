#include <cstdlib>	//std::rand()
#include <vector>	//std::vector<>
#include <list>		//std::list<>
#include <iostream>	//std::cout
#include <iterator>	//std::ostream_iterator<>
#include <algorithm> //std::reserve, std::generate
#include <set>
#include <map>


int main () {

	std::list<unsigned int> l0(100);

	for (std::list<unsigned int>::iterator it = l0.begin();
		it != l0.end(); ++it) {
		*it = std::rand() % 101;
	}

	std::vector<unsigned int> v0(l0.size());
	std::copy(std::begin(l0), std::end(l0), std::begin(v0));

	std::set<unsigned int> set0;


	std::map<unsigned int, unsigned int> map0;

	for(std::list<unsigned int>::iterator it = l0.begin();
		it != l0.end(); ++it){
		auto a = set0.insert(*it);
		if(a.second){
			map0[*it] = 1;
		} else {
			map0[*it] += 1;
		}
	}


	std::set<unsigned int> set1;
	for(unsigned int i=0; i<101; i++)
		set1.insert(i);

	for(std::set<unsigned int>::iterator it = set0.begin();
		it != set0.end(); ++it)
		set1.erase(*it);


	//Ausgaben

	/*std::copy(std::begin(l0), std::end(l0),
	std::ostream_iterator<unsigned int>(std::cout, "\n"));

	std::copy(std::begin(v0), std::end(v0),
	std::ostream_iterator<unsigned int>(std::cout, "\n"));

	std::cout << "--------------------------------------" << "\n";

	std::copy(std::begin(set0), std::end(set0),
	std::ostream_iterator<unsigned int>(std::cout, "\n"));

	std::cout << "Die Liste enthaelt: " << set0.size() << " Elemente" << "\n";

	std::copy(std::begin(set1), std::end(set1),
	std::ostream_iterator<unsigned int>(std::cout, "\n"));
*/

	for(std::set<unsigned int>::iterator it = set0.begin(); //3.4 Häufigkeit
		it != set0.end(); ++it)
		std::cout << *it << " : "<< map0[*it] << std::endl;

	return 0;
}