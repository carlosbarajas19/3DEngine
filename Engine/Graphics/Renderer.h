#pragma once
#include "Framework/System.h"
//#include "Texture.h"
#include "Math/MathTypes.h"
#include "Math/Transform.h"
#include <glad/glad.h>
#include <string>
#include <sdl.h>

namespace nc
{
	class Renderer : public System
	{
	public:
		void Startup() override;
		void Shutdown() override;
		void Update(float dt) override;

		void Create(const std::string& name, int width, int height);
		void BeginFrame();
		void EndFrame();

		/*void Draw(std::shared_ptr<nc::Texture> texture, const Vector2& position, float angle, const Vector2& scale = Vector2::one);
		void Draw(std::shared_ptr<nc::Texture> texture, const Transform& transform);
		void Draw(std::shared_ptr<nc::Texture> texture, const SDL_Rect& source, const Transform& transform);*/

		friend class Texture;

	private:
		SDL_GLContext context;
		SDL_Window* window = nullptr;
	};
}