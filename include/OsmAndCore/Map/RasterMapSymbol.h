#ifndef _OSMAND_CORE_RASTER_MAP_SYMBOL_H_
#define _OSMAND_CORE_RASTER_MAP_SYMBOL_H_

#include <OsmAndCore/stdlib_common.h>
#include <functional>

#include <OsmAndCore/QtExtensions.h>
#include <QString>

#include <OsmAndCore.h>
#include <OsmAndCore/CommonTypes.h>
#include <OsmAndCore/Callable.h>
#include <OsmAndCore/Map/MapSymbol.h>

namespace OsmAnd
{
    class OSMAND_CORE_API RasterMapSymbol : public MapSymbol
    {
        Q_DISABLE_COPY(RasterMapSymbol);

    private:
    protected:
        RasterMapSymbol(
            const std::shared_ptr<MapSymbolsGroup>& group,
            const bool isShareable);
    public:
        virtual ~RasterMapSymbol();

        std::shared_ptr<const SkBitmap> bitmap;
        PointI size;
        QString content;
        LanguageId languageId;
        PointI minDistance;
    };
}

#endif // !defined(_OSMAND_CORE_RASTER_MAP_SYMBOL_H_)
