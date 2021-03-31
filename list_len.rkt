#lang pl

(require rackunit)

;(: length : (Listof Any) -> Natural)
;; Produces the number of elements in the list
;(define (length lst)
  ;(match lst
   ; ['()   0]
  ;  [(cons h t)   (+ 1 (length (t)))]))

(: length3? : (Listof Any) -> Natural)
(define (length3? lst)
  (match lst
    ['()   0]
    [(list h t a)   1]
    [(list h t)   0]
    [(list h )   0]
    [(list h t y i...)   0]
    ))

(define x 0)
(: sum : (Listof Any) -> Natural)
(define (sum L)
  (match L 
    ['()   0]
    [(cons h t)
     (if(list? h)
        (+ (length3? h) (sum t))
        (sum t))]
    [e 0]
    ))
  
         

(test(sum '((7 6 5) (6 5) ("as" 2 1) () (3 2 1) )) => 3)
(test(sum '((7 6 5) ( ()6 5) () )) => 2)

