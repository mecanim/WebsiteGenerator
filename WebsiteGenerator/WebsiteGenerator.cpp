// WebsiteGenerator.cpp: определяет точку входа для консольного приложения.
//
#include <string>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <Windows.h>

using namespace std;

void inputName(string &, string = "Site name");

int main()
{
	string siteName, authorName, fileContent;
	LPCWSTR jsFolderNm = _T("js");	//Folder name for JavaScript
	LPCWSTR cssFolderNm = _T("css");	//Folder name for CSS
	ofstream mainPageFile;

	inputName(siteName);
	inputName(authorName, "Author name");


	/*check siteName for spaces in siteName var.  my site --> my_site.html*/
	mainPageFile.open("index.html");
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

		if ((cout << "Add folder for JS (y/n): ") && (getchar() == 'y'))
		{
			cin.ignore();
			CreateDirectory(jsFolderNm, nullptr);
		}

		if ((cout << "Add folder for CSS (y/n): ") && (getchar() == 'y'))
		{
			cin.ignore();
			CreateDirectory(cssFolderNm, nullptr);
		}
	}
	else
		cout << "Error with file creation. Maybe, try another site name." << endl;
	
	

	system("pause");
    return 0;
}

void inputName(string & name, string prompt)
{
	while (true)
	{
		cout << prompt << ": ";
		if (getline(cin, name))
			break;
		cin.clear();
		cout << "Not valid. Please, try again: ";
	}
}