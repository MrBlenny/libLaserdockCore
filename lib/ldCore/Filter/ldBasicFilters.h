/**
    libLaserdockCore
    Copyright(c) 2018 Wicked Lasers

    This file is part of libLaserdockCore.

    libLaserdockCore is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libLaserdockCore is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libLaserdockCore.  If not, see <https://www.gnu.org/licenses/>.
**/

#ifndef LDBASICFILTERS_H
#define LDBASICFILTERS_H

#include "ldCore/ldCore_global.h"
#include "ldCore/Utilities/ldBasicDataStructures.h"

#include "ldFilter.h"

// ---------- ldColorCurveFilter ----------

class LDCORESHARED_EXPORT ldColorCurveFilter : ldFilter {
public:
    explicit ldColorCurveFilter();

    virtual void process(Vertex &v) override;

    bool m_enabled = false;

    ldColorCurve curveR, curveG, curveB;

    bool blackUseTHold = false; // deprecated and can be removed?
};


// ---------- ldHueFilter ----------

class LDCORESHARED_EXPORT ldHueFilter : public ldFilter {
public:
    virtual void process(Vertex &input) override;
    virtual QString name() override { return QObject::tr("Custom hue basic"); }

    bool m_enabled = false;
    float m_value = 0;
};


// ---------- ldHueMatrixFilter ----------

class LDCORESHARED_EXPORT ldHueMatrixFilter : public ldFilter
{
public:
    virtual void process(Vertex &input) override;

    bool m_enabled = false;
    float m_value = 0.5f; // 0to1

private:
    float c1r, c1g, c1b, c2r, c2g, c2b, c3r, c3g, c3b;
    float m_last = -1.0f;
};


// ---------- ldHueShiftFilter ----------

class LDCORESHARED_EXPORT ldHueShiftFilter : public ldFilter
{
public:
    virtual void process(Vertex &input) override;

    bool m_enabled = false;
    float m_value = 0.5f; // 0to1
};


// ---------- ldRotateFilter ----------

class LDCORESHARED_EXPORT ldRotateFilter : public ldFilter
{
public:
    virtual void process(Vertex &input) override;

    bool m_enabled = true;
    float degCW = 0.f;
};


// ---------- LdTracerFilter ----------

// tracer adds a dashed line to black areas
class LDCORESHARED_EXPORT ldTracerFilter : public ldFilter
{
public:
    virtual QString name() override { return "Debug Trace"; }
    virtual void process(Vertex &input) override;

    bool m_enabled = false;
};

// ---------- ldScaleFilter ----------

const float DEFAULT_MAX_SCALE_VALUE = 1.f;
const float DEFAULT_RELATIVE_SCALE_VALUE = 0.5f;

class LDCORESHARED_EXPORT ldScaleFilter : ldFilter {
public:
    explicit ldScaleFilter();

    void setRelativeScale(float value);

    void setMaxXScale(float value);
    void setMaxYScale(float value);

    float xScale() const;
    float yScale() const;

    // ldFilter
    virtual void process(Vertex &v) override;

private:
    float m_maxX = DEFAULT_MAX_SCALE_VALUE;
    float m_maxY = DEFAULT_MAX_SCALE_VALUE;

    float m_relative = DEFAULT_RELATIVE_SCALE_VALUE;
};



#endif // LDBASICFILTERS_H
