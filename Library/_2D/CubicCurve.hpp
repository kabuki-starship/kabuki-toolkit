/*
 * Copyright 1997-2006 Sun Microsystems, Inc.  All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Sun designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Sun in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa Clara,
 * CA 95054 USA or visit www.sun.com if you need additional information or
 * have any questions.
 */

namespace _2D {



/**
* The <code>CubicCurve</code> class defines a cubic parametric curve
* segment in {@code (x,y)} coordinate space.
* <p>
* This class is only the abstract superclass for all objects which
* store a 2D cubic curve segment.
* The actual storage representation of the coordinates is left to
* the subclass.
*
* @author      Jim Graham
* @since 1.2
*/
class CubicCurve
{
    /**
    * This is an abstract class that cannot be instantiated directly.
    * Type-specific implementation subclasses are available for
    * instantiation and provide a number of formats for storing
    * the information necessary to satisfy the various accessor
    * methods below.
    *
    * @see java.awt.geom.CubicCurve.Float
    * @see java.awt.geom.CubicCurve.Double
    * @since 1.2
    */
    protected CubicCurve()
    {
    }

    /**
    * Returns the X coordinate of the start point in double precision.
    * @return the X coordinate of the start point of the
    *         {@code CubicCurve}.
    * @since 1.2
    */
    abstract double getX1();

    /**
    * Returns the Y coordinate of the start point in double precision.
    * @return the Y coordinate of the start point of the
    *         {@code CubicCurve}.
    * @since 1.2
    */
    abstract double getY1();

    /**
    * Returns the start point.
    * @return a {@code Point2D} that is the start point of
    *         the {@code CubicCurve}.
    * @since 1.2
    */
    abstract Point2D getP1();

    /**
    * Returns the X coordinate of the first control point in double precision.
    * @return the X coordinate of the first control point of the
    *         {@code CubicCurve}.
    * @since 1.2
    */
    abstract double getCtrlX1();

    /**
    * Returns the Y coordinate of the first control point in double precision.
    * @return the Y coordinate of the first control point of the
    *         {@code CubicCurve}.
    * @since 1.2
    */
    abstract double getCtrlY1();

    /**
    * Returns the first control point.
    * @return a {@code Point2D} that is the first control point of
    *         the {@code CubicCurve}.
    * @since 1.2
    */
    abstract Point2D getCtrlP1();

    /**
    * Returns the X coordinate of the second control point
    * in double precision.
    * @return the X coordinate of the second control point of the
    *         {@code CubicCurve}.
    * @since 1.2
    */
    abstract double getCtrlX2();

    /**
    * Returns the Y coordinate of the second control point
    * in double precision.
    * @return the Y coordinate of the second control point of the
    *         {@code CubicCurve}.
    * @since 1.2
    */
    abstract double getCtrlY2();

    /**
    * Returns the second control point.
    * @return a {@code Point2D} that is the second control point of
    *         the {@code CubicCurve}.
    * @since 1.2
    */
    abstract Point2D getCtrlP2();

    /**
    * Returns the X coordinate of the end point in double precision.
    * @return the X coordinate of the end point of the
    *         {@code CubicCurve}.
    * @since 1.2
    */
    abstract double getX2();

    /**
    * Returns the Y coordinate of the end point in double precision.
    * @return the Y coordinate of the end point of the
    *         {@code CubicCurve}.
    * @since 1.2
    */
    abstract double getY2();

    /**
    * Returns the end point.
    * @return a {@code Point2D} that is the end point of
    *         the {@code CubicCurve}.
    * @since 1.2
    */
    abstract Point2D getP2();

    /**
    * Sets the location of the end points and control points of this curve
    * to the specified double coordinates.
    *
    * @param x1 the X coordinate used to set the start point
    *           of this {@code CubicCurve}
    * @param y1 the Y coordinate used to set the start point
    *           of this {@code CubicCurve}
    * @param ctrlx1 the X coordinate used to set the first control point
    *               of this {@code CubicCurve}
    * @param ctrly1 the Y coordinate used to set the first control point
    *               of this {@code CubicCurve}
    * @param ctrlx2 the X coordinate used to set the second control point
    *               of this {@code CubicCurve}
    * @param ctrly2 the Y coordinate used to set the second control point
    *               of this {@code CubicCurve}
    * @param x2 the X coordinate used to set the end point
    *           of this {@code CubicCurve}
    * @param y2 the Y coordinate used to set the end point
    *           of this {@code CubicCurve}
    * @since 1.2
    */
    abstract void setCurve(double x1, double y1,
        double ctrlx1, double ctrly1,
        double ctrlx2, double ctrly2,
        double x2, double y2);

    /**
    * Sets the location of the end points and control points of this curve
    * to the double coordinates at the specified offset in the specified
    * array.
    * @param coords a double array containing coordinates
    * @param offset the index of <code>coords</code> from which to begin
    *          setting the end points and control points of this curve
    *          to the coordinates contained in <code>coords</code>
    * @since 1.2
    */
    void setCurve(double[] coords, int offset)
    {
        setCurve(coords[offset + 0], coords[offset + 1],
            coords[offset + 2], coords[offset + 3],
            coords[offset + 4], coords[offset + 5],
            coords[offset + 6], coords[offset + 7]);
    }

    /**
    * Sets the location of the end points and control points of this curve
    * to the specified <code>Point2D</code> coordinates.
    * @param p1 the first specified <code>Point2D</code> used to set the
    *          start point of this curve
    * @param cp1 the second specified <code>Point2D</code> used to set the
    *          first control point of this curve
    * @param cp2 the third specified <code>Point2D</code> used to set the
    *          second control point of this curve
    * @param p2 the fourth specified <code>Point2D</code> used to set the
    *          end point of this curve
    * @since 1.2
    */
    void setCurve(Point2D p1, Point2D cp1, Point2D cp2, Point2D p2)
    {
        setCurve(p1.getX(), p1.getY(), cp1.getX(), cp1.getY(),
            cp2.getX(), cp2.getY(), p2.getX(), p2.getY());
    }

    /**
    * Sets the location of the end points and control points of this curve
    * to the coordinates of the <code>Point2D</code> objects at the specified
    * offset in the specified array.
    * @param pts an array of <code>Point2D</code> objects
    * @param offset  the index of <code>pts</code> from which to begin setting
    *          the end points and control points of this curve to the
    *          points contained in <code>pts</code>
    * @since 1.2
    */
    void setCurve(Point2D[] pts, int offset)
    {
        setCurve(pts[offset + 0].getX(), pts[offset + 0].getY(),
            pts[offset + 1].getX(), pts[offset + 1].getY(),
            pts[offset + 2].getX(), pts[offset + 2].getY(),
            pts[offset + 3].getX(), pts[offset + 3].getY());
    }

    /**
    * Sets the location of the end points and control points of this curve
    * to the same as those in the specified <code>CubicCurve</code>.
    * @param c the specified <code>CubicCurve</code>
    * @since 1.2
    */
    void setCurve(CubicCurve c)
    {
        setCurve(c.getX1(), c.getY1(), c.getCtrlX1(), c.getCtrlY1(),
            c.getCtrlX2(), c.getCtrlY2(), c.getX2(), c.getY2());
    }

    /**
    * Returns the square of the flatness of the cubic curve specified
    * by the indicated control points. The flatness is the maximum distance
    * of a control point from the line connecting the end points.
    *
    * @param x1 the X coordinate that specifies the start point
    *           of a {@code CubicCurve}
    * @param y1 the Y coordinate that specifies the start point
    *           of a {@code CubicCurve}
    * @param ctrlx1 the X coordinate that specifies the first control point
    *               of a {@code CubicCurve}
    * @param ctrly1 the Y coordinate that specifies the first control point
    *               of a {@code CubicCurve}
    * @param ctrlx2 the X coordinate that specifies the second control point
    *               of a {@code CubicCurve}
    * @param ctrly2 the Y coordinate that specifies the second control point
    *               of a {@code CubicCurve}
    * @param x2 the X coordinate that specifies the end point
    *           of a {@code CubicCurve}
    * @param y2 the Y coordinate that specifies the end point
    *           of a {@code CubicCurve}
    * @return the square of the flatness of the {@code CubicCurve}
    *          represented by the specified coordinates.
    * @since 1.2
    */
    static double getFlatnessSq(double x1, double y1, double ctrlx1, double ctrly1, double ctrlx2, double ctrly2, 
        double x2, double y2)
    {
        return max(Line2D.ptSegDistSq(x1, y1, x2, y2, ctrlx1, ctrly1),
            Line2D.ptSegDistSq(x1, y1, x2, y2, ctrlx2, ctrly2));

    }

    /**
    * Returns the flatness of the cubic curve specified
    * by the indicated control points. The flatness is the maximum distance
    * of a control point from the line connecting the end points.
    *
    * @param x1 the X coordinate that specifies the start point
    *           of a {@code CubicCurve}
    * @param y1 the Y coordinate that specifies the start point
    *           of a {@code CubicCurve}
    * @param ctrlx1 the X coordinate that specifies the first control point
    *               of a {@code CubicCurve}
    * @param ctrly1 the Y coordinate that specifies the first control point
    *               of a {@code CubicCurve}
    * @param ctrlx2 the X coordinate that specifies the second control point
    *               of a {@code CubicCurve}
    * @param ctrly2 the Y coordinate that specifies the second control point
    *               of a {@code CubicCurve}
    * @param x2 the X coordinate that specifies the end point
    *           of a {@code CubicCurve}
    * @param y2 the Y coordinate that specifies the end point
    *           of a {@code CubicCurve}
    * @return the flatness of the {@code CubicCurve}
    *          represented by the specified coordinates.
    * @since 1.2
    */
    static double getFlatness(double x1, double y1, double ctrlx1, double ctrly1, double ctrlx2, double ctrly2,
        double x2, double y2) {
        return sqrt(getFlatnessSq(x1, y1, ctrlx1, ctrly1, ctrlx2, ctrly2, x2, y2));
    }

    /**
    * Returns the square of the flatness of the cubic curve specified
    * by the control points stored in the indicated array at the
    * indicated index. The flatness is the maximum distance
    * of a control point from the line connecting the end points.
    * @param coords an array containing coordinates
    * @param offset the index of <code>coords</code> from which to begin
    *          getting the end points and control points of the curve
    * @return the square of the flatness of the <code>CubicCurve</code>
    *          specified by the coordinates in <code>coords</code> at
    *          the specified offset.
    * @since 1.2
    */
    static double getFlatnessSq(double coords[], int offset) {
        return getFlatnessSq(coords[offset + 0], coords[offset + 1],
            coords[offset + 2], coords[offset + 3],
            coords[offset + 4], coords[offset + 5],
            coords[offset + 6], coords[offset + 7]);
    }

    /**
    * Returns the flatness of the cubic curve specified
    * by the control points stored in the indicated array at the
    * indicated index.  The flatness is the maximum distance
    * of a control point from the line connecting the end points.
    * @param coords an array containing coordinates
    * @param offset the index of <code>coords</code> from which to begin
    *          getting the end points and control points of the curve
    * @return the flatness of the <code>CubicCurve</code>
    *          specified by the coordinates in <code>coords</code> at
    *          the specified offset.
    * @since 1.2
    */
    static double getFlatness(double coords[], int offset) {
        return getFlatness(coords[offset + 0], coords[offset + 1],
            coords[offset + 2], coords[offset + 3],
            coords[offset + 4], coords[offset + 5],
            coords[offset + 6], coords[offset + 7]);
    }

    /**
    * Returns the square of the flatness of this curve.  The flatness is the
    * maximum distance of a control point from the line connecting the
    * end points.
    * @return the square of the flatness of this curve.
    * @since 1.2
    */
    double getFlatnessSq() {
        return getFlatnessSq(getX1(), getY1(), getCtrlX1(), getCtrlY1(),
            getCtrlX2(), getCtrlY2(), getX2(), getY2());
    }

    /**
    * Returns the flatness of this curve.  The flatness is the
    * maximum distance of a control point from the line connecting the
    * end points.
    * @return the flatness of this curve.
    * @since 1.2
    */
    double getFlatness() {
        return getFlatness(getX1(), getY1(), getCtrlX1(), getCtrlY1(),
            getCtrlX2(), getCtrlY2(), getX2(), getY2());
    }

    /**
    * Subdivides this cubic curve and stores the resulting two
    * subdivided curves into the left and right curve parameters.
    * Either or both of the left and right objects may be the same
    * as this object or nullptr.
    * @param left the cubic curve object for storing for the left or
    * first half of the subdivided curve
    * @param right the cubic curve object for storing for the right or
    * second half of the subdivided curve
    * @since 1.2
    */
    void subdivide(CubicCurve left, CubicCurve right) {
        subdivide(this, left, right);
    }

    /**
    * Subdivides the cubic curve specified by the <code>src</code> parameter
    * and stores the resulting two subdivided curves into the
    * <code>left</code> and <code>right</code> curve parameters.
    * Either or both of the <code>left</code> and <code>right</code> objects
    * may be the same as the <code>src</code> object or <code>nullptr</code>.
    * @param src the cubic curve to be subdivided
    * @param left the cubic curve object for storing the left or
    * first half of the subdivided curve
    * @param right the cubic curve object for storing the right or
    * second half of the subdivided curve
    * @since 1.2
    */
    static void subdivide(CubicCurve src,
        CubicCurve left,
        CubicCurve right)
    {
        double x1 = src.getX1(),
            y1 = src.getY1(),
            ctrlx1 = src.getCtrlX1(),
            ctrly1 = src.getCtrlY1(),
            ctrlx2 = src.getCtrlX2(),
            ctrly2 = src.getCtrlY2(),
            x2 = src.getX2(),
            y2 = src.getY2(),
            centerx = (ctrlx1 + ctrlx2) / 2.0,
            centery = (ctrly1 + ctrly2) / 2.0;
        ctrlx1 = (x1 + ctrlx1) / 2.0;
        ctrly1 = (y1 + ctrly1) / 2.0;
        ctrlx2 = (x2 + ctrlx2) / 2.0;
        ctrly2 = (y2 + ctrly2) / 2.0;
        double ctrlx12 = (ctrlx1 + centerx) / 2.0,
            ctrly12 = (ctrly1 + centery) / 2.0,
            ctrlx21 = (ctrlx2 + centerx) / 2.0,
            ctrly21 = (ctrly2 + centery) / 2.0;
        centerx = (ctrlx12 + ctrlx21) / 2.0;
        centery = (ctrly12 + ctrly21) / 2.0;
        if (left != nullptr) {
            left.setCurve(x1, y1, ctrlx1, ctrly1,
                ctrlx12, ctrly12, centerx, centery);
        }
        if (right != nullptr) {
            right.setCurve(centerx, centery, ctrlx21, ctrly21,
                ctrlx2, ctrly2, x2, y2);
        }
    }

    /**
    * Subdivides the cubic curve specified by the coordinates
    * stored in the <code>src</code> array at indices <code>srcoff</code>
    * through (<code>srcoff</code>&nbsp;+&nbsp;7) and stores the
    * resulting two subdivided curves into the two result arrays at the
    * corresponding indices.
    * Either or both of the <code>left</code> and <code>right</code>
    * arrays may be <code>nullptr</code> or a reference to the same array
    * as the <code>src</code> array.
    * Note that the last point in the first subdivided curve is the
    * same as the first point in the second subdivided curve. Thus,
    * it is possible to pass the same array for <code>left</code>
    * and <code>right</code> and to use offsets, such as <code>rightoff</code>
    * equals (<code>leftoff</code> + 6), in order
    * to avoid allocating extra storage for this common point.
    * @param src the array holding the coordinates for the source curve
    * @param srcoff the offset into the array of the beginning of the
    * the 6 source coordinates
    * @param left the array for storing the coordinates for the first
    * half of the subdivided curve
    * @param leftoff the offset into the array of the beginning of the
    * the 6 left coordinates
    * @param right the array for storing the coordinates for the second
    * half of the subdivided curve
    * @param rightoff the offset into the array of the beginning of the
    * the 6 right coordinates
    * @since 1.2
    */
    static void subdivide(double src[], int srcoff,
        double left[], int leftoff,
        double right[], int rightoff) {
        double x1 = src[srcoff + 0];
        double y1 = src[srcoff + 1];
        double ctrlx1 = src[srcoff + 2];
        double ctrly1 = src[srcoff + 3];
        double ctrlx2 = src[srcoff + 4];
        double ctrly2 = src[srcoff + 5];
        double x2 = src[srcoff + 6];
        double y2 = src[srcoff + 7];
        if (left != nullptr) {
            left[leftoff + 0] = x1;
            left[leftoff + 1] = y1;
        }
        if (right != nullptr) {
            right[rightoff + 6] = x2;
            right[rightoff + 7] = y2;
        }
        x1 = (x1 + ctrlx1) / 2.0;
        y1 = (y1 + ctrly1) / 2.0;
        x2 = (x2 + ctrlx2) / 2.0;
        y2 = (y2 + ctrly2) / 2.0;
        double centerx = (ctrlx1 + ctrlx2) / 2.0;
        double centery = (ctrly1 + ctrly2) / 2.0;
        ctrlx1 = (x1 + centerx) / 2.0;
        ctrly1 = (y1 + centery) / 2.0;
        ctrlx2 = (x2 + centerx) / 2.0;
        ctrly2 = (y2 + centery) / 2.0;
        centerx = (ctrlx1 + ctrlx2) / 2.0;
        centery = (ctrly1 + ctrly2) / 2.0;
        if (left != nullptr) {
            left[leftoff + 2] = x1;
            left[leftoff + 3] = y1;
            left[leftoff + 4] = ctrlx1;
            left[leftoff + 5] = ctrly1;
            left[leftoff + 6] = centerx;
            left[leftoff + 7] = centery;
        }
        if (right != nullptr) {
            right[rightoff + 0] = centerx;
            right[rightoff + 1] = centery;
            right[rightoff + 2] = ctrlx2;
            right[rightoff + 3] = ctrly2;
            right[rightoff + 4] = x2;
            right[rightoff + 5] = y2;
        }
    }

    /**
    * Solves the cubic whose coefficients are in the <code>eqn</code>
    * array and places the non-complex roots back into the same array,
    * returning the number of roots.  The solved cubic is represented
    * by the equation:
    * <pre>
    *     eqn = {c, b, a, d}
    *     dx^3 + ax^2 + bx + c = 0
    * </pre>
    * A return value of -1 is used to distinguish a constant equation
    * that might be always 0 or never 0 from an equation that has no
    * zeroes.
    * @param eqn an array containing coefficients for a cubic
    * @return the number of roots, or -1 if the equation is a constant.
    * @since 1.2
    */
    static int solveCubic(double eqn[])
    {
        return solveCubic(eqn, eqn);
    }

    /**
    * Solve the cubic whose coefficients are in the <code>eqn</code>
    * array and place the non-complex roots into the <code>res</code>
    * array, returning the number of roots.
    * The cubic solved is represented by the equation:
    *     eqn = {c, b, a, d}
    *     dx^3 + ax^2 + bx + c = 0
    * A return value of -1 is used to distinguish a constant equation,
    * which may be always 0 or never 0, from an equation which has no
    * zeroes.
    * @param eqn the specified array of coefficients to use to solve
    *        the cubic equation
    * @param res the array that contains the non-complex roots
    *        resulting from the solution of the cubic equation
    * @return the number of roots, or -1 if the equation is a constant
    * @since 1.3
    */
    static int solveCubic(double eqn[], double res[])
    {
        // From Numerical Recipes, 5.6, Quadratic and Cubic Equations
        double d = eqn[3];
        if (d == 0.0) {
            // The cubic has degenerated to quadratic (or line or ...).
            return QuadraticCurve.solveQuadratic(eqn, res);
        }
        double a = eqn[2] / d;
        double b = eqn[1] / d;
        double c = eqn[0] / d;
        int roots = 0;
        double Q = (a * a - 3.0 * b) / 9.0;
        double R = (2.0 * a * a * a - 9.0 * a * b + 27.0 * c) / 54.0;
        double R2 = R * R;
        double Q3 = Q * Q * Q;
        a = a / 3.0;
        if (R2 < Q3) {
            double theta = acos(R / sqrt(Q3));
            Q = -2.0 * sqrt(Q);
            if (res == eqn) {
                // Copy the eqn so that we don't clobber it with the
                // roots.  This is needed so that fixRoots can do its
                // work with the original equation.
                eqn = new double[4];
                System.arraycopy(res, 0, eqn, 0, 4);
            }
            res[roots++] = Q * cos(theta / 3.0) - a;
            res[roots++] = Q * cos((theta + PI * 2.0)/ 3.0) - a;
            res[roots++] = Q * cos((theta - PI * 2.0)/ 3.0) - a;
            fixRoots(res, eqn);
        } else {
            bool neg = (R < 0.0);
            double S = sqrt(R2 - Q3);
            if (neg) {
                R = -R;
            }
            double A = pow(R + S, 1.0 / 3.0);
            if (!neg) {
                A = -A;
            }
            double B = (A == 0.0) ? 0.0 : (Q / A);
            res[roots++] = (A + B) - a;
        }
        return roots;
    }

    /*
    * This pruning step is necessary since solveCubic uses the
    * cosine function to calculate the roots when there are 3
    * of them.  Since the cosine method can have an error of
    * +/- 1E-14 we need to make sure that we don't make any
    * bad decisions due to an error.
    *
    * If the root is not near one of the endpoints, then we will
    * only have a slight inaccuracy in calculating the x intercept
    * which will only cause a slightly wrong answer for some
    * points very close to the curve.  While the results in that
    * case are not as accurate as they could be, they are not
    * disastrously inaccurate either.
    *
    * On the other hand, if the error happens near one end of
    * the curve, then our processing to reject values outside
    * of the t=[0,1] range will fail and the results of that
    * failure will be disastrous since for an entire horizontal
    * range of test points, we will either overcount or undercount
    * the crossings and get a wrong answer for all of them, even
    * when they are clearly and obviously inside or outside the
    * curve.
    *
    * To work around this problem, we try a couple of Newton-Raphson
    * iterations to see if the true root is closer to the endpoint
    * or further away.  If it is further away, then we can stop
    * since we know we are on the right side of the endpoint.  If
    * we change direction, then either we are now being dragged away
    * from the endpoint in which case the first condition will cause
    * us to stop, or we have passed the endpoint and are headed back.
    * In the second case, we simply evaluate the slope at the
    * endpoint itself and place ourselves on the appropriate side
    * of it or on it depending on that result.
    */
    private static void fixRoots(double res[], double eqn[]) {
        final double EPSILON = 1E-5;
        for (int i = 0; i < 3; i++) {
            double t = res[i];
            if (abs(t) < EPSILON) {
                res[i] = findZero(t, 0, eqn);
            } else if (abs(t - 1) < EPSILON) {
                res[i] = findZero(t, 1, eqn);
            }
        }
    }

    private static double solveEqn(double eqn[], int order, double t) {
        double v = eqn[order];
        while (--order >= 0) {
            v = v * t + eqn[order];
        }
        return v;
    }

    private static double findZero(double t, double target, double eqn[])
    {
        double slopeqn[] = {eqn[1], 2*eqn[2], 3*eqn[3]};
        double slope;
        double origdelta = 0;
        double origt = t;
        while (true)
        {
            slope = solveEqn(slopeqn, 2, t);
            if (slope == 0)
            {
                // At a local minima - must return
                return t;
            }
            double y = solveEqn(eqn, 3, t);
            if (y == 0)
            {
                // Found it! - return it
                return t;
            }
            // assert(slope != 0 && y != 0);
            double delta = - (y / slope);
            // assert(delta != 0);
            if (origdelta == 0)
            {
                origdelta = delta;
            }
            if (t < target)
            {
                if (delta < 0) return t;
            }
            else if (t > target)
            {
                if (delta > 0) return t;
            }
            else
            {
                /* t == target */
                return (delta > 0
                    ? (target + java.lang.Double.MIN_VALUE)
                    : (target - java.lang.Double.MIN_VALUE));
            }
            double newt = t + delta;
            if (t == newt) {
                // The deltas are so small that we aren't moving...
                return t;
            }
            if (delta * origdelta < 0) {
                // We have reversed our path.
                int tag = (origt < t
                    ? getTag(target, origt, t)
                    : getTag(target, t, origt));
                if (tag != INSIDE) {
                    // Local minima found away from target - return the middle
                    return (origt + t) / 2;
                }
                // Local minima somewhere near target - move to target
                // and let the slope determine the resulting t.
                t = target;
            } else {
                t = newt;
            }
        }
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    bool contains(double x, double y)
    {
        if (!(x * 0.0 + y * 0.0 == 0.0))
        {
            /* Either x or y was infinite or NaN.
            * A NaN always produces a negative response to any test
            * and Infinity values cannot be "inside" any path so
            * they should return false as well.
            */
            return false;
        }
        // We count the "Y" crossings to determine if the point is
        // inside the curve bounded by its closing line.
        double x1 = getX1();
        double y1 = getY1();
        double x2 = getX2();
        double y2 = getY2();
        int crossings =
            (Curve.pointCrossingsForLine(x, y, x1, y1, x2, y2) +
                Curve.pointCrossingsForCubic(x, y,
                    x1, y1,
                    getCtrlX1(), getCtrlY1(),
                    getCtrlX2(), getCtrlY2(),
                    x2, y2, 0));
        return ((crossings & 1) == 1);
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    bool contains(Point2D p) {
        return contains(p.getX(), p.getY());
    }

    /*
    * Fill an array with the coefficients of the parametric equation
    * in t, ready for solving against val with solveCubic.
    * We currently have:
    * <pre>
    *   val = P(t) = C1(1-t)^3 + 3CP1 t(1-t)^2 + 3CP2 t^2(1-t) + C2 t^3
    *              = C1 - 3C1t + 3C1t^2 - C1t^3 +
    *                3CP1t - 6CP1t^2 + 3CP1t^3 +
    *                3CP2t^2 - 3CP2t^3 +
    *                C2t^3
    *            0 = (C1 - val) +
    *                (3CP1 - 3C1) t +
    *                (3C1 - 6CP1 + 3CP2) t^2 +
    *                (C2 - 3CP2 + 3CP1 - C1) t^3
    *            0 = C + Bt + At^2 + Dt^3
    *     C = C1 - val
    *     B = 3*CP1 - 3*C1
    *     A = 3*CP2 - 6*CP1 + 3*C1
    *     D = C2 - 3*CP2 + 3*CP1 - C1
    * </pre>
    */
    private static void fillEqn(double eqn[], double val,
        double c1, double cp1, double cp2, double c2) {
        eqn[0] = c1 - val;
        eqn[1] = (cp1 - c1) * 3.0;
        eqn[2] = (cp2 - cp1 - cp1 + c1) * 3.0;
        eqn[3] = c2 + (cp1 - cp2) * 3.0 - c1;
        return;
    }

    /*
    * Evaluate the t values in the first num slots of the vals[] array
    * and place the evaluated values back into the same array.  Only
    * evaluate t values that are within the range <0, 1>, including
    * the 0 and 1 ends of the range iff the include0 or include1
    * booleans are true.  If an "inflection" equation is handed in,
    * then any points which represent a point of inflection for that
    * cubic equation are also ignored.
    */
    private static int evalCubic(double vals[], int num,
        bool include0,
        bool include1,
        double inflect[],
        double c1, double cp1,
        double cp2, double c2) {
        int j = 0;
        for (int i = 0; i < num; i++) {
            double t = vals[i];
            if ((include0 ? t >= 0 : t > 0) &&
                (include1 ? t <= 1 : t < 1) &&
                (inflect == nullptr ||
                    inflect[1] + (2*inflect[2] + 3*inflect[3]*t)*t != 0))
            {
                double u = 1 - t;
                vals[j++] = c1*u*u*u + 3*cp1*t*u*u + 3*cp2*t*t*u + c2*t*t*t;
            }
        }
        return j;
    }

    bool intersects(double x, double y, double w, double h) {
        // Trivially reject non-existant rectangles
        if (w <= 0 || h <= 0) {
            return false;
        }

        // Trivially accept if either endpoint is inside the rectangle
        // (not on its border since it may end there and not go inside)
        // Record where they lie with respect to the rectangle.
        //     -1 => left, 0 => inside, 1 => right
        double x1 = getX1();
        double y1 = getY1();
        int x1tag = getTag(x1, x, x+w);
        int y1tag = getTag(y1, y, y+h);
        if (x1tag == INSIDE && y1tag == INSIDE) {
            return true;
        }
        double x2 = getX2();
        double y2 = getY2();
        int x2tag = getTag(x2, x, x+w);
        int y2tag = getTag(y2, y, y+h);
        if (x2tag == INSIDE && y2tag == INSIDE) {
            return true;
        }

        double ctrlx1 = getCtrlX1();
        double ctrly1 = getCtrlY1();
        double ctrlx2 = getCtrlX2();
        double ctrly2 = getCtrlY2();
        int ctrlx1tag = getTag(ctrlx1, x, x+w);
        int ctrly1tag = getTag(ctrly1, y, y+h);
        int ctrlx2tag = getTag(ctrlx2, x, x+w);
        int ctrly2tag = getTag(ctrly2, y, y+h);

        // Trivially reject if all points are entirely to one side of
        // the rectangle.
        if (x1tag < INSIDE && x2tag < INSIDE &&
            ctrlx1tag < INSIDE && ctrlx2tag < INSIDE)
        {
            return false;       // All points left
        }
        if (y1tag < INSIDE && y2tag < INSIDE &&
            ctrly1tag < INSIDE && ctrly2tag < INSIDE)
        {
            return false;       // All points above
        }
        if (x1tag > INSIDE && x2tag > INSIDE &&
            ctrlx1tag > INSIDE && ctrlx2tag > INSIDE)
        {
            return false;       // All points right
        }
        if (y1tag > INSIDE && y2tag > INSIDE &&
            ctrly1tag > INSIDE && ctrly2tag > INSIDE)
        {
            return false;       // All points below
        }

        // Test for endpoints on the edge where either the segment
        // or the curve is headed "inwards" from them
        // Note: These tests are a superset of the fast endpoint tests
        //       above and thus repeat those tests, but take more time
        //       and cover more cases
        if (inwards(x1tag, x2tag, ctrlx1tag) &&
            inwards(y1tag, y2tag, ctrly1tag))
        {
            // First endpoint on border with either edge moving inside
            return true;
        }
        if (inwards(x2tag, x1tag, ctrlx2tag) &&
            inwards(y2tag, y1tag, ctrly2tag))
        {
            // Second endpoint on border with either edge moving inside
            return true;
        }

        // Trivially accept if endpoints span directly across the rectangle
        bool xoverlap = (x1tag * x2tag <= 0);
        bool yoverlap = (y1tag * y2tag <= 0);
        if (x1tag == INSIDE && x2tag == INSIDE && yoverlap) {
            return true;
        }
        if (y1tag == INSIDE && y2tag == INSIDE && xoverlap) {
            return true;
        }

        // We now know that both endpoints are outside the rectangle
        // but the 4 points are not all on one side of the rectangle.
        // Therefore the curve cannot be contained inside the rectangle,
        // but the rectangle might be contained inside the curve, or
        // the curve might intersect the boundary of the rectangle.

        double[] eqn = new double[4];
        double[] res = new double[4];
        if (!yoverlap) {
            // Both y coordinates for the closing segment are above or
            // below the rectangle which means that we can only intersect
            // if the curve crosses the top (or bottom) of the rectangle
            // in more than one place and if those crossing locations
            // span the horizontal range of the rectangle.
            fillEqn(eqn, (y1tag < INSIDE ? y : y+h), y1, ctrly1, ctrly2, y2);
            int num = solveCubic(eqn, res);
            num = evalCubic(res, num, true, true, nullptr,
                x1, ctrlx1, ctrlx2, x2);
            // odd counts imply the crossing was out of [0,1] bounds
            // otherwise there is no way for that part of the curve to
            // "return" to meet its endpoint
            return (num == 2 &&
                getTag(res[0], x, x+w) * getTag(res[1], x, x+w) <= 0);
        }

        // Y ranges overlap.  Now we examine the X ranges
        if (!xoverlap) {
            // Both x coordinates for the closing segment are left of
            // or right of the rectangle which means that we can only
            // intersect if the curve crosses the left (or right) edge
            // of the rectangle in more than one place and if those
            // crossing locations span the vertical range of the rectangle.
            fillEqn(eqn, (x1tag < INSIDE ? x : x+w), x1, ctrlx1, ctrlx2, x2);
            int num = solveCubic(eqn, res);
            num = evalCubic(res, num, true, true, nullptr,
                y1, ctrly1, ctrly2, y2);
            // odd counts imply the crossing was out of [0,1] bounds
            // otherwise there is no way for that part of the curve to
            // "return" to meet its endpoint
            return (num == 2 &&
                getTag(res[0], y, y+h) * getTag(res[1], y, y+h) <= 0);
        }

        // The X and Y ranges of the endpoints overlap the X and Y
        // ranges of the rectangle, now find out how the endpoint
        // line segment intersects the Y range of the rectangle
        double dx = x2 - x1;
        double dy = y2 - y1;
        double k = y2 * x1 - x2 * y1;
        int c1tag, c2tag;
        if (y1tag == INSIDE) {
            c1tag = x1tag;
        } else {
            c1tag = getTag((k + dx * (y1tag < INSIDE ? y : y+h)) / dy, x, x+w);
        }
        if (y2tag == INSIDE) {
            c2tag = x2tag;
        } else {
            c2tag = getTag((k + dx * (y2tag < INSIDE ? y : y+h)) / dy, x, x+w);
        }
        // If the part of the line segment that intersects the Y range
        // of the rectangle crosses it horizontally - trivially accept
        if (c1tag * c2tag <= 0) {
            return true;
        }

        // Now we know that both the X and Y ranges intersect and that
        // the endpoint line segment does not directly cross the rectangle.
        //
        // We can almost treat this case like one of the cases above
        // where both endpoints are to one side, except that we may
        // get one or three intersections of the curve with the vertical
        // side of the rectangle.  This is because the endpoint segment
        // accounts for the other intersection in an even pairing.  Thus,
        // with the endpoint crossing we end up with 2 or 4 total crossings.
        //
        // (Remember there is overlap in both the X and Y ranges which
        //  means that the segment itself must cross at least one vertical
        //  edge of the rectangle - in particular, the "near vertical side"
        //  - leaving an odd number of intersections for the curve.)
        //
        // Now we calculate the y tags of all the intersections on the
        // "near vertical side" of the rectangle.  We will have one with
        // the endpoint segment, and one or three with the curve.  If
        // any pair of those vertical intersections overlap the Y range
        // of the rectangle, we have an intersection.  Otherwise, we don't.

        // c1tag = vertical intersection class of the endpoint segment
        //
        // Choose the y tag of the endpoint that was not on the same
        // side of the rectangle as the subsegment calculated above.
        // Note that we can "steal" the existing Y tag of that endpoint
        // since it will be provably the same as the vertical intersection.
        c1tag = ((c1tag * x1tag <= 0) ? y1tag : y2tag);

        // Now we have to calculate an array of solutions of the curve
        // with the "near vertical side" of the rectangle.  Then we
        // need to sort the tags and do a pairwise range test to see
        // if either of the pairs of crossings spans the Y range of
        // the rectangle.
        //
        // Note that the c2tag can still tell us which vertical edge
        // to test against.
        fillEqn(eqn, (c2tag < INSIDE ? x : x+w), x1, ctrlx1, ctrlx2, x2);
        int num = solveCubic(eqn, res);
        num = evalCubic(res, num, true, true, nullptr, y1, ctrly1, ctrly2, y2);

        // Now put all of the tags into a bucket and sort them.  There
        // is an intersection iff one of the pairs of tags "spans" the
        // Y range of the rectangle.
        int tags[] = new int[num+1];

        for (int i = 0; i < num; i++)
        {
            tags[i] = getTag(res[i], y, y+h);
        }
        tags[num] = c1tag;
        Arrays.sort(tags);

        return ((num >= 1 && tags[0] * tags[1] <= 0) || (num >= 3 && tags[2] * tags[3] <= 0));
    }

    bool intersects(Rectangle2D r) {
        return intersects(r.getX(), r.getY(), r.getWidth(), r.getHeight());
    }

    bool contains(double x, double y, double w, double h) {
        if (w <= 0 || h <= 0) {
            return false;
        }
        // Assertion: Cubic curves closed by connecting their
        // endpoints form either one or two convex halves with
        // the closing line segment as an edge of both sides.
        if (!(contains(x, y) &&
            contains(x + w, y) &&
            contains(x + w, y + h) &&
            contains(x, y + h))) {
            return false;
        }
        // Either the rectangle is entirely inside one of the convex
        // halves or it crosses from one to the other, in which case
        // it must intersect the closing line segment.
        Rectangle2D rect = new Rectangle2D.Double(x, y, w, h);
        return !rect.intersectsLine(getX1(), getY1(), getX2(), getY2());
    }

    bool contains(Rectangle2D r) {
        return contains(r.getX(), r.getY(), r.getWidth(), r.getHeight());
    }

    Rectangle getBounds() {
        return getBounds2D().getBounds();
    }

    PathIterator getPathIterator(AffineTransform at) {
        return new CubicIterator(this, at);
    }

    PathIterator getPathIterator(AffineTransform at, double flatness) {
        return new FlatteningPathIterator(getPathIterator(at), flatness);
    }

    private:

    enum {
        BELOW = -2,
        LOWEDGE = -1,
        INSIDE = 0,
        HIGHEDGE = 1,
        ABOVE = 2
    };

    /*
    * Determine where coord lies with respect to the range from
    * low to high.  It is assumed that low <= high.  The return
    * value is one of the 5 values BELOW, LOWEDGE, INSIDE, HIGHEDGE,
    * or ABOVE.
    */
    static int getTag(double coord, double low, double high)
    {
        if (coord <= low)
            return (coord < low ? BELOW : LOWEDGE);
        if (coord >= high)
            return (coord > high ? ABOVE : HIGHEDGE);
        return INSIDE;
    }

    static bool inwards(int pttag, int opt1tag, int opt2tag)
    {
        switch (pttag)
        {
            case BELOW:
            case ABOVE:
            default:
                return false;
            case LOWEDGE:
                return (opt1tag >= INSIDE || opt2tag >= INSIDE);
            case INSIDE:
                return true;
            case HIGHEDGE:
  
              return (opt1tag <= INSIDE || opt2tag <= INSIDE);
        }
    }
};

static class CubicCurve_f: public CubicCurve
/*< A 32-bit cubic parametric curve segment specified with. */
{
    float x1,
        y1,
        ctrlx1,
        ctrly1,
        ctrlx2,
        ctrly2,
        x2,
        y2;

    /**
    * Constructs and initializes a CubicCurve with coordinates
    * (0, 0, 0, 0, 0, 0, 0, 0).
    * @since 1.2
    */
    CubicCurve_f() {
    }

    /**
    * Constructs and initializes a {@code CubicCurve} from
    * the specified {@code float} coordinates.
    *
    * @param x1 the X coordinate for the start point
    *           of the resulting {@code CubicCurve}
    * @param y1 the Y coordinate for the start point
    *           of the resulting {@code CubicCurve}
    * @param ctrlx1 the X coordinate for the first control point
    *               of the resulting {@code CubicCurve}
    * @param ctrly1 the Y coordinate for the first control point
    *               of the resulting {@code CubicCurve}
    * @param ctrlx2 the X coordinate for the second control point
    *               of the resulting {@code CubicCurve}
    * @param ctrly2 the Y coordinate for the second control point
    *               of the resulting {@code CubicCurve}
    * @param x2 the X coordinate for the end point
    *           of the resulting {@code CubicCurve}
    * @param y2 the Y coordinate for the end point
    *           of the resulting {@code CubicCurve}
    * @since 1.2
    */
    Float(float x1, float y1,
        float ctrlx1, float ctrly1,
        float ctrlx2, float ctrly2,
        float x2, float y2)
    {
        setCurve(x1, y1, ctrlx1, ctrly1, ctrlx2, ctrly2, x2, y2);
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getX1() {
        return (double) x1;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getY1() {
        return (double) y1;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    Point2D getP1() {
        return new Point2D.Float(x1, y1);
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getCtrlX1() {
        return (double) ctrlx1;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getCtrlY1() {
        return (double) ctrly1;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    Point2D getCtrlP1() {
        return new Point2D.Float(ctrlx1, ctrly1);
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getCtrlX2() {
        return (double) ctrlx2;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getCtrlY2() {
        return (double) ctrly2;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    Point2D getCtrlP2() {
        return new Point2D.Float(ctrlx2, ctrly2);
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getX2() {
        return (double) x2;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getY2() {
        return (double) y2;
    }

    Point2D getP2() {
        return new Point2D.Float(x2, y2);
    }

    void setCurve(double x1, double y1,
        double ctrlx1, double ctrly1,
        double ctrlx2, double ctrly2,
        double x2, double y2)
    {
        x1     = (float) x1;
        y1     = (float) y1;
        ctrlx1 = (float) ctrlx1;
        ctrly1 = (float) ctrly1;
        ctrlx2 = (float) ctrlx2;
        ctrly2 = (float) ctrly2;
        x2     = (float) x2;
        y2     = (float) y2;
    }

    void setCurve(float x1, float y1, float ctrlx1, float ctrly1, float ctrlx2, float ctrly2, float x2, float y2)
    {
        x1     = x1;
        y1     = y1;
        ctrlx1 = ctrlx1;
        ctrly1 = ctrly1;
        ctrlx2 = ctrlx2;
        ctrly2 = ctrly2;
        x2     = x2;
        y2     = y2;
    }

    Rect_f getBounds2D()
    {
        float left   = min(min(x1, x2), min(ctrlx1, ctrlx2)),
            top    = min(min(y1, y2), min(ctrly1, ctrly2)),
            right  = max(max(x1, x2), max(ctrlx1, ctrlx2)),
            bottom = max(max(y1, y2), max(ctrly1, ctrly2));

        return Rect_f.Float(left, top, right - left, bottom - top);
    }
};


/**
* A 64-bit cubic parametric curve segment. */
static class CubicCurve_d: CubicCurve
{
    /**
    * The X coordinate of the start point
    * of the cubic curve segment.
    * @since 1.2
    * @serial
    */
    double x1,
        y1,
        ctrlx1,
        ctrly1,
        ctrlx2,
        ctrly2,
        x2,
        y2;

    /**
    * Constructs and initializes a CubicCurve with coordinates
    * (0, 0, 0, 0, 0, 0, 0, 0).
    * @since 1.2
    */
    CubicCurve_d()
    {
    }

    /**
    * Constructs and initializes a {@code CubicCurve} from
    * the specified {@code double} coordinates.
    *
    * @param x1 the X coordinate for the start point
    *           of the resulting {@code CubicCurve}
    * @param y1 the Y coordinate for the start point
    *           of the resulting {@code CubicCurve}
    * @param ctrlx1 the X coordinate for the first control point
    *               of the resulting {@code CubicCurve}
    * @param ctrly1 the Y coordinate for the first control point
    *               of the resulting {@code CubicCurve}
    * @param ctrlx2 the X coordinate for the second control point
    *               of the resulting {@code CubicCurve}
    * @param ctrly2 the Y coordinate for the second control point
    *               of the resulting {@code CubicCurve}
    * @param x2 the X coordinate for the end point
    *           of the resulting {@code CubicCurve}
    * @param y2 the Y coordinate for the end point
    *           of the resulting {@code CubicCurve}
    * @since 1.2
    */
    CubicCurve_d (double x1, double y1, double ctrlx1, double ctrly1, double ctrlx2, double ctrly2, double x2, 
        double y2)
    {
        setCurve(x1, y1, ctrlx1, ctrly1, ctrlx2, ctrly2, x2, y2);
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getX1() {
        return x1;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getY1() {
        return y1;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    Point2D getP1() {
        return new Point2D.Double(x1, y1);
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getCtrlX1() {
        return ctrlx1;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getCtrlY1() {
        return ctrly1;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    Point2D getCtrlP1() {
        return new Point2D.Double(ctrlx1, ctrly1);
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getCtrlX2() {
        return ctrlx2;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getCtrlY2() {
        return ctrly2;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    Point2D getCtrlP2() {
        return new Point2D.Double(ctrlx2, ctrly2);
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getX2() {
        return x2;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    double getY2() {
        return y2;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    Point2D getP2() {
        return new Point2D.Double(x2, y2);
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    void setCurve(double x1, double y1,
        double ctrlx1, double ctrly1,
        double ctrlx2, double ctrly2,
        double x2, double y2)
    {
        x1     = x1;
        y1     = y1;
        ctrlx1 = ctrlx1;
        ctrly1 = ctrly1;
        ctrlx2 = ctrlx2;
        ctrly2 = ctrly2;
        x2     = x2;
        y2     = y2;
    }

    /**
    * {@inheritDoc}
    * @since 1.2
    */
    Rect_d getBounds2D() {
        double left   = min(min(x1, x2),
            min(ctrlx1, ctrlx2));
        double top    = min(min(y1, y2),
            min(ctrly1, ctrly2));
        double right  = max(max(x1, x2),
            max(ctrlx1, ctrlx2));
        double bottom = max(max(y1, y2),
            max(ctrly1, ctrly2));
        return new Rect_d.Double(left, top,
            right - left, bottom - top);
    }
};

}   //< _2D
