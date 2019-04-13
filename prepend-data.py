f = open("book-data-edit.csv");

line = f.readline();
print(line, end="");

line = f.readline();
text = [ "Random House", "Harper Collins", "Oxford Press", "Simon & Schuster", "Bloomsbury", "Springer", "Penguin Classics"];

i = 0;
while line:

	if i == len(text):
		i = 0;

	print(text[i]+",", end="");
	print(line, end="");
	i += 1;
	line = f.readline();
