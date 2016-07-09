/* --------------------------------------------------------------------------
 *
 *      File            Ship.h
 *      Author          Y.H Mun
 * 
 * --------------------------------------------------------------------------
 *   
 *      Copyright (c) 2010-2012 cocos2d-x.org
 *      Copyright (c) 2012      Shengxiang Chen, Dingping Lv ( Licensed under GPL )
 *
 *         http://www.cocos2d-x.org  
 *         https://github.com/ShengxiangChen/MoonWarriors   
 *
 * --------------------------------------------------------------------------
 *      
 *      Copyright (c) 2010-2012 XMSoft. All rights reserved.
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

#ifndef __Ship_h__
#define __Ship_h__

#include "Global.h"

class Ship : public Sprite
{
	public :

		Ship ( KDvoid );

		CREATE_FUNC ( Ship );

	public :

		virtual KDbool  init ( KDvoid );

		virtual KDvoid  destroy ( KDvoid );

		virtual KDvoid  update ( KDfloat fDelta );

		virtual KDvoid  hurt ( KDvoid );

		virtual CCRect  collideRect ( KDvoid );

		virtual KDbool  active ( KDvoid );

	protected :

		KDvoid  onMakeBeAttack ( CCNode* pSender );

		KDvoid  onShoot ( KDfloat fDelta );

	private :

		KDint		m_nSpeed;
		KDfloat		m_fBulletSpeed;
		KDint		m_nHP;
		KDint		m_nBulletTypeValue;
		KDint		m_nBulletPowerValue;
		KDbool		m_bThworBombing;
		KDbool		m_bCanBeAttack;
		KDbool		m_bIsThrowingBomb;
		KDint		m_nMaxBulletPowerValue;
		KDint		m_nHurtColorLife;
		KDbool		m_bActive;
		KDfloat		m_fTimeTick;
};

#endif // __Ship_h__