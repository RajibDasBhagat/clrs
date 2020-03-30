#!/usr/bin/env python
# coding: utf-8

# In[6]:


#BFS implemention for bipartite checking
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
    if bipartite matching
        return True
    else
        return False
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
    file = open("bipartiteOutput.txt", "w")
    file.write(path)
    file.close()
            
def bfs(graph, source):
    #visited array to track solution of the path found
    #visited=[]
    nodes=len(graph)
    
    #initially all nodes are unvisited and hence color = "white"
    color = ["NULL"] * nodes  
    
    #source is discovered first and hence color = "pink"
    color[source] = "pink"
    
    #enqueue the initial source
    queue=[]
    queue.append(source)
    
    #while queue is not empty
    while(queue):
                #dequeue
                u = queue.pop(0)   
                #print(u,end=" ")
                #to track the bfs path
                #visited.append(u)
                
                #find all the neighbours of dequeue node and color it accordingly and calculate the distance
                for v in range(len(graph[u])):
                    if (color[graph[u][v]] == "NULL"):
                        if(color[graph[v][u]] == "pink"):
                            color[graph[u][v]] == "blue"
                        elif(color[graph[v][u]] == "blue"):
                            color[graph[u][v]] == "pink"
                    elif(color[graph[u][v]] == color[graph[v][u]]):
                        return False
                        
    return True                     
                

if __name__== "__main__":  
    
    #to read from input file
    graph = defaultdict(list)
    inputFile(graph)
    
    #breadth first search 
    solutionPath=solutionPath=bfs(graph,0)
    
    print(solutionPath)
    
    #write output  
    outputFile(str(solutionPath))
    


# In[ ]:




