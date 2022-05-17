type MinStack struct {
    stack []int
    mins []int
}


func Constructor() MinStack {
    return MinStack{
        make([]int, 0), 
        make([]int, 0)}
}


func (this *MinStack) Push(val int)  {
    l := len(this.mins)
    this.stack = append(this.stack, val)
    if l > 0 && this.mins[l-1] < val{
        this.mins = append(this.mins, this.mins[l-1])
    } else{
        this.mins = append(this.mins, val)
    }
}


func (this *MinStack) Pop()  {
    l := len(this.mins)
    this.stack = this.stack[:l-1]
    this.mins = this.mins[:l-1]
}


func (this *MinStack) Top() int {
    l := len(this.mins)
    return this.stack[l-1]
}


func (this *MinStack) GetMin() int {
    l := len(this.mins)
    return this.mins[l-1]
}

