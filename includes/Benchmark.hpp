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

void	print_benchmark_container(std::string prefix, std::string type);

void	print_benchmark_header(std::string& container);

void	format_benchmark_result(std::map< std::string, size_t >	& ft_rs,
								std::map< std::string, size_t >	& std_rs,
								std::string container);

void	print_benchmark_result(double ft_dur, double std_dur, const char* type);

#endif
