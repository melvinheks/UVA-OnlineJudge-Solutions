#include <iostream>
#include <string>
#include <map>
using std::cin;
using std::cout;
using std::map;
using std::string;
using std::stoi;
using std::to_string;
string printlevels(map<string, int>& tree, size_t numrow){
	string out = "";
	for(size_t i = 0; i <=numrow; i++){
		for(map<string, int>::iterator it = tree.begin(); it != tree.end(); it++){
			string key = (*it).first;
			if((*it).first.length() == i){
				out += to_string((*it).second) + " ";
				if(key.length() > 0 && tree.find(key.substr(0, key.length()-1)) == tree.end()){
					return "not complete\n";
				}
			}
		}
	}
	return out.substr(0, out.length()-1) + "\n";
}
int main()
{
	map<string, int> tree;
	string s;

	string key = "";
	string val = "";

	size_t compos;

	string output = "";

	bool valid = true;

	size_t numrow = 0;
	while(cin >> s){
		compos = s.find(",");
		if(compos!=string::npos){
			val = s.substr(1, compos-1);
			key = s.substr(compos+1, s.length()-compos-2);
			if(key.length() > numrow)numrow = key.length();
			if(tree.find(key) == tree.end()){
				tree[key] = stoi(val);
			}
			else{
				valid = false;
			}
		}
		else{
			if(!valid){
				output += "not complete\n";
			}
			else{
				output += printlevels(tree, numrow);
			}
			tree.clear();
			numrow = 0;
			valid = true;
		}
	}
	cout << output;
}
