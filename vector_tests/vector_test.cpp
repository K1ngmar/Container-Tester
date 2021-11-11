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

# define CREATE(container, _type, name)\
	ft::container<_type> ft_##name;\
	std::container<_type> std_##name;

# define COMPARE(name)\
	if (compare_these_vectors_yo(ft_##name, std_##name) == true)\
		std::cout << "[" << COLOR_GREEN << "OK" << COLOR_RESET << "]";\
	else{\
		std::cout << "[" << COLOR_RED << "KO" << COLOR_RESET << "]";\
		std::cout << "test_case: " << #name << std::endl;\
	}

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
	size_t ft_time	= 0;
	size_t std_time	= 0;

/* default constructor */

	CREATE(vector, int, default_constructor)
	COMPARE(default_constructor);


// /* set allocator */
// 	ft::vector<std::string, std::allocator<std::string> > set_allocator;
// 	std::vector<std::string, std::allocator<std::string> > sset_allocator;

// /* fill constructor */
	ft::vector<int> ft_fill_constructor(42, 'a');
	std::vector<int> std_fill_constructor(42, 'a');
	COMPARE(fill_constructor)

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