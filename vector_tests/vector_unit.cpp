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
#include <vector.hpp>
#include <vector>

template <class ft_vec, class std_vec>
bool	compare_these_vectors_yo(ft_vec& ft, std_vec& std)
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

	ft::vector<int> ft_dc;
	std::vector<int> std_dc;
	compare(ft_dc, std_dc, compare_these_vectors_yo, "Default constructor");

// /* set allocator */
	ft::vector<std::string, std::allocator<std::string> > ft_sa;
	std::vector<std::string, std::allocator<std::string> > std_sa;
	compare(ft_sa, std_sa, compare_these_vectors_yo, "Set allocator");

// /* fill constructor */
	ft::vector<int> ft_fc(42, 'a');
	std::vector<int> std_fc(42, 'a');
	compare(ft_dc, std_dc, compare_these_vectors_yo, "Fill constructor");

// /* range constructor */
	ft::vector<int> ft_rc(ft_fc.begin(), ft_fc.end() - 21);
	std::vector<int> std_rc(std_fc.begin(), std_fc.end() - 21);
	compare(ft_rc, std_rc, compare_these_vectors_yo, "range constructor");

// /* copy constructor */
	ft::vector<int> ft_cc(ft_rc);
	std::vector<int> std_cc(std_rc);
	compare(ft_cc, std_cc, compare_these_vectors_yo, "Copy constructor");

// /* assigantion operator */
	ft::vector<int> ft_ass = ft_cc;
	std::vector<int> std_ass = std_cc;
	compare(ft_ass, std_ass, compare_these_vectors_yo, "Assignation operator");
}

///////////////////
// iterator test //
///////////////////
static void iterator_test()
{
	ft::vector<int>								ft_vec;
	std::vector<int>							std_vec;
	ft::vector<int>::iterator					ft_itr;
	std::vector<int>::iterator					std_itr;
	ft::vector<int>::const_iterator				ft_citr;
	std::vector<int>::const_iterator			std_citr;

	for (size_t i = 0; i < 21; ++i)
		push_back_amount(ft_vec, std_vec, rand(), 1);

/* testing begin */

	ft_itr = ft_vec.begin();
	std_itr = std_vec.begin();
	compare(ft_itr, std_itr, compare_these_iterators_yo, "begin()");

/* testing const begin */
	ft_citr = ft_vec.begin();
	std_citr = std_vec.begin();
	compare(ft_citr, std_citr, compare_these_iterators_yo, "const begin()");


	/* do some reverse iterator test you imbecile */
	

/* testing end() */
	ft_itr = ft_vec.end() - 1;
	std_itr = std_vec.end() - 1;
	compare(ft_itr, std_itr, compare_these_iterators_yo, "end() - 1");

/* testing const end() */
	ft_citr = ft_vec.end() - 1;
	std_citr = std_vec.end() - 1;
	compare(ft_citr, std_citr, compare_these_iterators_yo, "const end() - 1");


	/* do some reverse const iterator test you imbecile */
}

//////////////
// CAPACITY //
//////////////
static void capacity_test()
{
	ft::vector<int>	ft_vec;
	std::vector<int> std_vec;

	ft_vec.reserve(42);
	std_vec.reserve(42);
	compare(ft_vec, std_vec, compare_these_vectors_yo, "reserve(42)");

	ft_vec.resize(69, 420);
	std_vec.resize(69, 420);
	compare(ft_vec, std_vec, compare_these_vectors_yo, "resize(69, 420)");

	ft_vec.resize(21, 69);
	std_vec.resize(21, 69);
	compare(ft_vec, std_vec, compare_these_vectors_yo, "rezize(21, 69)");

	ft_vec.resize(5000, 420);
	std_vec.resize(5000, 420);
	compare(ft_vec, std_vec, compare_these_vectors_yo, "rezize(5000, 420)");

	ft_vec.resize(21, 1337);
	std_vec.resize(21, 1337);
	compare(ft_vec, std_vec, compare_these_vectors_yo, "rezize(5000, 420)");

	std::string ft_msg;
	std::string std_msg;
	try {
		ft_vec.reserve(-1);
	} catch (std::exception &e) {
		ft_msg = std::string(e.what());
	}
	try {
		std_vec.reserve(-1);
	} catch (std::exception &e) {
		std_msg = std::string(e.what());
	}
	compare(ft_msg, std_msg, compare_exceptions, "reserve(-1)");
}

////////////////////
// ELEMENT ACCESS //
////////////////////
static void element_access_test()
{
	ft::vector<size_t> ft_vec;
	std::vector<size_t> std_vec;

	push_back_increment(ft_vec, std_vec, 1337);
	compare(ft_vec, std_vec, compare_these_vectors_yo, "[] operator");

/* subscript operator */
	int j = ft_vec.size() - 1;
	for (int i = 0; i != j; i++) {
		ft_vec[j] = std_vec[i];
		std_vec[j] = std_vec[i];
	}
	compare(ft_vec, std_vec, compare_these_vectors_yo, "reversed with [] operator");

/* at */
	std::string ft_msg;
	std::string std_msg;
	try {
		for (size_t i = 0; i < ft_vec.size() + 1; i++)
			if (ft_vec.at(i) != std_vec.at(i))
				break ;
	} catch (std::exception &e) {
		ft_msg = std::string(e.what());
	}

	try {
		for (size_t i = 0; i < std_vec.size() + 1; i++)
			std_vec.at(i);
	} catch (std::exception &e) {
		std_msg = std::string(e.what());
	}

	compare(ft_msg, std_msg, compare_exceptions, "at(ft_vec.size() + 1)");

	try {
		std::cout << ft_vec.at(-1) << std::endl;
	} catch (std::exception &e) {
		ft_msg = std::string(e.what());
	}

	try {
		std::cout << std_vec.at(-1) << std::endl;
	} catch (std::exception &e) {
		std_msg = std::string(e.what());
	}

	compare(ft_msg, std_msg, compare_exceptions, "at(-1");

/* front && back */
	compare(ft_vec.front(), std_vec.front(), compare_these_values_yo, "front()");
	compare(ft_vec.back(), std_vec.back(), compare_these_values_yo, "back()");
}

///////////////
// MODIFIERS //
///////////////
static void modifier_test()
{
	ft::vector<std::string>				ft_vec(2000, "MANY STRINGS YO");
	std::vector<std::string>			std_vec(2000, "MANY STRINGS YO");
	ft::vector<std::string>				ft_empty;
	std::vector<std::string>			std_empty;

/* iterator range assign */
	ft_empty.assign(ft_vec.begin() + 42, ft_vec.begin() + 1337);
	std_empty.assign(std_vec.begin() + 42, std_vec.begin() + 1337);
	compare(ft_empty, std_empty, compare_these_vectors_yo, "assign(std_vec.begin() + 42, std_vec.begin + 1337)");

/* fill assign */
	std::string assigned("we just got assigned yo");
	ft_empty.assign(420, assigned);
	std_empty.assign(420, assigned);
	compare(ft_empty, std_empty, compare_these_vectors_yo, "assign(420, assigned)");

	ft_empty.assign(5000, std::string("wejoooowww"));
	std_empty.assign(5000, std::string("wejoooowww"));
	compare(ft_empty, std_empty, compare_these_vectors_yo, "assign(5000, \"wejoow\")");
	
/* push back */
	for (size_t i = 0; i < 6969; ++i) {
		ft_empty.push_back(std::to_string(i));
		std_empty.push_back(std::to_string(i));
	}
	compare(ft_empty, std_empty, compare_these_vectors_yo, "push back increment");

/* pop back */
	for (size_t i = 0; i < 6969; i++) {
		ft_empty.pop_back();
		std_empty.pop_back();
	}
	compare(ft_empty, std_empty, compare_these_vectors_yo, "pop_back() * 6969");

/* insert */
	ft_empty.insert(ft_empty.begin() + 42, "LEGENDARY");
	std_empty.insert(std_empty.begin() + 42, "LEGENDARY");
	compare(ft_empty, std_empty, compare_these_vectors_yo, "insert(begin() + 42, \"LEGENDARY\")");

/* range erase */
	ft_empty.erase(ft_empty.begin(), ft_empty.end() - 1);
	std_empty.erase(std_empty.begin(), std_empty.end() - 1);
	compare(ft_empty, std_empty, compare_these_vectors_yo, "begin(), end() - 1");

/* fill insert */
	ft_empty.insert(ft_empty.end() - 1, 1337, "living on the edge");
	std_empty.insert(std_empty.end() - 1, 1337, "living on the edge");
	compare(ft_empty, std_empty, compare_these_vectors_yo, "end() - 1, 1337, \"living on the edge");

/* element erase */
	for (size_t i = 0; i < ft_empty.size(); i++) {
		ft_empty.erase(ft_empty.begin() + i);
		std_empty.erase(std_empty.begin() + i);

	}
	compare(ft_empty, std_empty, compare_these_vectors_yo, "erase(begin() + i)");

/* Range insert */
	ft_empty.insert(ft_empty.begin(), ft_vec.begin(), ft_vec.end());
	std_empty.insert(std_empty.begin(), std_vec.begin(), std_vec.end());
	compare(ft_empty, std_empty, compare_these_vectors_yo, "empty.begin(), vec.begin(), vec.end()");

/* clear test */
	ft_empty.clear();
	std_empty.clear();
	compare(ft_empty, std_empty, compare_these_vectors_yo, "clear()");

/* swaperoo */
	ft_empty.insert(ft_empty.begin(), 42, "About to get swapped");
	std_empty.insert(std_empty.begin(), 42, "About to get swapped");
	ft_empty.swap(ft_vec);
	std_empty.swap(std_vec);
	compare(ft_empty, std_empty, compare_these_vectors_yo, "swap()");
	compare(ft_vec, std_vec, compare_these_vectors_yo, "swap()");
}

void	vector_unit()
{
	print_header("Vector member functions");

	start_test("constructor", constructor_test);
	start_test("iterator", iterator_test);
	start_test("capacity", capacity_test); 
	start_test("element access", element_access_test); 
	start_test("modifier test", modifier_test);
}
