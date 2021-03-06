#!/bin/bash
OUTPUT="$1.C"
if [ $# -lt 1 ]; then
    echo "Usage: GenerateMacro.sh [MacroName]"
    exit
fi
if [ ! -n "$CMSSW_BASE" ]; then
    echo "Problem! CAF_TRIGGER environment variable is not set."
    echo "Did you run the setup file?"
    exit
fi
TEMPLATE="$CMSSW_BASE/src/UserCode/L1TriggerDPG/macros/MacroTemplate.C" 
if [ ! -e "$TEMPLATE" ]; then
    echo "Warning, file $TEMPLATE does not exist."
    exit
fi
if [ -e "$OUTPUT" ]; then
    echo "Warning, file $OUTPUT exists. You must rename your macro or remove the current file before generating."
    exit
fi
SEDPATTERN="s/MacroTemplate/$1/g"
THEDATE=`eval date`
sed -e $SEDPATTERN $TEMPLATE > $OUTPUT
sed -i "7i\// \n//    macro automatically generated by GenerateMacro.sh script \n//    author           : $USER\n//    creation date    : $THEDATE \n//    last update date : \n//    description      : \n//" $OUTPUT
echo "$OUTPUT file is generated"
 
