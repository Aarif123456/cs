from copy import deepcopy
# THIS DOES NOT WORK BECUASE STUPID TAGS ORDERING


# def testList(arr: list):
#     arr.sort(key = lambda x: x[1], reverse=True)
#     arr.sort(key = lambda x: x[0])
#     print(arr)
#     n = len(arr)
#     for i in range(1, n):
#         oldStart, oldEnd = arr[i-1]
#         newStart, newEnd = arr[1]
#         assert(oldEnd <= newStart)

# We transform our input to the form (index, isEnd, attribute) - sorted by index where ties are broken by prioritizing starts of interval before end of interval
def transformInput(givenFormat: dict):
    result = []
    for key, arr in givenFormat.items():
        for start, end in arr:
            result.append((start, False, key))
            result.append((end, True, key))
    result.sort(key = lambda x: x[1])
    result.sort(key = lambda x: x[0])

    return result

def getNonOverlapping(arr: list) -> list:
    result = []
    n = len(arr)
    curStart, curEnd, curAttribute = 0, -1, set()
    for i in range(len(arr)):
        index1, isEnd1, attribute1 = arr[i]
        index2, isEnd2, attribute2 = arr[i+1] if i+1 < n else (n, False, "")

        if not isEnd1: curAttribute.add(attribute1)
        else: curAttribute.remove(attribute1)
        curStart = index1 + 1 if isEnd1 else index1
        curEnd = index2 if isEnd2 else index2-1

        if curStart <= curEnd:
            nextAttributes = {}
            # If previous element has elements common with current - we will end
            if len(result) > 0:
                for attribute in curAttribute: 
                    result[3].pop(attribute)
                    result[3][attribute] = False
                for attribute, end in reversed(result[3].items()): 
                    if not end: nextAttributes[attribute] = True 

            for attribute in curAttribute: nextAttributes[attribute] = True 
           
            result.append((curStart, curEnd, nextAttributes))
    result.reverse()
    return result



def generateValidHTML(givenFormat: dict, s: str):
    htmlStart = {
                    'bold' : '<b>',
                    'italics' : '<i>',
                    'paragraph' : '<p>'
                }
    htmlEnd =   {
                    'bold' : '</b>',
                    'italics' : '</i>',
                    'paragraph' : '</p>'
                }

    transformed = transformInput(givenFormat)
    # print(transformed)
    nonOverlapping = getNonOverlapping(transformed)
    print(nonOverlapping)
    out = ""
    curStart, curEnd, attributes = nonOverlapping.pop()
    for i, c in enumerate(s):
        if i <= curStart:
            for attribute in attributes.keys():
                out += htmlStart[attribute]
        out += c
        if i>= curEnd:
            # First we close tags in from previous element in the correct order
            for prevClosing in prevClosingElements:
                out += htmlEnd[attributes]

            for attribute, end in attributes.items():
                if end: out += htmlEnd[attribute]








form = {
    'bold': [(0,4)],
    'italics': [(2,6)],
    'paragraph': [(0,2)]
}

form = {
    'bold': [(0,4)],
    'italics': [(2,6)],
    'paragraph': [(0,2)]
}

s = "ABCDEFGHIJ"
print(generateValidHTML(form, s))

