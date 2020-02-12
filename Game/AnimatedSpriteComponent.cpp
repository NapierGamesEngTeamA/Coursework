#include "AnimatedSpriteComponent.h"
#include "SystemRenderer.h"

//Constructor
AnimatedSpriteComponent::AnimatedSpriteComponent(Entity* p)
	: Component(p), _sprite(make_shared<Sprite>()), _animation(NULL), 
	_frameTime(0.2f), _isPaused(false), 
	_isLooped(false), _texture(NULL), _currentFrame(0), _currentTime(0)
{

}

//Set animation
void AnimatedSpriteComponent::SetAnimation(const Animation& anim)
{
	_animation = &anim;
	_texture = _animation->GetSpriteSheet();
	_currentFrame = 0;
	SetFrame(_currentFrame);
	_sprite->setTexture(*_animation->GetSpriteSheet());
}

//Set fps
void AnimatedSpriteComponent::SetFrameTime(double time)
{
	_frameTime = time;
}

//Play
void AnimatedSpriteComponent::Play()
{
	_isPaused = false;
}

//Play specific animation
void AnimatedSpriteComponent::Play(const Animation& animation)
{
	if (GetAnimation() != &animation)
	{
		SetAnimation(animation);
	}
	Play();
}

void AnimatedSpriteComponent::Pause()
{
	_isPaused = true;
}

void AnimatedSpriteComponent::Stop()
{
	_isPaused = true;
	_currentFrame = 0;
	SetFrame(_currentFrame);
}

void AnimatedSpriteComponent::SetLooped(bool looped)
{
	_isLooped = looped;
}

const Animation* AnimatedSpriteComponent::GetAnimation() const
{
	return _animation;
}

bool AnimatedSpriteComponent::IsLooped() const
{
	return _isLooped;
}

bool AnimatedSpriteComponent::IsPlaying() const
{
	return !_isPaused;
}

double AnimatedSpriteComponent::GetFrameTime() const
{
	return _frameTime;
}

void AnimatedSpriteComponent::SetFrame(size_t newFrame, bool resetTime)
{
	if (_animation)
	{
		IntRect rect = _animation->GetFrame(newFrame);
		_sprite->setTextureRect(rect);
	}

	if (resetTime)
	{
		_currentTime = 0;
	}
}

void AnimatedSpriteComponent::Update(double dt)
{
	_sprite->setPosition(_parent->GetPosition());

	if (!_isPaused && _animation)
	{
		_currentTime += dt;
		_currentTime *= 6;
		
		printf("%f", _currentTime);

		if (_currentTime > _frameTime)
		{
			_currentTime = 0;

			if (_currentFrame + 1 < _animation->GetSize())
			{
				_currentFrame++;
			}
			else
			{
				if (!_isLooped)
				{
					_isPaused = true;
				}
				else
				{
					_currentFrame = 0;
				}
			}

			SetFrame(_currentFrame, false);
		}
	}
}

void AnimatedSpriteComponent::Render()
{
	if (_animation && _texture)
	{
		Renderer::Queue(_sprite.get());
	}

	Renderer::Queue(_sprite.get());

}