bold=$(tput bold)
normal=$(tput sgr0)
green="\033[0;32m"
echo -n "${bold}Enter the lesson you want to run (number): "
read lessonNumber
#the path where the lessons programs located
path="Lesson${lessonNumber}/main.cpp"
op="Lesson${lessonNumber}/main"
echo "[*] Building..."
bash build.sh $path $op;
echo "${green}${bold}[+] Done!"
./$op