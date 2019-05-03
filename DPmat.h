#include <iostream>
#include <stdlib.h>
#include "Cell.h"

using namespace std;

#ifndef __DPMAT_H__
#define __DPMAT_H__

class DPmat
{
public:
	DPmat();
	DPmat(char* input_x, char* input_y);
	void print_result();
	void fill_in_DPmat();
	void print_mat();
	int calculate_gap_penalty(int i, int j, int direction);
	void trace_back(int trace_back_i, int trace_back_j, int trace_back_cnt);
	int chr2int(char chr);
	char int2chr(int num);

	int get_LEN_X(){ return LEN_OF_X; }
	int get_LEN_Y(){ return LEN_OF_Y; }
	int get_MAX_X(){ return max_X; }
	int get_MAX_Y(){ return max_Y; }
	int get_MAX_SCORE(){ return max_score; }
	~DPmat();

private:
	int* x;
	int* y;
	int* query_region;
	int* template_region;


	int LEN_OF_X;
	int LEN_OF_Y;
	int LEN_OF_SIMREGION;
	
	// variables for storing max index and max score
	int max_X;
	int max_Y;
	int max_score;

	Cell** mat;

};

#endif

