#!/usr/bin/env python
# coding: utf-8

# In[12]:


#BFS implemention
from collections import defaultdict
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
    
    the output of the bfs algorithm can be anything such as:
    @the nodes visited, 
    @the color status, 
    @the distance from the source to each nodes,
    @the parent nodes, 
    @the visited nodes (or the path found)
    
Here the output is the status of the queue after each node is processed and the final path found.
'''
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
    file = open("bfsOutput.txt", "w")
    file.write(path)
    file.close()
            
def bfs(graph, source):
    #visited array to track solution
    visited=[]
    nodes=len(graph)
    
    #initially all nodes are unvisited and hence color = "white", distance = "infinity" and parent= None
    color = ["white"] * nodes  
    distance = [-9999] * nodes  
    parent = [None] * nodes    
    
    #source is discovered first and hence color = "gray", distance = 0 and parent= None
    color[source] = "gray"
    distance[source] = 0
    parent[source] = [None]
    
    #enqueue the initial source
    queue=[]
    queue.append(source)
    
    #while queue is not empty
    while(queue):
                #to print the status of the queue
                print(queue)
                #dequeue
                u = queue.pop(0)   
                #print(u,end=" ")
                #to track the bfs path
                visited.append(u)
                
                #find all the neighbours of dequeue node and color it accordingly and calculate the distance
                for v in range(len(graph[u])):
                    if (color[graph[u][v]] == "white"):
                        #mark the neghbouring node as discovered and "gray"
                        color[graph[u][v]] = "gray"
                        #calculate the distance from its parent
                        distance[graph[u][v]] = distance[u] + 1
                        #mark the parent node
                        parent[graph[u][v]] = u
                        #enqueue the neighbour
                        queue.append(graph[u][v])
                #mark the dequeue node as visited and "black"        
                color[u] = "black"
    #return value can be color, distance, parent, visited             
    return visited                     
                

if __name__== "__main__":  
    
    #to read from input file
    graph = defaultdict(list)
    inputFile(graph)
    
    #breadth first search
    solutionPath=bfs(graph,1)
    print(solutionPath)
    
    #write output the path 
    outputFile(str(solutionPath))


# In[ ]:




