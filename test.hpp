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

# define COLOR_RED		"\033[31m"
# define COLOR_GREEN	"\033[32m"
# define COLOR_RESET	"\033[0m"
# define COLOR_YELLOW	"\033[33m"
# define COLOR_BLUE		"\033[27m"

//////////////
// Messages //
//////////////

# define TEST_SUCCESS "[" COLOR_GREEN "OK" COLOR_RESET "] "
# define TEST_FAILURE "[" COLOR_RED	"KO" COLOR_RESET "] "


////////////
// MACROS //
////////////

# define STRESS_TEST()\
	for (size_t i = 0; i < 50000; ++i)

void	print_header(std::string header)
{
	std::cout << "-----------------";
	std::cout << std::setw(15) << header;
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
		size_t			_started_time;

	public:
		Timer() : _duration(0), _started_time(0) {}
		
		void reset_timer()
		{
			_duration = 0;
		}

		void start_timer()
		{
			gettimeofday(&_time, NULL);
			_started_time = (_time.tv_sec * 1000 * 1000) + _time.tv_usec;
		}

		void end_timer()
		{
			gettimeofday(&_time, NULL);
			_duration += ((_time.tv_sec * 1000 * 1000) + _time.tv_usec) - _started_time;
		}

}; /* end of timer class */

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

#endif
