
   
#!/bin/sh

Color_Off='\033[0m'       # Text Reset
BPurple='\033[1;35m'      # Background Purple
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Red='\033[41m'         # Red

if [ -z "$1" ]
    then
        echo "${On_Red}     please specify the main directory path       ${Color_Off}"
    else
        cd $1
        while true
        do
                #sleep 300
                echo
                echo "${On_Green}                  PUSHING                 ${Color_Off}"
                git add .
                echo "${BPurple}please enter the commit message: ${Color_Off}"
                read commitmessage
                git commit -m "$commitmessage"
                git push
                echo "${On_Yellow} FINISHED : [THE NEXT PUSH IN 5 MINUTES] ${Color_Off}"
        done
fi
