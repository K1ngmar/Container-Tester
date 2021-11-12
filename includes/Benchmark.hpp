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

#ifndef REAL_COOL_BENCHMARK_CLASS_HPP
# define REAL_COOL_BENCHMARK_CLASS_HPP

# include <test.hpp>
# include <map>

template< class Container >
	class Benchmark
{

//////////////////////
// MEMBER VARiABLES //
//////////////////////
private:

	std::map< std::string, size_t >	results;
	Timer							time;
	Container						con;

//////////////////
// Construction //
//////////////////
public:

	Benchmark() : con(Container()) 
	{
	}

	~Benchmark() {}

////////////
// Tester //
////////////
public:

	void	run_test(void(*func)(Container&), std::string test_name)
	{
		time.start_timer();
		func(con);
		results[test_name] += time.end_reset();
	}

	void	run_test(void(*func)(Container&, Container&), std::string test_name)
	{
		Container empty;
		time.start_timer();
		func(con, empty);
		results[test_name] += time.end_reset();
	}

	size_t	get_total_time()
	{
		return (time.get_total_time());
	}

	Container&	get_container()
	{
		return (con);
	}

	std::map< std::string, size_t > get_result()
	{
		return (results);
	}

}; /* end of benchmark class */

///////////////////////
// Benchmark headers //
///////////////////////

void	print_benchmark_header(std::string prefix, std::string type)
{
	std::cout << COLOR_GREEN << prefix;
	std::cout << COLOR_RESET << "::" << COLOR_ORANGE << type << COLOR_RESET << std::setw(12) << std::left << std::setfill('-') << "";
}

void	print_benchmark_result(double ft_dur, double std_dur, const char* type)
{
	double result = (std_dur / ft_dur) * 100;

	std::cout << COLOR_GREEN << "\nft" << COLOR_RESET;
	std::cout << "::" << COLOR_ORANGE << type << COLOR_RESET;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << " was ";
	if (result >= (float)100) {
		std::cout << COLOR_GREEN << result - (float)100 << COLOR_RESET << "% ";
		std::cout << "faster :D\n";
	}
	else {
		std::cout << COLOR_RED << (float)100 - result << COLOR_RESET << "% ";
		std::cout << "slower :(\n";
	}
}

static size_t my_diff(size_t& first, size_t& second)
{
	if (first > second)
		return (first - second);
	return (second - first);
}

void	format_benchmark_result(std::map< std::string, size_t >	& ft_rs,
								std::map< std::string, size_t >	& std_rs,
								std::string container)
{
	std::cout << "\n" << std::setfill('-') << std::setw(21) << std::right;
	std::cout << COLOR_BLU << "BENCHMARK ";

	print_benchmark_header("ft", container);
	std::cout << std::endl << std::setfill(' ');

	std::map< std::string, size_t >::iterator ft_itr = ft_rs.begin();
	std::map< std::string, size_t >::iterator std_itr = std_rs.begin();
	while (ft_itr != ft_rs.end()) {
		std::cout	<< COLOR_PINK << std::setw(12) << std::right << (*ft_itr).first << COLOR_RESET  << " took: ";
	
		if ((double)my_diff((*ft_itr).second, (*std_itr).second) < (double)(*std_itr).second * (double)0.1)
			std::cout << COLOR_ORANGE;
		else if ((*ft_itr).second > (*std_itr).second)
			std::cout << COLOR_RED;
		else
			std::cout << COLOR_GREEN;
		
		std::cout << std::setw(10) << std::right << (*ft_itr).second << COLOR_BLU << "µs";
		std::cout << COLOR_LBLUE << std::setw(10) << std::right << (*std_itr).second << COLOR_BLU << "µs\n" << COLOR_RESET;

		++ft_itr;
		++std_itr;
	}
}

#endif
