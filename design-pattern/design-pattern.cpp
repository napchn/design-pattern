// design-pattern.cpp : Defines the entry point for the application.
//

#include "factory.h"

#include "design-pattern.h"

using namespace std;

int main()
{
	// factory
	IoCCtroller<Transport> ioc;
	ioc.RegisterType<Airport>("airport");
	std::shared_ptr<Transport> t1 = ioc.ResolveShared("airport");
	t1->info();
	ioc.RegisterType<Car>("car");
	std::shared_ptr<Transport> t2 = ioc.ResolveShared("car");
	t2->info();
	return 0;
}

