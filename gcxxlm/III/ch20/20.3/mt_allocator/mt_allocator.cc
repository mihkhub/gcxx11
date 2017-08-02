#include <ext/mt_allocator.h>
struct pod
{
	int i;
	int j;
};

int main()
{
	typedef pod value_type;
	typedef __gnu_cxx::__mt_alloc<value_type> allocator_type;
	typedef __gnu_cxx::__pool_base::_Tune tune_type;

	tune_type t_default;
	tune_type t_opt(16,5120, 32, 5120, 20, 10, false);
	tune_type t_single(16, 5120, 32, 5120, 1, 10 , false);


	allocator_type a;	
	allocator_type::pointer p1 = a.allocate(128);
	allocator_type::pointer p2 = a.allocate(128);
	
	a.deallocate(p1, 128);
	a.deallocate(p2, 5120);
	return 0;
}
