# change sublime build to fastStressTestCppBuild
# command + shift + b -> to run;

for((i = 1;; ++i)); do
    echo $i
    ./testGen $i > input
    ./sol < input > output
    echo "Input : "
    cat input
    echo "Output : "
    cat output
    echo ""
done