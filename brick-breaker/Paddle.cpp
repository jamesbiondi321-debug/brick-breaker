#include "Paddle.h"

#include "Game.h"

Paddle::Paddle(Game* game)
	: Actor{ {game->GetWidth() * 0.5f, game->GetHeight() - 20.f}, {100.f, 25.f}, WHITE, game }, m_speed{250.f}
{

}

void Paddle::Tick(float dt)
{
	if (IsKeyDown(KEY_D))
	{
		location.x += m_speed * dt;
	}
	if (IsKeyDown(KEY_A))
	{
		location.x -= m_speed * dt;
	}

	if (location.x < size.x * 0.5)
	{
		location.x = size.x * 0.5;
	}
	if (location.x > m_game->GetWidth() - size.x * 0.5)
	{
		location.x = m_game->GetWidth() - size.x * 0.5;
	}
}

void Paddle::Render()
{
	DrawRectanglePro({ location.x, location.y, size.x, size.y }, { size.x * 0.5f, size.y * 0.5f }, 0.f, color);
}
