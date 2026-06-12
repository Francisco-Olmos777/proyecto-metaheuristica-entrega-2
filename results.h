#pragma once
#include <string>
#include <vector>

// Guarda resultado en results_f{f}.csv
// Primera llamada por cada f crea el archivo con header; las siguientes hacen append.
void saveResult(const std::string& instName, int f, int makespan, const std::vector<int>& FA, const std::vector<int>& OS);