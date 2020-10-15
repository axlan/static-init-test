#include "base.h"

namespace test2
{

	const std::string NAME = "Test2";

	class Test2 : public Base {
		const std::string& get_name() override {
			return NAME;
		}
	};

	StaticClassConstructor constructor(NAME, std::make_unique<Test2>);
}