#include <assert.h>

class Usable;

class Usable_lock {
        friend class Usable;
    private:
	    Usable_lock() {}
};

class Usable : public virtual Usable_lock {
private:
    static int number_of_instances;
public:
    enum { MAX_NUMBER_OF_INSTANCES = 3 };
    Usable() {
	assert(number_of_instances < MAX_NUMBER_OF_INSTANCES);
	++number_of_instances;
    }
};

int Usable::number_of_instances = 0;

Usable a;
Usable b;

class DD : public Usable {};

DD dd;
int main()
{
    return 0;
}
