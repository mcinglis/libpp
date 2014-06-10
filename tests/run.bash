#!/bin/env bash


set -o errexit
set -o pipefail
set -o nounset


main() {
    local testdir="$(dirname $(readlink --canonicalize "$0"))"
    local nfails=0
    for f in "$testdir"/*.in.c; do
	local f_basename="$(basename $f)"
	local testname="${f_basename%.in.c}"
	if ! diff --ignore-blank-lines \
		<(gcc -E -std=c11 -I"$testdir/.." -Wall -Wpedantic -P "$f") \
		"${f%.in.c}".out.c; then
	    echo "Fail: $testname"
	    (( nfails += 1 ))
	else
	    echo "Pass: $testname"
	fi
    done
    exit $nfails
}


main "$@"

