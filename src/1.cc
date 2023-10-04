#include <iostream>
#include "./s21_Containers/s21_list.h"
//конспект https://www.youtube.com/watch?v=VehB3eglQMQ&t=27s
class Edge {
    Node adjacentNode;
    int weight;
    Edge(Node adjacentNode, int weight) {
        this.adjacentNode=adjacentNode; this->weight=weight;
    }
};

class Node {
    int value;
    LinkedHashSet<Edge> edges=newLinkedHashSet<>();
    LinkedHashMap<Node, Edge> parents=new LinkedHashMap<>();
    Node(int value) {this->value=value;}
};

Node addOrGetNode(HashMap<integer, Node> graph, int value) {
    if(value==-1) return NULL;
    if(graph.containsKey(value)) return graph.get(value);
    Node node = new Node(value);
    graph.put(value, node);
    return node;
}

// generation of graph
// go through the input values and take two nodes
// std::unordered set in C++

Hashmap<Integer, Node> createGraph(int[][]graphData) {
    HashMap<Integer, Node> graph = new HashMap<>();
    for(int[]row : graphData) {
        Node node = addOrGetNode(graph, row[0]);
        Node adjacentNode = addOrGetNode(graph, row[1]);
        if(adjacentNode==Null) continue;
        Edge edge = new Edge(adjacentNode, row[2]);
        node.edges.add(edge);
        adjacentNode.parents.put(node, edge);

    }
    return graph;
}

// в глубину только для связного графа

void DFS(Node node, HashSet<Node> passed) {
    print(node.value);
    passed.add(node);
    for(Edge edge : node.edges) 
        if(!passed.contains(edge.adjacentNode)) 
            DFS(edge.adjacentNode, passed);
}

// поиск в глубину - обертка. Будем перебирать все узлы без исключения

void DFSWrap(HashMap<Integer, Node> graph) {
    HashSet<Node> passed = new HasgSet<>();
    for(Map.Entry<Integer, Node>graphEntry : graph.entrySet()) {
        Node node = graphEntry.getValue();
        if(!passed.contains(node)) DFS(node, passed);
    }
}

//поиск в глубину = через циклы
//создаем структуру данных стек, кидаем туда самый первый узел с которого начинается обход и 
//крутим цикл до тех пор пока стек полностью не опустеет
void DFS(Node node, HasgSet<Node> passed) {
    void DFS(Node node, HasgSet<Node> passed) {
        Stack<Node> stack=new Stack<>();
        stack.push(node);
        while(stack.size() !=0) {
            node=stack.peek();
            if(!passed.contains(node)) {
                print(node.value);
                passed.add(node);
            }
            boolean hasChildren=false;
            for(Edge edge : node.edges) { 
                if (!passed.contains(edge.adjacentNode)) { //отправим первого найденного ребенка которого не посещали 
                    stack.push(edge.adjacentNode); // в стек
                    hasChildren = true;
                    break;
                }
            } // если дошли до конца (у крайнего узла нет дедей) то удаляем его из стека и поднимается выше
            if(!hasChildren) stack.pop();
        }
    }
}

boolean getPath(Node start, Node end, HashSet<Node> passed, LinkedList<Node> path) {
    if(start==end) {path.addFirst(start); return true;}
    passed.add(start);
    for(Edge edge : start.edges) {
        if(!passed.contains(edge.adjacentNode)) {
            if(getPath(edge.adjacentNode, end, passed, path)) {
                path.addFirst(start);
                return true;
            }
        }
    }
}


// поиск всех путей 

void getPath(Node start, Node end, LinkedHashSet<Node> passed, List <LinkedHashSet<Node>> paths) {
    if(start==end) {
        paths.add((LinkedHashSet<Node>) passed.clone());
        paths.get((paths.size()-1).add(end)); 
    }
    passed.add(start);
    for(Edge edge : start.edges) {
        if(!passed.contains(edge.adjacentNode)) {
            getPathAll(edge.adjacentNode, end, passed, paths);
        }
    } // как только мы прошли всех детей какого то узла то мы удаляем их из списка посещенных
    passed.remove(start);
}

//вширину

void BFS(Node node, HashSet<Node> visitingOrPassed) {
    LinkedLislt<Node> queue = new LinkedList<>();
    queue.add(node);
    visitingOrPassed.add(node);
    while(!queue.isEmpty()) {
        node = queue.removeFirst();
        print(node.value);
        for(Edge edge : node.edges) {
            if(!visitingOrPassed.contains(edge.adjacentNode)) {
                queue.addLast(edge.adjacentNode);
                print(edge.adjacentNode.value);

            }
        }
    }
}

//обертка для поиска в ширину которая гарантированно пройдет вширину  даже не связанные узлы
void BFSWrap(HashMap<Integer, Node> graph) {
    HashSet<Node> visitingOrPassed = new HashSet<>();
    for(Map.Entry<Integer, Node> entry : graph.entrySet()) {
        if(!visitingOrPassed.contains(entry.getValue()))
        BFS(entry.getValue(), visitingOrPassed);
    } 
}

// поиск крайтчайшего пути

PathNode findShortestPath(Node start, Node end) {
    HashSet<Node> visitingOrPassed = new HashSet<>();
    LinkedList<PathNode> queue =  new LinkedList<>();
    queue.addLast(new PathNode(start, null));
    visitingOrPassed.add(start);
    while(!queue.isEmpty()) {
        PathNode pathNode = queue.removeFirst();
        if(pathNode.node ==end) return pathNode;
        for(Edge edge : pathNode.node.edges) {
            if(visitingOrPassed.contains(edge.adjacentNode)) continue;
            if(edge.adjacentNode == end)
            return new PathNode(edge.adjacentNode, pathNode);
            queue.addLast(new PathNode(edge.adjacentNode, pathNode));
            visitingOrPath.add(pathNode.node);
        }
    }
    return null;
}

//в очередь добавляем не сами элементы а специальную обертку

class PathNode{
    public Node node;
    public PathNode parent;
    public PathNode(Node node, PathNode parent) {
        this.node=node; this.parent=parent;
    }
}

//распаковка пути

LinkedList<Node> extractPath(PathNode endNode) {
    LinkedList<Node> path = new LinkedList<>();
    while(endnNode !=null) {
        path.addFirst(endNode.node);
        endNode = endNode.parent;
    }
    return path;
}