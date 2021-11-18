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
#include <map.hpp>
#include <map>


template <class ft_map, class ft_itr, class std_map, class std_itr>
bool	compare_these_maps_yo(ft_map& ft, ft_itr fitr, std_map& std, std_itr sitr)
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
	while(fitr != ft.end()) {
		if (compare_these_map_iterators_yo(fitr, sitr) == false)
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

	ft::map<int, std::string> ft_dc;
	std::map<int, std::string> std_dc;
	compare(ft_dc, ft_dc.begin(), std_dc, std_dc.begin(), compare_these_maps_yo, "default constructor");


// // /* range constructor */
// 	ft::map<int, std::string> ft_rc(ft_fc.begin(), ft_fc.end() - 21);
// 	std::map<int, std::string> std_rc(std_fc.begin(), std_fc.end() - 21);
// 	compare(ft_rc, std_rc, compare_these_maps_yo, "range constructor");

	for (int i = 0; i < 15; i++) {
		ft_dc.insert(ft::make_pair(i, std::string("yos")));
		std_dc.insert(std::make_pair(i, std::string("yos")));
	}

/* copy constructor */
	ft::map<int, std::string> ft_cc(ft_dc);
	std::map<int, std::string> std_cc(std_dc);
	compare(ft_cc, ft_cc.begin(), std_cc, std_cc.begin(), compare_these_maps_yo, "copy constructor");

/* test for deep copy */
	ft_dc.erase(ft_dc.begin());
	std_dc.erase(std_dc.begin());
	compare(ft_dc, ft_dc.begin(), std_dc, std_dc.begin(), compare_these_maps_yo, "deep copy (copy construcor)");
	compare(ft_cc, ft_cc.begin(), std_cc, std_cc.begin(), compare_these_maps_yo, "deep copy (copy construcor)");


/* assigantion operator */
	ft::map<int, std::string> ft_ass = ft_cc;
	std::map<int, std::string> std_ass = std_cc;
	compare(ft_ass, ft_ass.begin(), std_ass, std_ass.begin(), compare_these_maps_yo, "assignation operator");

/* test for deep copy */
	ft_cc.erase(++(ft_dc.begin()));
	std_cc.erase(++(std_dc.begin()));
	compare(ft_cc, ft_cc.begin(), std_cc, std_cc.begin(), compare_these_maps_yo, "deep copy (copy construcor)");
	compare(ft_dc, ft_dc.begin(), std_dc, std_dc.begin(), compare_these_maps_yo, "deep copy (copy construcor)");

}

///////////////////
// iterator test //
///////////////////
static void iterator_test()
{
	ft::map<size_t, int>							ft_map;
	std::map<size_t, int>							std_map;
	ft::map<size_t, int>::iterator					ft_itr;
	std::map<size_t, int>::iterator					std_itr;
	ft::map<size_t, int>::const_iterator			ft_citr;
	std::map<size_t, int>::const_iterator			std_citr;

	for (size_t i = 0; i < 15; i++) {
		ft_map.insert(ft::make_pair(i, (int)i));
		std_map.insert(std::make_pair(i, (int)i));
	}

/* testing begin */

	ft_itr = ft_map.begin();
	std_itr = std_map.begin();
	compare(ft_itr, std_itr, compare_these_map_iterators_yo, "begin()");

/* testing const begin */
	// ft_citr = ft_map.begin();
	// std_citr = std_map.begin();
	// compare(ft_citr, std_citr, compare_these_map_iterators_yo, "const begin()");


	ft::map<int, int>	ft_empty;
	std::map<int, int>	std_empty;
	bool ft_cmp = ft_empty.begin() == ft_empty.end();
	bool std_cmp = std_empty.begin() == std_empty.end();
	compare(ft_cmp, std_cmp, compare_these_values_yo, "begin() == end()");


	/* do some reverse iterator test you imbecile */
	

/* testing end() */
	ft_itr = --(ft_map.end());
	std_itr = --(std_map.end());
	compare(ft_itr, std_itr, compare_these_map_iterators_yo, "end() - 1");

/* testing const end() */
// 	ft_citr = ft_map.end() - 1;
// 	std_citr = std_map.end() - 1;
// 	compare(ft_citr, std_citr, compare_these_map_iterators_yo, "const end() - 1");


	/* do some reverse const iterator test you imbecile */
}

////////////////////
// ELEMENT ACCESS //
////////////////////
static void element_access_test()
{
	ft::map<std::string, unsigned char>		ft_map;
	std::map<std::string, unsigned char>	std_map;

/* opeartor [] */
	for (size_t i = 0; i < 1337; i++) {
		ft_map[std::to_string(i)] = (unsigned char)i;
		std_map[std::to_string(i)] = (unsigned char)i;
	}
	compare(ft_map, ft_map.begin(), std_map, std_map.begin(), compare_these_maps_yo, "operator []");

	for (size_t i = 0; i < 1337; i++) {
		ft_map[std::to_string(i)] = (unsigned char)i;
		std_map[std::to_string(i)] = (unsigned char)i;
	}
	compare(ft_map, ft_map.begin(), std_map, std_map.begin(), compare_these_maps_yo, "operator []");

	size_t rando;
	for (size_t i = 0; i < 1337; i++) {
		rando = rand();
		ft_map[std::to_string(rando)] = (unsigned char)i;
		std_map[std::to_string(rando)] = (unsigned char)i;
	}
	compare(ft_map, ft_map.begin(), std_map, std_map.begin(), compare_these_maps_yo, "operator []");

/* swap */
	ft::map<std::string, unsigned char>				ft_tbs;
	std::map<std::string, unsigned char>			std_tbs;
	ft_tbs["I am going to be swapped"] = 69;
	std_tbs["I am going to be swapped"] = 69;
	ft::map<std::string, unsigned char>::iterator	ft_itr = ft_map.begin();
	std::map<std::string, unsigned char>::iterator	std_itr = std_map.begin();

	ft_map.swap(ft_tbs);
	std_map.swap(std_tbs);
	compare(ft_map, ft_map.begin(), std_map, std_map.begin(), compare_these_maps_yo, "swap");
	compare(ft_tbs, ft_itr, std_tbs, std_itr, compare_these_maps_yo, "swap");
}

///////////////
// MODIFIERS //
///////////////
static void modifier_test()
{
	ft::map<size_t, std::string>	ft_map;
	std::map<size_t, std::string>	std_map;
	ft::map<size_t, std::string>	ft_empty;
	std::map<size_t, std::string>	std_empty;

/* insert */
	for (size_t i = 0; i < 5000; i++) {
		ft_map.insert(ft::make_pair(i, std::string("yos")));
		ft_map.insert(ft::make_pair(i, std::string("yos")));
		std_map.insert(std::make_pair(i, std::string("yos")));
		std_map.insert(std::make_pair(i, std::string("yos")));
	}
	compare(ft_map, ft_map.begin(), std_map, std_map.begin(), compare_these_maps_yo, "insert");

/* erase */
	while (ft_map.size() > 1337) {
		ft_map.erase(ft_map.begin());
		std_map.erase(std_map.begin());
	}
	compare(ft_map, ft_map.begin(), std_map, std_map.begin(), compare_these_maps_yo, "erase");

/* clear */
	ft_map.clear();
	std_map.clear();
	compare(ft_map, ft_map.begin(), std_map, std_map.begin(), compare_these_maps_yo, "clear");
}

void	map_unit()
{
	print_header("map member functions");

	start_test("constructor", constructor_test);
	start_test("iterator", iterator_test);
	start_test("element access", element_access_test); 
	start_test("modifier test", modifier_test);
}
