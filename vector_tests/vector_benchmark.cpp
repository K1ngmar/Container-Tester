/* ************************************************************************** */
/*                                                                            */
/*              ,---------.     .-''-.      .-'''-.  ,---------.              */
/*              \          \  .'_ _   \    / _     \ \          \             */
/*               `--.  ,---' / ( ` )   '  (`' )/`--'  `--.  ,---'             */
/*                  |   \   . (_ o _)  | (_ o _).        |   \                */
/*                  :_ _:   |  (_,_)___|  (_,_). '.      :_ _:                */
/*                  (_I_)   '  \   .---. .---.  \  :     (_I_)                */
/*                 (_(=)_)   \  `-'    / \    `-'  |    (_(=)_)               */
/*                  (_I_)     \       /   \       /      (_I_)                */
/*                  '---'      `'-..-'     `-...-'       '---'                */
/*                                                                            */
/*                   Kingmar  |  https://github.com/K1ngmar                   */
/*                                                                            */
/* ************************************************************************** */

# include <test.hpp>
# include <vector.hpp>
# include <vector>

template< class Container >
	static size_t benchmark_test(Container& con, Container& vec)
{
	Timer	time;

	time.start_timer();
	for (size_t i = 0; i < 500000; ++i)
		con.push_back(test(i));
	time.end_and_print("push_back");

	time.start_timer();
	con.insert(con.begin(), 250000, test(1, "insert"));
	time.end_and_print("fill insert");

	time.start_timer();
	while (con.size() > 1337)
		con.pop_back();
	time.end_and_print("pop back");
	
	time.start_timer();
	for (size_t i = 0; i < 42069; ++i)
		vec.swap(con);
	time.end_and_print("swap");

	vec.insert(vec.begin(), 42069, test(1, "erase"));

	time.start_timer();
	vec.erase(vec.begin(), vec.end() - 2500);
	time.end_and_print("erase range");

	vec.insert(vec.begin(), 42069, test(1, "erase"));

	time.start_timer();
	vec.clear();
	time.end_and_print("clear");

	time.start_timer();
	for (size_t i = 0; i < 500; ++i) {
		vec.reserve(250);
		vec.reserve(500000);
		vec.clear();
	}
	time.end_and_print("Reserve");

	for (size_t i = 0; i < vec.capacity(); i++)
		vec.push_back(test(i));

	time.start_timer();
	for (size_t i = 0; i < 500; ++i) {
		vec.resize(25000);
		vec.resize(1337);
	}
	time.end_and_print("Resize");
	
	time.start_timer();
	for (size_t i = 0; i < 50; ++i) {
		vec.assign(420, test(69));
		vec.assign(200000, test(69));
	}
	time.end_and_print("assign");
	return (time.get_total_time());
}

void vector_benchmark()
{
	double ft_duration, std_duration;
	
	print_benchmark_header("ft", "vector");
	ft::vector<test> ft_con;
	ft::vector<test> ft_vec;
	ft_duration = benchmark_test(ft_con, ft_vec);

	print_benchmark_header("std", "vector");
	std::vector<test> std_con;
	std::vector<test> std_vec;
	std_duration = benchmark_test(std_con, std_vec);

	print_benchmark_result(ft_duration, std_duration, "vector");
}
