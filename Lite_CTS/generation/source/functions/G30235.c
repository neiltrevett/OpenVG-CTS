/*------------------------------------------------------------------------------
Copyright (c) 2008 The Khronos Group Inc.

All Rights Reserved.  This code is protected by copyright laws and contains
material proprietary to the Khronos Group, Inc.  This is UNPUBLISHED
PROPRIETARY SOURCE CODE that may not be disclosed in whole or in part to third
parties, and may not be reproduced, republished, distributed, transmitted,
displayed, broadcast or otherwise exploited in any manner without the express
prior written permission of Khronos Group.

The receipt or possession of this code does not convey any rights to reproduce,
disclose, or distribute its contents, or to manufacture, use, or sell anything
that it may describe, in whole or in part other than under the terms of the
Khronos Adopters Agreement or Khronos Conformance Test Source License Agreement
as executed between Khronos and the recipient.

For the avoidance of doubt, this code when provided: a) under the Khronos
Conformance Test Source License Agreement is for the sole purpose of creating
conformance tests for delivery to Khronos and does not provide for formally
testing products or use of Khronos trademarks on conformant products; b) under
the Khronos Adopters Agreement is for the sole purpose of formally
administering tests to products pursuant to the Khronos Conformance Process
Document.

Khronos, OpenKODE, OpenVG, OpenWF, glFX, OpenMAX and OpenSL ES are trademarks
of the Khronos Group Inc.  COLLADA is a trademark of Sony Computer
Entertainment Inc. used by permission by Khronos.  OpenGL and OpenML are
registered trademarks and the OpenGL ES logo is a trademark of Silicon Graphics
Inc. used by permission by Khronos. 

Use, duplication or disclosure by the Government is subject to restrictions as
set forth in subdivision (c)(1)(ii) of the Rights in Technical Data and
Computer Software clause at DFARS 252.227-7013, and/or in similar or successor
clauses in the FAR, DOD or NASA FAR Supplement. Unpublished rights reserved
under the Copyright Laws of the United States and other countries.
------------------------------------------------------------------------------*/

#include "../main.h"
#include "../util/util.h"

CT_Result G30235_PathStroking_by_ATI (CT_File *AnsFile)
{
    VGPaint fillpaint;
    VGPaint strokepaint;

 VGPath path158;
 VGubyte  path158cmd[]={ /* 3 segments */
   VG_MOVE_TO_ABS    , VG_CUBIC_TO_ABS   , VG_CUBIC_TO_ABS   };
 VGfloat path158coord[]={ /* 14 coordinates */
     2.860000e+001f,   1.752010e+002f,   2.860000e+001f,   1.752010e+002f,   1.340000e+001f,   1.800010e+002f,
     2.980000e+001f,   1.896010e+002f,   2.980000e+001f,   1.896010e+002f,   1.540000e+001f,   2.056010e+002f,
     1.740000e+001f,   2.196010e+002f};

 VGPath path159;
 VGubyte  path159cmd[]={ /* 4 segments */
   VG_MOVE_TO_ABS    , VG_CUBIC_TO_ABS   , VG_CUBIC_TO_ABS   ,
   VG_CLOSE_PATH     };
 VGfloat path159coord[]={ /* 14 coordinates */
     0.000000e+000f,   2.000000e+000f,   0.000000e+000f,   2.000000e+000f,   0.000000e+000f,   2.000000e+000f,
     0.000000e+000f,   2.000000e+000f,   4.000000e+000f,   1.000000e+001f,   8.000000e+000f,   0.000000e+000f,
     3.000000e+000f,  -2.000000e+000f};

 VGPath path160;
 VGubyte  path160cmd[]={ /* 3 segments */
   VG_MOVE_TO_ABS    , VG_CUBIC_TO_ABS   , VG_CUBIC_TO_ABS   };
 VGfloat path160coord[]={ /* 14 coordinates */
     0.000000e+000f,   2.000000e+000f,   0.000000e+000f,   2.000000e+000f,   0.000000e+000f,   2.000000e+000f,
     0.000000e+000f,   2.000000e+000f,   4.000000e+000f,   1.000000e+001f,   8.000000e+000f,   0.000000e+000f,
     3.000000e+000f,  -2.000000e+000f};


    VGfloat matrix[9];
    VGfloat defaultColor[] = {1.0f, 1.0f, 1.0f, 1.0f};/*clear color */                

    path158=vgCreatePath(VG_PATH_FORMAT_STANDARD,VG_PATH_DATATYPE_F, 1.0000f,0.0000f, 0,0, (unsigned int)VG_PATH_CAPABILITY_APPEND_TO);
    vgAppendPathData(path158,sizeof(path158cmd)/sizeof(VGubyte),path158cmd,path158coord);
    path159=vgCreatePath(VG_PATH_FORMAT_STANDARD,VG_PATH_DATATYPE_F, 1.0000f,0.0000f, 0,0, (unsigned int)VG_PATH_CAPABILITY_APPEND_TO);
    vgAppendPathData(path159,sizeof(path159cmd)/sizeof(VGubyte),path159cmd,path159coord);
    path160=vgCreatePath(VG_PATH_FORMAT_STANDARD,VG_PATH_DATATYPE_F, 1.0000f,0.0000f, 0,0, (unsigned int)VG_PATH_CAPABILITY_APPEND_TO);
    vgAppendPathData(path160,sizeof(path160cmd)/sizeof(VGubyte),path160cmd,path160coord);

    if ( path158 == VG_INVALID_HANDLE )
        return CT_ERROR;
    if ( path159 == VG_INVALID_HANDLE )
        return CT_ERROR;
    if ( path160 == VG_INVALID_HANDLE )
        return CT_ERROR;

    fillpaint = vgCreatePaint();
    if ( fillpaint == VG_INVALID_HANDLE )
        return CT_ERROR;
    vgSetParameteri(fillpaint, VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR);
    vgSetParameterfv(fillpaint, VG_PAINT_COLOR, 4, defaultColor);
    strokepaint = vgCreatePaint();
    if ( strokepaint == VG_INVALID_HANDLE )
        return CT_ERROR;
    vgSetParameteri(strokepaint, VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR);
    vgSetParameterfv(strokepaint, VG_PAINT_COLOR, 4, defaultColor);

    vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
    vgLoadMatrix(matrix);

    vgSetfv(VG_CLEAR_COLOR, 4, defaultColor);
    vgClear(0, 0, WINDSIZEX, WINDSIZEY);
    vgSeti(VG_RENDERING_QUALITY, VG_RENDERING_QUALITY_NONANTIALIASED);

   
  matrix[0]=   1.000000e+000f; matrix[1]=   0.000000e+000f; matrix[2]=   0.000000e+000f;
  matrix[3]=   0.000000e+000f; matrix[4]=   1.000000e+000f; matrix[5]=   0.000000e+000f;
  matrix[6]=  -1.200000e+001f; matrix[7]=  -1.700000e+002f; matrix[8]=   1.000000e+000f;
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgLoadMatrix(matrix);
  vgSetColor(strokepaint,0x0000FFFF);
  vgSetPaint(strokepaint, VG_STROKE_PATH);
  vgSetf(VG_STROKE_LINE_WIDTH,4.0000f);
  vgSetf(VG_STROKE_MITER_LIMIT,4.0000f);
  vgSeti(VG_STROKE_CAP_STYLE,VG_CAP_BUTT  );
  vgSeti(VG_STROKE_JOIN_STYLE,VG_JOIN_MITER);
  vgDrawPath(path158,VG_STROKE_PATH);
  
  matrix[0]=   4.000000e+000f; matrix[1]=   0.000000e+000f; matrix[2]=   0.000000e+000f;
  matrix[3]=   0.000000e+000f; matrix[4]=   4.000000e+000f; matrix[5]=   0.000000e+000f;
  matrix[6]=   1.600000e+001f; matrix[7]=   3.800000e+001f; matrix[8]=   1.000000e+000f;
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgLoadMatrix(matrix);
  vgSetColor(strokepaint,0xFF0000FF);
  vgSetPaint(strokepaint, VG_STROKE_PATH);
  vgSetf(VG_STROKE_LINE_WIDTH,2.0000f);
  vgSetf(VG_STROKE_MITER_LIMIT,4.0000f);
  vgSeti(VG_STROKE_CAP_STYLE,VG_CAP_BUTT  );
  vgSeti(VG_STROKE_JOIN_STYLE,VG_JOIN_MITER);
  vgDrawPath(path159,VG_STROKE_PATH);
  
  matrix[0]=   4.000000e+000f; matrix[1]=   0.000000e+000f; matrix[2]=   0.000000e+000f;
  matrix[3]=   0.000000e+000f; matrix[4]=   4.000000e+000f; matrix[5]=   0.000000e+000f;
  matrix[6]=   3.700000e+001f; matrix[7]=   1.200000e+001f; matrix[8]=   1.000000e+000f;
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgLoadMatrix(matrix);
  vgSetColor(strokepaint,0xFF0000FF);
  vgSetPaint(strokepaint, VG_STROKE_PATH);
  vgSetf(VG_STROKE_LINE_WIDTH,2.0000f);
  vgSetf(VG_STROKE_MITER_LIMIT,4.0000f);
  vgSeti(VG_STROKE_CAP_STYLE,VG_CAP_BUTT  );
  vgSeti(VG_STROKE_JOIN_STYLE,VG_JOIN_MITER);
  vgDrawPath(path160,VG_STROKE_PATH);

  vgDestroyPath(path158);
  vgDestroyPath(path159);
  vgDestroyPath(path160);

    vgDestroyPaint(fillpaint);
    vgDestroyPaint(strokepaint);

    if (vgGetError() == VG_NO_ERROR) {
        DISPLAY_TEST_BUFFER();    
        return CT_NO_ERROR;
    }
    else {
        return CT_ERROR;
    }
}

