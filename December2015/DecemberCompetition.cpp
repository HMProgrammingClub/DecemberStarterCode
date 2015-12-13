#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>

//Note: As Ben Spector, author of this C++ file, I declare firmly that I hate same-line '{' in code, but because Michael used it for Java I felt I had a responsibility to be consistent. Thank you.

// A class representing a point. Has x, y, and z components to denote its location in space
// The index variable denotes the order in which the point was read in.
// ex. first point in the input file has index = 0
struct Point {
	int x, y, z, index;
};

// Sets a 2d vector to be the problems.
// Each vector inside the 2d vector is the set of points for ONE INDIVIDUAL PROBLEM
// So for each vector in the 2d vector, you must try to find the shortest path between the points in that vector
void getProblems(std::vector< std::vector<Point> > & pts) {
	pts.resize(20);
	for(int a = 0; a < 20; a++) {
		pts[a].resize(200);
		std::string filename = "input/" + std::to_string(a + 1) + ".txt";
		std::ifstream f;
		f.open(filename);
		for(int b = 0; b < 200; b++)
		{
			f >> pts[a][b].x >> pts[a][b].y >> pts[a][b].z;
			pts[a][b].index = b;
		}
		f.close();
	}
}

// Given a 2d vector made up of a vector of points in the order of your chosen path for each problems,
// this function prints your solution to a file called 'output.txt'. This is the file that we will grade.
void outputSolutionsToFile(std::string name, std::vector<std::vector<Point> * > solutions) {
	std::string content = name + '\n';
	for(auto a = solutions.begin(); a != solutions.end(); a++) {
		for(auto b = (*a)->begin(); b != (*a)->end(); b++) {
			content += std::to_string(b->index) + ' ';
		}
		content += '\n';
	}

	std::ofstream output;
	std::string filename = name + '-' + std::to_string(time(NULL)) + ".txt";
	output.open(filename);
	if(output.is_open()) {
		std::cout << content;
		output << content;
	} else {
		std::cout << "There was an error outputting your solutions. You should probably find Ben Spector, Luca Koval, or Michael Truell. They will fix this.";
		throw std::runtime_error("Couldn't open file");
	}
}

int main() {
	// A 2d array containing a vector for each problem
	std::vector<std::vector<Point>> problems;
	getProblems(problems);

	// Will store your solutions
	std::vector<std::vector<Point> * > solutions = std::vector<std::vector<Point> * >();

	for(auto a = problems.begin(); a != problems.end(); a++) {
		std::vector<Point> * solution = new std::vector<Point>();

		// PUT YOUR CODE HERE
		// Find the shortest path between all the points in 'points'

		//This code mimicks the input. Please replace it with your own.
		*solution = *a;

		// Add your chosen 'path' aka. an ordered vector of points to the solutions vector
		// (the salesman starts at the first point in the vector and visits each one as they are ordered)

		solutions.push_back(solution);
	}

	// PUT YOUR NAME HERE. If you don't, you won't get credit for your solution.
	try {
		outputSolutionsToFile("YOURNAME_HERE", solutions);
	} catch(std::runtime_error e) {
		system("PAUSE");
		return EXIT_FAILURE;
	}
	for(auto a = solutions.begin(); a != solutions.end(); a++) delete *a;

	system("PAUSE");
	return EXIT_SUCCESS;
}