#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// * Function - Find spans by using brute force method
vector<int> span_brute_force(vector<int> &prices)
{
    // ? Sotre some data
    vector<int> temp, span;

    // ? Treverse through all stock prices
    for (int price : prices)
    {
        int days = 1;

        // ? Check current price with previous prices
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            // ? If found a price <= current price
            if (temp[i] <= price)
                days++;
            else
                break;
        }

        // ? Store calculated data
        span.push_back(days);
        temp.push_back(price);
    }

    return span;
}

// * Function - Find spans by using an optimal method
vector<int> span_optimal(vector<int> &prices)
{
    vector<int> span; stack<int> index_stack;

    // ? Traverse the given array of prices
    for (int i = 0; i < prices.size(); i++)
    {
        // ? If the stack is empty
        if (index_stack.empty())
            span.push_back(1);

        else
        {
            // ? Remove all small values from the stack till a greater found
            while (!index_stack.empty() && prices[index_stack.top()] <= prices[i])
                index_stack.pop();

            // ? Calculate and push the span
            int s = (!index_stack.empty()) ? i - index_stack.top() : 1;
            span.push_back(s);
        }

        index_stack.push(i);
    }

    return span;
}

int main()
{
    // ? Stock prices
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    // ? Calculate Span
    vector<int> span_bf = span_brute_force(prices), span_opt = span_optimal(prices);

    // ? Print
    cout << "\n** Brute Force **\n\n";
    for (int i = 0; i < span_bf.size(); i++)
        cout << "Price: " << prices[i] << " - Span: " << span_bf[i] << endl;

    cout << "\n** Optimal **\n\n";
    for (int i = 0; i < span_opt.size(); i++)
        cout << "Price: " << prices[i] << " - Span: " << span_opt[i] << endl;
}
