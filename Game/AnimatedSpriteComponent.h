#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "ecm.h"

using namespace std;
using namespace sf;

class AnimatedSpriteComponent : public Component
{
protected:
	shared_ptr<Sprite> _sprite;
public:
	AnimatedSpriteComponent() = delete;
	explicit AnimatedSpriteComponent(Entity* p);
	void Update(Time dt) override;
	void Render() override;
	void SetAnimation(const Animation& anim);
	void SetFrameTime(Time time);
	void Play();
	void Play(const Animation& anim);
	void Pause();
	void Stop();
	void SetLooped(bool looped);
	const Animation* GetAnimation() const;
	bool IsLooped() const;
	bool IsPlaying() const;
	Time GetFrameTime() const;
	void SetFrame(size_t newFrame, bool resetTime = true);
private:
	const Animation* _animation;
	Time _frameTime;
	Time _currentTime;
	bool _isPaused;
	bool _isLooped;
	const Texture* _texture;
	size_t _currentFrame;
};
