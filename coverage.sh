if [ -e ".coverage_rc" ]
     then
     source .coverage_rc
     fi
     if [ -z ${EXCLUDES+x} ]
          then
          EXCLUDES=
               fi
               if [ -z ${FILENAME+x} ]
                    then
# file is relative path as l18 changes path to ./build/test
                    FILENAME=./ceil-main
                    PARAM= 42 
#                    FILENAME=./test_app
#                    FILENAME=./test/testDJBeatController
                             fi

rm -rvf build ; mkdir build ; cd build ; cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE:STRING=Coverage .. ; make
                             make -j 9; ls  && \
                             "$FILENAME $PARAM" && \
                             lcov -i -c -d . -o coverage.info && \
                             lcov -c -d . -o coverage.info && \
                             lcov -r coverage.info "/usr*" -o coverage.info && \
                             lcov -r coverage.info $EXCLUDES -o coverage.info && \
                             genhtml --legend  --no-branch-coverage --demangle-cpp -o ../html coverage.info ;
# moving back to  /build/
cd .. ; 
make mvcdoc ;
# doc target seem to move up a folder 
 
mkdir resources/test ;
mv html resources/test/ ;
echo " you can run app now all doc & test were generated & moved to apropriate folders ";
