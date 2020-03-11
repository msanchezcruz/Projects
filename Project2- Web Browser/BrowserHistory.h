#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>     // std::next, std::prev
#include <list>

using std::string;
using namespace std;

//-------------------------------------------
//struct to store webpage information
struct Pages {
    string url = " ";
    size_t pageSize = 0;

    Pages(string x, size_t y){
    	
    	url = x;
    	pageSize = y;
    }


};

class BrowserHistory {
public:
    BrowserHistory(){
  	item = ""; // holds the input of the if stream
	tempUrl= ""; // holds the url to add to page node
	tempSize = 0; // holds the size of the added page node
	sequenceLength = 0; // counts the length of the list
	currentPageUrl = ""; 	// stores url of page iterator is pointing to
	currentPSize  = 0; // stores page size of current page iterator is pointing to
	//it = sequence.begin();
		// add iterator 
	}
	
    void visitSite(string url, size_t filesize);
    void backButton();
    void forwardButton();

    void readFile(string fileName);

    string currentUrl();
    size_t currentPageSize();
    size_t getHistoryLength();
private:
  // TO BE COMPLETED
	string item; // holds the input of the if stream
	string tempUrl; // holds the url to add to page node
	size_t tempSize; // holds the size of the added page node

	size_t sequenceLength ; // counts the length of the list
	
	string currentPageUrl ; 	// stores url of page iterator is pointing to
	size_t currentPSize ; // stores page size of current page iterator is pointing to
	
	std::list<Pages>  sequence;
	std::list<Pages>::iterator it; // creates a list of pages names sequence
	//std::list<Pages>::iterator it;//moved to readfile
	

};
//--------------------------------------------------------------------------
//user visits a webpage with the given URl and given page size
void BrowserHistory::visitSite(string url, size_t filesize){
	currentPageUrl = url; //assigns passed in parameter to currentUrl
	currentPSize = filesize;//assigns passed in parameter to currentPsize
	


	//********push in new struct object to list*******
	Pages x(url, filesize);
	sequence.push_back(x);
	sequenceLength = sequence.size() ; // save size of list
	
}
//--------------------------------------------------------------------------
//curent webpage changes to the previous one in the sequence. 
//if there is no previous page return "empty"
void BrowserHistory::backButton(){//ieterator &
		
	for(std::list<Pages>::iterator x = sequence.begin(); x != (--sequence.end()); x++){
			currentPageUrl = (*x).url;
			currentPSize = (*x).pageSize;
			it = x;
			//cout << "it loop urls" << (*x).url << endl;
			
		}
		


		//cout << "address set in backbutton " << &(*it) << endl;



}


//--------------------------------------------------------------------------
//curent webpage changes to the previous one in the sequence. 
//if there is no previous page return "empty"
void BrowserHistory::forwardButton(){
	
		for(std::list<Pages>::iterator x = sequence.begin(); x != (--sequence.end()); x++){
			currentPageUrl = (*x).url;
			currentPSize = (*x).pageSize;
			it = x;
			//cout << "it loop urls" << (*x).url << endl;
			
		}
	
	
	
	
	
}

//--------------------------------------------------------------------------

void BrowserHistory::readFile(string fileName){
	
	std::ifstream file;
	file.open(fileName);
	std::list<Pages>::iterator it;
	it = sequence.begin();
	

	while( !file.eof()){ // while not the endof file
		file >> item; // assign the string to variable
		
	if(item == "visit"){
		sequenceLength++;
		//if item !== to forward url then delete all other nodes
		

		file >> tempUrl; // stores the next input to tempUrl
		file >> tempSize; // stores the next input after url to tempSize
		


		visitSite(tempUrl, tempSize );//adds another node to sequence

		
		
		
		for(std::list<Pages>::iterator x = sequence.begin(); x != sequence.end(); x++){

			it = x;//sets the iterator to the last node added	
		}
		//it = sequence.back();
		
		
		


	}else if(item == "back"){
		
		
		backButton();
		

	}else{
		
		
		forwardButton();
	}

}

}

//--------------------------------------------------------------------------
//current URL , if emty retyrn empty string
string BrowserHistory::currentUrl(){
	return currentPageUrl;//sequence.it.url;
	
}

//--------------------------------------------------------------------------
//page size, empty return 0
size_t BrowserHistory::currentPageSize(){

	return currentPSize;
	
}

//--------------------------------------------------------------------------
//returns the length of webpage visit sequence
size_t BrowserHistory::getHistoryLength(){
	return sequenceLength;

}












