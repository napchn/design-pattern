// design-pattern.cpp : Defines the entry point for the application.
//

//#include "factory.h"
//#include "abstract_factory.h"
//#include "builder.h"

#include "design-pattern.h"

using namespace std;

int main()
{
	// Builder
	//FileHeader header = {"A680J232", "3/14/2024"};
	//std::list<FileBody> contents = {
	//	{"JEIIS0001", 428},
	//	{"JEIIS0002", 8},
	//	{"JEIIS0003", 234},
	//	{"JEIIS0004", 88},
	//};
	//FileFooter footer = {"Vistual Studio 2022"};
	//Builder* builder = new TxtBuilder;
	//Director director1(builder);
	//director1.Construct(header, contents, footer);
	//std::cout << builder->GetFile();
	//builder = new XmlBuilder();
	//Director director2(builder);
	//director2.Construct(header, contents, footer);
	//std::cout << builder->GetFile();

	// Abstract Factory
	//SchemaFactory schema;
	//schema.PrepareResolution(new SchemaPC);
	
	// Factory
	//IoCCtroller<Transport> ioc;
	//ioc.RegisterType<Airport>("airport");
	//std::shared_ptr<Transport> t1 = ioc.ResolveShared("airport");
	//t1->info();
	//ioc.RegisterType<Car>("car");
	//std::shared_ptr<Transport> t2 = ioc.ResolveShared("car");
	//t2->info();
	return 0;
}

