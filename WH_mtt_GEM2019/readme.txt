1. create the input tree list with: 
./getfiles.sh /lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/ >& list.txt

2.create the .C files with the TChain and output file name with:
./test_script_3.sh
NB: you should modify template.src   according to the location of your output file.
Be sure that the final directory of the output file exist!

3.run.sh
./compile.sh

4. step 3 create an executable called exe. To run the analysis just do: 
./exe 