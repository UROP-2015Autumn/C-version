/*

	SimilarityCheck.cpp
		Find similarity between origin source and vulnerable code


	INPUT FILE
		origin.txt : origin assembly source code
		part.txt : vulnerable source code

		 - both assembly code was made by 'objdump' disassembler tool in CentOS(or any Linux)
		 - You should give '--no-show-raw-insn' option when you disassembled binary code(execute file)


	OUTPUT
		You will get jaccard containment and similarity.


*/

#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
using namespace std;

void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " "){
	//find first character & initialize
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos){
		// sentence push into the vector
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		//jump delimeter & find next one
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}
}

//make the opcode set from raw assembly code
void makeSet(int n, string inFile, set<string>& strSet){
	ifstream origin;
	string line, op, gram = "";
	vector<string> v;
	origin.open(inFile);
	//make gram
	for (int i = 1; !origin.eof(); ){
		getline(origin, line);
		if (line != ""){
			// remove address part
			Tokenize(line, v, "\t");
			if (v.size() > 1){
				//remove operand part
				Tokenize(v[1], v);
				op = v[2].substr(0, 3);
				//if operator is shorter than 3, add '_' character
				if (op.size() < 3)		op += "_";

				if (i <= n){
					gram += op;
					if (i == n) strSet.insert(gram);
					i++;
				}
				else{
					gram = (gram.substr(3, gram.size())) + op;
					strSet.insert(gram);
				}
			}
			v.clear();
		}
	}
	origin.close();
}

//calculate jaccard containment and similarity from origin code set and vulnerable code set
void jaccard(set<string> src, set<string> cmp){
	set<string>::iterator it;
	float intersection = 0;
	for (set<string>::iterator i = cmp.begin(); i != cmp.end(); i++){
		it = src.find(*i);
		if (it != src.end())
			intersection++;
	}
	float jac = intersection / (src.size() + cmp.size() - intersection);
	float contain = intersection / cmp.size();

	cout << "jaccard similarity : " << jac << endl;
	cout << "jaccard containment : " << contain << endl;

}

int main(void){
	int n;
	set<string> src, cmp;
	cout << "type the size of n : ";
	cin >> n;
	makeSet(n, "origin.txt", src);
	makeSet(n, "part.txt", cmp);

	cout << cmp.size() << endl;

	jaccard(src, cmp);

	return 0;
}

