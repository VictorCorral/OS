/* $Id$ */
/** @file OSExpressionTree.h
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2014, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include "OSnLNode.h"
#include <vector>
#include <map>
#include <complex>

// forward declarations to deal with circularity
class ExprNode; 
class OSnLNode; 
class OSnLMNode; 

/*! \class OSExpressionTree
 *  \brief Used to hold the instance in memory.
 *
 * \remarks
 * This is a generic class.
 * Specific classes RealValuedExpressionTree (for expressions that evaluate to real values)
 * ComplexValuedExpressionTree (for expressions that evaluate to complex values)
 * and MatrixExpressionTree (for expressions that evaluate to matrices) are derived
 * from this class. 
 */

class OSExpressionTree
{
public:

    /**
     * m_treeRoot holds the root node (as a generic node) of the expression tree.
     */
    ExprNode *m_treeRoot;

    /**
     * m_bDestroyNlNodes is true if the destructor deletes the OSnLNodes in the Expression tree
     */
    bool bDestroyNlNodes;

    /**
     * default constructor.
     */
    OSExpressionTree();

    /**
     * default destructor.
     */
    ~OSExpressionTree();

    /**
     * Get a vector of pointers to ExprNodes that correspond to
     * an OSExpressionTree in prefix format
     *
     * </p>
     *
     * @return the expression tree as a vector of ExprNodes in prefix.
     */
    virtual std::vector<ExprNode*> getPrefixFromExpressionTree();

    /**
     * Get a vector of pointers to ExprNodes that correspond to
     * an OSExpressionTree in postfix format
     *
     * </p>
     *
     * @return the expression tree as a vector of ExprNodes in postfix.
     */
    virtual std::vector<ExprNode*> getPostfixFromExpressionTree();

    /**
     * Create or clone an expression tree.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     */
    //virtual OSExpressionTree *cloneExpressionTree() = 0;

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OSExpressionTree *that);
};//end OSExpressionTree


/*! \class RealValuedExpressionTree
 *  \brief Used to hold part of the instance in memory.
 *
 * \remarks
 * This class stores the OSiL instance in memory as
 * an expression tree.
 */
class RealValuedExpressionTree : public OSExpressionTree
{
public:
    /**
     * default constructor.
     */
    RealValuedExpressionTree();

    /**
     * default destructor.
     */
    ~RealValuedExpressionTree();

    /**
     * Retrieve a map of the indices of the variables
     * that are in the expression tree
     *
     * </p>
     *
     * @return a map of the variables in the current expression tree.
     */
    virtual std::map<int, int> *getVariableIndicesMap();

    /**
     * m_bIndexMapGenerated is set to true if getVariableIndicesMap() has been called
     */
    bool m_bIndexMapGenerated;

    /**
     * is true if an AD Expression Tree has an expression that can change depending on
     * the value of the input, e.g. an if statement -- false by default
     */
    bool bADMustReTape;

    /**
     * m_mapVarIdx is a map used to generate the infix expression for AD   
     * the key is idx, a variable number;
     * the value of the map is the location of the corresponding entry in the sparse Jacobian
     */
    std::map<int, int> *mapVarIdx;

    /**
     * Calculate the expression tree function value given the current variable
     * values using the calculateFunction method of OSnLNode.
     * If the function has been calculated, the method will retrieve it.
     *
     * </p>
     *
     * @param x holds the values of the variables in a double array.
     * @param new_x is false if any evaluation method was previously called for the current x
     * @return the expression tree function value given the current variable values.
     */
    virtual double calculateFunction( double *x, bool new_x);

    /*! \fn OSExpressionTree *cloneExpressionTree() 
     *  \brief The implementation of the virtual function.
     *  \return a pointer to a new OSExpressionTree of the proper type.
     */
    /*virtual*/ RealValuedExpressionTree *cloneExpressionTree();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(RealValuedExpressionTree *that);

private:
    /**
     * m_dTreeRootValue is the function value of the root node
     */
    double m_dTreeRootValue;
};//end RealValuedExpressionTree


/*! \class ComplexValuedExpressionTree
 *  \brief Used to hold part of the instance in memory.
 *
 * \remarks
 * This class stores the OSiL instance in memory as
 * an expression tree.
 */
class ComplexValuedExpressionTree : public OSExpressionTree
{
public:

    /**
     * default constructor.
     */
    ComplexValuedExpressionTree();

    /**
     * default destructor.
     */
    ~ComplexValuedExpressionTree();

    /**
     * Retrieve a map of the indices of the variables
     * that are in the expression tree
     *
     * </p>
     *
     * @return a map of the variables in the current expression tree.
     */
//    virtual std::map<int, int> *getVariableIndicesMap();

    /**
     * m_bIndexMapGenerated is set to true if getVariableIndicesMap() has been called
     */
//    bool m_bIndexMapGenerated;

    /**
     * is true if an AD Expression Tree has an expression that can change depending on
     * the value of the input, e.g. an if statement -- false by default
     */
//    bool bADMustReTape;

    /**
     * Calculate the expression tree function value given the current variable
     * values using the calculateFunction method of OSnLNode.
     * If the function has been calculated, the method will retrieve it.
     *
     * </p>
     *
     * @param x holds the values of the variables in a double array.
     * @param new_x is false if any evaluation method was previously called for the current x
     * @return the expression tree function value given the current variable values.
     */
    virtual std::complex<double> calculateFunction( double *x, bool new_x);

    /*! \fn OSExpressionTree *cloneExpressionTree()
     *  \brief The implementation of the virtual function.
     *  \return a pointer to a new OSExpressionTree of the proper type.
     */
    /*virtual*/ ComplexValuedExpressionTree *cloneExpressionTree();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(ComplexValuedExpressionTree *that);

private:
    /**
     * m_dTreeRootValue is the function value of the root node
     */
    std::complex<double> m_dTreeRootValue;
};//end ComplexValuedExpressionTree


/*! \class MatrixExpressionTree
 *  \brief Used to hold the instance in memory.
 *
 * \remarks
 * This class stores a matrix-valued linear or nonlinear expression
 * in memory as an expression tree.
 *
 */

class MatrixExpressionTree : public OSExpressionTree
{
public:
    /**
     * default constructor.
     */
    MatrixExpressionTree();

    /**
     * default destructor.
     */
    ~MatrixExpressionTree();

    /**
     * Retrieve a map of the indices of the variables
     * that are in the expression tree
     *
     * </p>
     *
     * @return a map of the variables in the current expression tree.
     */
    //virtual std::map<int, int> *getVariableIndicesMap();

#if 0
    /**
     * m_bIndexMapGenerated is set to true if getVariableIndicesMap() has been called
     */
    bool m_bIndexMapGenerated;

    /**
     * is true if an AD Expression Tree has an expression that can change depending on
     * the value of the input, e.g. an if statement -- false by default
     */
    bool bADMustReTape;

    /**
     * Calculate the expression tree function value given the current variable
     * values using the calculateFunction method of OSnLNode.
     * If the function has been calculated, the method will retrieve it.
     *
     * </p>
     *
     * @param x holds the values of the variables in a double array.
     * @param new_x is false if any evaluation method was previously called for the current x
     * @return the expression tree function value given the current variable values.
     */
    //virtual double calculateFunction( double *x, bool new_x);
#endif

    /*! \fn OSExpressionTree *cloneExpressionTree()
     *  \brief The implementation of the virtual function.
     *  \return a pointer to a new OSExpressionTree of the proper type.
     */
    /*virtual*/ MatrixExpressionTree *cloneExpressionTree();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixExpressionTree *that);

private:

    /**
     * m_dTreeRootValue is the function value of the root node
     */
    //double m_dTreeRootValue;
};//end MatrixExpressionTree



/** 
 * A utility method to convert an expression tree into its ASCII representation in infix notation.
 * This is useful in printModel (OSInstance) as well as matrix handling (OSMatrix).
 */
std::string getExpressionTreeAsInfixString(std::vector<ExprNode*> postfixVec);

#endif

