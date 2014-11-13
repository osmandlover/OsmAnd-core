#ifndef _OSMAND_CORE_PRIMITIVISER_P_H_
#define _OSMAND_CORE_PRIMITIVISER_P_H_

#include "stdlib_common.h"

#include "QtExtensions.h"
#include <QList>

#include "OsmAndCore.h"
#include "CommonTypes.h"
#include "PrivateImplementation.h"
#include "IQueryController.h"
#include "MapCommonTypes.h"
#include "MapPresentationEnvironment.h"
#include "Primitiviser.h"

namespace OsmAnd
{
    class Primitiviser;
    class Primitiviser_P Q_DECL_FINAL
    {
        Q_DISABLE_COPY_AND_MOVE(Primitiviser_P);
    public:
        typedef Primitiviser::CoastlineMapObject CoastlineMapObject;
        typedef Primitiviser::FoundationMapObject FoundationMapObject;
        typedef Primitiviser::PrimitiveType PrimitiveType;
        typedef Primitiviser::Primitive Primitive;
        typedef Primitiviser::PrimitivesCollection PrimitivesCollection;
        typedef Primitiviser::PrimitivesGroup PrimitivesGroup;
        typedef Primitiviser::PrimitivesGroupsCollection PrimitivesGroupsCollection;
        typedef Primitiviser::Symbol Symbol;
        typedef Primitiviser::SymbolsCollection SymbolsCollection;
        typedef Primitiviser::SymbolsGroup SymbolsGroup;
        typedef Primitiviser::SymbolsGroupsCollection SymbolsGroupsCollection;
        typedef Primitiviser::TextSymbol TextSymbol;
        typedef Primitiviser::IconSymbol IconSymbol;
        typedef Primitiviser::PrimitivisedArea PrimitivisedArea;
        typedef Primitiviser::Cache Cache;

    private:
    protected:
        Primitiviser_P(Primitiviser* const owner);

        enum class PrimitivesType
        {
            Polygons,
            Polylines,
            Polylines_ShadowOnly,
            Points,
        };

        static void applyEnvironment(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<PrimitivisedArea>& primitivisedArea);

        static AreaI alignAreaForCoastlines(const AreaI& area31);

        static bool polygonizeCoastlines(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<const PrimitivisedArea>& primitivisedArea,
            const QList< std::shared_ptr<const MapObject> >& coastlines,
            QList< std::shared_ptr<const MapObject> >& outVectorized,
            bool abortIfBrokenCoastlinesExist,
            bool includeBrokenCoastlines);

        static bool buildCoastlinePolygonSegment(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<const PrimitivisedArea>& primitivisedArea,
            bool currentInside,
            const PointI& currentPoint31,
            bool prevInside,
            const PointI& previousPoint31,
            QVector< PointI >& segmentPoints);

        static bool calculateIntersection(
            const PointI& p1,
            const PointI& p0,
            const AreaI& bbox,
            PointI& pX);

        static void appendCoastlinePolygons
            (QList< QVector< PointI > >& closedPolygons,
            QList< QVector< PointI > >& coastlinePolylines,
            QVector< PointI >& polyline);

        static void convertCoastlinePolylinesToPolygons(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<const PrimitivisedArea>& primitivisedArea,
            QList< QVector< PointI > >& coastlinePolylines,
            QList< QVector< PointI > >& coastlinePolygons);

        static bool isClockwiseCoastlinePolygon(const QVector< PointI > & polygon);

        static void obtainPrimitives(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<PrimitivisedArea>& primitivisedArea,
            const QList< std::shared_ptr<const OsmAnd::MapObject> >& source,
#ifdef Q_COMPILER_RVALUE_REFS
            MapStyleEvaluationResult&& evaluationResult,
#else
            MapStyleEvaluationResult& evaluationResult,
#endif // Q_COMPILER_RVALUE_REFS
            const std::shared_ptr<Cache>& cache,
            const IQueryController* const controller,
            Primitiviser_Metrics::Metric_primitivise* const metric);

        static std::shared_ptr<const PrimitivesGroup> obtainPrimitivesGroup(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<PrimitivisedArea>& primitivisedArea,
            const std::shared_ptr<const MapObject>& mapObject,
#ifdef Q_COMPILER_RVALUE_REFS
            MapStyleEvaluationResult&& evaluationResult,
#else
            MapStyleEvaluationResult& evaluationResult,
#endif // Q_COMPILER_RVALUE_REFS
            MapStyleEvaluator& orderEvaluator,
            MapStyleEvaluator& polygonEvaluator,
            MapStyleEvaluator& polylineEvaluator,
            MapStyleEvaluator& pointEvaluator,
            Primitiviser_Metrics::Metric_primitivise* const metric);

        static void sortAndFilterPrimitives(
            const std::shared_ptr<PrimitivisedArea>& primitivisedArea);

        static void filterOutHighwaysByDensity(
            const std::shared_ptr<PrimitivisedArea>& primitivisedArea);

        static void obtainPrimitivesSymbols(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<PrimitivisedArea>& primitivisedArea,
#ifdef Q_COMPILER_RVALUE_REFS
            MapStyleEvaluationResult&& evaluationResult,
#else
            MapStyleEvaluationResult& evaluationResult,
#endif // Q_COMPILER_RVALUE_REFS
            const std::shared_ptr<Cache>& cache,
            const IQueryController* const controller);

        static void collectSymbolsFromPrimitives(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<const PrimitivisedArea>& primitivisedArea,
            const PrimitivesCollection& primitives,
            const PrimitivesType type,
#ifdef Q_COMPILER_RVALUE_REFS
            MapStyleEvaluationResult&& evaluationResult,
#else
            MapStyleEvaluationResult& evaluationResult,
#endif // Q_COMPILER_RVALUE_REFS
            SymbolsCollection& outSymbols,
            const IQueryController* const controller);

        static void obtainSymbolsFromPolygon(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<const PrimitivisedArea>& primitivisedArea,
            const std::shared_ptr<const Primitive>& primitive,
#ifdef Q_COMPILER_RVALUE_REFS
            MapStyleEvaluationResult&& evaluationResult,
#else
            MapStyleEvaluationResult& evaluationResult,
#endif // Q_COMPILER_RVALUE_REFS
            SymbolsCollection& outSymbols);

        static void obtainSymbolsFromPolyline(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<const PrimitivisedArea>& primitivisedArea,
            const std::shared_ptr<const Primitive>& primitive,
#ifdef Q_COMPILER_RVALUE_REFS
            MapStyleEvaluationResult&& evaluationResult,
#else
            MapStyleEvaluationResult& evaluationResult,
#endif // Q_COMPILER_RVALUE_REFS
            SymbolsCollection& outSymbols);

        static void obtainSymbolsFromPoint(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<const PrimitivisedArea>& primitivisedArea,
            const std::shared_ptr<const Primitive>& primitive,
#ifdef Q_COMPILER_RVALUE_REFS
            MapStyleEvaluationResult&& evaluationResult,
#else
            MapStyleEvaluationResult& evaluationResult,
#endif // Q_COMPILER_RVALUE_REFS
            SymbolsCollection& outSymbols);

        static void obtainPrimitiveTexts(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<const PrimitivisedArea>& primitivisedArea,
            const std::shared_ptr<const Primitive>& primitive,
            const PointI& location,
#ifdef Q_COMPILER_RVALUE_REFS
            MapStyleEvaluationResult&& evaluationResult,
#else
            MapStyleEvaluationResult& evaluationResult,
#endif // Q_COMPILER_RVALUE_REFS
            SymbolsCollection& outSymbols);

        static void obtainPrimitiveIcon(
            const std::shared_ptr<const MapPresentationEnvironment>& env,
            const std::shared_ptr<const Primitive>& primitive,
            const PointI& location,
#ifdef Q_COMPILER_RVALUE_REFS
            MapStyleEvaluationResult&& evaluationResult,
#else
            MapStyleEvaluationResult& evaluationResult,
#endif // Q_COMPILER_RVALUE_REFS
            SymbolsCollection& outSymbols);
    public:
        ~Primitiviser_P();

        ImplementationInterface<Primitiviser> owner;

        std::shared_ptr<const PrimitivisedArea> primitiviseWithCoastlines(
            const AreaI area31,
            const PointI sizeInPixels,
            const ZoomLevel zoom,
            const MapFoundationType foundation,
            const QList< std::shared_ptr<const MapObject> >& objects,
            const std::shared_ptr<Cache>& cache,
            const IQueryController* const controller,
            Primitiviser_Metrics::Metric_primitivise* const metric);

        std::shared_ptr<const PrimitivisedArea> primitiviseWithoutCoastlines(
            const ZoomLevel zoom,
            const QList< std::shared_ptr<const MapObject> >& objects,
            const std::shared_ptr<Cache>& cache,
            const IQueryController* const controller,
            Primitiviser_Metrics::Metric_primitivise* const metric);

    friend class OsmAnd::Primitiviser;
    };
}

#endif // !defined(_OSMAND_CORE_PRIMITIVISER_P_H_)
