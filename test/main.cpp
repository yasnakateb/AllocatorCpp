#include "allocator.hpp"
#include "monitor.hpp"

//////////////////////////////////////////////////////////////////////////////
/////////////                                                    /////////////
/////////////                                                    /////////////
/////////////        Comparison Of Memory Allocation Time        /////////////
/////////////                                                    /////////////
/////////////                                                    /////////////
//////////////////////////////////////////////////////////////////////////////

int main( int argc, char** argv )
{
    using namespace msalloc;
    using namespace msalloc::mointor;
    
    const int num = 10000;
    const int size = 1000;

    struct Frame
    {
        uint8_t start_byte;
        uint32_t data;
        uint8_t stop_byte;
    };
    using Type = Frame;

    //////////////////////////////////////////////////////////////////////////////
    /////////////                                                    /////////////
    /////////////                         NEW                        /////////////
    /////////////                                                    /////////////
    //////////////////////////////////////////////////////////////////////////////
        {
            MemoryMonitor monitor_new( "new", true );
            Type* arr[size];

            for ( int n = 0; n < num; ++n )
            {

                for ( int i = size - 1; 0 <= i; --i )
                {
                    arr[i] = new Type;
                }

                for ( int i = size - 1; 0 <= i; --i )
                {
                    delete arr[i];
                }

            }     
        }
        //////////////////////////////////////////////////////////////////////////////
        /////////////                                                    /////////////
        /////////////                       MSALLOC                      /////////////
        /////////////                                                    /////////////
        //////////////////////////////////////////////////////////////////////////////
        {
            MemoryMonitor monitor_msalloc( "msalloc", true );
            Type* ms_arr[size];
            MemorySpace<Type> ms;
            ms.create_memory_space( size );

            for ( int n = 0; n < num; ++n )
            {

                for ( int i = size - 1; 0 <= i; --i )
                {
                    ms_arr[i] = ms.ms_allocate();
                }

                for ( int i = size - 1; 0 <= i; --i )
                {
                    ms.ms_free( ms_arr[i] );
                }

            }
            ms.delete_memory_space();
        }
    return 0;
}