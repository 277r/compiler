#include <iostream>
#include <fstream>
#include <sstream>
#include <string>



std::string preprocess(std::string input);
std::string loadFile(std::string name, bool isLocal);



// WARNING: add more exception errors for when circular includes or file unexistent
std::string loadFile(std::string name, bool isLocal){
	// open file
	std::ifstream file;
	
	if (isLocal) {
		file.open(name);
	}
	else {
		// open file un local
		file.open("h");
	}

	// flush whole file into rawData
	std::ostringstream sstr;
	sstr << file.rdbuf();
	// return the file preprocessed
	return preprocess(sstr.str());
}


std::string preprocess(std::string input){
	std::string outputData;




















	// preprocess and take 
	for (long i = 0; i < input.size(); i++){
		
		// variable declarations
		bool isDefineLocalFile;





		// first strings and chars
		// these must be copied, but there shouldn't be any sanitizing of it
		if (input[i] == '"') {
			outputData += input[i];
			i++;
			while (input[i] != '"' || input[i-1] == '\\' && i < input.size()){
				outputData += input[i];
				i++;	
			}
		}

		// char 
		else if (input[i] == '\'') {
			outputData += input[i];
			i++;
			while (input[i] != '\'' || input[i-1] == '\\'){
				outputData += input[i];
				i++;	
			}
		}
		
		// oh no
		else if (input[i] == '#'){
			i++;

			// debug
			std::cout << input.substr(i, 7);


			if (input.substr(i, 7) == "include"){
				i+= 7;
				
				
				// now get the include file
				while (input[i] != '"' && input[i] != '<') {
					i++;
				}



				// check if file local or not (in this directory or in globally set include directories)
				if (input[i] == '<'){
					isDefineLocalFile = false;
				}
				else {
					isDefineLocalFile = true;
				}
				// increment so we are at the name
				i++;
				std::string fileName;
				// expect include filenames to not contain a new line
				while (input[i] != '\n' && i < input.size()){
					fileName += input[i];
					i++;
				}
				

				// now, remove last part of string
				fileName.erase(fileName.size() -1);
				std::cout << fileName;

				// we got the file, now we need to load that file but this file might contain #includes, so we parse that file through this function
				outputData += loadFile(fileName, isDefineLocalFile);
				
				



			}



		}
		
		
		
		
		
		
		
		// comments
		else if (input[i] == '/'){
			if (i + 1 < input.size()){
				if (input[i+1] == '/'){
					i+=2;
					while (i < input.size() && input[i] != '\n'){
						i++;
					}
					i++;
				}
				/* comments*/
				if (input[i+1] == '*'){
					i+= 2;
					while (i + 1 < input.size() && input[i] != '*' || input[i+1] != '/'){
						i++;
					} 
					i+=2;
				}
			}
		}
		




		outputData += input[i];
	}
	return outputData;
}


int main(){
	std::ifstream x("in.cpp");
	std::ofstream y("out.pcf");

	std::stringstream buffer;
	buffer << x.rdbuf();

	y << preprocess(buffer.str());
	y.close();

}




















