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

(define x 0)

(: count-3lists : (Listof Any) -> Natural)
(define (count-3lists L)
  (match L 
    ['()   0]
    [(cons h t)
     (if(list? h)
        (+ (length3? (flat h)) (count-3lists t))
        (count-3lists t))]
    [e 0]
    ))

(: flat : (Listof Any) ->(Listof Any))
(define (flat lst)
  (match lst
    ['()   null]
    [(cons h t)
     (cond
       [(and (list? h) (list? t)) (append (flat h ) (flat t ))]
       [(list? h) (list (flat h ) t )]
       [(list? t) (append (list h) (flat t ) )]
       [else (list h t )])]

    ))

;(test(flat '((7 6 5) (6 5) ())) => '(7 6 5 6 5 ))
(test (count-3lists '((1 3 4) (() (1 2 3)) ("tt" "Three" 7) (2 4 6 8) (1 2 3))) => 4)
