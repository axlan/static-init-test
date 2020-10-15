#include "base.h"

namespace test1
{
	const std::string NAME = "Test1";

	class Test1 : public Base {
		const std::string& get_name() override {
			return NAME;
		}
	};

	StaticClassConstructor constructor(NAME, std::make_unique<Test1>);
}