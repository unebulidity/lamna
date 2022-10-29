///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: key_icon.cpp
///
/// Author: $author$
///   Date: 9/8/2016
///////////////////////////////////////////////////////////////////////
#include "lamna/graphic/surface/shape/key_icon.hpp"

namespace lamna {
namespace graphic {
namespace surface {
namespace shape {

///////////////////////////////////////////////////////////////////////
///  Class: key_icon
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
eError key_icon::Plot(tOffset x, tOffset y) {
    eError error = e_ERROR_NONE;
    tSelectedImage* selectedImage = SurfaceSelectImage(&m_handleColor);
    tSize rWidth = uX*2;
    tSize rHeight = uY*2;
    tSize r2Width = uX/2?uX/2:3;
    tSize r2Height = uY/2?uY/2:3;
    tSize hWidth = uX*4;
    tSize hHeight = uY*4;
    tSize tWidth = uX;
    tSize tHeight = uY*3/2;
    tSize lWidth = uX/4?uX/4:2;
    tSize lHeight = uY/4?uY/4:2;
    tSize i=0,iX=0,iY=0,jX=0,jY=0;

    if ((m_border)) {
        tSize cWidth = m_border+m_borderColor.Width()-2,
              cHeight = m_border+m_borderColor.Height()-2;

        filled_rectangle bcolor
        (surface_image_, m_borderColor, m_border,m_border);

        elliptical_rounded_rectangle brrio
        (surface_image_, bcolor,
         hWidth-cWidth, hHeight-cHeight,
         rWidth+m_border, rHeight+m_border);

        brrio.Plot((iX=x+rWidth-1), (iY=y+rHeight-1));

        filled_rectangle brio
        (surface_image_, bcolor, uX+m_border-cWidth,
         hHeight+m_border+m_border-cHeight);

        brio.Plot(jX=(iX=iX+hWidth+rWidth-2), jY=iY-m_border);

        filled_rectangle brio2
        (surface_image_, bcolor, uX*6+m_border-cWidth,
         tHeight+m_border+m_border-cHeight);

        brio2.Plot(iX+uX, iY+uY*2-tHeight-m_border);

        filled_triangle btior
        (surface_image_, bcolor, 0,0,
         uX+m_border-cWidth,0, 0,tHeight+m_border-cHeight);

        btior.Plot(iX=iX+uX, iY=iY+uY*2);

        filled_triangle btiol
        (surface_image_, bcolor, 0,0,
         uX+m_border-cWidth,0, uX+m_border-cWidth,tHeight+m_border-cHeight);

        for (iX = iX+tWidth, i = 0; i < 3; i++, iX = iX+tWidth+tWidth) {
            btiol.Plot(iX-m_border,iY);
            btior.Plot(iX+tWidth,iY);
        }

        filled_triangle btioe
        (surface_image_, bcolor, 0,0,
         0,tHeight+m_border-cHeight,
         uX+m_border-cWidth,tHeight+m_border-cHeight);

        btioe.Plot(iX=iX-tWidth, iY=iY-tHeight-m_border);
    }
    filled_elliptical_rounded_rectangle rrio
    (surface_image_, m_handleColor, hWidth, hHeight, rWidth, rHeight, 1,
     e_RECTANGLE_CORNER_ALL, e_RECTANGLE_SIDE_TOP
     | e_RECTANGLE_SIDE_RIGHT | e_RECTANGLE_SIDE_BOTTOM);

    hollowed_elliptical_rounded_rectangle rrio2
    (surface_image_, m_handleColor, 1, hHeight-r2Height-r2Height, r2Width, r2Height, 1);

    filled_rectangle hrio
    (surface_image_, m_handleColor, rWidth-r2Width, hHeight);

    filled_rectangle hrio2
    (surface_image_, m_handleColor, hWidth-r2Width, hHeight);

    filled_rectangle hrio3
    (surface_image_, m_lineColor, lWidth, lHeight);

    filled_rectangle rio
    (surface_image_, m_bladeColor, uX, hHeight);

    filled_rectangle rio2
    (surface_image_, m_bladeColor, uX*6, tHeight);

    filled_triangle tior
    (surface_image_, m_bladeColor, 0,0, uX,0, 0,tHeight);

    filled_triangle tiol
    (surface_image_, m_bladeColor, 0,0, uX,0, uX,tHeight);

    filled_triangle tioe
    (surface_image_, m_bladeColor, 0,0, 0,tHeight, uX,tHeight);

    rrio.Plot((iX=x+rWidth-1), (iY=y+rHeight-1));
    rrio2.Plot(iX, iY+r2Height);
    hrio.Plot(x, iY+1);
    hrio2.Plot(iX+r2Width, iY+1);

    rio.Plot(jX=(iX=iX+hWidth+rWidth-2), jY=iY);
    rio2.Plot(iX+uX, iY+uY*2-tHeight);

    tior.Plot(iX=iX+uX, iY=iY+uY*2);
    for (iX = iX+tWidth, i = 0; i < 3; i++, iX = iX+tWidth+tWidth)
    {
        tiol.Plot(iX,iY);
        tior.Plot(iX+tWidth,iY);
    }
    tioe.Plot(iX=iX-tWidth, iY=iY-tHeight);

    surface_image_.SelectImage(&hrio3);

    iX=jX; iY=jY;
    surface_image_.Draw(iX,iY, iX+uX-1,iY);
    surface_image_.Draw(iX+uX-1,iY, iX+uX-1,iY+hHeight-1);
    surface_image_.Draw(iX,iY+hHeight-1, iX+uX-1,iY+hHeight-1);
    surface_image_.Draw(iX+uX,iY+uY*2-tHeight, iX+uX+uX*6-1,iY+uY*2-tHeight);

    iX=iX+uX; iY=iY+uY*2;
    surface_image_.Draw(iX,iY, iX+tWidth-1,iY);
    surface_image_.Draw(iX,iY+tHeight-1, iX+tWidth-1,iY);

    for (iX = iX+tWidth, i = 0; i < 3; i++, iX = iX+tWidth+tWidth)
    {
        surface_image_.Draw(iX,iY, iX+tWidth+tWidth-2,iY);
        surface_image_.Draw(iX,iY, iX+tWidth-1,iY+tHeight-1);
        surface_image_.Draw(iX+tWidth,iY+tHeight-1, iX+tWidth+tWidth-1,iY);
    }
    iX=iX-tWidth; iY=iY-tHeight;
    surface_image_.Draw(iX,iY, iX+tWidth-1,iY+tHeight-1);

    SurfaceSelectImage(selectedImage);
    return error;
}

} // namespace shape 
} // namespace surface 
} // namespace graphic 
} // namespace lamna 
