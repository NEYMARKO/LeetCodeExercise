"""
Finds what is the best time to buy and sell stocks
"""

def maximize_profit(values: list[int]) -> tuple[int, int]:
    """
    Calculates when should stock be bought and when it should
    get sold to maximize profit.

    Returns day of buying and day of selling.
    """
    if len(values) <= 1:
        return (-1, -1)
    
    day_bought = -1
    day_sold = -1
    cheapest = values[0]
    max_profit = 0
    cheapest_pos = 0
    for i in range(1, len(values)):
        if values[i] < cheapest:
            cheapest = values[i]
            cheapest_pos = i
            continue
        profit = values[i] - cheapest
        if profit > max_profit:
            day_sold = i
            day_bought = cheapest_pos
            max_profit = profit
    print(max_profit)
    return (day_bought, day_sold)

def main():
    stock_values = [5, 10, 1, 2, 3]
    stock_values = [7, 1, 5, 3, 6, 4]
    stock_values = [3, 2, 6, 1, 4]
    print(maximize_profit(stock_values))

if __name__ == "__main__":
    main()