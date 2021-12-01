#pragma once

#define REGISTER_CLASS(class) nc::ObjectFactory::Instance().Register<class>(#class);

//systems
#include "Audio/AudioSystem.h"
#include "Input/InputSystem.h"

//Framework
#include "Framework/EventSystem.h"
#include "Resource/ResourceSystem.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"

//core
#include "Core/Utilities.h"
#include "Core/FileSystem.h"
#include "Core/Timer.h"
#include "Core/Json.h"
#include "Core/Serializable.h"

//Math
#include "Math/MathTypes.h"
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"

//graphics
#include "Graphics/Renderer.h"
#include "Graphics/Material.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexIndexBuffer.h"

//Physics System


//objects
#include "Object/Scene.h"
#include "Object/Actor.h"

//components
#include "Component/PhysicsComponent.h"
#include "Component/AudioComponent.h"
#include "Component/CameraComponent.h"
#include "Component/MeshComponent.h"
#include "Component/FreeCameraController.h"
#include "Component/LightComponent.h"


#define NOMINMAX
#include <vector>
#include <memory>
#include <algorithm>

namespace nc
{

	using ObjectFactory = Singleton<Factory<std::string, Object>>;

	class Engine
	{
	public:
		void Startup();
		void Shutdown();

		void Update();
		void Draw(Renderer* renderer);

		template<typename T>
		T* Get();
	public:
		FrameTimer time;
	private:
		std::vector<std::unique_ptr<System>> systems;
	};

	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems)
		{
			if (dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}

		return nullptr;
	}
}