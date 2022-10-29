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
///   File: curve.hpp
///
/// Author: $author$
///   Date: 7/16/2016
///
/// LibRaw based implementation of gamma curve C++ template
///////////////////////////////////////////////////////////////////////
#ifndef _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_GAMMA_LIBRAW_CURVE_HPP
#define _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_GAMMA_LIBRAW_CURVE_HPP

#include "lamna/base/base.hpp"
#include <math.h>

namespace lamna {
namespace graphic {
namespace image {
namespace format {
namespace raw {
namespace gamma {
namespace libraw {

typedef unsigned short curve_sample_t;
typedef unsigned long curve_samples_size_t;
enum { curve_samples_size = 0x10000};

typedef implement_base curve_implements;
typedef base curve_extends;
///////////////////////////////////////////////////////////////////////
///  Class: curvet
///////////////////////////////////////////////////////////////////////
template
<typename TSample = curve_sample_t,
 typename TSamplesSize = curve_samples_size_t,
 TSamplesSize VSamplesSize = curve_samples_size,
 class TImplements = curve_implements, class TExtends = curve_extends>

class _EXPORT_CLASS curvet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TSample sample_t;
    typedef TSamplesSize samples_size_t;
    enum { samples_size = VSamplesSize };
    typedef sample_t samples_t[samples_size];
    enum { parameters_size = 6 };
    typedef double parameters_t[parameters_size];
    typedef int mode_t;
    enum {
        mode_parameters   = 0,
        mode_to_linear    = 1,
        mode_to_nonlinear = 2
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    curvet
    (double pwr, double ts, sample_t imax, mode_t mode = mode_to_nonlinear) {
        generate(pwr, ts, imax, mode);
    }
    curvet() {
    }
    virtual ~curvet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual curvet generate
    (double pwr, double ts, sample_t imax, mode_t mode = mode_to_nonlinear) {
        parameters_t g = {pwr, ts, 0, 0, 0, 0};
        double bnd[2] = {0, 0}, r = 0;
        int i = 0;

        bnd[g[1] >= 1] = 1;

        if (g[1] && (g[1]-1)*(g[0]-1) <= 0) {
          for (i=0; i < 48; i++) {
            g[2] = (bnd[0] + bnd[1])/2;
            if (g[0]) {
                bnd[(pow(g[2]/g[1],-g[0]) - 1)/g[0] - 1/g[2] > -1] = g[2];
            } else {
                bnd[g[2]/exp(1-1/g[2]) < g[1]] = g[2];
            }
          }
          g[3] = g[2] / g[1];
          if (g[0]) {
              g[4] = g[2] * (1/g[0] - 1);
          }
        }
        if (g[0]) {
            g[5] = 1 / (g[1]*sqr(g[3])/2 - g[4]*(1 - g[3]) +
              (1 - pow(g[3],1+g[0]))*(1 + g[4])/(1 + g[0])) - 1;
        } else {
            g[5] = 1 / (g[1]*sqr(g[3])/2 + 1
              - g[2] - g[3] -	g[2]*g[3]*(log(g[3]) - 1)) - 1;
        }
        set_parameters(g);

        if (mode != (mode_parameters)) {
            bool to_nonlinear = (mode != mode_to_linear);

            for (i = 0; i < samples_size; i++) {
              samples_[i] = (samples_size - 1);

              if ((r = (double) i / imax) < 1) {
                    samples_[i] = samples_size * ( (to_nonlinear)
                    ? ((r < g[3]) ? (r*g[1]) : ((g[0]) ? (pow( r,g[0])*(1+g[4])-g[4])    : (log(r)*g[2]+1)))
                    : ((r < g[2]) ? (r/g[1]) : ((g[0]) ? (pow((r+g[4])/(1+g[4]),1/g[0])) : (exp((r-1)/g[2])))));
              }
            }
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual parameters_t& set_parameters(const parameters_t& to) {
        for (int i = 0; i < parameters_size; ++i) {
            parameters_[i] = to[i];
        }
        return parameters_;
    }
    virtual parameters_t& parameters() const {
        return (parameters_t&)parameters_;
    }
    virtual parameters_t& operator >> (parameters_t& to) const {
        for (int i = 0; i < parameters_size; ++i) {
            to[i] = parameters_[i];
        }
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual samples_t& set_samples(const samples_t& to) {
        for (samples_size_t i = 0; i < samples_size; ++i) {
            samples_[i] = to[i];
        }
        return samples_;
    }
    virtual samples_t& samples() const {
        return (samples_t&)samples_;
    }
    virtual samples_t& operator >> (samples_t& to) const {
        for (samples_size_t i = 0; i < samples_size; ++i) {
            to[i] = samples_[i];
        }
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual sample_t& operator[](samples_size_t i) const {
        if ((i >= 0) && (i < samples_size)) {
            return (sample_t&)samples_[i];
        }
        return (sample_t&)samples_[0];
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    inline double sqr(double x) {
        return x*x;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    parameters_t parameters_;
    samples_t samples_;
};
typedef curvet<> curve;

} // namespace libraw 
} // namespace gamma 
} // namespace raw 
} // namespace format 
} // namespace image 
} // namespace graphic 
} // namespace lamna 

#endif // _LAMNA_GRAPHIC_IMAGE_FORMAT_RAW_GAMMA_LIBRAW_CURVET_HPP 
