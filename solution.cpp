#include  <iostream>
#include  <bits/stdc++.h>
#include  <vector>
#include  <algorithm>
#include  <set>
#include  <map>

using namespace std;

set<string> included_tx_id; 

string fileName = "mempool.csv";
double maxweight = 4000000.0;

class Transaction
{
public:
    string tx_id;
    vector<string> parents;
    int fee;
    int weight;
};

pair<string, Transaction *> createTransaction(vector<string> &row)
{
    auto ans = new Transaction();
    ans->tx_id = row[0];
    ans->fee = stoi(row[1]);
    ans->weight = stoi(row[2]);
    vector<string> p;
    for (int i = 3; i < row.size(); i++)
    {
        p.push_back(row[i]);
    }
    ans->parents = p;
    return {row[0], ans};
}

void readCSV(string fileName, unordered_map<string, Transaction *> &umap)
{
    ifstream fin(fileName);
    vector<string> row;
    string temp, line, word;
    getline(fin, line);
    while (getline(fin, line))
    {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word); 
        }
        pair<string, Transaction *> p = createTransaction(row);
        umap[p.first] = p.second;
    }
    fin.close();
    cout << "Total number of transactions read: " << umap.size() << endl;
}

bool isValidTx(Transaction *tx, set<string> &included_tx_set)
{
    for (auto parent : tx->parents)
    {
        if (included_tx_set.find(parent) == included_tx_set.end())
            return false;
    }
    return true;
}
void writeOutput(vector<string> &included_tx_vector, string fn)
{
    ofstream myfile(fn);
    for (auto s : included_tx_vector)
        myfile << s << endl;
    myfile.close();
}
int main()
{
    unordered_map<string, Transaction *> umap;
    readCSV(fileName, umap);
    set<pair<float, Transaction *>, greater<pair<float, Transaction *>>> tx_set; 
    set<string> included_tx_set;                                                 
    vector<string> included_tx_vector;                                           
    for (auto p : umap)
    {
        tx_set.insert({(float)p.second->fee / (float)p.second->weight, p.second});
    }
    double currBlockWeight = 0.0;
    int totalFee = 0;
    while (!tx_set.empty() && currBlockWeight < maxweight)
    {
        bool found = false;
        for (auto itr = tx_set.begin(); itr != tx_set.end(); itr++)
        {
            Transaction *curr_tx = (*itr).second;
            int currFee = curr_tx->fee;
            int currWeight = curr_tx->weight;
            if (isValidTx(curr_tx, included_tx_set) && (currBlockWeight + currWeight) <= maxweight)
            {
                currBlockWeight += currWeight;
                included_tx_set.insert(curr_tx->tx_id);
                included_tx_vector.push_back(curr_tx->tx_id);
                totalFee = totalFee+currFee;
                tx_set.erase(itr);
                found = true;
                break;
            }
        }
        if (!found)
            break;
    }
    cout << "Number of tx in final block " << included_tx_set.size() << "\n";
    cout << "Total fee in curr block : " << totalFee<<"\n";
    cout << "Total weight : " << currBlockWeight<<"\n";
    double percentage=(currBlockWeight/maxweight)*100.0;
    cout<<"Percentage of weight: "<<percentage<<" %"<<"\n";
    cout<<"\n";
    writeOutput(included_tx_vector, "block.txt");
}