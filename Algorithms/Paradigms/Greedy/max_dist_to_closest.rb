# @param {Integer[]} seats
# @return {Integer}
EMPTY = 0
FULL = 1
def count_prefix_zero(seats)
    count = 0
    seats.each do |seat|
        if seat == FULL
            break
        end
        count+=1
    end 
    count
end

def get_zero_between(seats)
    count = 0
    best = 0
    seats.each do |seat|
        count+=1
        count *= 1-seat
        best = [best, count].max
    end 
    best
end
def max_dist_to_closest(seats)
    leading_zeros, trailing_zeros = count_prefix_zero(seats), count_prefix_zero(seats.reverse)
    inbetween = get_zero_between(seats)
    inbetween += 1 if inbetween.odd?
    space = inbetween/2 
    return [leading_zeros, trailing_zeros, space].max
end