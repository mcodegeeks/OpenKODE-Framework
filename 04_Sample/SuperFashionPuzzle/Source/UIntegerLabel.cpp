/* --------------------------------------------------------------------------
 *
 *      File            UIntegerLabel.cpp
 *
 *      Ported By       Young-Hwan Mun
 *      Contact         xmsoft77@gmail.com 
 * 
 * --------------------------------------------------------------------------
 *      
 *      Copyright (c) 2010-2013 XMSoft. 
 *      Copyright (c) 2010      Ricardo Ruiz López, 2010. All rights reserved.
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
#include "UIntegerLabel.h"

UIntegerLabel* UIntegerLabel::create ( KDvoid )
{
	UIntegerLabel*	pRet = new UIntegerLabel ( );

	if ( pRet && pRet->init ( ) )
	{
		pRet->autorelease ( );
	}
	else
	{
		CC_SAFE_DELETE ( pRet );
	}

	return pRet;
}

UIntegerLabel* UIntegerLabel::create ( KDfloat fFontSize, KDint nOffset, const KDchar* szFontName, const ccColor3B& tForegroundColor, const ccColor3B& tBackgroundColor )
{
	UIntegerLabel*	pRet = new UIntegerLabel ( );

	if ( pRet && pRet->initWithFontSize ( fFontSize, nOffset, szFontName, tForegroundColor, tBackgroundColor ) )
	{
		pRet->autorelease ( );
	}
	else
	{
		CC_SAFE_DELETE ( pRet );
	}

	return pRet;
}

KDbool UIntegerLabel::init ( KDvoid )
{
	return this->initWithFontSize ( 30, 2, "Helvetica.ttf", ccBLACK, ccWHITE );
}

KDbool UIntegerLabel::initWithFontSize ( KDfloat fFontSize, KDint nOffset, const KDchar* szFontName, const ccColor3B& tForegroundColor, const ccColor3B& tBackgroundColor )
{
	if ( !Label::initWithFontSize ( fFontSize, nOffset, szFontName, tForegroundColor, tBackgroundColor ) )
	{
		return KD_FALSE; 
	}

	m_uUnsignedInteger = 0;

	return KD_TRUE;
}

KDuint UIntegerLabel::getUInteger ( KDvoid )
{
	return m_uUnsignedInteger;
}

KDvoid UIntegerLabel::setUInteger ( KDuint uInteger )
{
	m_uUnsignedInteger = uInteger;

	Label::setString ( ccszf ( "%d", uInteger ) );
}
