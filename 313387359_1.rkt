#lang pl

(require rackunit)


(: append5 : Char Char Char Char Char -> String)
(define (append5 A p1 a b c )
  (string A p1 a b c))

(test(append5 #\A #\0 #\A #\2 #\A  ) => "A0Ap2A")

(test(append5 #\A #\p #\A #\p #\A  ) => "ApApA")
;(test(append5 #\A #\p #\A #\p 4  ) =error> " ")
;(test(append5 #\A #\p ) =error> " ")
;(test(append5 "" ) =error> " ")

----------------------------------------------



(: permutations : Char Char Char -> (Listof String ))
(define (permutations a b c)
  (cond [(or (null? a) (null? b) (null? c)) (error "no char ~s")]
        [else (list (string a b c) (string a c b) (string b a c) (string b c a) (string c a b ) (string c b a))]))

(test (permutations #\a #\b #\c) => '("abc" "acb" "bac" "bca" "cab" "cba"))


--------------------------------------------------



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
        (+ (length3? h) (count-3lists t))
        (count-3lists t))]
    [e 0]
    ))
  
(test(count-3lists '(5 (7) )) => 0)
(test(count-3lists '( )) => 0)
(test(count-3lists '((7 6 5) (6 5) ("as" 2 1) () (3 2 1) )) => 3)
(test(count-3lists '((7 6 5) ( ()6 5) () )) => 2)
(test (count-3lists '((1 3 4) (() (1 2 3)) ("tt" "Three" 7) (2 4 6 8) (1 2 3))) => 3)

----------------------------------------------


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
  

(test(count-3lists '(5 (7) )) => 0)
(test(count-3lists '( )) => 0)
(test(count-3lists '((7 6 5) (6 5) ("as" 2 1) () (3 2 1) )) => 3)
(test(count-3lists '((7 6 5) ( ()6 5) () )) => 2)
(test (count-3lists '((1 3 4) (() (1 2 3)) ("tt" "Three" 7) (2 4 6 8) (1 2 3))) => 3)

-------------------------------------



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
(test(count-3lists '(5 (7) )) => 0)
(test(count-3lists '( )) => 0)
(test(count-3lists '((7 6 5) (6 5) ("as" 2 1) () (3 2 1) )) => 3)
(test(count-3lists '((7 6 5) ( () 6 5) () )) => 1)
(test (count-3lists '((1 3 4) (() (1 2 3)) ("tt" "Three" 7) (2 4 6 8) (1 2 3))) => 4)

---------------------------------


(define-type KeyStack     ; constructor
 [EmptyKS]    
 [push Symbol String KeyStack])




(: Push : Symbol String KeyStack -> KeyStack )
(define  (Push val key stk)
  (cases stk
    [(EmptyKS) (push 'b "s" (EmptyKS))]
    [(push e s g) (cond
                     [(and (symbol? val) (string? key)) (push val key stk)]) ]) 
  )

(: pop-stack : KeyStack -> Any )
(define  (pop-stack stk)
  (cases stk
    [(EmptyKS) #f]
    [(push e s g)  (cases g
                      [(EmptyKS) (EmptyKS)]
                      [(push a b c) g]
     )] 
  ))


(: search-stack : Symbol KeyStack -> Any )
(define  (search-stack sim stk)
  (cases stk
    [(EmptyKS) #f]
    [(push e s g)  (if(eq? sim e) s
                       (cases g
                      [(EmptyKS) #f]
                      [(push a b c) (search-stack sim c)]
     ))] 
  ))

(test (EmptyKS) => (EmptyKS))
(test (Push 'b "B" (EmptyKS)) =>  (Push 'b "B" (EmptyKS)))
(test (Push 'b "B" (Push 'a "A" (EmptyKS))) =>  (Push 'b "B" (Push 'a "A" (EmptyKS))))
(test (Push 'a "AAA" (Push 'b "B" (Push 'a "A" (EmptyKS)))) => (Push 'a "AAA" (Push 'b "B" (Push 'a "A" (EmptyKS)))))
(test (search-stack 'a (Push 'a "AAA" (Push 'b "B" (Push 'a "A" (EmptyKS))))) => "AAA")
(test (search-stack 'c (Push 'a "AAA" (Push 'b "B" (Push 'a "A" (EmptyKS))))) => #f)

(test (search-stack 'c (EmptyKS)) => #f)
(test (pop-stack (Push 'a "AAA" (Push 'b "B" (Push 'a "A" 
(EmptyKS))))) => (Push 'b "B" (Push 'a "A" (EmptyKS))))

(test (pop-stack (EmptyKS)) => #f)
