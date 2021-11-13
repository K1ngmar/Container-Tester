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

# include <test_utility.hpp>
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

void	print_benchmark_container(std::string prefix, std::string type)
{
	std::cout << COLOR_GREEN << prefix;
	std::cout << COLOR_RESET << "::" << COLOR_ORANGE << type << COLOR_RESET << std::setw(12) << std::left << std::setfill('-') << "";
}

void	print_benchmark_header(std::string& container)
{
	std::cout << "\n" << std::setfill('-') << std::setw(21) << std::right;
	std::cout << COLOR_BLU << "BENCHMARK ";

	print_benchmark_container("ft", container);
	std::cout << std::endl << std::setfill(' ');
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
		std::cout << "faster " << COLOR_YELLOW << ":D\n";
	}
	else {
		std::cout << COLOR_RED << (float)100 - result << COLOR_RESET << "% ";
		std::cout << "slower " << COLOR_OYELLOW << ":(\n";
	}
}

static size_t my_diff(size_t& first, size_t& second)
{
	if (first > second)
		return (first - second);
	return (second - first);
}

static void		set_performance_color(size_t ft_t, size_t std_t)
{
	/* if the diffrence is less than 10% */
	if ((double)my_diff(ft_t, std_t) < (double)std_t * (double)0.1)
		std::cout << COLOR_ORANGE;
	else if (ft_t > std_t)
		std::cout << COLOR_RED;
	else
		std::cout << COLOR_GREEN;
}

void	format_benchmark_result(std::map< std::string, size_t >	& ft_rs,
								std::map< std::string, size_t >	& std_rs,
								std::string container)
{
	print_benchmark_header(container);

	std::map< std::string, size_t >::iterator ft_itr = ft_rs.begin();
	std::map< std::string, size_t >::iterator std_itr = std_rs.begin();

	size_t ft_time, std_time;
	while (ft_itr != ft_rs.end())
	{
		ft_time = (*ft_itr).second;
		std_time = (*std_itr).second;

		/* test name */
		std::cout	<< COLOR_PINK << std::setw(12) << std::right << (*ft_itr).first << COLOR_RESET  << " took: ";
	
		/* ft result */
		set_performance_color(ft_time, std_time);
		std::cout << std::setw(10) << std::right << ft_time << COLOR_BLU << "µs";

		/* std result */
		std::cout << COLOR_LBLUE << std::setw(10) << std::right << std_time << COLOR_BLU << "µs\n" << COLOR_RESET;

		++ft_itr;
		++std_itr;
	}
}

#endif
