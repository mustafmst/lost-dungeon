#include "AssetManager.hpp"


void ld::AssetManager::LoadTexture(std::string name, std::string filePath)
{
	sf::Texture tex;
	if(tex.loadFromFile(filePath))
	{
		_textures[name] = tex;
	}
}

sf::Texture & ld::AssetManager::GetTexture(std::string name)
{
	return _textures.at(name);
}

void ld::AssetManager::LoatFont(std::string name, std::string filePath)
{
	sf::Font font;
	if(font.loadFromFile(filePath))
	{
		_fonts[name] = font;
	}
}

sf::Font & ld::AssetManager::GetFont(std::string name)
{
	return _fonts.at(name);
}

