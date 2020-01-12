#ifndef SEQUENCE_MAP_H
#define SEQUENCE_MAP_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class SequenceMap{
public:
	SequenceMap(const string &a_rec_seq, const string &an_enz_acro){
		recognition_sequence_ = a_rec_seq;
		enzyme_acronyms_.push_back(an_enz_acro);
	}

	bool operator<(const SequenceMap&rhs) const{
		if(rhs.recognition_sequence_ < recognition_sequence_){
			return true;
		}else{
			return false;
		}
	}

	friend std::ostream &operator<<(std::ostream &out, const SequenceMap &a_secquence_map){
		for( auto it = a_secquence_map.enzyme_acronyms_.begin() ; it != a_secquence_map.enzyme_acronyms_.end() ; it++){
			cout<<*it<<' ';
		}
		return out;
	}

	void merge(const SequenceMap &other_sequence){
		for( auto it = other_sequence.enzyme_acronyms_.begin() ; it!=other_sequence.enzyme_acronyms_.end()  ; it++){
			enzyme_acronyms_.push_back(*it);
		}
	}

	bool operator==(const SequenceMap&rhs) const{
		if (recognition_sequence_ == rhs.recognition_sequence_){
			return true;
		}
		else{
			return false;
		}
	}

	string getSequence() const {
		return recognition_sequence_;
	}

private:
	string recognition_sequence_ ;
	vector<string> enzyme_acronyms_;

};
#endif