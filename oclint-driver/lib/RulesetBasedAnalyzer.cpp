#include "oclint/Debug.h"
#include "oclint/Results.h"
#include "oclint/RuleBase.h"
#include "oclint/RuleCarrier.h"
#include "oclint/RuleSet.h"
#include "oclint/RulesetBasedAnalyzer.h"
#include "oclint/ViolationSet.h"

using namespace oclint;

void RulesetBasedAnalyzer::preprocess(std::vector<clang::ASTContext *> &contexts)
{
    debug::emit("Start pre-processing:\n");
    for (auto context : contexts)
    {
        debug::emit(".");
    }
    debug::emit("\n");
}

void RulesetBasedAnalyzer::analyze(std::vector<clang::ASTContext *> &contexts)
{
    debug::emit("Start analyzing:\n");
    for (auto context : contexts)
    {
        debug::emit(".");
        ViolationSet *violationSet = new ViolationSet();
        RuleCarrier *carrier = new RuleCarrier(context, violationSet);
        for (int ruleIdx = 0, numRules = RuleSet::numberOfRules(); ruleIdx < numRules; ruleIdx++)
        {
            RuleSet::getRuleAtIndex(ruleIdx)->takeoff(carrier);
        }
        Results *results = Results::getInstance();
        results->add(violationSet);

    }
    debug::emit("\n");
}

void RulesetBasedAnalyzer::postprocess(std::vector<clang::ASTContext *> &contexts)
{
    debug::emit("Start post-processing:\n");
    for (auto context : contexts)
    {
        debug::emit(".");
    }
    debug::emit("\n");
}
