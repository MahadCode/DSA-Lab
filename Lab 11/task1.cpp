#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Paragraph
{
    string content;

public:
    Paragraph(const string& content)
    {
        this->content = content;
    }
    void setContent(const string& content)
    {
        this->content = content;
    }

    const string& getContent() const
    {
        return content;
    }

    int getWordCount() const
    {
        return content.length();
    }
};

class DocumentEditor
{
    vector<Paragraph> paragraphs;

public:
    void addParagraph(const Paragraph& para)
    {
        paragraphs.push_back(para);
    }

    bool removeParagraph(const int &index)
    {
        if (index < 0 || index >= paragraphs.size())
        {
            cout << "Index is not Valid!!" << endl;
            return false;
        }

        paragraphs.erase(paragraphs.begin() + index, paragraphs.begin() + index + 1);
        return true;
    }

    bool editParagraph(const int &index, const string& str)
    {
        if (index < 0 || index >= paragraphs.size())
        {
            cout << "Index is not Valid!!" << endl;
            return false;
        }

        paragraphs[index] = str;
        return true;
    }

    int getTotalWords() const
    {
        int size = 0;
        for (int i = 0; i < getParagraphCount(); i++)
        {
            size += paragraphs[i].getWordCount();
        }
        return size;
    }

    int getParagraphCount() const
    {
        return paragraphs.size();
    }

    const vector<Paragraph>& getAllParagraphs()
    {
        return paragraphs;
    }

    bool saveToFile(ostream &output) const
    {
        if (output)
        {
            for (int i = 0; i < paragraphs.size(); i++)
            {
                output << paragraphs[i].getContent() << endl;
            }
            return true;
        }
        cout << "Error! File not opened" << endl;
        return false;
    }

    bool loadFromFile(istream &input)
    {
        if (input)
        {
            while (!input)
            {
                string temp;
                input >> temp;
                Paragraph t1(temp);
                addParagraph(temp);
            }
            return true;
        }
        cout << "Error! File not opened" << endl;
        return false;
    }
};













void display()
{
    int i=1;
       cout << i++ << "    addParagraph" << endl;
       cout << i++ <<  "    removeParagraph " << endl;
       cout << i++ <<  "    getParagraph" << endl;
       cout << i++ <<  "    editParagraph" << endl;
       cout << i++ <<  "    getTotalWords" << endl;
       cout << i++ <<  "    getParagraphCount" << endl;
       cout << i++ <<  "    getAllParagraphs" << endl;
       cout << i++ <<  "    saveToFile" << endl;
       cout << i++ <<  "    loadFromFile" << endl;
}

int main()
{
    DocumentEditor obj1;
    int choice=0;

    while (true)
    {
        display();
        cout << endl;
        cout << "Enter Choice" << endl;
        cin >> choice;
        if(choice = 1){
            cout << "Enter paragarph" << endl;
            string temp="";
            cin >> temp;
            Paragraph t1(temp);
            obj1.addParagraph(t1);
        }
        else if(choice == 2){
            int i;
            cout << "Enter index" << endl;
            cin >> i;
            obj1.removeParagraph(i);
        }
        else if(choice == 7){
            vector<Paragraph> t = obj1.getAllParagraphs();
            for(auto i: t){
                cout << i.getContent() << endl;
            }
        }
        else{
            break;
        }
    }
}