#pragma once

namespace Sansa {
	class TextureTest : public Test {
	public:
		void OnUpdate() override;
		void OnRender() override;
		void OnImGuiRender() override;
	};
};