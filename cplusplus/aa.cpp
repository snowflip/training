class Usable_lock {
    private:
	    Usable_lock() {}
	        Usable_lock(const Usable_lock&) {}
};

class Aa : public virtual Usable_lock {
	 public:
	     Aa();
	     Aa(char*);
};

class DD : public Aa { };
	
int main(int argc, char *argv[])
{
     Aa a;
     //DD dd;

     return 0;
}

