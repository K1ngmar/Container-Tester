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

# include <iostream>
# include <iomanip>
# include <string>
# include <sys/time.h>
# include <stdlib.h>
# include <test.hpp>

void	print_header(std::string header)
{
	std::cout << "-----------------" << COLOR_ORANGE;
	std::cout << std::setw(15) << header << COLOR_RESET;
	std::cout << "-----------------\n" << std::endl;
}

template< class ft_container, class std_container, class T >
void	insert_amount(ft_container& ft_con, std_container& std_con, T val, size_t n)
{
	for (size_t i = 0; i < n; ++i) {
		ft_con.insert(val);
		std_con.insert(val);
	}
}

template< class ft_container, class std_container >
void	push_back_increment(ft_container& ft_con, std_container& std_con, size_t n)
{
	for (size_t i = 0; i < n; ++i) {
		ft_con.push_back(i);
		std_con.push_back(i);
	}
}

template< class ft_container, class std_container >
void	insert_increment(ft_container& ft_con, std_container& std_con, size_t n)
{
	for (size_t i = 0; i < n; ++i) {
		ft_con.insert(i);
		std_con.insert(i);
	}
}

template< class ft_container, class std_container, class T >
void	push_back_amount(ft_container& ft_con, std_container& std_con, T val, size_t n)
{
	for (size_t i = 0; i < n; ++i) {
		ft_con.push_back(val);
		std_con.push_back(val);
	}
}

void	start_test(std::string name, void(*func)())
{
	std::cout << COLOR_YELLOW << std::right << std::setw(15) << name << COLOR_RESET << ": ";
	func();
	std::cout << "\n";
}

template < class ft_val, class std_val >
void	compare(ft_val& ft_con, std_val& std_con, bool(*comp)(ft_val&, std_val&), const char* test)
{
	if (comp(ft_con, std_con) == true)
		std::cout << TEST_SUCCESS;
	else {
		std::cout << TEST_FAILURE;
		std::cout << "test: " << test << std::endl;
	}
}

template < class T1, class T2 >
void	print_difference(T1 expected, T2 received)
{
	std::cout	<< "expected value: " << expected << std::endl\
				<< "received value: " << received << std::endl;
}

template <class ft_vec, class std_vec>
bool	compare_these_iterators_yo(ft_vec& ft, std_vec& std)
{
	if (*ft != *std) {
		print_difference(*std, *ft);
		return false;
	}
	return (true);
}

template <class ft_vec, class std_vec>
bool	compare_these_values_yo(ft_vec& ft, std_vec& std)
{
	if (ft != std) {
		print_difference(std, ft);
		return false;
	}
	return (true);
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

size_t	Timer::get_total_time()
{
	return (_total_time);
}

void	Timer::end_and_print(const char* msg)
{
	size_t duration = this->end_timer();
	this->print_time(duration, msg);
	this->reset_timer();
}

void	Timer::print_time(size_t& time, const char * msg)
{
	std::cout	<< COLOR_PINK	<< std::setw(12) << std::right << msg\
				<< COLOR_RESET  << " took: " \
				<< COLOR_BLUE	<< std::setw(10) << std::right << time \
				<< COLOR_RED	<< "µs" \
				<< COLOR_RESET	<< std::endl;
}

////////////////
// Test class //
////////////////

test::test(int val, std::string name) 
	: _val(val), _name(name) 
{
}
