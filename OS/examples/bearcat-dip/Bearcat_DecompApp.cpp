//===========================================================================//
// This file is part of the Decomp Solver Framework.                         //
//                                                                           //
// Decomp is distributed under the Common Public License as part of the      //
// COIN-OR repository (http://www.coin-or.org).                              //
//                                                                           //
// Author: Matthew Galati, Lehigh University                                 //
//                                                                           //
// Copyright (C) 2002-2009, Lehigh University, Matthew Galati, and Ted Ralphs//
// All Rights Reserved.                                                      //
//===========================================================================//

//===========================================================================//
#include "Bearcat_Status.h"
#include "Bearcat_DecompApp.h"
//===========================================================================//
#include "DecompVar.h"

void Bearcat_DecompApp::initializeApp(UtilParameters & utilParam) {

	UtilPrintFuncBegin(m_osLog, m_classTag,
			"initializeApp()", m_appParam.LogLevel, 2);

	//---
	//--- get application parameters
	//---
	m_appParam.getSettings( utilParam);
	if(m_appParam.LogLevel >= 1)
		m_appParam.dumpSettings(m_osLog);

	
	//---
	//--- read instance
	//
	std::string instanceFile = "spl.xml";
	m_osInterface.readInstance( instanceFile);

	//---
	//--- create models
	//---
	createModels();

	UtilPrintFuncEnd(m_osLog, m_classTag, "initializeApp()",
			m_appParam.LogLevel, 2);
}



//===========================================================================//
void Bearcat_DecompApp::findActiveColumns(const vector<int> & rowsPart, set<
		int> & activeColsSet) {

	const CoinPackedMatrix * M =  m_osInterface.getCoinPackedMatrix();
	const int * ind = M->getIndices();
	const int * beg = M->getVectorStarts();
	const int * len = M->getVectorLengths();
	const int * indR = NULL;

	//---
	//--- which columns are present in this part's rows
	//---
	int k, r;
	vector<int>::const_iterator it;
	for (it = rowsPart.begin(); it != rowsPart.end(); it++) {
		r = *it;
		indR = ind + beg[r];
		for (k = 0; k < len[r]; k++) {
			activeColsSet.insert(indR[k]);
		}
	}
}


//===========================================================================//
void Bearcat_DecompApp::createModelPart(DecompConstraintSet * model,
		const int nRowsPart, const int * rowsPart) {

	const int nCols =  m_osInterface.getVariableNumber();
	const double * rowLB =  m_osInterface.getRowLower();
	const double * rowUB =  m_osInterface.getRowUpper();
	const double * colLB =  m_osInterface.getColLower();
	const double * colUB =  m_osInterface.getColUpper();
	const char * integerVars =  m_osInterface.getIntegerColumns();
	
	std::cout << "GAIL IS STARTING createModelPart" << std::endl;

	model->M = new CoinPackedMatrix(false, 0.0, 0.0);
	if (!model->M)
		throw UtilExceptionMemory("createModels", "Bearcat_DecompApp");
	model->reserve(nRowsPart, nCols);
	model->M->submatrixOf(* m_osInterface.getCoinPackedMatrix(), nRowsPart, rowsPart);

	//---
	//--- set the row upper and lower bounds
	//--- set the col upper and lower bounds
	//---
	int i, r;
	for (i = 0; i < nRowsPart; i++) {
		r = rowsPart[i];
		if (m_appParam.UseNames) {
			const char * rowName =  m_osInterface.getConstraintNames()[r].c_str();
			if (rowName)
				model->rowNames.push_back(rowName);
		}
		model->rowLB.push_back(rowLB[r]);
		model->rowUB.push_back(rowUB[r]);
	}
	copy(colLB, colLB + nCols, back_inserter(model->colLB));
	copy(colUB, colUB + nCols, back_inserter(model->colUB));

	//---
	//--- big fat hack... we don't deal with dual rays yet,
	//---  so, we assume subproblems are bounded
	//---
	//--- NOTE: might also need to tighten LBs
	//---
	//--- Too small - ATM infeasible!
	//--- Too big   - round off issues with big coeffs in 
	//---             master-only vars
	//---
	//--- TODO: need extreme rays or bounded subproblems from user
	//---
	
	/*
	if (m_appParam.ColumnUB < 1.0e15) {
		for (i = 0; i < nCols; i++) {
			if (colUB[i] > 1.0e15) {
				model->colUB[i] = m_appParam.ColumnUB;
			}
		}
	}
	if (m_appParam.ColumnLB > -1.0e15) {
		for (i = 0; i < nCols; i++) {
			if (colLB[i] < -1.0e15) {
				model->colLB[i] = m_appParam.ColumnLB;
			}
		}
	}
*/
	//---
	//--- set the indices of the integer variables of modelRelax
	//---  also set the column names, if they exist
	//---
	for (i = 0; i < nCols; i++) {
		if (m_appParam.UseNames) {
			//const char * colName =  m_osInterface.columnName(i);
			const char * colName =  m_osInterface.getConstraintNames()[ i].c_str();
			
			if (colName)
				model->colNames.push_back(colName);
		}
		if (integerVars && integerVars[i]) {
			model->integerVars.push_back(i);
		}
	}
}

//===========================================================================//
void Bearcat_DecompApp::createModelPartSparse(DecompConstraintSet * model,
		const int nRowsPart, const int * rowsPart) {

	const int nColsOrig =  m_osInterface.getVariableNumber();
	const double * rowLB =  m_osInterface.getRowLower();
	const double * rowUB =  m_osInterface.getRowUpper();
	const double * colLB =  m_osInterface.getColLower();
	const double * colUB =  m_osInterface.getColUpper();
	const char * integerVars =  m_osInterface.getIntegerColumns();

	//---
	//--- set model as sparse
	//---
	model->setSparse(nColsOrig);
	std::cout << "GAIL IS STARTING createModelSparse" << std::endl;
	int nCols, origIndex, newIndex;
	vector<int>::iterator vit;
	newIndex = 0;
	for (vit = model->activeColumns.begin(); vit != model->activeColumns.end(); vit++) {
		origIndex = *vit;
		
		std::cout << "lower bound = " << colLB[origIndex] << std::endl;
		std::cout << "upper bound = " << colUB[origIndex] << std::endl;

		model->pushCol(colLB[origIndex], colUB[origIndex],
				integerVars[origIndex] == 0 ? false : true, origIndex);

		//---
		//--- big fat hack... we don't deal with dual rays yet,
		//---  so, we assume subproblems are bounded
		//---
		/*
		if (m_appParam.ColumnUB < 1.0e15) {
			if (colUB[origIndex] > 1.0e15) {
				model->colUB[newIndex] = m_appParam.ColumnUB;
			}
		}
		if (m_appParam.ColumnLB > -1.0e15) {
			if (colLB[origIndex] < -1.0e15) {
				model->colLB[newIndex] = m_appParam.ColumnLB;
			}
		}
		*/

		if (m_appParam.UseNames) {
			//const char * colName =  m_osInterface.columnName(origIndex);
			const char * colName =  m_osInterface.getConstraintNames()[origIndex].c_str();
			
			
			if (colName)
				model->colNames.push_back(colName);
		}
		newIndex++;
	}

	nCols = static_cast<int> (model->activeColumns.size());
	assert(static_cast<int> (model->colLB.size()) == nCols);
	assert(static_cast<int> (model->colUB.size()) == nCols);

	model->M = new CoinPackedMatrix(false, 0.0, 0.0);
	if (!model->M)
		throw UtilExceptionMemory("createModels", "Bearcat_DecompApp");
	model->M->setDimensions(0, nCols);
	model->reserve(nRowsPart, nCols);

	//---
	//--- for each row in rowsPart, create the row using sparse mapping
	//---
	int i, k, r, begInd;
	const map<int, int> & origToSparse = model->getMapOrigToSparse();
	const CoinPackedMatrix * M =  m_osInterface.getCoinPackedMatrix();
	const int * matInd = M->getIndices();
	const CoinBigIndex * matBeg = M->getVectorStarts();
	const int * matLen = M->getVectorLengths();
	const double * matVal = M->getElements();
	const int * matIndI = NULL;
	const double * matValI = NULL;

	vector<CoinBigIndex> & rowBeg = model->m_rowBeg;//used as temp
	vector<int> & rowInd = model->m_rowInd;//used as temp
	vector<double> & rowVal = model->m_rowVal;//used as temp
	map<int, int>::const_iterator mit;

	begInd = 0;
	rowBeg.push_back(0);
	for (i = 0; i < nRowsPart; i++) {
		r = rowsPart[i];
		if (m_appParam.UseNames) {
			const char * rowName =  m_osInterface.getConstraintNames()[r].c_str();
			if (rowName)
				model->rowNames.push_back(rowName);
		}
		model->rowLB.push_back(rowLB[r]);
		model->rowUB.push_back(rowUB[r]);

		matIndI = matInd + matBeg[r];
		matValI = matVal + matBeg[r];
		for (k = 0; k < matLen[r]; k++) {
			origIndex = matIndI[k];
			mit = origToSparse.find(origIndex);
			assert(mit != origToSparse.end());
			rowInd.push_back(mit->second);
			rowVal.push_back(matValI[k]);
		}
		begInd += matLen[r];
		rowBeg.push_back(begInd);
	}
	model->M->appendRows(nRowsPart, &rowBeg[0], &rowInd[0], &rowVal[0]);
	rowBeg.clear();
	rowInd.clear();
	rowVal.clear();
}

//===========================================================================//
void Bearcat_DecompApp::createModels() {
	std::cout << "GAIL 1" << std::endl;

	UtilPrintFuncBegin(m_osLog, m_classTag, "createModels()",
			m_appParam.LogLevel, 2);
	int i;
	//---
	//--- how many rows to put into relaxation
	//---
	int nRowsRelax, nRowsCore;
	std::cout << "GAIL 1" << std::endl;
	const int nRows =  m_osInterface.getConstraintNumber();
	std::cout << "GAIL 2" << std::endl;
	const int nCols =  m_osInterface.getVariableNumber();

	
	//kipp -- problem specific change later
	int nBlocks = 3;
	nRowsRelax = 15;

	nRowsCore = nRows - nRowsRelax;

	UTIL_MSG(m_appParam.LogLevel, 2,
		(*m_osLog) << "Instance    = " << m_appParam.Instance << endl;
		(*m_osLog) << " nRows      = " << nRows << endl;
		(*m_osLog) << " nCols      = " << nCols << endl;
		(*m_osLog) << " nBlocks    = " << nBlocks << endl;
		(*m_osLog) << " nRowsCore  = " << nRowsCore << endl;
		(*m_osLog) << " nRowsRelax = " << nRowsRelax << " [ " << 100
				* nRowsRelax / nRows << " % ]" << endl;
		);
	
	   //---
	   //--- setup markers for core and relax rows
	   //---   
	   int * rowsMarker = new int[nRows];
	   int * rowsCore   = new int[nRowsCore];   
	   UtilFillN(rowsMarker, nRows, -1);//-1 will mark core rows
	   

	   //kipp -- hard wired
		//Now define the core model -- for simple plant location this
		// is the assignment constraints, rows 1-5.s
	   
	   for(i = 0; i < nRows; i++){
		   if( i > 4 ){
			   rowsMarker[i] = i;
		   }
		   
	   }
	   
	   int nRowsCoreTmp  = 0;
	   for(i = 0; i < nRows; i++){
	      if(rowsMarker[i] == -1)
	         rowsCore[nRowsCoreTmp++]   = i;
	   }
	   assert(nRowsCoreTmp == nRowsCore);
	   
	   UTIL_MSG(m_appParam.LogLevel, 3,
			   (*m_osLog) << "Core  Rows:";
	            for(i = 0; i < nRowsCore; i++)
	               (*m_osLog) << rowsCore[i] << " ";
	            (*m_osLog) << "\n";
	            );
	      
	
	
	//First the define the objective function over the entire variable space
	//Create the memory for the objective  function
	m_objective  =  new double[ nCols];
	for(i = 0; i  < nCols; i++){
		m_objective[ i] = m_osInterface.getObjectiveFunctionCoeff()[ i];
		std::cout << "obj coeff = " << m_objective[ i] << std::endl;
	}
	setModelObjective(m_objective);
	


	//---
	//--- Construct the core matrix.
	//---
	DecompConstraintSet * modelCore = new DecompConstraintSet();
	createModelPart(modelCore, nRowsCore, rowsCore);
	
	m_modelC = modelCore;
	setModelCore(modelCore, "core");

	//---
	//--- save a pointer so we can delete it later
	//---
	m_modelC = modelCore;
	
	// Now construct the relaxation matrices
	//kipp hard code do one by one
	//block 1
    DecompConstraintSet * modelRelax1 = new DecompConstraintSet();
    CoinAssertHint(modelRelax1, "Error: Out of Memory");
    
    //---
    //--- find and set active columns

    //block 1

	int * rowsRelax1   = new int[ 5 ]; 
    nRowsRelax = 5;
    

    
    rowsRelax1[0] = 5;
    rowsRelax1[1] = 6;
    rowsRelax1[2] = 7;
    rowsRelax1[3] = 8;
    rowsRelax1[4] = 9;
    
    

	modelRelax1->activeColumns.push_back(0);
	modelRelax1->activeColumns.push_back(1);
	modelRelax1->activeColumns.push_back(2);
	modelRelax1->activeColumns.push_back(3);
	modelRelax1->activeColumns.push_back(4);
	modelRelax1->activeColumns.push_back(15);
    
    if(m_appParam.LogLevel >= 3){
	 (*m_osLog) << "Active Columns 1:" << endl;
	 UtilPrintVector(modelRelax1->activeColumns, m_osLog);
	 if(modelCore->getColNames().size() > 0)
	    UtilPrintVector(modelRelax1->activeColumns, 
			    modelCore->getColNames(), m_osLog);
    }
    createModelPartSparse(modelRelax1, nRowsRelax, rowsRelax1);
    m_modelR.insert(make_pair( 1, modelRelax1) );
    setModelRelax(modelRelax1, "relax1", 0);
    

    //block 2
    DecompConstraintSet * modelRelax2 = new DecompConstraintSet();
    CoinAssertHint(modelRelax2, "Error: Out of Memory");
	
	int * rowsRelax2   = new int[5 ]; 
    nRowsRelax = 5;
    rowsRelax2[0] = 10;
    rowsRelax2[1] = 11;
    rowsRelax2[2] = 12;
    rowsRelax2[3] = 12;
    rowsRelax2[4] = 14;
    
	modelRelax2->activeColumns.push_back(5);
	modelRelax2->activeColumns.push_back(6);
	modelRelax2->activeColumns.push_back(7);
	modelRelax2->activeColumns.push_back(8);
	modelRelax2->activeColumns.push_back(9);
	modelRelax2->activeColumns.push_back(16);
    
    if(m_appParam.LogLevel >= 3){
	 (*m_osLog) << "Active Columns 2:" << endl;
	 UtilPrintVector(modelRelax2->activeColumns, m_osLog);
	 if(modelCore->getColNames().size() > 0)
	    UtilPrintVector(modelRelax2->activeColumns, 
			    modelCore->getColNames(), m_osLog);
    }
    createModelPartSparse(modelRelax2, nRowsRelax, rowsRelax2);
    m_modelR.insert(make_pair( 2, modelRelax2) );
    setModelRelax(modelRelax2, "relax2", 1);
    
    
    //block 3
    DecompConstraintSet * modelRelax3 = new DecompConstraintSet();
    CoinAssertHint(modelRelax3, "Error: Out of Memory");

	int * rowsRelax3 = new int[5 ]; 
    nRowsRelax = 5;
    rowsRelax3[0] = 15;
    rowsRelax3[1] = 16;
    rowsRelax3[2] = 17;
    rowsRelax3[3] = 18;
    rowsRelax3[4] = 19;
    
	modelRelax3->activeColumns.push_back(10);
	modelRelax3->activeColumns.push_back(11);
	modelRelax3->activeColumns.push_back(12);
	modelRelax3->activeColumns.push_back(13);
	modelRelax3->activeColumns.push_back(14);
	modelRelax3->activeColumns.push_back(17);
    

	(*m_osLog) << "Active Columns 3:" << endl;

	UtilPrintVector(modelRelax3->activeColumns, m_osLog);
	if(modelCore->getColNames().size() > 0)
		UtilPrintVector(modelRelax3->activeColumns, 
				modelCore->getColNames(), m_osLog);
	
	createModelPartSparse(modelRelax3, nRowsRelax, rowsRelax3);
	m_modelR.insert(make_pair( 3, modelRelax3) );
	setModelRelax(modelRelax3, "relax3", 2);

    

 
	UtilPrintFuncBegin(m_osLog, m_classTag,
			"printCurrentProblem()", m_appParam.LogLevel, 2);   

}// end createModels()



//===========================================================================//
/**
void Bearcat_DecompApp::createModelMasterOnlys2(vector<int> & masterOnlyCols) {

	//int nBlocks = static_cast<int> (m_blocks.size());
	//kipp -- problem specific
	int nBlocks = 3;
	const int nCols =  m_osInterface.getVariableNumber();
	const double * colLB =  m_osInterface.getColLower();
	const double * colUB =  m_osInterface.getColUpper();
	const char * integerVars =  m_osInterface.getIntegerColumns();
	int nMasterOnlyCols = static_cast<int> (masterOnlyCols.size());

	if (m_appParam.LogLevel >= 1) {
		(*m_osLog) << "nCols           = " << nCols << endl;
		(*m_osLog) << "nMasterOnlyCols = " << nMasterOnlyCols << endl;
	}

	if (nMasterOnlyCols == 0)
		return;

	int i;
	vector<int>::iterator vit;
	for (vit = masterOnlyCols.begin(); vit != masterOnlyCols.end(); vit++) {
		i = *vit;

		//THINK:
		//  what-if master-only var is integer and bound is not at integer

		DecompConstraintSet * model = new DecompConstraintSet();
		model->m_masterOnly = true;
		model->m_masterOnlyIndex = i;
		model->m_masterOnlyLB = colLB[i];
		model->m_masterOnlyUB = colUB[i];
		//0=cont, 1=integer
		model->m_masterOnlyIsInt = integerVars[i] ? true : false;
		if (m_appParam.ColumnUB < 1.0e15)
			if (colUB[i] > 1.0e15)
				model->m_masterOnlyUB = m_appParam.ColumnUB;
		if (m_appParam.ColumnLB > -1.0e15)
			if (colLB[i] < -1.0e15)
				model->m_masterOnlyLB = m_appParam.ColumnLB;

		//m_modelR.insert(make_pair(nBlocks, model));
		setModelRelax(model, "master_only" + UtilIntToStr(i), nBlocks);
		nBlocks++;
	}

	return;
}//end createModelMasterOnlys2

*/


int Bearcat_DecompApp::generateInitVars(DecompVarList & initVars){

   //---
   //--- generateInitVars is a virtual method and can be overriden
   //---   if the user has some idea how to initialize the list of 
   //---   initial variables (columns in the DW master)
   //---
	std::cout << "GENERATE INIT VARS" << std::endl;
   UtilPrintFuncBegin(m_osLog, m_classTag, "generateInitVars()",  m_appParam.LogLevel, 2);

   //---
   //--- To follow the example in the chapter: (4,1) and (5,5)
   //---
   int    indPlant1 [6] = {0, 1, 2, 3, 4, 15};
   int    indPlant2 [6] = {5, 6, 7, 8, 9, 16};
   int    indPlant3 [6] = {10, 11, 12, 13, 14, 17};
   int whichBlock;
   DecompVar *var;
   
   double els[6] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
   
   whichBlock = 0;
   var = new DecompVar(6, indPlant1, els, 23.0);
   var->setBlockId(whichBlock);
   initVars.push_back( var);

   
   whichBlock = 1;
   var = new DecompVar(6, indPlant2, els, 19.0);
   var->setBlockId(whichBlock);
   initVars.push_back( var);
   
   whichBlock = 2;
   var = new DecompVar(6, indPlant3, els, 18.0);
   var->setBlockId(whichBlock);
   initVars.push_back(var);
   
   UtilPrintFuncEnd(m_osLog, m_classTag, "generateInitVars()",  m_appParam.LogLevel, 2);
   return static_cast<int>(initVars.size());
}