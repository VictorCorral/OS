/* $Id$ */
/** @file OSMatlab.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2012, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#include <iostream>
#include <sstream>
#include <string>
#include "OSMatlabSolver.h"
#include "OSConfig.h"
#include "OSOutput.h"

#ifdef COIN_HAS_LINDO
#include "OSLindoSolver.h"
#endif

#ifdef COIN_HAS_IPOPT
#include "OSIpoptSolver.h"
#endif


using std::endl;
using std::ostringstream;


OSMatlab::OSMatlab()
{
    sparseMat = NULL;
    bu = NULL;
    bl = NULL;
    obj = NULL;
    vl = NULL;
    vu = NULL;
    objType = 0;
    osinstance = NULL;
    varType = NULL;
    numQTerms = 0;
    qRows = NULL;
    qIndex1 = NULL;
    qIndex2 = NULL;
    qVal = NULL;
    numVar = 0;
    numCon = 0;
    instanceName=" ";
    sSolverName="";
    sAgentAddress="";
    solverType = NULL;
}//end OSMatlab


OSMatlab::~OSMatlab()
{
    delete osinstance;
}//end ~OSMatlab

std::string OSMatlab::solve()
{
    ostringstream outStr;
    //std::string osol = "<osol> <optimization>  <other name=\"os_solver\">" +
    //sSolverName + "</other> </optimization></osol>";
    std::string osol = "";
    osil = "";
//
//
//
//
    try
    {
        if(osinstance == NULL ) throw ErrorClass( "there is no problem instance");
        else
        {
            OSiLWriter *osilwriter;
            osilwriter = new OSiLWriter();
            osilwriter->m_bWhiteSpace = true;
            osil =  osilwriter->writeOSiL( osinstance);
            if( sSolverName.find( "lindo") != std::string::npos)
            {
                // we are requesting the Lindo solver
                bool bLindoIsPresent = false;
#ifdef COIN_HAS_LINDO
                bLindoIsPresent = true;
                solverType = new LindoSolver();
#endif
                if(bLindoIsPresent == false) throw ErrorClass( "the Lindo solver requested is not present");
            }
            else
            {
                if( sSolverName.find( "clp") != std::string::npos)
                {
                    solverType = new CoinSolver();
                    solverType->sSolverName = "clp";
                }
                else
                {
                    if( sSolverName.find( "cbc") != std::string::npos)
                    {
                        solverType = new CoinSolver();
                        solverType->sSolverName = "cbc";
                    }
                    else
                    {
                        if( sSolverName.find( "cplex") != std::string::npos)
                        {
                            solverType = new CoinSolver();
                            solverType->sSolverName = "cplex";
                        }
                        else
                        {
                            if( sSolverName.find( "glpk") != std::string::npos)
                            {
                                solverType = new CoinSolver();
                                solverType->sSolverName = "glpk";


                            }
                            else
                            {
                                if( sSolverName.find( "ipopt") != std::string::npos)
                                {
                                    // have to act differently since Ipopt uses smart pointers
                                    // we are requesting the Ipopt solver
                                    bool bIpoptIsPresent = false;
                                    if(sAgentAddress == "" )
                                    {
#ifdef COIN_HAS_IPOPT
                                        bIpoptIsPresent = true;
                                        IpoptSolver *ipoptSolver  = new IpoptSolver();
                                        ipoptSolver->osol = osol;
                                        ipoptSolver->osinstance = osinstance;
                                        ipoptSolver->solve();
                                        return  ipoptSolver->osrl ;
#endif
                                        if(bIpoptIsPresent == false) throw ErrorClass( "the Ipopt solver requested is not present");
                                    }
                                }
                                else
                                {
                                    if( sSolverName.find( "symphony") != std::string::npos)
                                    {
                                        solverType = new CoinSolver();
                                        solverType->sSolverName = "symphony";
                                    }
                                    else
                                    {
                                        if( sSolverName.find( "dylp") != std::string::npos)
                                        {
                                            solverType = new CoinSolver();
                                            solverType->sSolverName = "dylp";
                                        }
                                        else
                                        {
                                            throw ErrorClass( "a supported solver is not present");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        // do a local solve
        if( (sSolverName.find( "ipopt") == std::string::npos) && (sAgentAddress == ""))
        {
            solverType->osol = osol;
            solverType->osinstance = osinstance;
            solverType->solve();
            return solverType->osrl ;
        }
    }
    catch(const ErrorClass& eclass)
    {
        return eclass.errormsg;
    }

    // do the following for a remote solve
    if(sAgentAddress != "")
    {
        OSSolverAgent* osagent = NULL;
        OSiLWriter *osilwriter = NULL;
        osilwriter = new OSiLWriter();
        std::string  osil = osilwriter->writeOSiL( osinstance);
        osagent = new OSSolverAgent( sAgentAddress);
        return osagent->solve(osil, osol);
    }
    return "";

}//end solve

void OSMatlab::createOSInstance()
{
    ostringstream outStr;

    int i;
    osinstance = new OSInstance();
    //
    // put in some of the OSInstance <instanceHeader> information
    //osinstance->setInstanceSource("An example from the LINDO API samples directory");
    osinstance->setInstanceDescription("A MATLAB Created Problem");
    osinstance->setInstanceName( instanceName);
    //
    // now put in the OSInstance <instanceData> information
    //
    // first the variables
    std::string *varNames;
    varNames = new std::string[ numVar];
    osinstance->setVariableNumber( numVar);
    for(i = 0; i < numVar; i++)
    {
        outStr << "x";
        outStr << i ;
        varNames[ i] = outStr.str();
        osinstance->addVariable(i, varNames[ i] , vl[ i], vu[ i], varType[ i]);
        outStr.str("");
    }

    // now add the objective function
    osinstance->setObjectiveNumber( 1);
    // now the coefficient
    SparseVector *objcoeff;
    objcoeff = new SparseVector( numVar);
    objcoeff->indexes = new int[ numVar];
    objcoeff->values = new double[ numVar];
    for(i = 0; i < numVar; i++)
    {
        objcoeff->indexes[ i] = i;
        objcoeff->values[ i] = obj[ i];
    }
    std::string maxOrMin = "min";
    if( objType == true) maxOrMin = "max";
    osinstance->addObjective(-1, "objfunction", maxOrMin, 0.0, 1.0, objcoeff);

    // now the constraints
    std::string *conNames;
    conNames = new std::string[ numCon];
    outStr.str("");
    osinstance->setConstraintNumber( numCon);
    for(i = 0; i < numCon; i++)
    {
        outStr << "r";
        outStr << i;
        conNames[ i] = outStr.str();
        osinstance->addConstraint(i, "row" , bl[ i], bu[ i], 0);

        outStr.str("");
    }
    osinstance->setLinearConstraintCoefficients(sparseMat->valueSize, true, sparseMat->values, 0, sparseMat->valueSize - 1,
            sparseMat->indexes, 0, sparseMat->valueSize - 1, sparseMat->starts, 0, sparseMat->startSize - 1);
    if(numQTerms > 0)
    {
        osinstance->setQuadraticTermsInNonlinearExpressions(numQTerms, qRows, qIndex1, qIndex2, qVal);
    }
    return;
}// end createOSInstance
