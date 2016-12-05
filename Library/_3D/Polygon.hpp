/** Kabuki Software Development Kit
    @file    /.../KabukiSDK/_3D/Polygon.hpp
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

#pragma once

#incude <KabukiSDK-Config.hpp>

#include "Point.hpp"

namespace _3D {

class Polygon_f
/*<  */
{
    /**  */   
    Polygon_f (int* indexOfPoints, _3D::Point_f* pointValues, int aNumPoints);
    
    /**  */  
    _3D::Point_f Vertex (int forThisPoint);
    
    /**  */  
    int VertexIndex (int forThisPoint);
    
    /**  */  
    _3D::Point_f getNormal ();
    
    /**  */  
    void computeNormal ();
    
    /**  */  
    double NormalMagnitude ();
    
    /**  */  
    void ScaleNormalMagnitude (double scaleFactor);

    /**  */  
    double getZAverage ();
    
    /**  */  
    void computeZAverge ();

    void print (Terminal io);
    /*< Prints this object to a Terminal. */
    
    private:

    enum {
        FlatShading = 0,        //< Just draws plain triangles.
        Textured
    };

    bool isTwoSided,
            isClipped,
            isActive,
            isVisible;

    _G::Color color,            //< The color of the polygon.
            shade;              //< The shade of the polygon (Need to fix texture mapping.).
       
    int shadingType,            //< The type of shadding: Flat, Textured.
        numVerticies;
    
    double  normalMagnitude,
            zAverage;  

    _3D::Point_f normal;

    _3D::Point_f[] vertexPoint;

    int* vertexIndex;
};

}   //< _3D
