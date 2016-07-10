/* --------------------------------------------------------------------------
 *
 *      File            InputLayer.h
 *      Description     
 *      Ported By       Young-Hwan Mun
 *      Contact         xmsoft77@gmail.com
 * 
 * --------------------------------------------------------------------------
 *      
 *      Copyright (c) 2010-2013 XMSoft. 
 *      Copyright (c) 2012      喆 肖 (12/07/13). All rights reserved.
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

#ifndef __InputLayer_h__
#define __InputLayer_h__

#include "../SneakyInput/SneakyButton.h"
#include "../SneakyInput/SneakyJoystick.h"

class MapLayer;

class InputLayer : public CCLayer 
{ 
	public :

		static InputLayer*		create ( KDvoid );

	public :

		virtual KDbool			init ( KDvoid );

		KDvoid					setMapLayer ( MapLayer* pLayer );

	private :

		virtual KDvoid			update ( KDfloat fDelta );

		KDvoid					addFireButton ( KDvoid );

		KDvoid					addJoystick ( KDvoid );

	private :

		SneakyButton*			m_pFireButton;
		SneakyJoystick*			m_pJoystick;    
		MapLayer*				m_pMapLayer;
};

#endif	// __InputLayer_h__