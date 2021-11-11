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

#ifndef THIS_IS_A_REALLY_COOL_TESTER_HPP
# define THIS_IS_A_REALLY_COOL_TESTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sys/time.h>
# include <stdlib.h>

///////////////////
// COLOR DEFINES //
///////////////////

# define COLOR_RED 		"\e[38;5;31m"
# define COLOR_GREEN	"\e[32m"
# define COLOR_BLUE 	"\e[38;5;51m"
# define COLOR_BLU		"\e[38;5;190m"
# define COLOR_ORANGE	"\e[38;5;214m"
# define COLOR_PURPLE	"\e[38;5;98m"
# define COLOR_YELLOW	"\e[38;5;220m"
# define COLOR_PINK		"\e[38;5;205m"
# define COLOR_YOS		"\e[38;5;226"

# define COLOR_RESET	"\e[0m"

//////////////
// Messages //
//////////////

# define TEST_SUCCESS "[" COLOR_GREEN "OK" COLOR_RESET "] "
# define TEST_FAILURE "[" COLOR_RED	"KO" COLOR_RESET "] "



void	print_header(std::string header)
{
	std::cout << "-----------------" << COLOR_ORANGE;
	std::cout << std::setw(15) << header << COLOR_RESET;
	std::cout << "-----------------\n" << std::endl;
};

template< class ft_container, class std_container, class T >
void	insert_amount(ft_container& ft_con, std_container& std_con, T val, size_t n = 420)
{
	for (size_t i = 0; i < n; ++i) {
		ft_con.insert(val);
		std_con.insert(val);
	}
}

template< class ft_container, class std_container >
void	push_back_increment(ft_container& ft_con, std_container& std_con, size_t n = 420)
{
	for (size_t i = 0; i < n; ++i) {
		ft_con.push_back(i);
		std_con.push_back(i);
	}
}

template< class ft_container, class std_container >
void	insert_increment(ft_container& ft_con, std_container& std_con, size_t n = 420)
{
	for (size_t i = 0; i < n; ++i) {
		ft_con.insert(i);
		std_con.insert(i);
	}
}

template< class ft_container, class std_container, class T >
void	push_back_amount(ft_container& ft_con, std_container& std_con, T val, size_t n = 420)
{
	for (size_t i = 0; i < n; ++i) {
		ft_con.push_back(val);
		std_con.push_back(val);
	}
}

class Timer
{
	private:
		struct timeval	_time;
		size_t			_duration;
		size_t			_total_time;
		size_t			_started_time;

	public:
		Timer() : _duration(0), _total_time(0), _started_time(0) {}
		
		void reset_timer()
		{
			_duration = 0;
		}

		void start_timer()
		{
			gettimeofday(&_time, NULL);
			_started_time = (_time.tv_sec * 1000 * 1000) + _time.tv_usec;
		}

		size_t end_timer()
		{
			gettimeofday(&_time, NULL);
			_duration += ((_time.tv_sec * 1000 * 1000) + _time.tv_usec) - _started_time;
			_total_time += _duration;
			return (_duration);
		}

		size_t	get_total_time()
		{
			return (_total_time);
		}

		void	end_and_print(const char* msg)
		{
			size_t duration = this->end_timer();
			this->print_time(duration, msg);
			this->reset_timer();
		}

		void	print_time(size_t& time, const char * msg)
		{
			std::cout	<< COLOR_PINK	<< std::setw(12) << std::right << msg\
						<< COLOR_RESET  << " took: " \
						<< COLOR_BLUE	<< std::setw(10) << std::right << time \
						<< COLOR_RED	<< "µs" \
						<< COLOR_RESET	<< std::endl;
		}

}; /* end of timer class */

struct test
{
	private: 
		int			_val;
		std::string	_name;
	public:
		test(int val = 0, std::string name = "unknown") : _val(val), _name(name) {}
		~test() {}

	void	print_test() const {
		std::cout << "val = " << _val << " name = " << _name << std::endl;
	}
}; /* end of test class */

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

#endif
