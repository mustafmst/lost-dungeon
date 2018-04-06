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

