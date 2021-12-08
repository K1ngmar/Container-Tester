/* ************************************************************************** */
/*                                                                            */
/*        ,--,  .---.  .-. .-. _______  .--.  ,-..-. .-.,---.  ,---.          */
/*      .' .') / .-. ) |  \| ||__   __|/ /\ \ |(||  \| || .-'  | .-.\         */
/*      |  |(_)| | |(_)|   | |  )| |  / /__\ \(_)|   | || `-.  | `-'/         */
/*      \  \   | | | | | |\  | (_) |  |  __  || || |\  || .-'  |   (          */
/*       \  `-.\ `-' / | | |)|   | |  | |  |)|| || | |)||  `--.| |\ \         */
/*        \____\)---'  /(  (_)   `-'  |_|  (_)`-'/(  (_)/( __.'|_| \)\        */
/*             (_)    (__)                      (__)   (__)        (__)       */
/*              _______ ,---.     .---.  _______ ,---.  ,---.                 */
/*             |__   __|| .-'    ( .-._)|__   __|| .-'  | .-.\                */
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
#include <set.hpp>
#include <set>


template <class ft_set, class ft_itr, class std_set, class std_itr>
bool	compare_these_sets_yo(ft_set& ft, ft_itr fitr, std_set& std, std_itr sitr)
{
	if (ft.size() != std.size()) {
		std::cout << "\nwrong size() :(" << std::endl;
		print_difference(std.size(), ft.size());
		return false;
	}
	if (ft.empty() != std.empty()) {
		std::cout << "\nwrong empty() :(" << std::endl;
		print_difference(std.empty(), ft.empty());
		return false;
	}
	while(fitr != ft.end()) {
		if (compare_these_iterators_yo(fitr, sitr) == false)
			return false;
		fitr++;
		sitr++;
	}
	return (true);
}

/////////////////
// CONSTRUCTOR //
/////////////////
static void constructor_test()
{

/* default constructor */

	ft::set<int>	ft_dc;
	std::set<int>	std_dc;
	compare(ft_dc, ft_dc.begin(), std_dc, std_dc.begin(), compare_these_sets_yo, "default constructor");


// // /* range constructor */
// 	ft::set<int, std::string> ft_rc(ft_fc.begin(), ft_fc.end() - 21);
// 	std::set<int, std::string> std_rc(std_fc.begin(), std_fc.end() - 21);
// 	compare(ft_rc, std_rc, compare_these_sets_yo, "range constructor");

	for (int i = 0; i < 15; i++) {
		ft_dc.insert(i);
		std_dc.insert(i);
	}

/* copy constructor */
	ft::set<int>	ft_cc(ft_dc);
	std::set<int>	std_cc(std_dc);
	compare(ft_cc, ft_cc.begin(), std_cc, std_cc.begin(), compare_these_sets_yo, "copy constructor");

/* test for deep copy */
	ft_dc.erase(ft_dc.begin());
	std_dc.erase(std_dc.begin());
	compare(ft_dc, ft_dc.begin(), std_dc, std_dc.begin(), compare_these_sets_yo, "deep copy (copy construcor)");
	compare(ft_cc, ft_cc.begin(), std_cc, std_cc.begin(), compare_these_sets_yo, "deep copy (copy construcor)");


/* assigantion operator */
	ft::set<int>	ft_ass = ft_cc;
	std::set<int>	std_ass = std_cc;
	compare(ft_ass, ft_ass.begin(), std_ass, std_ass.begin(), compare_these_sets_yo, "assignation operator");

/* test for deep copy */
	ft_cc.erase(++(ft_dc.begin()));
	std_cc.erase(++(std_dc.begin()));
	compare(ft_cc, ft_cc.begin(), std_cc, std_cc.begin(), compare_these_sets_yo, "deep copy (copy construcor)");
	compare(ft_dc, ft_dc.begin(), std_dc, std_dc.begin(), compare_these_sets_yo, "deep copy (copy construcor)");
}

///////////////////
// iterator test //
///////////////////
static void iterator_test()
{
	ft::set<int>					ft_set;
	std::set<int>					std_set;
	ft::set<int>::iterator			ft_itr;
	std::set<int>::iterator			std_itr;
	ft::set<int>::const_iterator	ft_citr;
	std::set<int>::const_iterator	std_citr;

	for (size_t i = 0; i < 15; i++) {
		ft_set.insert(i);
		std_set.insert(i);
	}

/* testing begin */

	ft_itr = ft_set.begin();
	std_itr = std_set.begin();
	compare(ft_itr, std_itr, compare_these_iterators_yo, "begin()");

/* testing const begin */
	ft_citr = ft_set.begin();
	std_citr = std_set.begin();
	compare(ft_citr, std_citr, compare_these_iterators_yo, "const begin()");


	ft::set<int, int>	ft_empty;
	std::set<int, int>	std_empty;
	bool ft_cmp = ft_empty.begin() == ft_empty.end();
	bool std_cmp = std_empty.begin() == std_empty.end();
	compare(ft_cmp, std_cmp, compare_these_values_yo, "begin() == end()");


	/* do some reverse iterator test you imbecile */
	

/* testing end() */
	ft_itr = --(ft_set.end());
	std_itr = --(std_set.end());
	compare(ft_itr, std_itr, compare_these_iterators_yo, "end() - 1");

/* testing const end() */
	ft_citr = --ft_set.end();
	std_citr = --std_set.end();
	compare(ft_citr, std_citr, compare_these_iterators_yo, "const end() - 1");


	/* do some reverse const iterator test you imbecile */
}

///////////////
// Observers //
///////////////
static void observer_test()
{
	ft::set<size_t>						ft_set;
	std::set<size_t>					std_set;
	ft::set<size_t>::iterator			ft_itr;
	std::set<size_t>::iterator			std_itr;
	ft::set<size_t>::const_iterator		ft_citr;
	std::set<size_t>::const_iterator	std_citr;

	for (size_t i = 0; i < 15; i++) {
		ft_set.insert(i);
		std_set.insert(i);
	}

/* testing value compare second argument is bigger */
	ft_itr = ft_set.begin();
	std_itr = std_set.begin();
	bool ft_res = ft_set.value_comp()(*ft_itr, *(++ft_itr));
	bool std_res = std_set.value_comp()(*std_itr, *(++std_itr));
	compare(ft_res, std_res, compare_these_values_yo, "value_compare arg1 < arg2");

/* testing value compare first arguement is bigger */
	ft_res = ft_set.value_comp()(*(++ft_itr), *ft_itr);
	std_res = std_set.value_comp()(*(++std_itr), *std_itr);
	compare(ft_res, std_res, compare_these_values_yo, "value_comparea arg1 > arg2");


/* testing key compare second argument is bigger */
	ft_res = ft_set.key_comp()((*ft_itr), (*(++ft_itr)));
	std_res = std_set.key_comp()((*std_itr), (*(++std_itr)));
	compare(ft_res, std_res, compare_these_values_yo, "key_compare arg1 < arg2");

/* testing key compare first arguement is bigger */
	ft_res = ft_set.key_comp()((*(++ft_itr)), (*ft_itr));
	std_res = std_set.key_comp()((*(++std_itr)), (*std_itr));
	compare(ft_res, std_res, compare_these_values_yo, "value_compare arg1 > arg2");


}

////////////////////
// ELEMENT ACCESS //
////////////////////
static void element_access_test()
{
	ft::set<std::string>	ft_set;
	std::set<std::string>	std_set;

/* opeartor [] */
	for (size_t i = 0; i < 1337; i++) {
		ft_set.insert(std::to_string(i));
		std_set.insert(std::to_string(i));
	}
	compare(ft_set, ft_set.begin(), std_set, std_set.begin(), compare_these_sets_yo, "operator []");

	for (size_t i = 0; i < 1337; i++) {
		ft_set.insert(std::to_string(i));
		std_set.insert(std::to_string(i));
	}
	compare(ft_set, ft_set.begin(), std_set, std_set.begin(), compare_these_sets_yo, "operator []");

	size_t rando;
	for (size_t i = 0; i < 1337; i++) {
		rando = rand();
		ft_set.insert(std::to_string(i));
		std_set.insert(std::to_string(i));
	}
	compare(ft_set, ft_set.begin(), std_set, std_set.begin(), compare_these_sets_yo, "operator []");

/* swap */
	ft::set<std::string>				ft_tbs;
	std::set<std::string>			std_tbs;
	ft_tbs.insert("I am going to be swapped");
	std_tbs.insert("I am going to be swapped");
	ft::set<std::string, unsigned char>::iterator	ft_itr = ft_set.begin();
	std::set<std::string, unsigned char>::iterator	std_itr = std_set.begin();

	ft_set.swap(ft_tbs);
	std_set.swap(std_tbs);
	compare(ft_set, ft_set.begin(), std_set, std_set.begin(), compare_these_sets_yo, "swap");
	compare(ft_tbs, ft_itr, std_tbs, std_itr, compare_these_sets_yo, "swap");
}

///////////////
// MODIFIERS //
///////////////
static void modifier_test()
{
	ft::set<size_t>		ft_set;
	std::set<size_t>	std_set;
	ft::set<size_t>		ft_empty;
	std::set<size_t>	std_empty;

/* insert */
	for (size_t i = 0; i < 5000; i++) {
		ft_set.insert(i);
		std_set.insert(i);
	}
	compare(ft_set, ft_set.begin(), std_set, std_set.begin(), compare_these_sets_yo, "insert");

/* return value key doesnt exist */
	bool ft_res = ft_set.insert(42069).second;
	bool std_res = std_set.insert(42069).second;
	compare(ft_res, std_res, compare_these_values_yo, "return value new key");

/* return value key exists */
	ft_res = ft_set.insert(420).second;
	std_res = std_set.insert(420).second;
	compare(ft_res, std_res, compare_these_values_yo, "return value existing key");

/* insert */
	for (size_t i = 0; i < 5000; i++) {
		ft_set.insert(i);
		std_set.insert(i);
	}
	compare(ft_set, ft_set.begin(), std_set, std_set.begin(), compare_these_sets_yo, "insert existing key");

/* erase */
	while (ft_set.size() > 1337) {
		ft_set.erase(ft_set.begin());
		std_set.erase(std_set.begin());
	}
	compare(ft_set, ft_set.begin(), std_set, std_set.begin(), compare_these_sets_yo, "erase");

/* hint insert */
	for (size_t i = 0; i < 5000; i++) {
		ft_set.insert(--ft_set.end(), i);
		std_set.insert(--std_set.end(), i);
	}
	compare(ft_set, ft_set.begin(), std_set, std_set.begin(), compare_these_sets_yo, "hint insert");

/* erase value */
	for (size_t i = ft_set.size(); i > 1337; i--) {
		ft_set.erase(i);
		std_set.erase(i);
	}
	compare(ft_set, ft_set.begin(), std_set, std_set.begin(), compare_these_sets_yo, "value erase");

/* clear */
	ft_set.clear();
	std_set.clear();
	compare(ft_set, ft_set.begin(), std_set, std_set.begin(), compare_these_sets_yo, "clear");

/* clear */
	ft_set.clear();
	std_set.clear();
	compare(ft_set, ft_set.begin(), std_set, std_set.begin(), compare_these_sets_yo, "clear on empty erase");
}

static void operations_test()
{
	typedef ft::set<size_t>::iterator			ft_iterator;
	typedef ft::set<size_t>::const_iterator		ft_citerator;
	typedef std::set<size_t>::iterator			std_iterator;
	typedef std::set<size_t>::const_iterator	std_citerator;

	ft::set<size_t>		ft_set;
	std::set<size_t>	std_set;
	ft_iterator			ft_itr;
	ft_citerator		ft_citr;
	std_iterator		std_itr;
	std_citerator		std_citr;

	for (size_t i = 0; i < 420; i++) {
		ft_set.insert(i);
		std_set.insert(i);
	}

	/* find */
	ft_itr = ft_set.find((size_t)69);
	std_itr = std_set.find((size_t)69);
	compare(ft_itr, std_itr, compare_these_iterators_yo, "find existing element");
	
	/* const find */
	ft_citr = ft_set.find((size_t)42);
	std_citr = std_set.find((size_t)42);
	compare(ft_citr, std_citr, compare_these_iterators_yo, "const find existing element");

	/* find non existing */
	ft_itr = --ft_set.find((size_t)1337);
	std_itr = --std_set.find((size_t)1337);
	compare(ft_itr, std_itr, compare_these_iterators_yo, "find non existing element");
	
	/* const find non existing */
	ft_citr = --ft_set.find((size_t)1337);
	std_citr = --std_set.find((size_t)1337);
	compare(ft_citr, std_citr, compare_these_iterators_yo, "const find non existing element");

	/* count */
	bool ft_res = ft_set.count(21);
	bool std_res = std_set.count(21);
	compare(ft_res, std_res, compare_these_values_yo, "count exists");

	/* count non existante */
	ft_res = ft_set.count(42069);
	std_res = std_set.count(42069);
	compare(ft_res, std_res, compare_these_values_yo, "count doesn't exists");

	/* lower bound */
	ft_itr = ft_set.lower_bound((size_t)200);
	std_itr = std_set.lower_bound((size_t)200);
	compare(ft_itr, std_itr, compare_these_iterators_yo, "lower bound");
	
	/* lower bound  const */
	ft_citr = ft_set.lower_bound((size_t)69);
	std_citr = std_set.lower_bound((size_t)69);
	compare(ft_citr, std_citr, compare_these_iterators_yo, "const lower bound");

	/* lower bound existing */
	ft_itr = --ft_set.lower_bound((size_t)-1);
	std_itr = --std_set.lower_bound((size_t)-1);
	compare(ft_itr, std_itr, compare_these_iterators_yo, "lower bound non existent");
	
	/* lower bound non existing */
	ft_citr = --ft_set.lower_bound((size_t)-42);
	std_citr = --std_set.lower_bound((size_t)-42);
	compare(ft_citr, std_citr, compare_these_iterators_yo, "const lower bound non existent");

	/* lower bound */
	ft_set.insert(-420);
	std_set.insert(-420);
	ft_itr = ft_set.lower_bound(1200);
	std_itr = std_set.lower_bound(1200);
	compare(ft_itr, std_itr, compare_these_iterators_yo, "lower bound");

	/* upper bound */
	ft_itr = ft_set.upper_bound((size_t)200);
	std_itr = std_set.upper_bound((size_t)200);
	compare(ft_itr, std_itr, compare_these_iterators_yo, "upper bound");
	
	/* upper bound  const */
	ft_citr = ft_set.upper_bound((size_t)69);
	std_citr = std_set.upper_bound((size_t)69);
	compare(ft_citr, std_citr, compare_these_iterators_yo, "const upper bound");

	/* upper bound existing */
	ft_itr = --ft_set.upper_bound((size_t)-1);
	std_itr = --std_set.upper_bound((size_t)-1);
	compare(ft_itr, std_itr, compare_these_iterators_yo, "upper bound non existent");
	
	/* upper bound non existing */
	ft_citr = --ft_set.upper_bound((size_t)-42);
	std_citr = --std_set.upper_bound((size_t)-42);
	compare(ft_citr, std_citr, compare_these_iterators_yo, "const upper bound non existent");

	/* upper bound */
	ft_itr = ft_set.upper_bound(1200);
	std_itr = std_set.upper_bound(1200);
	compare(ft_itr, std_itr, compare_these_iterators_yo, "upper bound");

	/* equal range */
	ft::pair<ft_iterator, ft_iterator>		ft_pair;
	std::pair<std_iterator, std_iterator>	std_pair;
	ft::pair<ft_citerator, ft_citerator>	ft_cpair;
	std::pair<std_citerator, std_citerator>	std_cpair;

	ft_pair = ft_set.equal_range((size_t)200);
	std_pair = std_set.equal_range((size_t)200);
	compare(ft_pair, std_pair, compare_these_iterator_pairs_yo, "equal range");

	/* equal range  const */
	ft_cpair = ft_set.equal_range((size_t)69);
	std_cpair = std_set.equal_range((size_t)69);
	compare(ft_cpair, std_cpair, compare_these_iterator_pairs_yo, "const equal range");

	/* equal range existing */
	ft_pair = ft_set.equal_range((size_t)-1);
	std_pair = std_set.equal_range((size_t)-1);
	ft_pair.first--; ft_pair.second--; std_pair.first--; std_pair.second--;
	compare(ft_pair, std_pair, compare_these_iterator_pairs_yo, "equal range non existent");
	
	/* equal range non existing */
	ft_cpair = ft_set.equal_range((size_t)-42);
	std_cpair = std_set.equal_range((size_t)-42);
	ft_cpair.first--; ft_cpair.second--; std_cpair.first--; std_cpair.second--;
	compare(ft_cpair, std_cpair, compare_these_iterator_pairs_yo, "const equal range non existent");

	/* equal range */
	ft_pair = ft_set.equal_range(1200);
	std_pair = std_set.equal_range(1200);
	compare(ft_pair, std_pair, compare_these_iterator_pairs_yo, "equal range");

}

void	set_unit()
{
	print_header("set member functions");

	start_test("constructor", constructor_test);
	start_test("iterator", iterator_test);
	start_test("element access", element_access_test); 
	start_test("modifiers", modifier_test);
	start_test("operations", operations_test);
	start_test("observers", observer_test);
}
