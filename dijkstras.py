#!/usr/bin/env python
# coding: utf-8

# In[12]:


#Dijkstras algorithm (BFS implemention)
#find the shortest path from source to each other nodes and calculate the distance
#non-neagtive weights
'''
input format:
    node1 node2 weight1
    node1 node3 weight2
    node3 node4 weight3
    ...
    ...
    
ex:
    0 1 22
    0 2 32
    1 2 11
    1 3 21
    2 4 7
    3 4 8
    
output:
    
    the output of the bfs algorithm can be anything such as:
    @the distance from the source to each nodes,
    @the parent nodes, 
    @the visited nodes (or the path found)
    
Here, output is the distance from the source to each other nodes.
    
'''

from collections import defaultdict
import heapq 

#to read input file 
def inputFile(graph):
    
    with open('dijkstrasInput.txt', 'r') as file:
        for line in file:
            u, v, w = line.split()
            graph[int(u)].append(int(v))
            graph[int(v)].append(int(u))            
    
    #weight matrix 
    weight = [[ float('Inf') for i in range(len(graph))] for j in range(len(graph))]
    with open('dijkstrasInput.txt', 'r') as file:
        for line in file:
            u, v, w = line.split()
            weight[int(u)][int(v)]=float(w)
            weight[int(v)][int(u)]=float(w)            
    file.close()
    return graph, weight
                
#to write to output file            
def outputFile(path):
    file = open("dijkstrasOutput.txt", "w")
    file.write(path)
    file.close()
           
def initializeSingleSource(graph,source):
    #initially nodes are unvisited, hence initialzation 
    
    nodes = len(graph)
    distance = [float('Inf')] * nodes
    parent =  [None] * nodes
    distance[source]=0
    return distance, parent    
    
def dijkstras(graph,w,source):
    nodes=len(graph)
    d, p =initializeSingleSource(graph,source)
    
    #tuples (distance,node)
    queue = [(source)]
    
    while(queue):
        #print(queue)
        #extract the min heap
        u = heapq.heappop(queue)

        for v in range(nodes):
            if d[v] > d[u] + w[u][v]:
                d[v] = d[u] + w[u][v]
                p[v] = u
                #push to the heap
                heapq.heappush(queue, v)
    return d


if __name__== "__main__":  
    
    #to read from input file
    graph = defaultdict(list) 
    g, w = inputFile(graph)
    
    #input source
    source=7
    solution=dijkstras(g,w,source)
    
    print(solution)
    
    #write output the path 
    outputFile(str(solution))


# In[ ]:





# In[ ]:





# In[ ]:




