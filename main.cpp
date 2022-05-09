#include <iostream>
#include <vector>

template<typename VT, typename CI>
void inputMatrix(VT &m, CI nRows, CI nCols) {
    for (int i = 0; i < nRows; i++) {
        std::vector<int> vectorCols(nCols);
        for (int j = 0; j < nCols; j++) {
            std::cin >> vectorCols.at(j);
        }
        m.push_back(vectorCols);
    }
}

template<typename VT, typename CI>
void countMarksForEachSubject(const VT &m, CI nRows, CI nCols) {
    int numberOfExam = 0;
    for (int i = 0; i < nCols; i++) {
        int absenceCounter = 0;
        int unsatisfactoryMarksCounter = 0;
        int satisfactoryMarksCounter = 0;
        int goodMarksCounter = 0;
        int excellentMarksCounter = 0;
        numberOfExam++;

        for (int j = 0; j < nRows; j++) {
            switch (m.at(j).at(i)) {
                case 1: {
                    absenceCounter++;
                    break;
                }
                case 2: {
                    unsatisfactoryMarksCounter++;
                    break;
                }
                case 3: {
                    satisfactoryMarksCounter++;
                    break;
                }
                case 4: {
                    goodMarksCounter++;
                    break;
                }
                case 5: {
                    excellentMarksCounter++;
                    break;
                }
            }
        }
        std::cout << "\n--- " << numberOfExam << " exam ---\n";
        std::cout << "Missing people: " << absenceCounter << '\n';
        std::cout << "Unsatisfactory marks: " << unsatisfactoryMarksCounter << '\n';
        std::cout << "Satisfactory marks: " << satisfactoryMarksCounter << '\n';
        std::cout << "Good marks: " << goodMarksCounter << '\n';
        std::cout << "Excellent marks: " << excellentMarksCounter << '\n';
    }
}

int main() {
    int nStudents, nSubjects;
    std::cin >> nStudents >> nSubjects;

    std::vector<std::vector<int>> m;
    inputMatrix(m, nStudents, nSubjects);
    countMarksForEachSubject(m, nStudents, nSubjects);

    return 0;
}