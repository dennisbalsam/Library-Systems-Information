#include <string>
#include "Date.h"

class BookInformation
{
private:
	String title, author, subject, id, publisher;
	Date publishingDate, dueDate;
	int status, circulationPeriod, location;
	double costOfBook, finePerDayOverdue
public:
	BookInformation();
	BookInformation(String t, String a, String s, String i, String p, Date pubD, Date dueD, double fine, double cost, int l, const int &st = 1, int circ)
		: title(t), address(a), subject(s), id(i), publisher(p),publishingDate(pubD), dueDate(dueD), location(l), finePerDayOverdue(fine), costOfBook(cost),
		status(st), circulationPeriod(circ) {}

	void setTitle(String t);
	void setAuthor(String a);
	void setSubject(String s);
	void setID(String i);
	void setPublisher(String p);

	void setPublishingDate(Date d);
	void setPublishingDate(int d, int m, int y);
	void setDueDate(Date d);
	void setDueDate(int d, int m, int y);

	void setLocation(int l);
	void setStatus(int s); // int values: [ 0: Unavailable / 1: Available / 2: Hold / 3: Maintenance ]
	void setCirculationPeriod(int c); // int value in amount of DAYS

	void setCostOfBook(double c); // $ - . - -
	void setFinePerDayOverdue(double f);
	void setFinePerDayOverdue();

	String getTitle();
	String getAuthor();
	String getSubject();
	String getID();
	String getPublisher();
	String getLocation();

	Date getPublishingDate();
	Date getDueDate();

	int getStatus();
	int getCirculationPeriod();

	double getCostOfBook();
	double getFinePerDayOverdue();
};
