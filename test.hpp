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

///////////////////
// COLOR DEFINES //
///////////////////

# define COLOR_RED		"\033[31m"
# define COLOR_GREEN	"\033[32m"
# define COLOR_RESET	"\033[0m"
# define COLOR_YELLOW	"\033[33m"
# define COLOR_BLUE		"\033[27m"

void	print_header(std::string header)
{
	std::cout << "-----------------";
	std::cout << std::setw(15) << header;
	std::cout << "-----------------" << std::endl;
};

template< class Container >
size_t	time_function(void(*func)(Container), Container& con, std::string container)
{
	struct timeval	time;
	size_t			duration;

	gettimeofday(&time, NULL);
	duration = (time.tv_sec * 1000 * 1000) + time.tv_usec;
	func(con);
	gettimeofday(&time, NULL);
	duration = ((time.tv_sec * 1000 * 1000) + time.tv_usec) - duration;
	return (duration);
}

template< class ft_container, class std_container, class T >
void	insert_amount(ft_container& ft_con, std_container& std_con, T& val, size_t n = 420)
{
	for (size_t i = 0; i < n; ++i) {
		ft_con.insert(val);
		std_con.insert(val);
	}
}

#endif
