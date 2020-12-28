# change sublime build to fastStressTestCppBuild
# command + shift + b -> to run;

for((i = 1; i < 10; ++i)); do
    echo $i
    python3 croupier.py "./test $i" "./sol"
    echo "\n"
done