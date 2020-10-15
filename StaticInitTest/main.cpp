#include "base.h"


int main()
{
    
    BasePtr ptr;
    bool good;
    good = Base::make_obj("Test1", ptr);
    std::cout << good << " " << ptr->get_name() << std::endl;
    good = Base::make_obj("Test2", ptr);
    std::cout << good << " " << ptr->get_name() << std::endl;

    std::cout << Base::make_obj("Test3", ptr) << std::endl;

    return 0;
}
