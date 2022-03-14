
   
#!/bin/bash
# Reset
Color_Off='\033[0m'       # Text Reset
# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White
# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

if [ -z "$1" ]
    then
        echo -e "${BRed}${On_White}Please specify the main directory path${Color_Off}"
    else
        if [ -z "$2" ]
            then
                echo -e "${BRed}${On_White}Please specify a commit message${Color_Off}"
            else
                cd $1
                while true
                do
                        echo -e "${BBlue}${On_White}Waiting...${Color_Off}"
                        #sleep 300
                        echo
                        echo -e "${BGreen}${On_White}PUSHING${Color_Off}"
                        git add .
                        #echo -en "${BPurple}${On_White}please enter the commit message: ${Color_Off}"
                        #read commitmessage
                        #git commit -m "$commitmessage"
                        sleep 5
                        echo -en "${BPurple}${On_White}Commit message: $2${Color_Off}"
                        git commit -m "$2"
                        git push
                        clear
                done
        fi
fi