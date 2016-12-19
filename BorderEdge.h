// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BorderEdge_h
#define BorderEdge_h

#include "ComputedStyleConstants.h"
#include "Color.h"
//#include "wtf/Allocator.h"
#include <assert.h>
#define ASSERT(X) assert(X)

namespace blink {

struct BorderEdge {
//    STACK_ALLOCATED();
public:
    BorderEdge(int edgeWidth, const Color& edgeColor, EBorderStyle edgeStyle, bool edgeIsPresent = true);
    BorderEdge();

    bool hasVisibleColorAndStyle() const;
    bool shouldRender() const;
    bool presentButInvisible() const;
    bool obscuresBackgroundEdge() const;
    bool obscuresBackground() const;
    int usedWidth() const;

    bool sharesColorWith(const BorderEdge& other) const;

    EBorderStyle borderStyle() const  { return static_cast<EBorderStyle>(style); }

    enum DoubleBorderStripe {
        DoubleBorderStripeOuter,
        DoubleBorderStripeInner
    };

    int getDoubleBorderStripeWidth(DoubleBorderStripe) const;

    int width;
    Color color;
    bool isPresent;

private:
    unsigned style: 4; // EBorderStyle
};

} // namespace blink

#endif // BorderEdge_h
