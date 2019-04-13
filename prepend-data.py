f = open("book-data.csv");

line = f.readline();
print(line, end="");

line = f.readline();
text = ["5", "15", "3", "10", "7", "14", "8", "20"];

i = 0;
while line:

	if i == len(text):
		i = 0;

	print(text[i]+",", end="");
	print(line, end="");
	i += 1;
	line = f.readline();
