#ifndef _OSMAND_CORE_I_MAP_STYLES_COLLECTION_H_
#define _OSMAND_CORE_I_MAP_STYLES_COLLECTION_H_

#include <OsmAndCore/stdlib_common.h>

#include <OsmAndCore/QtExtensions.h>
#include <QString>
#include <QHash>

#include <OsmAndCore.h>

namespace OsmAnd
{
    class MapStyle;

    class OSMAND_CORE_API IMapStylesCollection
    {
        Q_DISABLE_COPY(IMapStylesCollection);
    private:
    protected:
        IMapStylesCollection();
    public:
        virtual ~IMapStylesCollection();

        virtual QHash< QString, std::shared_ptr<const MapStyle> > getCollection() const = 0;
        virtual bool obtainBakedStyle(const QString& name, std::shared_ptr<const MapStyle>& outStyle) const = 0;
        inline std::shared_ptr<const MapStyle> getBakedStyle(const QString& name) const
        {
            std::shared_ptr<const MapStyle> style;
            obtainBakedStyle(name, style);
            return style;
        }
    };
}

#endif // !defined(_OSMAND_CORE_I_MAP_STYLES_COLLECTION_H_)
