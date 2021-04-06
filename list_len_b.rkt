#lang pl

(require rackunit)


(: length3? : (Listof Any) -> Natural)
(define (length3? lst)
  (match lst
    ['()   0]
    [(list h t a)   1]
    [(list h t)   0]
    [(list h )   0]
    [(list h t y i...)   0]
    ))


  
 (: count-3lists : (Listof Any) -> Natural)
(define (count-3lists  L)
  
 (: helper : Natural (Listof Any) -> Natural)
(define (helper acc L)
  (match L 
 ['()   acc]
 [(cons h t)
       (if  (list? h)
          (helper (+ (length3? h) acc) (rest L))
          (helper acc (rest L)))]
 [e 0]
  
  ))
  (helper 0 L)
  )  
  

(test(count-3lists '((7 6 5) (6 5) ("as" 2 1) () (3 2 1) )) => 3)
(test(count-3lists '((7 6 5) ( ()6 5) () )) => 2)
(test (count-3lists '((1 3 4) (() (1 2 3)) ("tt" "Three" 7) (2 4 6 8) (1 2 3))) => 3)

