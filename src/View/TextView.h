#ifndef TEXTVIEW_H_HEADER_INCLUDED_AD80E160
#define TEXTVIEW_H_HEADER_INCLUDED_AD80E160
#include "ViewFrame.h"

using cocos2d::CCLabelTTF;
using cocos2d::CCLabelBMFont;

//##ModelId=522B2C2C0328
class TextView : public ViewFrame
{
    //##ModelId=522B2D070321
    Uint8 size;
    //##ModelId=522B2CF60171
    Uint32 color;
    //##ModelId=522B2D200197
    String fontName;
    //##ModelId=522B2D3D01F4
    String content;
    
    // indicate is bitmap font or not
    bool bmfont;

public:
    TextView(CCNode* n) : ViewFrame(n), size(18), color(0xFFFFFFFF),
    content(""), fontName("Arial"), plabel(NULL), pBMlabel(NULL), bmfont(false) {}
    TextView(CCNode* n, String str) : ViewFrame(n), size(18), color(0xFFFFFFFF),
    		content(str), fontName("Arial"), plabel(NULL), pBMlabel(NULL), bmfont(false) {}
    TextView(CCNode* n, String str, bool bm) : ViewFrame(n), size(18), color(0xFFFFFFFF),
    		content(str), fontName("fonts/characters.fnt"), plabel(NULL), pBMlabel(NULL), bmfont(bm) {}
    virtual ~TextView()
    {
        Destory();
    }
    
    inline void SetSize(Uint32 s) { size = s; }
    inline Uint32 GetSize() { return size; }
    inline Uint32 GetColor() { return color; }
    inline void SetColor(Uint32 c) { color = c; }
    inline String GetFont() { return fontName; }
    inline void SetFont(String f) { fontName = f; }
    inline void SetContent(String c)
    {
        content = c;
        
        if (plabel)
            plabel->setString((const char*)content);
    }
    // get content length in character unit, how many characters in content
    inline int GetContentLength()
    {
    	return content.CharNumber();
    }
    
    virtual void Display();
    virtual void Dismiss();
    virtual void Destory();
    
private:
    TextView();
    CCLabelTTF* plabel;
    CCLabelBMFont* pBMlabel;
};

#endif /* TEXTVIEW_H_HEADER_INCLUDED_AD80E160 */
