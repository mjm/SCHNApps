/*******************************************************************************
* SCHNApps                                                                     *
* Copyright (C) 2015, IGG Group, ICube, University of Strasbourg, France       *
*                                                                              *
* This library is free software; you can redistribute it and/or modify it      *
* under the terms of the GNU Lesser General Public License as published by the *
* Free Software Foundation; either version 2.1 of the License, or (at your     *
* option) any later version.                                                   *
*                                                                              *
* This library is distributed in the hope that it will be useful, but WITHOUT  *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License  *
* for more details.                                                            *
*                                                                              *
* You should have received a copy of the GNU Lesser General Public License     *
* along with this library; if not, write to the Free Software Foundation,      *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.           *
*                                                                              *
* Web site: http://cgogn.unistra.fr/                                           *
* Contact information: cgogn@unistra.fr                                        *
*                                                                              *
*******************************************************************************/

#ifndef SCHNAPPS_PLUGIN_POINT_SET_RENDER_MAP_PARAMETERS__H_
#define SCHNAPPS_PLUGIN_POINT_SET_RENDER_MAP_PARAMETERS__H_

#include <schnapps/plugins/point_set_render/dll.h>
#include <schnapps/core/types.h>

#include <QColor>

namespace schnapps
{

namespace plugin_point_set_render
{

class Plugin_PointSetRender;

struct SCHNAPPS_PLUGIN_POINT_SET_RENDER_API MapParameters
{
	friend class Plugin_PointSetRender;

	MapParameters() :
		vertex_color_(190, 85, 168),
		vertex_scale_factor_(1.0f),
		vertex_base_size_(1.0f),
		render_vertices_(false)
	{}

	CGOGN_NOT_COPYABLE_NOR_MOVABLE(MapParameters);
	QColor vertex_color_;
	float32 vertex_scale_factor_;
	float32 vertex_base_size_;
	bool render_vertices_;
};

} // namespace plugin_point_set_render

}// namespace schnapps

#endif SCHNAPPS_PLUGIN_POINT_SET_RENDER_MAP_PARAMETERS__H_
