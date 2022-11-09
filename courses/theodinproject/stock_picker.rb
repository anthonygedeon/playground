# Chooses the best day to buy and sell a stock
# 
# @param stock_prices [Array] prices of stocks starting from day 0
# @return [Array] pair of days representing the best day to buy and the best day to sell
def stock_picker(stock_prices)
	best_days_to_purchase = {}
	stock_prices_clone = stock_prices.clone # FIXME:  utilize the original vector instead of allocating more memory
	stock_prices.each do |_|		
		buy_stock_index = stock_prices_clone.index(stock_prices_clone.min)
		trim_stock_prices = stock_prices_clone.drop(buy_stock_index)
		sell_stock_index = stock_prices_clone.index(trim_stock_prices.max)
		
		best_price = trim_stock_prices.minmax.rotate.reduce(:-)		
		
		best_days_to_purchase[best_price] = [buy_stock_index, sell_stock_index]
		stock_prices_clone.delete_at(buy_stock_index) # FIXME: mutating
	end
	best_days_to_purchase.max.last
end

p stock_picker([17,3,6,9,15,8,6,1,10])
# => [1,4]  # for a profit of $15 - $3 == $12

#puts

p stock_picker([17,3,6,9,8,15,6,1,10])
# => [1,5]  # for a profit of $15 - $3 == $12
