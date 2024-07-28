var canReachCorner = function(gridWidth, gridHeight, obstacles) { 
    function bfs(graph, startNode, targetNode1, targetNode2, totalNodes) { 
        const nodeQueue = []; 
        const visitedNodes = Array(totalNodes + 4).fill(false); 
        nodeQueue.push(startNode); 
        visitedNodes[startNode] = true; 
 
        while (nodeQueue.length > 0) { 
            const currentNode = nodeQueue.shift(); 
            for (const neighbor of graph[currentNode]) { 
                if (!visitedNodes[neighbor]) { 
                    nodeQueue.push(neighbor); 
                    visitedNodes[neighbor] = true; 
                } 
            } 
        } 
 
        return visitedNodes[targetNode1] || visitedNodes[targetNode2]; 
    } 
 
    const obstacleCount = obstacles.length; 
    const graph = Array(obstacleCount + 4).fill(null).map(() => []); 
    const obstacleData = obstacles.map(obstacle => [obstacle[0], obstacle[1], obstacle[2]]); 
 
    for (let i = 0; i < obstacleCount; ++i) { 
        if (obstacleData[i][0] <= obstacleData[i][2]) { 
            graph[obstacleCount].push(i); 
            graph[i].push(obstacleCount); 
        } 
        if (gridWidth - obstacleData[i][0] <= obstacleData[i][2]) { 
            graph[obstacleCount + 2].push(i); 
            graph[i].push(obstacleCount + 2); 
        } 
        if (obstacleData[i][1] <= obstacleData[i][2]) { 
            graph[obstacleCount + 1].push(i); 
            graph[i].push(obstacleCount + 1); 
        } 
        if (gridHeight - obstacleData[i][1] <= obstacleData[i][2]) { 
            graph[obstacleCount + 3].push(i); 
            graph[i].push(obstacleCount + 3); 
        } 
        for (let j = i + 1; j < obstacleCount; ++j) { 
            const deltaX = obstacleData[i][0] - obstacleData[j][0]; 
            const deltaY = obstacleData[i][1] - obstacleData[j][1]; 
            const distanceBetween = Math.sqrt(deltaX * deltaX + deltaY * deltaY); 
            if (obstacleData[i][2] + obstacleData[j][2] >= distanceBetween) { 
                graph[i].push(j); 
                graph[j].push(i); 
            } 
        } 
    } 
 
    return !(bfs(graph, obstacleCount, obstacleCount + 1, obstacleCount + 2, obstacleCount + 4) || 
             bfs(graph, obstacleCount + 3, obstacleCount + 2, obstacleCount + 1, obstacleCount + 4)); 
};
