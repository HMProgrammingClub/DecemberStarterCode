from os import listdir
from os.path import isfile, join

# A class representing a point. Has x, y, and z components to denote its location in space
# The index variable denotes the order in which the point was read in.
# ex. first point in the input file has index = 0
class Point:
	def __init__(self, x, y, z, index):
		self.x = x
		self.y = y
		self.z = z
		self.index = index

# Returns a 2d list of points
# Each list inside the 2d list is the set of points for ONE INDIVIDUAL PROBLEM
# So for each list in the 2d list, you must try to find the shortest path between the points in that list
def getProblems():
	path = "input/"
	problems = []
	for a in range(0, 20):
		with open(path+str(a+1)+".txt", "r") as f:
			points = []
			lines = f.readlines()
			points = []
			index = 0
			for line in lines:
				components = line.split(" ")
				points.append(Point(int(components[0]), int(components[1]), int(components[2]), index))
				index += 1
			problems.append(points)
	return problems

# Given a 2d list made up of a list of points in the order of your chosen path for each problems,
# this function prints your solution to a file called 'output.txt'. This is the file that we will grade.
def outputSolutionsToFile(name, solutions):
	content = name+"\n"
	for points in solutions:
		for point in points: 
			content += str(point.index) + " "
		content += "\n"
	open("output.txt", "w").write(content)

# 2d list to hold your solutions
solutions = []

# Loads the problems into a 2d array
problems = getProblems()

for points in problems:
	
	# PUT YOUR CODE HERE
	# Find the shortest path between all the points in 'points'

	# Add your chosen 'path' aka. an ordered list of points to the solutions list
	# (the salesman starts at the first point in the list and visits each one as they are ordered)
	solutions.append(points)

# PUT YOUR NAME HERE
outputSolutionsToFile("Michael Truell", solutions)
