# stressTest solution with bruteforce
# change sublime build to fastStressTestCppBuild
# command + shift + b -> to run;

for((i = 1; ; ++i)); do
    echo $i
    ./testGen $i > input
    ./sol < input > output1
    ./bruteSol < input > output2
    diff -w output1 output2 || break
done