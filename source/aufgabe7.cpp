#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include "circle.hpp"

	bool is_odd(int i){
		return (i % 2) != 0;
	}

	bool is_even(int i){
		return (i % 2) == 0;
	}



TEST_CASE("describe_factorial", "[aufgbae3]")
{
	//ihre Loesung :

	std::set<Circle> set0;

	for (int i = 0; i < 5; ++i) {

		float rad= std::rand() % 10;
		Circle c(rad, 0.0f, 0.0f);
		set0.insert(c);
	}

	std::set<Circle> set1;

	Circle c1(6.0f, 0.0f, 0.0f);
	Circle c2(5.0f, 0.0f, 0.0f);
	Circle c3(7.0f, 0.0f, 0.0f);
	Circle c4(2.0f, 0.0f, 0.0f);

	set1.insert(c1);
	set1.insert(c2);
	set1.insert(c3);
	set1.insert(c4);

REQUIRE(std::is_sorted(set0.begin(), set0.end()));
REQUIRE(std::is_sorted(set1.begin(), set1.end()));

}

template<typename T>
void swap(T& a, T& b) {
	T c(a);
	a = b;
	b = c;
}

TEST_CASE("describe_swap", "[aufgabe3.8]"){

	Circle c1(6.0f, 0.0f, 0.0f);
	Circle c2(5.0f, 0.0f, 0.0f);


	swap(c1, c2);

	REQUIRE(c1.get_r()==5.0f);
	REQUIRE(c2.get_r()==6.0f);



}




int main (int argc, char* argv[])
{
	return Catch::Session().run (argc, argv);
}