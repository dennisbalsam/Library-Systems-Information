f = open("book-data.csv");

line = f.readline();
print(line, end="");

line = f.readline();
text = ["2.00","4.00","6.00"];

i = 0;
while line:

	if i == len(text):
		i = 0;

	print(text[i]+",", end="");
	print(line, end="");
	i += 1;
	line = f.readline();
