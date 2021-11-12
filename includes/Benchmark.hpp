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
		results[test_name] = time.end_reset();
	}

	void	run_test(void(*func)(Container&, Container&), std::string test_name)
	{
		Container empty;
		time.start_timer();
		func(con, empty);
		results[test_name] = time.end_reset();
	}

	void	get_total_time()
	{
		return (time.get_total_time());
	}

}; /* end of benchmark class */

#endif
