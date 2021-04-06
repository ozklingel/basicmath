#lang pl

(require rackunit)


(: permutations : Char Char Char -> (Listof String ))
(define (permutations a b c)
  (cond [(or (null? a) (null? b) (null? c)) (error "no char ~s")]
        [else (list (string a b c) (string a c b) (string b a c) (string b c a) (string c a b ) (string c b a))]))

(test (permutations #\a #\b #\c) => '("abc" "acb" "bac" "bca" "cab" "cba"))
