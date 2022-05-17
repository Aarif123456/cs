import(
    "fmt"
    "reflect"
)

func sortColors(nums []int)  {
    const red, white, blue = 0,1,2
    numRed, numWhite, numBlue := 0,0,0
    for _, x := range nums {
        if x == red {
            numRed++
        } else if x == white{
            numWhite++
        } else { /* If blue*/
            numBlue++
        }
    }
    swapper := reflect.Swapper(nums) 
    curRed, curWhite, curBlue := 0, numRed, numRed + numWhite
    redEnd, whiteEnd, blueEnd := curWhite, curBlue, len(nums)
    for curWhite < whiteEnd && nums[curWhite] == white  {
        curWhite++
    }
    for curBlue < blueEnd && nums[curBlue] == blue {
        curBlue++
    }
    for curRed < redEnd {
        if nums[curRed] == red {
            curRed++
        } else if nums[curRed] == white {
            swapper(curRed, curWhite)
            curWhite++
        } else { /* If blue*/
            swapper(curRed, curBlue)
            curBlue++
        }
    }

    for curWhite < whiteEnd {
        if nums[curWhite] == white{
            curWhite++
        } else { /* If blue because red are all in spot */
            swapper(curWhite, curBlue)
            curBlue++
        }
    }

}