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

#include <test.hpp>
#include <vector.hpp>
#include <vector>

template <class ft_vec, class std_vec>
bool	compare_these_vectors_yo(ft_vec& ft, std_vec& std)
{
	if (ft.size() != std.size())
		return false;
	for(size_t i = 0; i < ft.size(); ++i) {
		if (ft[i] != std[i])
			return false;
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
	ft::vector<int>::iterator					ft_iterator;
	std::vector<int>::iterator					std_iterator;
	ft::vector<int>::const_iterator				ft_cit;
	std::vector<int>::const_iterator			std_cit;
	// ft::vector<int>::reverse_iterator			ft_rit;
	// std::vector<int>::reverse_iterator			std_rit;
	// ft::vector<int>::const_reverse_iterator		ft_crit;
	// std::vector<int>::const_reverse_iterator	std_crit;

	for (size_t i = 0; i < 21; ++i)
		push_back_amount(ft_vec, std_vec, rand(), 1);

	// ft_iterator = ft_vec.begin();
	// std_iterator = std_vec.begin();
	// COMPARE_ITR(iterator)

	// cit = vec.begin();
	// rit = vec.rbegin();
	// crit = vec.rbegin();
	// std::cout << "Begin: " << *it << std::endl;
	// std::cout << "Const begin: " << *cit << std::endl;
	// std::cout << "Reverse begin: " << *rit << std::endl;
	// std::cout << "Const reverse begin: " << *crit << std::endl;
	
	// it = vec.end() - 1;
	// cit = vec.end() - 1;
	// rit = vec.rend() - 1;
	// crit = vec.rend() - 1;
	// std::cout << "End: " << *it << std::endl;
	// std::cout << "Const end: " << *cit << std::endl;
	// std::cout << "Reverse end: " << *rit << std::endl;
	// std::cout << "Const reverse end: " << *crit << std::endl;
}

void	vector_test()
{
	print_header("Vector member functions");
	start_test("constructor", constructor_test);
	start_test("iterator", iterator_test);
}


int main()
{
	srand(42);
	vector_test();
	return(0);
}