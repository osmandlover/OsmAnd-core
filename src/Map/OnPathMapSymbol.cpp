#include "OnPathMapSymbol.h"

OsmAnd::OnPathMapSymbol::OnPathMapSymbol(
    const std::shared_ptr<MapSymbolsGroup>& group_,
    const bool isShareable_,
    const int order_,
    const IntersectionModeFlags intersectionModeFlags_,
    const std::shared_ptr<const SkBitmap>& bitmap_,
    const QString& content_,
    const LanguageId& languageId_,
    const PointI& minDistance_,
    const QVector<PointI>& path_,
    const QVector<float>& glyphsWidth_)
    : RasterMapSymbol(group_, isShareable_, order_, intersectionModeFlags_, bitmap_, content_, languageId_, minDistance_)
    , path(path_)
    , glyphsWidth(glyphsWidth_)
{
}

OsmAnd::OnPathMapSymbol::~OnPathMapSymbol()
{
}
