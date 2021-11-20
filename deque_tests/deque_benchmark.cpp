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

# include <test_utility.hpp>
# include <deque.hpp>
# include <deque>
# include <Benchmark.hpp>

template < class Container >
	static void	fill_container(Container& con)
{
	for (size_t i = 0; i < 25000; i++) {
		con.push_back(test(i, "data"));
		con.push_front(test(i, "data"));
	}
}

template < class Container >
	static	void bench_push_back(Container& con)
{
	for (size_t i = 0; i < 500000; ++i)
		con.push_back(test(i));
}

template < class Container >
	static void bench_pop_front(Container& con)
{
	while (con.size() > 1337)
		con.pop_front();
}

template < class Container >
	static	void bench_push_front(Container& con)
{
	for (size_t i = 0; i < 500000; ++i)
		con.push_front(test(i));
}

template < class Container >
	static void bench_pop_back(Container& con)
{
	while (con.size() > 1337)
		con.pop_back();
}

template < class Container >
	static void bench_swap(Container& con, Container& vec)
{
	for (size_t i = 0; i < 42069; ++i)
		vec.swap(con);
}

template < class Container >
	static void bench_clear(Container& con)
{
	con.clear();
}

template < class Container >
	static void bench_resize(Container& con)
{
	for (size_t i = 0; i < 500; ++i) {
		con.resize(25000);
		con.resize(1337);
	}
}

template < class Container >
	static void bench_assign(Container& con)
{
	for (size_t i = 0; i < 50; ++i) {
		con.assign(420, test(69));
		con.assign(200000, test(69));
	}
}

template < class Bench >
	static void bench_tests(Bench& bench)
{
	bench.run_test(bench_push_back, "push back");
	bench.run_test(bench_pop_front, "pop front");
	bench.run_test(bench_push_front, "push front");
	bench.run_test(bench_pop_back, "pop back");

	fill_container(bench.get_container());
	bench.run_test(bench_swap, "swap");

	for (size_t i = 0; i < 250; ++i) {
		fill_container(bench.get_container());
		bench.run_test(bench_clear, "clear");
	}

	fill_container(bench.get_container());
	bench.run_test(bench_resize, "resize");
	bench.run_test(bench_assign, "assign");
}

void deqtor_benchmark()
{
	Benchmark< ft::deque<test> >	ft_bench;
	Benchmark< std::deque<test> >	std_bench;

	bench_tests(ft_bench);
	bench_tests(std_bench);

	std::map< std::string, size_t >	ft_result = ft_bench.get_result();
	std::map< std::string, size_t >	std_result = std_bench.get_result();

	format_benchmark_result(ft_result, std_result, "deque");
	print_benchmark_result(ft_bench.get_total_time(), std_bench.get_total_time(), "deque");
}
