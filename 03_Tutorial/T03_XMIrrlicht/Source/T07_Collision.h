/* --------------------------------------------------------------------------
 *
 *      File            T07_Collision.h
 *      Author          Y.H Mun
 * 
 * --------------------------------------------------------------------------
 *      
 *      Copyright (C) 2010-2012 XMSoft. All rights reserved.
 * 
 *      Contact Email: xmsoft77@gmail.com 
 *                     
 * --------------------------------------------------------------------------
 * 
 *      This library is free software; you can redistribute it and/or
 *      modify it under the terms of the GNU Lesser General Public
 *      License as published by the Free Software Foundation; either
 *      version 2 of the License, or (at your option) any later version.
 * 
 *      This library is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *      Lesser General Public License for more details.
 * 
 *      You should have received a copy of the GNU Lesser General Public
 *      License along with this library in the file COPYING.LIB;
 *      if not, write to the Free Software Foundation, Inc.,
 *      59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 *
 * -------------------------------------------------------------------------- */

#ifndef __T07_Collision_h__
#define __T07_Collision_h__

enum
{
	// I use this ISceneNode ID to indicate a scene node that is
	// not pickable by getSceneNodeAndCollisionPointFromRay()
	ID_IsNotPickable = 0,

	// I use this flag in ISceneNode IDs to indicate that the
	// scene node can be picked by ray selection.
	IDFlag_IsPickable = 1 << 0,

	// I use this flag in ISceneNode IDs to indicate that the
	// scene node can be highlighted.  In this example, the
	// homonids can be highlighted, but the level mesh can't.
	IDFlag_IsHighlightable = 1 << 1
};

class CT07_Collision : public CTutorial
{
	public :
	
		CT07_Collision ( KDvoid );

		virtual ~CT07_Collision ( KDvoid );

	public :

		virtual KDvoid  Draw ( KDvoid );

		virtual const wchar_t*  getTitle ( KDvoid );

		virtual KDbool  getVirPad ( KDvoid );

	private :

		scene::ICameraSceneNode*		m_pCamera;
		scene::IBillboardSceneNode*		m_pBill;
		video::SMaterial				m_tMaterial;
		scene::ISceneNode*				m_pHighlightedSceneNode;
		scene::ISceneCollisionManager*  m_pColMgr;
};

#endif