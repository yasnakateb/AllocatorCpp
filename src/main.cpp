#include "msalloc.hpp"
#include <iostream>

int main( int argc, char** argv )
{
    using namespace msalloc;
    using namespace std;
    
    MemorySpace <int> ms;
    ms.create_memory_space( 10 );

    int* p0 = ms.ms_alloc();
    *p0 = 35;
    cout << *p0 << endl;

    ms.ms_free( p0 );
    ms.delete_memory_space();
    
    return 0;
}