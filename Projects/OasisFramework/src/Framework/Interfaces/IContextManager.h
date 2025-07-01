#pragma once

#include "Core.h"
#include "oapch.h"

#include <Framework/Types.h>
#include <Framework/Data.h>

namespace OASFramework {
	namespace Interface {
		OASIS_INTERFACE __declspec(dllexport) IContextManager {
		public:
			virtual ~IContextManager() {}

			virtual void Initialize(const Data::ContextData & ctx_data = Data::ContextData()) = NULL;
			virtual void OnUpdate() = NULL;
			virtual void Shutdown() = NULL;

			virtual inline std::string GetName() const = NULL;
			virtual inline unsigned int GetWidth() const = NULL;
			virtual inline unsigned int GetHeight() const = NULL;

			virtual inline void SetVSync(bool val) = NULL;
			virtual inline bool IsVSync() const = NULL;
		};
	}
}