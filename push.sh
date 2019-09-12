#!/bin/bash
#===============================================================================
#
#          FILE:  push.sh
# 
#         USAGE:  ./push.sh 
# 
#   DESCRIPTION:  
# 
#       OPTIONS:  ---
#  REQUIREMENTS:  ---
#          BUGS:  ---
#         NOTES:  ---
#        AUTHOR: guojun (), jun_guo@dtri.com
#       COMPANY: DT Research
#       CREATED: 09/12/2019 12:57:00 PM CST
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

git add .
git push -u origin master

