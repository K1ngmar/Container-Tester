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
# include <sstream>

void	print_header(std::string header)
{
	std::cout << "\n-----------------" << COLOR_ORANGE;
	std::cout << std::setw(15) << header << COLOR_RESET;
	std::cout << "-----------------\n" << std::endl;
}

void	start_test(std::string name, void(*func)())
{
	std::cout << COLOR_YELLOW << std::right << std::setw(15) << name << COLOR_RESET << ": ";
	func();
	std::cout << "\n";
}

bool compare_exceptions(std::string& ft_exc, std::string& std_exc)
{
	if (ft_exc != std_exc) {
		print_difference(std_exc, ft_exc);
		return false;
	}
	else
		return true;
}

///////////
// Timer //
///////////
Timer::Timer() : _duration(0), _total_time(0), _started_time(0) {}

void Timer::reset_timer()
{
	_duration = 0;
}

void Timer::start_timer()
{
	gettimeofday(&_time, NULL);
	_started_time = (_time.tv_sec * 1000 * 1000) + _time.tv_usec;
}

size_t Timer::end_timer()
{
	gettimeofday(&_time, NULL);
	_duration += ((_time.tv_sec * 1000 * 1000) + _time.tv_usec) - _started_time;
	_total_time += _duration;
	return (_duration);
}

size_t Timer::end_reset()
{
	size_t duration = this->end_timer();
	this->reset_timer();
	return (duration);
}

size_t	Timer::get_total_time()
{
	return (_total_time);
}

void	Timer::end_and_print(const char* msg)
{
	size_t duration = this->end_timer();
	std::cout << this->format_time(duration, msg) << std::endl;
	this->reset_timer();
}

std::string	Timer::end_and_format(const char* msg)
{
	size_t duration = this->end_timer();
	this->reset_timer();
	return (format_time(duration, msg));
}

std::string	Timer::format_time(size_t& time, const char * msg)
{
	std::stringstream ret;

	ret	<< COLOR_PINK << std::setw(12) << std::right << msg\
		<< COLOR_RESET  << " took: " \
		<< COLOR_LBLUE	<< std::setw(10) << std::right << time \
		<< COLOR_BLU	<< "µs" \
		<< COLOR_RESET;
	return (ret.str());
}

////////////////
// Test class //
////////////////

test::test(int val, std::string name) 
	: _val(val), _name(name) 
{
}

///////////////////////
// Benchmark headers //
///////////////////////

void	print_benchmark_header(std::string prefix, std::string type)
{
	std::cout << COLOR_GREEN << prefix;
	std::cout << COLOR_RESET << "::" << COLOR_ORANGE << type << COLOR_RESET << std::setw(12) << std::left << std::setfill('-') << "";
}

void	print_benchmark_result(double&	ft_dur, double& std_dur, const char* type)
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

void	format_benchmark_result(std::vector< std::pair< std::string, size_t> >& ft_rs,
								std::vector< std::pair< std::string, size_t> >& std_rs,
								std::string container)
{
	std::cout << "\n" << std::setfill('-') << std::setw(21) << std::right;
	std::cout << COLOR_BLU << "BENCHMARK ";
	print_benchmark_header("ft", container);
	std::cout << std::endl << std::setfill(' ');
	for (size_t i = 0; i < ft_rs.size(); ++i) {
		std::cout	<< COLOR_PINK << std::setw(12) << std::right << ft_rs[i].first << COLOR_RESET  << " took: ";
	
		if (my_diff(ft_rs[i].second, std_rs[i].second) <= 2 *  MILISECOND)
			std::cout << COLOR_ORANGE;
		else if (ft_rs[i].second > std_rs[i].second)
			std::cout << COLOR_RED;
		else
			std::cout << COLOR_GREEN;
		
		std::cout << std::setw(10) << std::right << ft_rs[i].second << COLOR_BLU << "µs";
		std::cout << COLOR_LBLUE << std::setw(10) << std::right << std_rs[i].second << COLOR_BLU << "µs\n" << COLOR_RESET;
	}
}
