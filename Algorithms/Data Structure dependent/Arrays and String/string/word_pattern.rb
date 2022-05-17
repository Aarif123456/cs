# @param {String} pattern
# @param {String} s
# @return {Boolean}
def get_mapped_words(s)
    lastNumber = 0
    hash = {}
    arr = []
    s.each do |word| 
        if !hash.key? word
            hash[word] = lastNumber
            lastNumber+=1
        end
        arr << hash[word]
    end
    arr
end
def word_pattern(pattern, s)
    a, b = get_mapped_words(s.split(' ')), get_mapped_words(pattern.split(''))
    a == b
end