class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        # Go through word by word and track length of output
        # if size would exceed our maxWidth we put in next line
        def createLines(words, maxWidth):
            lines, curLine, numChars = [], [], 0
            for word in words:
                # Our new line width with the new word would be the sum of
                # - total length of every word
                # - 1 mandatory space per word
                # - plus the new word
                newWidth = numChars + len(curLine) + len(word)
                if newWidth > maxWidth:
                    lines.append((curLine, numChars))
                    curLine = [word]
                    numChars = len(word)
                else:
                    curLine.append(word)
                    numChars += len(word)

            if curLine:
                lines.append((curLine, numChars))

            return lines

        def formatLines(lines, maxWidth):
            n = len(lines)
            out = []
            for i, (line, numChars) in enumerate(lines):
                formattedLine = ""
                # left justify line
                if i == n-1 or len(line) == 1:
                    for word in line:
                        formattedLine += f"{word} "
                    formattedLine = formattedLine.strip()
                    formattedLine += " " * (maxWidth - len(formattedLine))
                # full justify line
                else:
                    numGaps = len(line) - 1
                    # numChars = sum([len(word) for word in line])
                    requiredSpaces = maxWidth - numChars
                    # each word is followed by min number of spaces
                    minSpaces = requiredSpaces//numGaps
                    # the first x words will have an additional space
                    extraSpaces = requiredSpaces%numGaps
                    for word in line:
                        formattedLine += word + (" " * minSpaces)
                        if extraSpaces:
                            formattedLine += " "
                            extraSpaces -= 1
                    formattedLine = formattedLine.strip()


                out.append(formattedLine)

            return out



        lines = createLines(words, maxWidth)

        return formatLines(lines, maxWidth)
