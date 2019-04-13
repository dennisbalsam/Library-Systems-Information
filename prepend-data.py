f = open("book-data.csv");

line = f.readline();
print(line, end="");

line = f.readline();
text = ["10.95", "20.00", "5.00", "16.69", "22.16","13.25","16.70","25.50","5.50"];

i = 0;
while line:

	if i == len(text):
		i = 0;

	print(text[i]+",", end="");
	print(line, end="");
	i += 1;
	line = f.readline();
