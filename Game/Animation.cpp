#include "Animation.h"

using namespace sf;
using namespace std;

Animation::Animation() : _texture(NULL)
{

}

void Animation::AddFrame(IntRect rect)
{
	_frames.push_back(rect);
}

void Animation::SetSpriteSheet(const Texture& texture)
{
	_texture = &texture;
}

const Texture* Animation::GetSpriteSheet() const
{
	return _texture;
}

size_t Animation::GetSize() const
{
	return _frames.size();
}

const IntRect& Animation::GetFrame(size_t n) const
{
	return _frames[n];
}