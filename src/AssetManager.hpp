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
		std::map<std::string, sf::Font> _fonts;
	public:
		void LoadTexture(std::string name, std::string filePath);
		sf::Texture & GetTexture(std::string name);
		
		void LoatFont(std::string name, std::string filePath);
		sf::Font & GetFont(std::string name);
	};
}

