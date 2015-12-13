import java.util.*;
import java.io.*;

public class DecemberCompetition {
	// A class representing a point. Has x, y, and z components to denote its location in space
	// The index variable denotes the order in which the point was read in.
	// ex. first point in the input file has index = 0
	static class Point {
		int x, y, z, index;
		public Point(int x, int y, int z, int index) {
			this.x = x;
			this.y = y;
			this.z = z;
			this.index = index;
		}
	}

	// Returns a 2d list of points
	// Each list inside the 2d list is the set of points for ONE INDIVIDUAL PROBLEM
	// So for each list in the 2d list, you must try to find the shortest path between the points in that list
	public static ArrayList<ArrayList<Point>> getProblems() {
		ArrayList<ArrayList<Point>> problems = new ArrayList<ArrayList<Point>>(0);
		for(int a = 0; a < 20; a++) {
			File fileEntry = new File("input/"+(a+1)+".txt");
			try (BufferedReader br = new BufferedReader(new FileReader(fileEntry))) {
				ArrayList<Point> points = new ArrayList<Point>(0);
				int index = 0;
				String line;
				while ((line = br.readLine()) != null) {
					String[] components = line.split(" ");
					points.add(new Point(
						Integer.parseInt(components[0]), 
						Integer.parseInt(components[1]), 
						Integer.parseInt(components[2]), 
						index));
					index++;
				}
				problems.add(points);
			} catch(Exception e) {
				e.printStackTrace();
				System.out.println("There was an error reading in your solutions. You should probably find Ben Spector, Luca Koval, or Michael Truell. They will fix this.");
			}
		}

		return problems;
	}

	// Given a 2d list made up of a list of points in the order of your chosen path for each problems,
	// this function prints your solution to a file called 'output.txt'. This is the file that we will grade.
	public static void outputSolutionsToFile(String name, ArrayList<ArrayList<Point>> solutions) {
		String content = name+"\n";
		for(ArrayList<Point> solution : solutions) {
			for(Point point : solution) {
				content += point.index + " ";
			}
			content += "\n";
		}

		try {
			FileWriter writer = new FileWriter(new File("output.txt"), false);
            writer.write(content);
            writer.close();
		} catch(Exception e) {
			e.printStackTrace();
			System.out.println("There was an error outputting your solutions. You should probably find Ben Spector, Luca Koval, or Michael Truell. They will fix this.");
		}
	}

	public static void main(String[] args) {
		// A 2d array containing an ArrayList for each problem
		ArrayList<ArrayList<Point>> problems = getProblems();

		// Will store your solutions
		ArrayList<ArrayList<Point>> solutions = new ArrayList<ArrayList<Point>>(0);
		
		for(ArrayList<Point> points : problems) {
			// PUT YOUR CODE HERE
			// Find the shortest path between all the points in 'points'

			// Add your chosen 'path' aka. an ordered list of points to the solutions list
			// (the salesman starts at the first point in the list and visits each one as they are ordered)
			solutions.add(points);
		}

		// PUT YOUR NAME HERE
		outputSolutionsToFile("Michael Truell", solutions);
	}
}