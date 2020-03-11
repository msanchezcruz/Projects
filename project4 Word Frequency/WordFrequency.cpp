


#include "WordFrequency.h"


WordFrequency::WordFrequency(){

	unorderedMap.insert({ "" , 0 });



}
void WordFrequency::readIn(const string & filename){

	std::ifstream infile;
	infile.open(filename);
	string word; // stores the current word in the text file
	
	while(!infile.eof()){ // while it is not the end of file

		infile >> word; //take string and save into word
		
		//NOTE: S   anitize function was not removing the punctuations
	    //sanitize(word); // sanitizes the word by removing all punctuation

	    //using this method to remove punctuations
		for (int i = 0, len = word.size(); i < len; i++){
        	if (ispunct(word[i]))
        		{
           			word.erase(i--, 1);
            		len = word.size();
        		}
    		}
		//iterator to point to the returned iterator of the find function
		std::unordered_map<std::string, size_t>::iterator it;

		//assign the iterator to where the word is located
		it =unorderedMap.find(word);

		//std::cout << "word " << word << "         " ;

		// if it is found then we increment the words value by 1
		if(it != unorderedMap.end()){

			//std::cout << it->first <<"::"<< it->second << std::endl;
			it->second += 1;			

		//if it is not found then we add the word to the map
		}else{
		
		unorderedMap.insert({word, 1});
		words++;

		}//end else 	

	}//end while loop-----------------------------------------------
    		
    	

	

}
size_t WordFrequency::numberOfWords(){

	// returns the number of buckets in the map
		return words;

}
size_t WordFrequency::wordCount(const string & word){

	std::unordered_map<std::string, size_t>::iterator it;
	it = unorderedMap.find(word);

  size_t  wordcount = it->second;
  //std::cout << it->first << " --->>>" << it->second << std::endl;

	return it->second;

}
string WordFrequency::mostFrequentWord(){
	
		size_t tracker = 0; // keeps track of the bucket size
		string mostUsed = ""; // initialize most used to an empty string

		//for loop to iterate through the unordered_map
	for ( auto it = unorderedMap.begin(); it != unorderedMap.end(); ++it ){
	 	
	 	//if the size of the bucket is larger than previous 
	 	if( it->second > tracker){

	 		//assign the current iterator tracker value and string to variables
	 		tracker = it->second;
	 		mostUsed = it->first;
	 	}
	 }
	

    

	//get te max bucket size and and return the string

	return  mostUsed;
}
size_t WordFrequency::maxBucketSize(){

	//keeps track of the largest bucket
	size_t tracker = 0;

	//store the number of buckets in the map
	size_t nbuckets = unorderedMap.bucket_count();//nbuckets = unorderedMap.bucket_count();
	
	//iterate through all the buckets
	for ( size_t i = 0 ; i < nbuckets ; ++i ){
	 	
	 	//if the size of the current bucket is larger than the tracker 
		//update tracker with size of current bucket
	 	if(tracker < unorderedMap.bucket_size(i)){

	 		//update tracker 
	 		tracker = unorderedMap.bucket_size(i);

	 		//test
	 		//std::cout << tracker << std::endl;
	 		}
	 	//std::cout << "bucket #" << i << " has " << unorderedMap.bucket_size(i) << " elements.\n";
	 }


  


	return tracker;

}
