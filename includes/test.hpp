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

# include <string>

///////////////////
// COLOR DEFINES //
///////////////////

	# define COLOR_RED 		"\033[38;5;31m"
	# define COLOR_GREEN	"\033[32m"
	# define COLOR_BLUE 	"\033[38;5;51m"
	# define COLOR_BLU		"\033[38;5;190m"
	# define COLOR_ORANGE	"\033[38;5;214m"
	# define COLOR_PURPLE	"\033[38;5;98m"
	# define COLOR_YELLOW	"\033[38;5;220m"
	# define COLOR_PINK		"\033[38;5;205m"
	# define COLOR_YOS		"\033[38;5;226"

	# define COLOR_RESET	"\033[0m"

//////////////
// Messages //
//////////////

	# define TEST_SUCCESS "[" COLOR_GREEN "OK" COLOR_RESET "] "
	# define TEST_FAILURE "[" COLOR_RED	"KO" COLOR_RESET "] "

/////////////
// Utility //
/////////////

	void		print_header(std::string header);

	template < class ft_container, class std_container, class T >
		void	insert_amount(ft_container& ft_con, std_container& std_con, T val, size_t n = 420);

	template < class ft_container, class std_container >
		void	push_back_increment(ft_container& ft_con, std_container& std_con, size_t n = 420);

	template < class ft_container, class std_container >
		void	insert_increment(ft_container& ft_con, std_container& std_con, size_t n = 420);

	template < class ft_container, class std_container, class T >
		void	push_back_amount(ft_container& ft_con, std_container& std_con, T val, size_t n = 420);

	void		start_test(std::string name, void(*func)());

/////////////////////
// Compare utility //
/////////////////////

	template < class ft_val, class std_val >
		void	compare(ft_val& ft_con, std_val& std_con, bool(*comp)(ft_val&, std_val&), const char* test);

	template <class ft_vec, class std_vec>
		bool	compare_these_iterators_yo(ft_vec& ft, std_vec& std);

	template <class ft_vec, class std_vec>
		bool	compare_these_values_yo(ft_vec& ft, std_vec& std);

	template < class T1, class T2 >
		void	print_difference(T1 expected, T2 received);

	bool		compare_exceptions(std::string& ft_exc, std::string& std_exc);

///////////////////
// Class utility //
///////////////////

	class Timer
	{
		private:
			struct timeval	_time;
			size_t			_duration;
			size_t			_total_time;
			size_t			_started_time;

		public:
			Timer();
			~Timer(){}
			
			void	reset_timer();
			void	start_timer();
			size_t	end_timer();
			size_t	get_total_time();
			void	end_and_print(const char* msg);
			void	print_time(size_t& time, const char * msg);

	}; /* end of timer class */
	
	struct test
	{
		private: 
			int			_val;
			std::string	_name;

		public:
			test(int val = 0, std::string name = "unknown");
			~test() {}

			bool	operator == (const test&x) {return (this->_val == x._val && this->_name == x._name);}

	}; /* end of test class */

/////////////////////
// Test Prototypes //
/////////////////////

	void	vector_unit();

#endif
