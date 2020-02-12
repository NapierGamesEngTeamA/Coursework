#ifndef ANIMATION_INCLUDE
#define ANIMATION_INCLUDE

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Animation
{
public:
	Animation();

	void AddFrame(IntRect rect);
	void SetSpriteSheet(const Texture& texture);
	const Texture* GetSpriteSheet() const;
	const IntRect& GetFrame(size_t n) const;
	size_t GetSize() const;

private:
	vector<IntRect> _frames;
	const Texture* _texture;
};

#endif // !ANIMATION_INCLUDE