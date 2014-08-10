#include "OnSurfaceVectorMapSymbol.h"

OsmAnd::OnSurfaceVectorMapSymbol::OnSurfaceVectorMapSymbol(
    const std::shared_ptr<MapSymbolsGroup>& group_,
    const bool isShareable_)
    : VectorMapSymbol(group_, isShareable_)
    , direction(0.0f)
{
}

OsmAnd::OnSurfaceVectorMapSymbol::~OnSurfaceVectorMapSymbol()
{
}

float OsmAnd::OnSurfaceVectorMapSymbol::getDirection() const
{
    return direction;
}

void OsmAnd::OnSurfaceVectorMapSymbol::setDirection(const float newDirection)
{
    direction = newDirection;
}

OsmAnd::PointI OsmAnd::OnSurfaceVectorMapSymbol::getPosition31() const
{
    return position31;
}

void OsmAnd::OnSurfaceVectorMapSymbol::setPosition31(const PointI newPosition31)
{
    position31 = newPosition31;
}
