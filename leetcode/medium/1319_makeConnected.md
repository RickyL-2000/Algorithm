# Number of Operations to Make Network Connected

There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections{i} = {a, b} represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

{{1,5},{1,7},{1,2},{1,4},{3,7},{4,7},{3,5},{0,6},{0,1},{0,4},{2,6},{0,3},{0,2}}

## my solution 1    20/1/13 50 min

> makeConnected1.md

