#include <iostream>
#include "./s21_Containers/s21_list.h"
//�������� https://www.youtube.com/watch?v=VehB3eglQMQ&t=27s
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

// � ������� ������ ��� �������� �����

void DFS(Node node, HashSet<Node> passed) {
    print(node.value);
    passed.add(node);
    for(Edge edge : node.edges) 
        if(!passed.contains(edge.adjacentNode)) 
            DFS(edge.adjacentNode, passed);
}

// ����� � ������� - �������. ����� ���������� ��� ���� ��� ����������

void DFSWrap(HashMap<Integer, Node> graph) {
    HashSet<Node> passed = new HasgSet<>();
    for(Map.Entry<Integer, Node>graphEntry : graph.entrySet()) {
        Node node = graphEntry.getValue();
        if(!passed.contains(node)) DFS(node, passed);
    }
}

//����� � ������� = ����� �����
//������� ��������� ������ ����, ������ ���� ����� ������ ���� � �������� ���������� ����� � 
//������ ���� �� ��� ��� ���� ���� ��������� �� ��������
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
                if (!passed.contains(edge.adjacentNode)) { //�������� ������� ���������� ������� �������� �� �������� 
                    stack.push(edge.adjacentNode); // � ����
                    hasChildren = true;
                    break;
                }
            } // ���� ����� �� ����� (� �������� ���� ��� �����) �� ������� ��� �� ����� � ����������� ����
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


// ����� ���� ����� 

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
    } // ��� ������ �� ������ ���� ����� ������ �� ���� �� �� ������� �� �� ������ ����������
    passed.remove(start);
}

//�������

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

//������� ��� ������ � ������ ������� �������������� ������� �������  ���� �� ��������� ����
void BFSWrap(HashMap<Integer, Node> graph) {
    HashSet<Node> visitingOrPassed = new HashSet<>();
    for(Map.Entry<Integer, Node> entry : graph.entrySet()) {
        if(!visitingOrPassed.contains(entry.getValue()))
        BFS(entry.getValue(), visitingOrPassed);
    } 
}

// ����� ������������ ����

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

//� ������� ��������� �� ���� �������� � ����������� �������

class PathNode{
    public Node node;
    public PathNode parent;
    public PathNode(Node node, PathNode parent) {
        this.node=node; this.parent=parent;
    }
}

//���������� ����

LinkedList<Node> extractPath(PathNode endNode) {
    LinkedList<Node> path = new LinkedList<>();
    while(endnNode !=null) {
        path.addFirst(endNode.node);
        endNode = endNode.parent;
    }
    return path;
}