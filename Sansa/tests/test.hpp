#pragma once

namespace SansaTest {
	class Test {
	public:
		Test();
		~Test();
			
		virtual void OnUpdate();
		virtual void OnRender();
		virtual void OnImGuiRender();
	};
};