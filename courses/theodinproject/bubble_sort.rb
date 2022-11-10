# Bubble sort algorithm
#
# @param list [Array]
# @return [Array] sorted array
def bubble_sort(list)
  loop do 
    is_swapping = false
    for num in 0..list.size-2 do 
      next_val = list[num+1]
      curr_val = list[num]
      
      if curr_val > next_val 
        list[num], list[num+1] = list[num+1], list[num]
        is_swapping = true
      end
    end

    break unless is_swapping
  end

  list
end

p bubble_sort([4,3,78,2,0,2])
# => [0,2,2,3,4,78]
