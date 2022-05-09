#ifndef RENDERER2D_H
#define RENDERER2D_H

#include <component.h>
#include <SFML/Graphics.hpp>

class Renderer2D : public Component
{
	friend class Application;
public:
	Renderer2D();
	explicit Renderer2D(std::string source_path, bool smooth, bool repeat);
	~Renderer2D() override;

	void set_texture_source(std::string source_path, bool smooth, bool repeat);

private:
	sf::Texture* source;
};

#endif