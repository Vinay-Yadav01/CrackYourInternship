/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int imp = 0;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->id == id) {
                imp += employees[i]->importance;
                if (employees[i]->subordinates.empty())
                    return imp;
                for (int j = 0; j < employees[i]->subordinates.size(); j++) {
                    imp +=
                        getImportance(employees, employees[i]->subordinates[j]);
                }
            }
        }
        return imp;
    }
};