#include "Dimension.h"
#include "Definitions.h"

Dimension::Dimension(const GOLoader loader) : position(loader.xPosition, loader.yPosition), size(loader.width, loader.height) {}

Dimension::~Dimension() {}

void Dimension::update(Vector2D velocity)
{
    position.x += velocity.x * defaultFrameDelayinSeconds;
    position.y -= velocity.y * defaultFrameDelayinSeconds;
}
