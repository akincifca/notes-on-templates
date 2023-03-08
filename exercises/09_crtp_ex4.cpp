/*
 * Implement the class ShareMe and use it.

    Objects of the class ShareMe should return an std::shared_ptr to themselves.

 */

#include <iostream>

// Implement the class here
struct ShareMe : std::enable_shared_from_this<ShareMe> {
    std::shared_ptr<ShareMe> getShared(){
        return shared_from_this();
    }
};

int main() {
    // After implementing the shareMe class uncomment the code given below


    std::cout << std::endl;

    // share the same ShareMe object
    std::shared_ptr<ShareMe> shareMe(new ShareMe);
    std::shared_ptr<ShareMe> shareMe1= shareMe->getShared();

    // both resources have the same address
    std::cout << "Address of resource of shareMe "<< (void*)shareMe.get() << " " << std::endl;
    std::cout << "Address of resource of shareMe1 "<< (void*)shareMe1.get() << " " << std::endl;

    // the use_count is 2
    std::cout << "shareMe.use_count(): "<< shareMe.use_count() << std::endl;
    std::cout << std::endl;
    */
}
