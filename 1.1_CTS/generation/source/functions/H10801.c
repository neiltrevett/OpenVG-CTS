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

CT_Result H10801_ImageOperation_by_HUONE (CT_File *AnsFile)               
{
    VGImage image;
    VGfloat clearColor[] = {0.0f, 0.0f, 0.0f, 0.0f};/* black color */                       
    VGfloat redColor[] = {1.0f, 0.0f, 0.0f, 1.0f};/* red color */
    VGuint *data;

    vgSetfv(VG_CLEAR_COLOR, 4, redColor);
    vgClear(0, 0, WINDSIZEX, WINDSIZEY);
    
    vgSeti(VG_RENDERING_QUALITY, VG_RENDERING_QUALITY_NONANTIALIASED);
    vgSeti(VG_MATRIX_MODE, VG_MATRIX_IMAGE_USER_TO_SURFACE);
    vgLoadIdentity();

    data = (VGuint *)MALLOC(sizeof(VGuint)*WINDSIZEX*WINDSIZEY);
    if(!data)
        return CT_ERROR;
    
    MEMSET(data, 0x00000000, WINDSIZEX*WINDSIZEY*sizeof(VGuint));
    vgReadPixels(data, 4*WINDSIZEX, VG_sRGBA_8888, -32, -32, 64, 64);
    
    image  = vgCreateImage( VG_sRGBA_8888, 64, 64, VG_IMAGE_QUALITY_NONANTIALIASED );
    if ( image == VG_INVALID_HANDLE )
        return CT_ERROR;
        
    vgImageSubData(image, data, 4*WINDSIZEX, VG_sRGBA_8888, 0, 0, 64, 64);

    vgSetfv(VG_CLEAR_COLOR, 4, clearColor);
    vgClear(0, 0, WINDSIZEX, WINDSIZEY);
    
    vgDrawImage(image);
   
    vgDestroyImage(image);

    FREE(data);
    
    if ( vgGetError() == VG_NO_ERROR)
        return SaveImageFile(0, 0, WINDSIZEX, WINDSIZEY, AnsFile);
    else
        return CT_ERROR;
}


