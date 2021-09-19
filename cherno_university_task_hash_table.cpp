#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void CP(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

class HashTable{
	private:
		enum Status { not_used, occupied, tombstone };
		string status_to_string(Status st){
			if(st == not_used) return "(not_used)";
			if(st == occupied) return "(occupied)";
			if(st == tombstone) return "(tombstone)";
		}
	private:
		static const int size = 26;
		struct HashNode{
			string data;
			Status status = not_used;
		};
		HashNode table[size];
	public:
		void print(){
			bool putSpace = false;
			for(int i=0; i<size; i++) if(table[i].status == occupied){
				cout << (putSpace?" ":"") << table[i].data;
				putSpace = true;
			}
		}
		void completePrint(){
			cout << "\nComplete Print:\n";
			for(int i=0; i<size; i++){
				cout << table[i].data << " " << status_to_string(table[i].status) << "\n";
			}
		}
		void add(string addString){
			auto find = [=](){
				int index = addString.back() - 'a';
				while(1){
					if(table[index].data == addString) return -1;
					if(table[index].status != occupied) return index;
					index = (index + 1)%size;
				}
			};
			int index = find();
			if(index != -1){
				table[index].data = addString;
				table[index].status = occupied;
			}
		}
		void remove(string removeString){
			auto find = [=](){
				int index = removeString.back() - 'a';
				while(1){
					if(table[index].status == not_used) return -1;
					if(table[index].data == removeString) return index;
					index = (index + 1)%size;
				}
			};
			int index = find();
			if(index != -1){
				table[index].status = tombstone;
				table[index].data = "";
			}
		}
};

int main(){
	CP();
	string inputLine, query; getline(cin, inputLine);
	stringstream queryStream(inputLine);
	HashTable table;
	while(getline(queryStream, query, ' ')){
		if(query.length() == 0) continue;
		switch(query[0]){
			case 'A' : table.add(query.substr(1)); break;
			case 'D' : table.remove(query.substr(1)); break;
			default : cout << "Invalid Input: " << query << "\n"; exit(0);
		}
	}
	table.print();
	// table.completePrint();
	return 0;
}