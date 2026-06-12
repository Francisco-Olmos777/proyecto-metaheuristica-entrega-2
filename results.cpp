#include "results.h"
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void saveResult(const string& instName, int f, int makespan, const vector<int>& FA, const vector<int>& OS) {
    static set<int> initialized;

    bool first = (initialized.find(f) == initialized.end());
    auto mode  = first ? (ios::out | ios::trunc) : ios::app;

    string filename = "results_f" + to_string(f) + ".csv";
    ofstream file(filename, mode);

    if (!file) {
        cerr << "Error: no se pudo abrir " << filename << "\n";
        return;
    }

    if (first) {
        file << "instance,makespan,FA,OS\n";
        initialized.insert(f);
    }

    stringstream fa_ss, os_ss;
    
    fa_ss << "\"[";
    for (size_t i = 0; i < FA.size(); i++) {
        fa_ss << FA[i] << (i == FA.size() - 1 ? "" : ",");
    }
    fa_ss << "]\"";

    os_ss << "\"[";
    for (size_t i = 0; i < OS.size(); i++) {
        os_ss << OS[i] << (i == OS.size() - 1 ? "" : ",");
    }
    os_ss << "]\"";

    file << instName << "," << makespan << "," << fa_ss.str() << "," << os_ss.str() << "\n";
} 