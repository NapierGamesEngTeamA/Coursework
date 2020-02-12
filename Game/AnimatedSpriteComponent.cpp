#include "AnimatedSpriteComponent.h"
#include "SystemRenderer.h"

//Constructor
AnimatedSpriteComponent::AnimatedSpriteComponent(Entity* p)
	: Component(p), _sprite(make_shared<Sprite>()), _animation(NULL), 
	_frameTime(seconds(0.2f)), _isPaused(false), 
	_isLooped(true), _texture(NULL), _currentFrame(0)
{

}

//Set animation
void AnimatedSpriteComponent::SetAnimation(const Animation& anim)
{
	_animation = &anim;
	_texture = _animation->GetSpriteSheet();
	SetFrame(_currentFrame);
	_sprite->setTexture(*_texture);
}

//Set fps
void AnimatedSpriteComponent::SetFrameTime(Time time)
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

//Pause animation
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

Time AnimatedSpriteComponent::GetFrameTime() const
{
	return _frameTime;
}

void AnimatedSpriteComponent::SetFrame(size_t newFrame, bool resetTime)
{
	if (_animation)
	{
		IntRect rect = _animation->GetFrame(newFrame);
		_sprite->setTextureRect(rect);
		//printf("%zu ", newFrame);

	}

	/*if (resetTime)
	{
		_currentTime = Time::Zero;
	}*/
}

void AnimatedSpriteComponent::Update(Time dt)
{
	_sprite->setPosition(_parent->GetPosition());

	if (!_isPaused && _animation)
	{
		_currentTime += dt;
		
		//printf("Delta Time: %f \n", dt.asMicroseconds());
		//printf("Current Time: %f \n", _currentTime.asSeconds());

		if (_currentTime >= _frameTime)
		{
			//_currentTime = microseconds(_currentTime.asMicroseconds() % _frameTime.asMicroseconds());
			_currentTime = Time::Zero;

			//printf("%f", _currentTime.asSeconds());
			//printf("Current Time (After): %f \n", _currentTime.asSeconds());


			if (_currentFrame + 1 != _animation->GetSize())
			{
				_currentFrame++;
				printf("%zu ", _currentFrame);

			}
			else
			{
				_currentFrame = 0;
				printf("%zu ", _currentFrame);

			}



			//printf("%zu ", _animation->GetSize());

			/*if (_currentFrame + 1> _animation->GetSize());
			{
				if (!_isLooped)
				{
					_isPaused = true;
				}
				else
				{
					_currentFrame = 0;
				}
			}*/

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