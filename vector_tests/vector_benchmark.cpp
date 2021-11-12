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
	static size_t benchmark_test(Container& con, Container& vec, std::vector< std::pair< std::string, size_t > >& result)
{
	Timer	time;

	time.start_timer();
	for (size_t i = 0; i < 500000; ++i)
		con.push_back(test(i));
	result.push_back(std::make_pair("push_back", time.end_reset()));

	time.start_timer();
	con.insert(con.begin(), 250000, test(1, "insert"));
	result.push_back(std::make_pair("fill insert", time.end_reset()));

	time.start_timer();
	while (con.size() > 1337)
		con.pop_back();
	result.push_back(std::make_pair("pop_back", time.end_reset()));
	
	time.start_timer();
	for (size_t i = 0; i < 42069; ++i)
		vec.swap(con);
	result.push_back(std::make_pair("swap", time.end_reset()));

	vec.insert(vec.begin(), 42069, test(1, "erase"));

	time.start_timer();
	vec.erase(vec.begin(), vec.end() - 2500);
	result.push_back(std::make_pair("erase", time.end_reset()));

	vec.insert(vec.begin(), 42069, test(1, "erase range"));

	time.start_timer();
	vec.clear();
	result.push_back(std::make_pair("clear", time.end_reset()));

	time.start_timer();
	for (size_t i = 0; i < 500; ++i) {
		vec.reserve(250);
		vec.reserve(500000);
		vec.clear();
	}
	result.push_back(std::make_pair("reserve", time.end_reset()));

	for (size_t i = 0; i < vec.capacity(); i++)
		vec.push_back(test(i));

	time.start_timer();
	for (size_t i = 0; i < 500; ++i) {
		vec.resize(25000);
		vec.resize(1337);
	}
	result.push_back(std::make_pair("resize", time.end_reset()));
	
	time.start_timer();
	for (size_t i = 0; i < 50; ++i) {
		vec.assign(420, test(69));
		vec.assign(200000, test(69));
	}
	result.push_back(std::make_pair("assign", time.end_reset()));

	return (time.get_total_time());
}

void vector_benchmark()
{
	double ft_duration, std_duration;
	std::vector< std::pair< std::string, size_t> > ft_result, std_result;
	
	ft::vector<test> ft_con;
	ft::vector<test> ft_vec;
	ft_duration = benchmark_test(ft_con, ft_vec, ft_result);

	std::vector<test> std_con;
	std::vector<test> std_vec;
	std_duration = benchmark_test(std_con, std_vec, std_result);

	format_benchmark_result(ft_result, std_result, "vector");

	print_benchmark_result(ft_duration, std_duration, "vector");
}
