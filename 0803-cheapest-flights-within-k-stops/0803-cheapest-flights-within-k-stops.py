class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        # Construct adjacency list representation of the graph
        graph = [[] for _ in range(n)]
        for u, v, price in flights:
            graph[u].append((v, price))
        
        # Initialize a priority queue for Dijkstra's algorithm
        heap = [(0, src, 0)]  # (price, node, stops)
        
        # Initialize a visited set to keep track of visited nodes and stops
        visited = set()
        
        # Perform Dijkstra's algorithm
        while heap:
            price, node, stops = heapq.heappop(heap)
            
            # If the destination node is reached, return the minimum cost
            if node == dst:
                return price
            
            # If the number of stops exceeds k or if the node has been visited with fewer stops, skip it
            if stops > k or (node, stops) in visited:
                continue
            
            # Mark the current node and stops as visited
            visited.add((node, stops))
            
            # Explore neighbors and update the priority queue
            for neighbor, neighbor_price in graph[node]:
                heapq.heappush(heap, (price + neighbor_price, neighbor, stops + 1))
        
        # If the destination node is not reached within k stops, return -1
        return -1