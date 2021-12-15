# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwastche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 11:13:27 by cwastche          #+#    #+#              #
#    Updated: 2021/12/15 11:16:15 by cwastche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
 args=""; #Insert numbers here
 ./push_swap $args | ./checker_Mac $args
 ./push_swap $args | ./checker $args
