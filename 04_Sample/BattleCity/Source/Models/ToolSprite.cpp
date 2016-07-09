/* --------------------------------------------------------------------------
 *
 *      File            ToolSprite.cpp
 *      Description     
 *      Ported By       Young-Hwan Mun
 *      Contact         xmsoft77@gmail.com
 * 
 * --------------------------------------------------------------------------
 *      
 *      Copyright (c) 2010-2013 XMSoft. 
 *      Copyright (c) 2012      喆 肖 (12/08/10). All rights reserved.
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

#include "Precompiled.h"
#include "ToolSprite.h"

ToolSprite* ToolSprite::create ( ToolSpriteKind eKind )
{
	ToolSprite*	pRet = new ToolSprite ( );

	if ( pRet && pRet->initWithKind ( eKind ) )
	{
		pRet->autorelease ( );	
	}
	else
	{
		CC_SAFE_DELETE ( pRet );
	}

	return pRet;
}

KDbool ToolSprite::initWithKind ( ToolSpriteKind eKind )
{
	const KDchar*	szFrameName;

    switch ( eKind ) 
	{            
        case eStart	:	szFrameName = "props-start.png";	break;         
        case ePass	:	szFrameName = "props-timer.png";	break;   
		case eLife	:	szFrameName = "props-tank.png";		break; 
		case eSafe	:	szFrameName = "props-protect.png";	break; 
		case eMine	:	szFrameName = "props-tank.png";		break; 
		case eWall	:	szFrameName = "props-protect.png";	break;
    }

	if ( !CCSprite::initWithSpriteFrameName ( szFrameName ) )
	{
		return KD_FALSE;
	}

	m_eKind = eKind;

	return KD_TRUE;
}

ToolSpriteKind ToolSprite::getKind ( KDvoid )
{
	return m_eKind;
}