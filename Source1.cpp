#include <iostream>
#include <iomanip>
#include <vector>

struct Row {
    std::string name;
    int age;
    std::string occupation;
};

void printTable(const std::vector<Row>& rows) {
    // Print table header
    std::cout << std::left << std::setw(20) << "Name"
        << std::setw(10) << "Age"
        << std::setw(20) << "Occupation" << std::endl;

    // Print table rows
    for (const auto& row : rows) {
        std::cout << std::setw(20) << row.name
            << std::setw(10) << row.age
            << std::setw(20) << row.occupation << std::endl;
    }
}

int main() {
    std::vector<Row> tableRows = {
        {"John Doe", 30, "Engineer"},
        {"Jane Smith", 25, "Designer"},
        {"Mike Johnson", 40, "Manager"}
    };

    printTable(tableRows);

    return 0;
}
