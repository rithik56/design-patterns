#include <iostream>
using namespace std;

class CodeReviewPipeline
{
public:
    void loadSourceCode(string filePath)
    {
        cout << "loading source code method is same for all" << endl;
    }
    virtual bool eslintChecks() = 0;
    virtual bool typescriptChecks() = 0;
    virtual bool securityChecks() = 0;
    void runPipeline(string filePath)
    {
        loadSourceCode(filePath);
        bool eslintCheck = eslintChecks();
        if (eslintCheck)
        {
            bool typescriptCheck = typescriptChecks();
            if (typescriptCheck)
            {
                bool securityCheck = securityChecks();
                if (securityCheck)
                {
                    cout << "code review successful" << endl;
                }
                else
                {
                    cout << "security checks failed, exiting" << endl;
                }
            }
            else
            {
                cout << "typescript checks failed, exiting" << endl;
            }
        }
        else
        {
            cout << "eslint checks failed, exiting" << endl;
        }
    }
};

class LowChecksPipeline : public CodeReviewPipeline
{
public:
    LowChecksPipeline()
    {
    }
    bool eslintChecks() override
    {
        cout << "executed low level eslint checks" << endl;
        return true;
    }
    bool typescriptChecks() override
    {
        cout << "executed low level ts checks" << endl;
        return true;
    }
    bool securityChecks() override
    {
        cout << "executed low level security checks" << endl;
        return true;
    }
};

class MediumChecksPipeline : public CodeReviewPipeline
{
public:
    MediumChecksPipeline()
    {
    }
    bool eslintChecks() override
    {
        cout << "executed medium level eslint checks" << endl;
        return true;
    }
    bool typescriptChecks() override
    {
        cout << "executed medium level ts checks" << endl;
        return true;
    }
    bool securityChecks() override
    {
        cout << "executed medium level security checks" << endl;
        return false;
    }
};

class HighChecksPipeline : public CodeReviewPipeline
{
public:
    HighChecksPipeline()
    {
    }
    bool eslintChecks() override
    {
        cout << "executed high level eslint checks" << endl;
        return true;
    }
    bool typescriptChecks() override
    {
        cout << "executed high level ts checks" << endl;
        return false;
    }
    bool securityChecks() override
    {
        cout << "executed high level security checks" << endl;
        return false;
    }
};

int main()
{
    LowChecksPipeline *lowChecksPipeline = new LowChecksPipeline();
    MediumChecksPipeline *mediumChecksPipeline = new MediumChecksPipeline();
    HighChecksPipeline *highChecksPipeline = new HighChecksPipeline();
    lowChecksPipeline->runPipeline("sample.js");
    mediumChecksPipeline->runPipeline("sample.js");
    highChecksPipeline->runPipeline("sample.js");

    // loading source code method is same for all
    // executed low level eslint checks
    // executed low level ts checks
    // executed low level security checks
    // code review successful
    // loading source code method is same for all
    // executed medium level eslint checks
    // executed medium level ts checks
    // executed medium level security checks
    // security checks failed, exiting
    // loading source code method is same for all
    // executed high level eslint checks
    // executed high level ts checks
    // typescript checks failed, exiting
    return 0;
}