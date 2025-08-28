#!/usr/bin/env bash
# Usage: ./run_tests.sh [./vbc]
BIN=${1:-./vbc}

pass=0
fail=0
total=0

run() {
  local input="$1"
  local expected="$2"
  total=$((total+1))
  local out
  out="$("$BIN" "$input" 2>&1)"
  if diff -u <(printf "%s\n" "$expected") <(printf "%s\n" "$out") >/dev/null; then
    printf "✅ %02d: %q -> OK\n" "$total" "$input"
    pass=$((pass+1))
  else
    printf "❌ %02d: %q\n" "$total" "$input"
    echo "   expected: $(printf %q "$expected")"
    echo "   got     : $(printf %q "$out")"
    fail=$((fail+1))
  fi
}

echo "== Valid expressions =="
run '1' '1'
run '2+3' '5'
run '3*4+5' '17'
run '3+4*5' '23'
run '(3+4)*5' '35'
run '1 + (4 + 2) + 2 + 1' '10'
run '((1+2)+(3+4))*2' '20'
run '(((1)))' '1'
run $'\t7\t+\t2' '9'
run '9*0+1' '1'
run '8+(2*(3+4))+1' '23'
run '0+0+0' '0'
run '9*9*9' '729'
run '1+(2*3)+(4*(5+6))' '51'
run '1+2+3+4+5' '15'
run '((((9))))' '9'
run '9*(9*(9+1))' '810'

echo
echo "== Errors: Unexpected end of input =="
run '' 'Unexpected end of input'
run '   ' 'Unexpected end of input'
run '(1+2' 'Unexpected end of input'
run '1+(2*3' 'Unexpected end of input'
run '( ( ( 1 + 2 )' 'Unexpected end of input'
run '1+ ' 'Unexpected end of input'

echo
echo "== Errors: Unexpected token 'X' =="
run '1)+ (2 + 1) * 2 + 2' "Unexpected token ')'"
run '1+2)' "Unexpected token ')'"
run ')1+2' "Unexpected token ')'"
run 'a+1' "Unexpected token 'a'"
run '1+2a' "Unexpected token 'a'"
run '*1+2' "Unexpected token '*'"
run '1**2' "Unexpected token '*'"
run '1++2' "Unexpected token '+'"
run '1 (2)' "Unexpected token '('"
run '()' "Unexpected token ')'"
run '(1)+(+2)' "Unexpected token '+'"
run '2+3 4' "Unexpected token '4'"
run $'4 +\t\t\t)' "Unexpected token ')'"

echo
echo "== Summary =="
echo "Passed: $pass / $total"
echo "Failed: $fail / $total"
exit $(( fail > 0 ))
