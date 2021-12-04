#pragma once

#include "pch.hpp"

namespace Sansa {
	struct VBOLayoutElement 
	{
		unsigned int count;
		unsigned int type;
		bool normilized;
	};

	class VBOLayout {
	private:
		std::vector<VBOLayoutElement> m_Elements;
		unsigned int m_Stride = 0;
	public:
			template <typename T>
			void Push(VBOLayoutElement) {
				static_assert(true);
			};

			template <>
			void Push<float>(int count ) {
				m_Elements.push_back({ count, GL_FLOAT, false });
					m_Stride = sizeof(GL_FLOAT);
			};

			template <>
			void Push<unsigned int>(int count) {
				m_Elements.push_back({ count, GL_UNSIGNED_INT, false });
				m_Stride = sizeof(GL_UNSIGNED_INT);
			};

			template <>
			void Push<char>(int count) {
				m_Elements.push_back({ count, GL_BYTE, true });
				m_Stride = sizeof(GL_BYTE);
			};

			inline const std::vector<VBOLayoutElement>& GetElements() { return m_Elements; };

			inline unsigned int GetStride() const {return m_Stride;};

	};
};