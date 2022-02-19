#!/bin/bash 
# This file is part of the so_long project at Ecole 42 Schools
# Copyright (c) 2022 42istanbul
#  
# This program is free software: you can redistribute it and/or modify  
# it under the terms of the GNU General Public License as published by  
# the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License 
# along with this program. If not, see <http://www.gnu.org/licenses/>.

FILES=$(ls tests)
rm -rf log.txt
for i in $FILES
do
	./so_long tests/$i >> log.txt
	# Dönüş kodu hatalı olmalı
	if [ $? -ne 0 ]; then
		tput setaf 2
		printf "%-30s %s" $i  "[OK]"
		tput sgr0
	else
		tput setaf 1
		printf "%-30s %s" $i  "[KO]"
		tput sgr0
	fi
	printf "\n"
done

exit 0