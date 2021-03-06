#include "oclint/AbstractASTVisitorRule.h"
#include "oclint/RuleSet.h"

#include "../abstract/AbstractEmptyBlockStmtRule.h"

using namespace std;
using namespace clang;
using namespace oclint;

class EmptyIfStatementRule : public AbstractEmptyBlockStmtRule<EmptyIfStatementRule>
{
private:
    static RuleSet rules;

public:
    virtual const string name() const override
    {
        return "empty if statement";
    }

    virtual int priority() const override
    {
        return 2;
    }

    bool VisitIfStmt(IfStmt *ifStmt)
    {
        return checkLexicalEmptyStmt(ifStmt->getThen(), this);
    }
};

RuleSet EmptyIfStatementRule::rules(new EmptyIfStatementRule());
