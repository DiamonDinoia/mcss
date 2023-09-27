# iterate over a set of strings
# and run the test script on each
# string
#

runs=5

echo "" > cpu.txt

for rng in "mt" "xoshiro" "mixmax" "chacha" "counter"
do
  for (( i = 0; i < runs; i++ )); do
      ./mcss -n100000000 -t20 -r $rng >> cpu.txt
  done
done

echo "" > gpu.txt
for rng in "xoshiro" "mixmax" "philox" "mrg32" "chacha" "counter"
do
  for (( i = 0; i < runs; i++ )); do
      ./mcss -n100000000 -g -r $rng >> gpu.txt
  done
done
