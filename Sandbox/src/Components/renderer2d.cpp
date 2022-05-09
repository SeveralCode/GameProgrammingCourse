#include "renderer2D.h"
#include "Classes/area2d.h"

Renderer2D::Renderer2D() : Component("Renderer 2D")
{
	source = nullptr;
}

Renderer2D::Renderer2D(const std::string source_path, bool smooth = true, bool repeat = false) : Component("Renderer 2D")
{
	source = new sf::Texture();
	source->create(10, 10);
	if(!source->loadFromFile(source_path))
	{
		printf("Can't load texture at path[%s]\n", source_path.c_str());
		return;
	}
	source->setSmooth(smooth);
	source->setRepeated(repeat);

	const auto rect = get_owner()->get_component<RectTransform>();
	if (!rect)
	{
		printf("can't load rect transform from component owner\n");
		system("pause");
		return;
	}

	rect->get_transform()->setTexture(source);
}

Renderer2D::~Renderer2D()
{
	delete source;
}

void Renderer2D::set_texture_source(const std::string source_path, const bool smooth = true, const bool repeat = false)
{
	delete source;
	source = new sf::Texture();
	if (!source->loadFromFile(source_path))
	{
		printf("Can't load texture at path[%s]\n", source_path.c_str());
		return;
	}
	source->setSmooth(smooth);
	source->setRepeated(repeat);

	const auto owner = dynamic_cast<Area2D*>(get_owner());
	if (!owner)
	{
		printf("owner casting failed!\n");
		system("pause");
		return;
	}

	owner->rect_transform->get_transform()->setTexture(source);
}


