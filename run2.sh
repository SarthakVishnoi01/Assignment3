if [ -e "codeOutput" ]; then
    ./codeOutput $1
else
    echo "First run compile.sh to compile the code"
fi
