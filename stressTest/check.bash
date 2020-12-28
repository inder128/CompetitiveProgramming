# stressTest solution with bruteforce
# change sublime build to fastStressTestCppBuild
# command + shift + b -> to run;

for((i = 1; ; ++i)); do
    echo $i
    ./testGen $i > input
    ./sol < input > output1
    ./bruteSol < input > output2
    if !(diff -w output1 output2)
    then
    	echo "\nFailed on Test No. $i :( \n"
    	echo "Failed Input : "
    	cat input
    	echo ""
    	echo "Correct Output : "
    	cat output2
    	echo ""
    	echo "Your Output : "
    	cat output1
    	echo ""
    	break
    fi
done