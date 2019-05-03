#include "DPmat.h"
#include "string.h"
#include "algorithm"


//////////////////////////   A - C   D   E   F   G   H   I - K   L   M   N - P   Q   R   S   T - V   W - Y
int scoring_mat[20][20] = {{ 4,  0, -2, -1, -2,  0, -2, -1, -1, -1, -1, -2, -1, -1, -1,  1,  0,  0, -3, -2},
						   { 0,  9, -3, -4, -2, -3, -3, -1, -3, -1, -1, -3, -3, -3, -3, -1, -1, -1, -2, -2},
   						   {-2, -3,  6,  2, -3, -1, -1, -3, -1, -4, -3,  1, -1,  0, -2,  0, -1, -3, -4, -3},
   						   {-1, -4,  2,  5, -3, -2,  0, -3,  1, -3, -2,  0, -1,  2,  0,  0, -1, -2, -3, -2},
   						   {-2, -2, -3, -3,  6, -3, -1,  0, -3,  0,  0, -3, -4, -3, -3, -2, -2, -1,  1,  3},
   						   { 0, -3, -1, -2, -3,  6, -2, -4, -2, -4, -3,  0, -2, -2, -2,  0, -2, -3, -2, -3},
   						   {-2, -3, -1,  0, -1, -2,  8, -3, -1, -3, -2,  1, -2,  0,  0, -1, -2, -3, -2,  2},
   						   {-1, -1, -3, -3,  0, -4, -3,  4, -3,  2,  1, -3, -3, -3, -3, -2, -1,  3, -3, -1},
   						   {-1, -3, -1,  1, -3, -2, -1, -3,  5, -2, -1,  0, -1,  1,  2,  0, -1, -2, -3, -2},
   						   {-1, -1, -4, -3,  0, -4, -3,  2, -2,  4,  2, -3, -3, -2, -2, -2, -1,  1, -2, -1},
   						   {-1, -1, -3, -2,  0, -3, -2,  1, -1,  2,  5, -2, -2,  0, -1, -1, -1,  1, -1, -1},
   						   {-2, -3,  1,  0, -3,  0,  1, -3,  0, -3, -2,  6, -2,  0,  0, 1 ,  0, -3, -4, -2},
   						   {-1, -3, -1, -1, -4, -2, -2, -3, -1, -3, -2, -2,  7, -1, -2, -1, -1, -2, -4, -3},
   						   {-1, -3,  0,  2, -3, -2,  0, -3,  1, -2,  0,  0, -1,  5,  1,  0, -1, -2, -2, -1},
   						   {-1, -3, -2,  0, -3, -2,  0, -3,  2, -2, -1,  0, -2,  1,  5, -1, -1, -3, -3, -2},
   						   { 1, -1,  0,  0, -2,  0, -1, -2,  0, -2, -1,  1, -1,  0, -1,  4,  1, -2, -3, -2},
   						   { 0, -1, -1, -1, -2, -2, -2, -1, -1, -1, -1,  0, -1, -1, -1,  1,  5,  0, -2, -2},
   						   { 0, -1, -3, -2, -1, -3, -3,  3, -2,  1,  1, -3, -2, -2, -3, -2,  0,  4, -3, -1},
   						   {-3, -2, -4, -3,  1, -2, -2, -3, -3, -2, -1, -4, -4, -2, -3, -3, -2, -3, 11,  2},
   						   {-2, -2, -3, -2,  3, -3,  2, -1, -2, -1, -1, -2, -3, -1, -2, -2, -2, -1,  2,  7}};

DPmat::DPmat(){}
DPmat::DPmat(char* input_x, char* input_y)
{
	int i;

	LEN_OF_X = strlen(input_x);
	LEN_OF_Y = strlen(input_y);

	max_X = 0;
	max_Y = 0;
	max_score = 0;

	x = new int[LEN_OF_X];
	for(i = 0; i < LEN_OF_X; i++){
		x[i] = chr2int(input_x[i]);
	}

	y = new int[LEN_OF_Y];
	int length = LEN_OF_X;
	if(LEN_OF_X < LEN_OF_Y){
		length = LEN_OF_Y;
	}
	query_region = new int[length];
	template_region = new int[length];

	for(i = 0; i < LEN_OF_Y; i++){
		y[i] = chr2int(input_y[i]);
	}

	mat = new Cell* [LEN_OF_X+1];
	for (i = 0; i < LEN_OF_X+1; i++){
		mat[i] = new Cell[LEN_OF_Y+1];
	}

}

int DPmat::chr2int(char chr)
{
	if      ((chr == 'A')||(chr == 'a')) return 1;
	else if ((chr == 'C')||(chr == 'c')) return 2;
	else if ((chr == 'D')||(chr == 'd')) return 3;
	else if ((chr == 'E')||(chr == 'e')) return 4;
	else if ((chr == 'F')||(chr == 'f')) return 5;
	else if ((chr == 'G')||(chr == 'g')) return 6;
	else if ((chr == 'H')||(chr == 'h')) return 7;
	else if ((chr == 'I')||(chr == 'i')) return 8;
	else if ((chr == 'K')||(chr == 'k')) return 9;
	else if ((chr == 'L')||(chr == 'l')) return 10;
	else if ((chr == 'M')||(chr == 'm')) return 11;
	else if ((chr == 'N')||(chr == 'n')) return 12;
	else if ((chr == 'P')||(chr == 'p')) return 13;
	else if ((chr == 'Q')||(chr == 'q')) return 14;
	else if ((chr == 'R')||(chr == 'r')) return 15;
	else if ((chr == 'S')||(chr == 's')) return 16;
	else if ((chr == 'T')||(chr == 't')) return 17;
	else if ((chr == 'V')||(chr == 'v')) return 18;
	else if ((chr == 'W')||(chr == 'w')) return 19;
	else if ((chr == 'Y')||(chr == 'y')) return 20;
	else
	{
		cout << "Input Error! NOT valid character" << endl;
		exit(0);
	}
}
char DPmat::int2chr(int num)
{
	if      (num == 0) return '-';
	else if (num == 1) return 'A';
	else if (num == 2) return 'C';
	else if (num == 3) return 'D';
	else if (num == 4) return 'E';
	else if (num == 5) return 'F';
	else if (num == 6) return 'G';
	else if (num == 7) return 'H';
	else if (num == 8) return 'I';
	else if (num == 9) return 'K';
	else if (num == 10) return 'L';
	else if (num == 11) return 'M';
	else if (num == 12) return 'N';
	else if (num == 13) return 'P';
	else if (num == 14) return 'Q';
	else if (num == 15) return 'R';
	else if (num == 16) return 'S';
	else if (num == 17) return 'T';
	else if (num == 18) return 'V';
	else if (num == 19) return 'W';
	else if (num == 20) return 'Y';
	else
	{
		cout << "Output Error! NOT valid number(0~20)" << endl;
		exit(0);
	}

}
void DPmat::print_result()
{
	//cout << "length of similar region is " << LEN_OF_SIMREGION << endl;
	for(int i = 0; i < LEN_OF_SIMREGION; i++){
		cout << int2chr(query_region[LEN_OF_SIMREGION - 1 - i]) << " ";
	}
	cout << endl;

	for(int i = 0; i < LEN_OF_SIMREGION; i++){
		cout << int2chr(template_region[LEN_OF_SIMREGION - 1 - i]) << " ";
	}
	cout << endl;

	cout<<"Score : "<<max_score<<endl;
}

void DPmat::print_mat()
{
	cout << "<< score & flag of matrix>>"<< endl;
	int score;
	bool* flg;
	for(int i=0;i<LEN_OF_X+1;i++){
		for(int j=0;j<LEN_OF_Y+1;j++){
			score = mat[i][j].obtain_score();
			flg = mat[i][j].obtain_flag();
			cout << "[";
			for (int k=0; k<3; k++)
			{
				cout << flg[k] <<" ";
			}
			cout << score <<"]"<<"\t";
		}
		cout << "\n";
	}
	cout << endl;

}

void DPmat::fill_in_DPmat()
{

	// Initialize the first row and the first column of DPmat and fill in the remaining cells of DPmat with a score(S(i,j)) and a direction(flg(i,j))
	// To get a score(S(i,j)) and a direction(flg(i,j)) of a cell[i,j], perform following steps
	// 1st step: calculate three scores(S(i-1, j-1) + s(i,j), S(i-1,j)-6, S(i,j-1)-6)
	// 2nd step: compare three scores and take the highest one
	// 3rd step: save the highest score as score(S(i,j)) and its direction
	int score[3];
	bool find;
	int max_index;
	bool temp[3] = {0,0,1};

	for (int i=1;i<LEN_OF_X+1;i++){
		mat[i][0].set_scoreflag(0, temp);
	}
	temp[0] = 1;
	temp[2] = 0;
	for (int j=1;j<LEN_OF_Y+1;j++){
		mat[0][j].set_scoreflag(0, temp);
	}

	for (int i=1;i<LEN_OF_X+1;i++){
		for (int j=1;j<LEN_OF_Y+1;j++){
			bool temp[3] = {0,0,0};

			score[0] = mat[i][j-1].obtain_score()-calculate_gap_penalty(i, j, 0);
			score[1] = mat[i-1][j-1].obtain_score() + scoring_mat[x[i-1]-1][y[j-1]-1];
			score[2] = mat[i-1][j].obtain_score()-calculate_gap_penalty(i, j, 2);

			if(score[0]<=0 && score[1]<=0 && score[2]<=0){
				mat[i][j].set_scoreflag(0, temp);
				continue; }
			if(score[0]>=score[1] && score[0]>=score[2]){
				temp[0]=true; 
				max_index = 0;}
			if(score[1]>=score[0] && score[1]>=score[2]){
				temp[1]=true; 
				max_index = 1;}
			if(score[2]>=score[0] && score[2]>=score[1]){
				temp[2]=true; 
				max_index = 2;}
			mat[i][j].set_scoreflag(score[max_index],temp);

			// updating max score
			if(score[max_index]>=max_score){
				max_score = score[max_index];
				max_X = i;
				max_Y = j;
			}
		}
	}
}

int DPmat::calculate_gap_penalty(int i, int j, int direction){
	if(j>=1 && direction==0){
		if(mat[i][j-1].obtain_flag()[direction]==0){
			return 2;
		}
		else{
			return calculate_gap_penalty(i,j-1,0) + 2;
		}
	}

	else{
		if(i>=1 && mat[i-1][j].obtain_flag()[direction]==0){
			return 2;
		}
		else{
			return calculate_gap_penalty(i-1,j,2) + 2;
		}
	}
}

void DPmat::trace_back(int trace_back_i, int trace_back_j, int trace_back_cnt)
{

	// trace back the direction from mat[LEN_OF_X][LEN_OF_Y] by recursive process
	// modify z while tracing
	// print z and score of mat[LEN_OF_X][LEN_OF_Y] at the end of tracing using function 'DPmat::print_z_chr()'
	if(mat[trace_back_i][trace_back_j].obtain_score()==0){
		LEN_OF_SIMREGION = trace_back_cnt;
		print_result();
		return;
	}

	bool* current_flag = mat[trace_back_i][trace_back_j].obtain_flag();
	//cout<<"current_x: "<<trace_back_i<<"  current_y: "<<trace_back_j<<"  current_flag: "<<current_flag[0]<<current_flag[1]<<current_flag[2]<<" trace_back_count : "<<trace_back_cnt<<endl;
	if(current_flag[1]){ 
		query_region[trace_back_cnt] = x[trace_back_i-1];
		template_region[trace_back_cnt] = y[trace_back_j-1];
		trace_back(trace_back_i-1,trace_back_j-1,trace_back_cnt+1);
	}
	else if(current_flag[0]){
		query_region[trace_back_cnt] = 0;
		template_region[trace_back_cnt] = y[trace_back_j-1];
		trace_back(trace_back_i,trace_back_j-1,trace_back_cnt+1);
	}
	else if(current_flag[2]){
		query_region[trace_back_cnt] = x[trace_back_i-1];
		template_region[trace_back_cnt] = 0;
		trace_back(trace_back_i-1,trace_back_j,trace_back_cnt+1);
	}
}

DPmat::~DPmat()
{
	delete [] x;
	delete [] y;
	delete [] template_region;
	delete [] query_region;

	for(int i = 0; i<LEN_OF_X+1; i++) {
		delete [] mat[i];
	}
	delete [] mat;

}



