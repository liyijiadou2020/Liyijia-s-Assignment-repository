#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define M 5000
#include "Dictionary.h"

bool cmp_test(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}
