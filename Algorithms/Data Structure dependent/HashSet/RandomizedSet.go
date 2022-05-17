package main

import (
    "reflect"
    "math/rand"
    "fmt"
)
  
type RandomizedSet struct {
    indices map[int]int
    vals []int
}


func Constructor() RandomizedSet {
    return RandomizedSet{
        make(map[int]int),
        make([]int, 0, 100)}
}


func (this *RandomizedSet) Insert(val int) bool {
    /* If found we cannot insert */
    if _, ok := this.indices[val]; ok {
        return false
    }
    /* Store index and appends to slice */
    this.indices[val] = len(this.vals)
    this.vals = append(this.vals, val)

    return true
}


func (this *RandomizedSet) Remove(val int) bool {
    /* If not found we cannot remove */
    if _, ok := this.indices[val]; !ok {
        return false
    }
    // fmt.Printf("vals: %v, i:%v - %v - len:%v \n", val, this.indices[val], this.vals, len(this.vals))
    last := len(this.vals)-1
    if this.indices[val] != last {
        oldVal := this.indices[val]
        /* store value switch */
        this.vals[oldVal] = this.vals[last]
        this.indices[this.vals[last]] = oldVal
    }
    delete(this.indices, val)
    /* Pop from list */
    this.vals = this.vals[:last]

    return true
}


func (this *RandomizedSet) GetRandom() int {
    i := rand.Intn(len(this.vals))
    return this.vals[i]
}
