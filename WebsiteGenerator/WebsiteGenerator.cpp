// WebsiteGenerator.cpp: определяет точку входа для консольного приложения.
//
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string siteName, authorName, fileContent;
	ofstream mainPageFile;

	
	while (true)
	{
		cout << "Site name: ";
		if (getline(cin, siteName))
			break;
		cin.clear();
		cout << "Not valid site name. Please, try again.";
	}
	
	while (true)
	{
		cout << "Author name: ";
		if (getline(cin, authorName))
			break;
		cin.clear();
		cout << "Not valid author name. Please, try again.";
	}

	/*check siteName for spaces in siteName var.  my site --> my_site.html*/
	mainPageFile.open(siteName + ".html");
	if (mainPageFile.is_open())
	{
		fileContent = "<html>\n<head>\n<meta";	//add header
		fileContent += "http-equiv=\"Content - Type\" content=\"text / html; charset = utf - 8\">\n"; 
		fileContent += "<meta name = \"author\" content = \"" + authorName + "\">\n";		//add author info
		fileContent += "<title>" + siteName + "</title>\n";
		fileContent += "</head>\n<body>\n";
		fileContent += "<h1>Website skeleton</h1>\n";
		fileContent += "<p>This is first step for new CMS creation</p>\n";
		fileContent += "</body>\n</html>";
		
		mainPageFile << fileContent;	//write html code into file

		mainPageFile.close();
	}
	
	cout << siteName << endl;

	system("pause");
    return 0;
}

