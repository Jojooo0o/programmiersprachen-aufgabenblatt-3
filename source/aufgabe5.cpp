#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>

	bool is_odd(int i){
		return (i % 2) != 0;
	}

	bool is_even(int i){
		return (i % 2) == 0;
	}



TEST_CASE("describe_factorial", "[aufgbae3]")
{
	//ihre Loesung :

	std::vector<int> v0(100);

	for (std::vector<int>::iterator it = v0.begin();
		it != v0.end(); ++it) {
		*it = std::rand() % 101;
	}

	v0.erase( std::remove_if(v0.begin(), v0.end(), is_odd), v0.end() );


	REQUIRE(std::all_of(v0.begin(), v0.end(), is_even));
}

int main (int argc, char* argv[])
{
	return Catch::Session().run (argc, argv);
}