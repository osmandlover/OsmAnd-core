/**
 * @file
 *
 * @section LICENSE
 *
 * OsmAnd - Android navigation software based on OSM maps.
 * Copyright (C) 2010-2013  OsmAnd Authors listed in AUTHORS file
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _OSMAND_CORE_MAP_RENDERER_SETUP_OPTIONS_H_
#define _OSMAND_CORE_MAP_RENDERER_SETUP_OPTIONS_H_

#include <cstdint>
#include <memory>
#include <functional>
#include <array>

#include <OsmAndCore/QtExtensions.h>

#include <OsmAndCore.h>
#include <OsmAndCore/CommonTypes.h>

namespace OsmAnd {

    struct OSMAND_CORE_API MapRendererSetupOptions
    {
        MapRendererSetupOptions();
        ~MapRendererSetupOptions();

        typedef std::function<void ()> FrameRequestCallback;

        typedef std::function<void ()> BackgroundWorkerPrologue;
        typedef std::function<void ()> BackgroundWorkerEpilogue;

        struct {
            bool enabled;
            BackgroundWorkerPrologue prologue;
            BackgroundWorkerEpilogue epilogue;
        } backgroundWorker;

        FrameRequestCallback frameRequestCallback;

        float displayDensityFactor;
    };

}

#endif // _OSMAND_CORE_MAP_RENDERER_SETUP_OPTIONS_H_
