// Algorithms to calculate the nth fibonacci number

package main

import (
    "fmt"
    "math"
)

func main() {
    c := fibGenerator()
    for i := 1; i <= 20; i++ {
        fmt.Println(fibonacci(i))
        fmt.Println(fibonacciRecursive(i))
        fmt.Println(fibonacciTail(i))
        fmt.Println(fibonacciBinet(i))
        fmt.Println(<- c)
        fmt.Println("")
    }
}

// Iterative
func fibonacci(n int) int {
    current, prev := 0, 1
    for i := 0; i < n; i++ {
        current, prev = current + prev, current
    }
    return current
}

// Recursive
func fibonacciRecursive(n int) int {
    if n < 2 {
        return n
    } 
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2)
}

// Tail recursion
func fibonacciTail(n int) int {
    return tailHelper(n, 1, 0)
}
func tailHelper(term, val, prev int) int {
    if term == 1 {
        return val
    }
    return tailHelper(term - 1, val + prev, val)
}

// Analytic (Binet's formula)
func fibonacciBinet(num int) int {
    var n float64 = float64(num);
    return int( ((math.Pow(((1 + math.Sqrt(5)) / 2), n) - math.Pow(1 - ((1 + math.Sqrt(5)) / 2), n)) / math.Sqrt(5)) + 0.5 )
}

// Using channel, iterator, go routine
// http://codereview.stackexchange.com/q/28386/30763
func fibGenerator() chan int {
    c:= make(chan int)
    go func() {
        for i, j := 1, 0; ; i, j = i + j, i {
            c <- i
        }
    }()
    return c
}

