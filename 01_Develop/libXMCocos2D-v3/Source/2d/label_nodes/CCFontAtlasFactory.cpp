/* -----------------------------------------------------------------------------------
 *
 *      File            CCFontAtlasFactory.cpp
 *      Ported By       Young-Hwan Mun
 *      Contact         xmsoft77@gmail.com 
 * 
 * -----------------------------------------------------------------------------------
 *   
 *      Copyright (c) 2010-2014 XMSoft
 *      Copyright (c) 2010-2013 cocos2d-x.org
 *      Copyright (c) 2013      Zynga Inc.
 *
 *         http://www.cocos2d-x.org      
 *
 * -----------------------------------------------------------------------------------
 * 
 *     Permission is hereby granted, free of charge, to any person obtaining a copy
 *     of this software and associated documentation files (the "Software"), to deal
 *     in the Software without restriction, including without limitation the rights
 *     to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *     copies of the Software, and to permit persons to whom the Software is
 *     furnished to do so, subject to the following conditions:
 *
 *     The above copyright notice and this permission notice shall be included in
 *     all copies or substantial portions of the Software.
 *     
 *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *     IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *     AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *     LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *     THE SOFTWARE.
 *
 * --------------------------------------------------------------------------------- */ 

#include "2d/label_nodes/CCFontAtlasFactory.h"
#include "2d/label_nodes/CCFontFNT.h"

// carloX this NEEDS to be changed
#include "2d/label_nodes/CCLabelBMFont.h"

NS_CC_BEGIN

FontAtlas * FontAtlasFactory::createAtlasFromTTF(const char* fntFilePath, int fontSize, GlyphCollection glyphs, const char *customGlyphs)
{
    
    Font *font = Font::createWithTTF(fntFilePath, fontSize, glyphs, customGlyphs);
    if (font)
        return font->createFontAtlas();
    else
        return nullptr;
}

FontAtlas * FontAtlasFactory::createAtlasFromFNT(const char* fntFilePath)
{
    Font *font = Font::createWithFNT(fntFilePath);
    
    if(font)
    {
        FontAtlas * atlas = font->createFontAtlas();
        return atlas;
    }
    else
    {
        return nullptr;
    }
}

NS_CC_END