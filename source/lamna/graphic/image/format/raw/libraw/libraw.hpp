///////////////////////////////////////////////////////////////////////
/// Copyright (C) 2008-2016 LibRaw LLC (http://www.libraw.org, info@libraw.org)
///
/// LibRaw is free software; you can redistribute it and/or modify
/// it under the terms of the one of three licenses as you choose:
///
/// 1. GNU LESSER GENERAL PUBLIC LICENSE version 2.1
///    (See file LICENSE.LGPL provided in LibRaw distribution archive for details).
///
/// 2. COMMON DEVELOPMENT AND DISTRIBUTION LICENSE (CDDL) Version 1.0
///    (See file LICENSE.CDDL provided in LibRaw distribution archive for details).
///
/// 3. LibRaw Software License 27032010
///    (See file LICENSE.LibRaw.pdf provided in LibRaw distribution archive for details).
///
///
/// LibRaw uses code from dcraw.c -- Dave Coffin's raw photo decoder,
/// dcraw.c is copyright 1997-2012 by Dave Coffin, dcoffin a cybercom o net.
///
/// LibRaw uses DCB demosaic and FBDD denoise licensed under BSD-like 3-clause license
/// DCB and FBDD are Copyright (C) 2010,  Jacek Gozdz (cuniek@kft.umcs.lublin.pl)
///
/// LibRaw uses X3F library to unpack Foveon Files, licensed BSD-style license
/// Copyright (c) 2010, Roland Karlsson (roland@proxel.se)
/// All rights reserved.
///
///   File: libraw.hpp
///
/// Author: $author$
///   Date: 3/28/2016
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_LIBRAW_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_LIBRAW_HPP

#include "lamna/base/base.hpp"
#include "xos/base/matrix.hpp"
#include "xos/base/vector.hpp"

#define OLD_INT64 INT64
#undef INT64
#define INT64 RAW_INT64

#define OLD_UINT64 UINT64
#undef UINT64
#define UINT64 RAW_UINT64

#include <libraw/libraw.h>
#include <math.h>

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace raw {
namespace libraw {

typedef libraw_data_t imgdata_t;
typedef libraw_colordata_t colordata_t;
typedef libraw_output_params_t output_params_t;
typedef float color_cmatrix_t[3][4];
typedef ushort curve_t[0x10000];
typedef double gamm_t[6];

typedef double to_rgb_row_t[3];
typedef xos::base::double_vectort<3> to_rgb_vector_t;
typedef xos::base::double_matrixt<3, 3> to_rgb_matrix_t;

class _EXPORT_CLASS gamma {
public:
    ///////////////////////////////////////////////////////////////////////
    /// Function curve
    ///////////////////////////////////////////////////////////////////////
    static void curve
    (curve_t curve, gamm_t gamm, double pwr, double ts, int mode, int imax) {
      int i;
      double g[6], bnd[2]={0,0}, r;

      g[0] = pwr;
      g[1] = ts;
      g[2] = g[3] = g[4] = 0;
      bnd[g[1] >= 1] = 1;
      if (g[1] && (g[1]-1)*(g[0]-1) <= 0) {
        for (i=0; i < 48; i++) {
          g[2] = (bnd[0] + bnd[1])/2;
          if (g[0]) bnd[(pow(g[2]/g[1],-g[0]) - 1)/g[0] - 1/g[2] > -1] = g[2];
          else	bnd[g[2]/exp(1-1/g[2]) < g[1]] = g[2];
        }
        g[3] = g[2] / g[1];
        if (g[0]) g[4] = g[2] * (1/g[0] - 1);
      }
      if (g[0]) g[5] = 1 / (g[1]*sqr(g[3])/2 - g[4]*(1 - g[3]) +
            (1 - pow(g[3],1+g[0]))*(1 + g[4])/(1 + g[0])) - 1;
      else      g[5] = 1 / (g[1]*sqr(g[3])/2 + 1
            - g[2] - g[3] -	g[2]*g[3]*(log(g[3]) - 1)) - 1;
      if (!mode--) {
        memcpy (gamm, g, sizeof gamm);
        return;
      }
      for (i=0; i < 0x10000; i++) {
        curve[i] = 0xffff;
        if ((r = (double) i / imax) < 1)
          curve[i] = 0x10000 * ( mode
        ? (r < g[3] ? r*g[1] : (g[0] ? pow( r,g[0])*(1+g[4])-g[4]    : log(r)*g[2]+1))
        : (r < g[2] ? r/g[1] : (g[0] ? pow((r+g[4])/(1+g[4]),1/g[0]) : exp((r-1)/g[2]))));
      }
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function sqr
    ///////////////////////////////////////////////////////////////////////
    static inline double sqr(double x) {
        return x*x;
    }
};

} // namespace libraw
} // namespace raw 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#undef UINT64
#undef RAW_UINT64
#define UINT64 OLD_UINT64
#undef OLD_UINT64

#undef INT64
#undef RAW_INT64
#define INT64 OLD_INT64
#undef OLD_INT64

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_LIBRAW_LIBRAW_HPP
