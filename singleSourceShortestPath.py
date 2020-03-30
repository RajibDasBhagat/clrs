#!/usr/bin/env python
# coding: utf-8

# In[5]:


#Single source shortest path for unweighted graph (BFS implemention)
#to find path between a given source and a given destination 
'''
input format:
    node1 node2
    node1 node3
    node3 node4
    ...
    ...
    
ex:
    0 1
    0 2
    1 2
    1 3
    2 4
    3 4
    
output:
    @distance
    @parent
'''
from collections import defaultdict

#to read input file 
def inputFile(graph):
    with open('bfsInput.txt', 'r') as file:
        for line in file:
            u, v = line.split()
            graph[int(u)].append(int(v))
            graph[int(v)].append(int(u))
    file.close()        
            
#to write to output file            
def outputFile(path):
    file = open("singleSourceOutput.txt", "w")
    file.write(path)
    file.close()
            
def bfs(graph, source):
    #array to track solution
    visited=[]
    nodes=len(graph)
    
    #initially all nodes are unvisited and hence distance = "infinity" and parent= None  
    distance = [-9999] * nodes  
    parent = [-1] * nodes    
    
    #source is discovered first and hence distance = 0
    distance[source] = 0
    
    #enqueue the initial source
    queue=[]
    queue.append(source)
    visited.append(source)
    
    #while queue is not empty
    while(queue):
                #dequeue
                u = queue.pop(0)   
                
                #find all the neighbours of dequeue node and calculate the distance
                for v in range(len(graph[u])):   
                    if (graph[u][v] not in visited):
                        #calculate the distance from its parent
                        distance[graph[u][v]] = distance[u] + 1
                        #mark the parent node
                        parent[graph[u][v]] = u
                        queue.append(graph[u][v])
                        visited.append(graph[u][v]) 
                        
    return parent #distance, parent                    

def calculateDistance(solutionPath,destination):
    path = []
    temp=destination
    path.append(destination)
    dist=0
    while (solutionPath[temp] != -1):
        path.append(solutionPath[temp])
        temp = solutionPath[temp]
        dist += 1

    print(list(reversed(path)))
    print(dist)

if __name__== "__main__":  
    
    #to read from input file
    graph = defaultdict(list)
    inputFile(graph)
    
    #inputs source and destination
    source=1
    destination=6
    
    #breadth first search
    solutionPath=bfs(graph,source)     
    
    #write output the path 
    outputFile(str(solutionPath))
    
    #calculate the distance from source to destination
    calculateDistance(solutionPath, destination)


# In[ ]:





# In[ ]:




