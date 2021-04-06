#lang pl

(require rackunit)


(: append5 : Char Char Char Char Char -> String)
(define (append5 A p1 a b c )
  (string A p1 a b c))


(test(append5 #\A #\p #\A #\p #\A  ) => "ApApA")
;(test(append5 #\A #\p #\A #\p 4  ) =error> " ")
;(test(append5 #\A #\p ) =error> " ")
;(test(append5 "" ) =error> " ")

