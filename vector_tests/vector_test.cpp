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

# define TEST(container, tp, name)\
	ft::container<tp> ft_##name;\
	std::container<tp> std_##name;

template <class ft_vec, class std_vec>
void	compare_these_vectors_yo(ft_vec& ft, std_vec& std)
{
	bool success = true;

	if (ft.size() != std.size())
		success = false;
	for(size_t i = 0; i < ft.size(); ++i) {
		if (ft[i] != std[i]) {
			success = false;
			break ;
		}
	}
	if (success == true)
		std::cout << "[" << COLOR_GREEN << "OK" << COLOR_RESET << "]";
	else
		std::cout << "[" << COLOR_RED << "KO" << COLOR_RESET << "]";
}

/////////////////
// CONSTRUCTOR //
/////////////////
static void constructor_test()
{

/* default constructor */

	TEST(vector, int, default_constructor)

	std::cout << ft_default_constructor.size() << std::endl;

// /* set allocator */
// 	ft::vector<std::string, std::allocator<std::string> > set_allocator;
// 	std::vector<std::string, std::allocator<std::string> > sset_allocator;

// /* fill constructor */
// 	ft::vector<int> fill_constructor(42, 'a');
// 	std::vector<int> sfill_constructor(42, 'a');

// /* range constructor */
// 	ft::vector<int> range_constructor(fill_constructor.begin(), fill_constructor.end() - 21);
// 	std::vector<int> srange_constructor(sfill_constructor.begin(), sfill_constructor.end() - 21);

// /* copy constructor */
// 	ft::vector<int> copy_constructor(range_constructor);
// 	std::vector<int> scopy_constructor(srange_constructor);

// /* assigantion operator */
// 	ft::vector<int> assignation = copy_constructor;
// 	std::vector<int> sassignation = scopy_constructor;
	
}

void	vector_test()
{
	constructor_test();
}


int main()
{
	vector_test();
	return(0);
}