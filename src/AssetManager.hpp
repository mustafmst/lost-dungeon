#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace ld
{
	class AssetManager
	{
	private:
		std::map<std::string, sf::Texture> _textures;
	public:
		void LoadTexture(std::string name, std::string filePath);
		sf::Texture & GetTexture(std::string name);
	};
}

