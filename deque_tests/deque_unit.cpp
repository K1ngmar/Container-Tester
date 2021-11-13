/* ************************************************************************** */
/*                                                                            */
/*     ,--,  .---.  .-. .-. _______  .--.  ,-..-. .-.,---.  ,---.    .---.    */
/*   .' .') / .-. ) |  \| ||__   __|/ /\ \ |(||  \| || .-'  | .-.\  ( .-._)   */
/*   |  |(_)| | |(_)|   | |  )| |  / /__\ \(_)|   | || `-.  | `-'/ (_) \      */
/*   \  \   | | | | | |\  | (_) |  |  __  || || |\  || .-'  |   (  _  \ \     */
/*    \  `-.\ `-' / | | |)|   | |  | |  |)|| || | |)||  `--.| |\ \( `-'  )    */
/*     \____\)---'  /(  (_)   `-'  |_|  (_)`-'/(  (_)/( __.'|_| \)\`----'     */
/*          (_)    (__)                      (__)   (__)        (__)          */
/*              _______ ,---.     .---.  _______ ,---.  ,---.                 */
/*              __   __|| .-'    ( .-._)|__   __|| .-'  | .-.\                */
/*               )| |   | `-.   (_) \     )| |   | `-.  | `-'/                */
/*              (_) |   | .-'   _  \ \   (_) |   | .-'  |   (                 */
/*                | |   |  `--.( `-'  )    | |   |  `--.| |\ \                */
/*                `-'   /( __.' `----'     `-'   /( __.'|_| \)\               */
/*                     (__)                     (__)        (__)              */
/*                                                                            */
/*                   Kingmar  |  https://github.com/K1ngmar                   */
/*                                                                            */
/* ************************************************************************** */

#include <test_utility.hpp>
#include <deque.hpp>
#include <deque>

template <class ft_deq, class std_deq>
bool	compare_these_deqtors_yo(ft_deq& ft, std_deq& std)
{
	if (ft.size() != std.size()) {
		std::cout << "\nwrong size() :(" << std::endl;
		print_difference(std.size(), ft.size());
		return false;
	}
	if (ft.max_size() != std.max_size()) {
		std::cout << "\nwrong max_size() :(" << std::endl;
		print_difference(std.max_size(), ft.max_size());
		return false;
	}
	if (ft.empty() != std.empty()) {
		std::cout << "\nwrong empty() :(" << std::endl;
		print_difference(std.empty(), ft.empty());
		return false;
	}
	for(size_t i = 0; i < ft.size(); ++i) {
		if (ft[i] != std[i]) {
			std::cout << "\nindex: " << i << std::endl;
			print_difference(std[i], ft[i]);
			return false;
		}
	}
	return (true);
}

/////////////////
// CONSTRUCTOR //
/////////////////
static void constructor_test()
{

/* default constructor */

	ft::deque<int> ft_dc;
	std::deque<int> std_dc;
	compare(ft_dc, std_dc, compare_these_deqtors_yo, "Default constructor");

/* set allocator */
	ft::deque<std::string, std::allocator<std::string> > ft_sa;
	std::deque<std::string, std::allocator<std::string> > std_sa;
	compare(ft_sa, std_sa, compare_these_deqtors_yo, "Set allocator");

/* fill constructor */
	ft::deque<int> ft_fc(42, 'a');
	std::deque<int> std_fc(42, 'a');
	compare(ft_dc, std_dc, compare_these_deqtors_yo, "Fill constructor");

/* range constructor */
	// ft::deque<int> ft_rc(ft_fc.begin(), ft_fc.end() - 21);
	// std::deque<int> std_rc(std_fc.begin(), std_fc.end() - 21);
	// compare(ft_rc, std_rc, compare_these_deqtors_yo, "range constructor");

/* copy constructor */
	// ft::deque<int> ft_cc(ft_fc);
	// std::deque<int> std_cc(std_fc);
	// compare(ft_cc, std_cc, compare_these_deqtors_yo, "Copy constructor");

/* assigantion operator */
	// ft::deque<int> ft_ass = ft_cc;
	// std::deque<int> std_ass = std_cc;
	// compare(ft_ass, std_ass, compare_these_deqtors_yo, "Assignation operator");
}

///////////////////
// iterator test //
///////////////////
// static void iterator_test()
// {
// 	ft::deque<int>								ft_deq;
// 	std::deque<int>							std_deq;
// 	ft::deque<int>::iterator					ft_itr;
// 	std::deque<int>::iterator					std_itr;
// 	ft::deque<int>::const_iterator				ft_citr;
// 	std::deque<int>::const_iterator			std_citr;

// 	for (size_t i = 0; i < 21; ++i)
// 		push_back_amount(ft_deq, std_deq, rand(), 1);

// /* testing begin */

// 	ft_itr = ft_deq.begin();
// 	std_itr = std_deq.begin();
// 	compare(ft_itr, std_itr, compare_these_iterators_yo, "begin()");

// /* testing const begin */
// 	ft_citr = ft_deq.begin();
// 	std_citr = std_deq.begin();
// 	compare(ft_citr, std_citr, compare_these_iterators_yo, "const begin()");


// 	/* do some reverse iterator test you imbecile */
	

// /* testing end() */
// 	ft_itr = ft_deq.end() - 1;
// 	std_itr = std_deq.end() - 1;
// 	compare(ft_itr, std_itr, compare_these_iterators_yo, "end() - 1");

// /* testing const end() */
// 	ft_citr = ft_deq.end() - 1;
// 	std_citr = std_deq.end() - 1;
// 	compare(ft_citr, std_citr, compare_these_iterators_yo, "const end() - 1");


// 	/* do some reverse const iterator test you imbecile */
// }

//////////////
// CAPACITY //
//////////////
static void capacity_test()
{
	ft::deque<int>	ft_deq;
	std::deque<int> std_deq;

	ft_deq.resize(69, 420);
	std_deq.resize(69, 420);
	compare(ft_deq, std_deq, compare_these_deqtors_yo, "resize(69, 420)");

	ft_deq.resize(21, 69);
	std_deq.resize(21, 69);
	compare(ft_deq, std_deq, compare_these_deqtors_yo, "resize(21, 69)");

	ft_deq.resize(5000, 420);
	std_deq.resize(5000, 420);
	compare(ft_deq, std_deq, compare_these_deqtors_yo, "resize(5000, 420)");

	ft_deq.resize(21, 1337);
	std_deq.resize(21, 1337);
	compare(ft_deq, std_deq, compare_these_deqtors_yo, "resize(21, 1337)");
}

////////////////////
// ELEMENT ACCESS //
////////////////////
static void element_access_test()
{
	ft::deque<size_t> ft_deq;
	std::deque<size_t> std_deq;

	push_back_increment(ft_deq, std_deq, 1337);
	compare(ft_deq, std_deq, compare_these_deqtors_yo, "[] operator");

/* subscript operator */
	int j = ft_deq.size() - 1;
	for (int i = 0; i != j; i++) {
		ft_deq[j] = std_deq[i];
		std_deq[j] = std_deq[i];
	}
	compare(ft_deq, std_deq, compare_these_deqtors_yo, "reversed with [] operator");

/* at */
	std::string ft_msg;
	std::string std_msg;
	try {
		for (size_t i = 0; i < ft_deq.size() + 1; i++)
			if (ft_deq.at(i) != std_deq.at(i))
				break ;
	} catch (std::exception &e) {
		ft_msg = std::string(e.what());
	}

	try {
		for (size_t i = 0; i < std_deq.size() + 1; i++)
			std_deq.at(i);
	} catch (std::exception &e) {
		std_msg = std::string(e.what());
	}

	compare(ft_msg, std_msg, compare_exceptions, "at(ft_deq.size() + 1)");

	try {
		std::cout << ft_deq.at(-1) << std::endl;
	} catch (std::exception &e) {
		ft_msg = std::string(e.what());
	}

	try {
		std::cout << std_deq.at(-1) << std::endl;
	} catch (std::exception &e) {
		std_msg = std::string(e.what());
	}

	compare(ft_msg, std_msg, compare_exceptions, "at(-1");

/* front && back */
	compare(ft_deq.front(), std_deq.front(), compare_these_values_yo, "front()");
	compare(ft_deq.back(), std_deq.back(), compare_these_values_yo, "back()");
}

///////////////
// MODIFIERS //
///////////////
static void modifier_test()
{
	ft::deque<std::string>			ft_deq(2000, "MANY STRINGS YO");
	std::deque<std::string>			std_deq(2000, "MANY STRINGS YO");
	ft::deque<std::string>			ft_empty;
	std::deque<std::string>			std_empty;

/* iterator range assign */
	// ft_empty.assign(ft_deq.begin() + 42, ft_deq.begin() + 1337);
	// std_empty.assign(std_deq.begin() + 42, std_deq.begin() + 1337);
	// compare(ft_empty, std_empty, compare_these_deqtors_yo, "assign(std_deq.begin() + 42, std_deq.begin + 1337)");

/* fill assign */
	std::string assigned("we just got assigned yo");
	ft_empty.assign(420, assigned);
	std_empty.assign(420, assigned);
	compare(ft_empty, std_empty, compare_these_deqtors_yo, "assign(420, assigned)");

	ft_empty.assign(5000, std::string("wejoooowww"));
	std_empty.assign(5000, std::string("wejoooowww"));
	compare(ft_empty, std_empty, compare_these_deqtors_yo, "assign(5000, \"wejoow\")");
	
/* push back */
	for (size_t i = 0; i < 6969; ++i) {
		ft_empty.push_back(std::to_string(i));
		std_empty.push_back(std::to_string(i));
	}
	compare(ft_empty, std_empty, compare_these_deqtors_yo, "push back increment");

/* pop back */
	for (size_t i = 0; i < 6969; i++) {
		ft_empty.pop_back();
		std_empty.pop_back();
	}
	compare(ft_empty, std_empty, compare_these_deqtors_yo, "pop_back() * 6969");

/* push front */
	for (size_t i = 0; i < 6969; ++i) {
		ft_empty.push_front(std::to_string(i));
		std_empty.push_front(std::to_string(i));
	}
	compare(ft_empty, std_empty, compare_these_deqtors_yo, "push front increment");

/*
** does the big segfault
*/

/* pop front */
	for (size_t i = 0; i < 6969; i++) {
		ft_empty.pop_front();
		std_empty.pop_front();
	}
	compare(ft_empty, std_empty, compare_these_deqtors_yo, "pop_front() * 6969");


/* clear test */
	ft_empty.clear();
	std_empty.clear();
	compare(ft_empty, std_empty, compare_these_deqtors_yo, "clear()");

/* swaperoo */
	ft_empty.swap(ft_deq);
	std_empty.swap(std_deq);
	compare(ft_empty, std_empty, compare_these_deqtors_yo, "swap()");
	compare(ft_deq, std_deq, compare_these_deqtors_yo, "swap()");
}

void	deqtor_unit()
{
	print_header("deqtor member functions");

	start_test("constructor", constructor_test);
	// start_test("iterator", iterator_test);
	start_test("capacity", capacity_test); 
	start_test("element access", element_access_test); 
	start_test("modifier test", modifier_test);
}
