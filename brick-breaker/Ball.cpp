#include "Ball.h"
#include "Game.h"
#include <raymath.h>

Ball::Ball(Game* game)
	: Actor{ { game->GetWidth() * 0.5f, game->GetHeight() * 0.5f}, {10.f, 10.f }, WHITE, game }, velocity{ 0.5f, 0.5f }, moveSpeed{ 250.f }
{

}

void Ball::Tick(float dt)
{
	location += velocity * moveSpeed * dt;
}

void Ball::Render()
{
	DrawCircleV(location, Vector2Length(size), color);
}
