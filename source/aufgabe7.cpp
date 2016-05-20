#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include "circle.hpp"

	bool is_odd(int i){
		return (i % 2) != 0;
	}

	bool is_even(int i){
		return (i % 2) == 0;
	}



TEST_CASE("describe_sort", "[sort]")
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
	int a = 0;
	int b = 1;

	swap(c1, c2);
	swap(a, b);

	REQUIRE(c1.get_r()==5.0f);
	REQUIRE(c2.get_r()==6.0f);

	REQUIRE(a == 1);
	REQUIRE(b == 0);

}


TEST_CASE("describe_sort2", "[sort2]"){

	std::list<Circle> list0(5);
	for (int i = 0; i < 5; ++i) {

		float rad = std::rand() % 10;
		Circle c(rad, 0.0f, 0.0f);
		list0.push_back(c);
	}

	list0.sort([](Circle a, Circle b) {
		return a.get_r() < b.get_r();
	});


	REQUIRE(std::is_sorted(list0.begin(), list0.end()));
}

TEST_CASE("describe_add_lambda", "[add_lambda]"){


	std::vector<int> v1{1,2,3,4,5,6,7,8,9};
	std::vector<int> v2{9,8,7,6,5,4,3,2,1};
	std::vector<int> v3(9);

	std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), []( int a, int b) {
		return a+b;
	});

	REQUIRE(std::all_of(v3.begin(), v3.end(), [] (int a) {
		return a == 10;
	}));



}





int main (int argc, char* argv[])
{
	return Catch::Session().run (argc, argv);
}