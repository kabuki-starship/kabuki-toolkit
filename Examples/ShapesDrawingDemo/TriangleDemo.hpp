/** Kabuki Card Games
    @file    /.../KabukiSDK-Examples/ShapesDrawingDemo/TrangleDemo.hpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2016 [Cale McCollough](calemccollough.github.io)

                            All right reserved (R).

        Licensed under the Apache License, Version 2.0 (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

                    http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#include <BaloonTest.hpp>

namespace KabukiSDKExamples {

class TriangleDemo: public _App::App
{  
    int clipMinX, clipMinY, clipMaxX, clipMaxY;
    
    TriangleDemo ();
    
    void draw (_G::Cell& C);
    
    void drawTriangle (_G::Cell& C, _G::Color_i color, _2D::Point one, _2D::Point two, _2D::Point three);
    
    void drawTopTriangle (_G::Cell& C, _G::Color_i color, _2D::Point one, _2D::Point two, _2D::Point three);
    
    // 
    void drawBottomTriangle (_G::Cell& C, _G::Color_i color, _2D::Point one, _2D::Point two, _2D::Point three);
    
    class ClickListener: public _G::event.MouseListener
    {
        void mousePressed (_G::event.MouseEvent event)
        {
            repaint();
        }
      
      void mouseClicked  (_G::event.MouseEvent event)   {}
      void mouseReleased (_G::event.MouseEvent event )  {}
      void mouseEntered  (_G::event.MouseEvent event )  {}
      void mouseExited   (_G::event.MouseEvent event )  {}
    }
};

}   //< KabukiSDKExamples
