#include "Cell.h"
#include "DPmat.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	int* scores = new int[200];
 	int n = 0;
	char seq_query[] = "MITPLRRQFKRELKMSLPMLQVALDNQTLSHAYETTRLIAEEVDIIEVGTILCVGEGVRAVRDLKALYPHKIVLADAKIADAGKILSRMCFEANADWVTVICCADINTAKGALDVAKEFNGDVQIELTGFWTWEQAQEWRDAGIQQVVYHRSRDAQAAGVAWGEADISAIKRLADMGFKVTVTGGLALEDLPLFKGIPIHVFIAGRSIRDAASPVEAARQFKRSIAQLWG";

	std::ifstream myfile;
 	myfile.open("db/oneline.fa", ios::in);

 	std::string line;

	while(getline(myfile,line)){
		getline(myfile, line);
		char *seq_template = &line[0];

		DPmat SA(seq_query,seq_template);
		SA.fill_in_DPmat();

		scores[n] = SA.get_MAX_SCORE();
		n++;
	}
	myfile.close();

	for(int i=0; i<200; i++){
		int maxindex = 0;
		for(int j=0; j<200; j++){
			if (scores[maxindex]<scores[j]){
				maxindex = j;
			}
		}
		cout<<"template_"<<maxindex+1<<"\t"<<"score: "<<scores[maxindex]<<endl;
		scores[maxindex] = -1;
	}

	return 0;
}




