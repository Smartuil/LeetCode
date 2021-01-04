#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include "aStar.h"
using namespace std;
using namespace cv;

const int mapSize = 50;   // ��ͼ��С
const int imgGridSize = 5;// ��ʾ��ͼ��դ���С

// �����ϰ���
void defineObstacle(vector<vector<node*>>& roadmap) {
    // �ȿ�ס����
    for (int i = 0; i < mapSize; ++i) {
        roadmap[0][i]->setObstacle();
        roadmap[i][0]->setObstacle();
        roadmap[i][mapSize - 1]->setObstacle();
        roadmap[mapSize - 1][i]->setObstacle();
    }

    // �ٶ���һ�����ο�
    for (int i = 1; i < mapSize / 2; ++i) {
        roadmap[mapSize * 2 / 3][i]->setObstacle();
        roadmap[mapSize * 2 / 3 - 1][i]->setObstacle();
        roadmap[mapSize * 1 / 3][mapSize - i]->setObstacle();
        roadmap[mapSize * 1 / 3 - 1][mapSize - i]->setObstacle();
    }
}

// ������ͼ
void drawMap(Mat& background, node startNode, node goalNode, vector<vector<node*>> roadmap) {
    // �����ϰ���
    for (int i = 0; i < mapSize; ++i) {
        for (int j = 0; j < mapSize; ++j) {
            if (roadmap[i][j]->isObstacle())
                roadmap[i][j]->drawNode(background, imgGridSize, Scalar(0, 0, 0));
        }
    }

    // ������ʼ����յ�
    startNode.drawNode(background, imgGridSize, Scalar(255, 0, 0));//���Ϊ��ɫ
    goalNode.drawNode(background, imgGridSize, Scalar(0, 0, 255)); //Ŀ��λ��Ϊ��ɫ
}

// ��������ʽ����
double calHeristic(node* n1, node n2) {
    return (double)sqrt(pow(n1->coordinateX() - n2.coordinateX(), 2) + pow(n1->coordinateY() - n2.coordinateY(), 2));
}

// �жϽڵ��Ƿ����
bool verifyNode(node rhs) {
    if (rhs.coordinateX() < 0 || rhs.coordinateX() >= mapSize
        || rhs.coordinateY() < 0 || rhs.coordinateY() >= mapSize) {
        return false;
    }
    return true;
}

void aStar(const node& startNode, const node& goalNode, vector<vector<node*>>& roadmap, Mat& background) {
    // ʹ��Lambda���ʽ����һ�����ȶ���
    auto cmp = [](node* left, node* right) { return left->gN() > right->gN(); };
    priority_queue<node*, vector<node*>, decltype(cmp)> O(cmp);

    node* tmp = roadmap[startNode.coordinateX()][startNode.coordinateY()];
    O.push(tmp);

    // Algorithm 24 A* Algorithm
    while (!O.empty()) {
        // Pick nbest from O such that f(nbest) <= f(n).
        node* nBest = O.top();
        // Remove nbest from O and add to C(isVisited).
        O.pop();
        nBest->setIsVisited();
        // if nbest == qgoal, EXIT.
        if (*nBest == goalNode)
            break;

        // �˸����򶼿�����
        std::vector<node> motion = { node(1,   0,  1),
                node(0,   1,  1),
                node(-1,   0,  1),
                node(0,   -1,  1),
                node(-1,   -1,  std::sqrt(2)),
                node(-1,   1,  std::sqrt(2)),
                node(1,   -1,  std::sqrt(2)),
                node(1,    1,  std::sqrt(2)) };

        for (int i = 0; i < 8; i++) {
            node tmpNode = motion[i];
            tmpNode += *nBest;
            node* tmpNodePointer = roadmap[tmpNode.coordinateX()][tmpNode.coordinateY()];
            *tmpNodePointer = tmpNode;
            if (verifyNode(*tmpNodePointer) && !tmpNodePointer->returnIsVisited() && !tmpNodePointer->isObstacle()) {
                O.push(tmpNodePointer);
                tmpNodePointer->setIsVisited();
                tmpNodePointer->setBackpoint(nBest);
                tmpNodePointer->drawNode(background, imgGridSize, Scalar(0, 255, 0), 0);
                imshow("aStar", background);
                waitKey(5);
            }
        }
    }

    // �������յ�·��
    tmp = roadmap[goalNode.coordinateX()][goalNode.coordinateY()];
    while (!(*tmp == startNode)) {
        tmp->drawNode(background, imgGridSize, Scalar(255, 0, 0));
        tmp = tmp->returnBackpoint();
        imshow("aStar", background);
        waitKey(5);
    }
}

int main(int argc, char* argv[]) {
    
    node startNode(40, 10);// ��ʼ��
    node goalNode(10, 40); // Ŀ���

    int gridSize = 1, robotSize = 1;// դ��ߴ�ͻ����˳ߴ�

    vector<vector<node*>> roadmap;// ��ͼ,����洢����ָ��(������������߬д)

    // ��ʼ��roadmap
    for (int i = 0; i < mapSize; ++i) {
        vector<node*> tmp;
        for (int j = 0; j < mapSize; ++j) {
            node* tmpNode = new node(i, j);
            tmpNode->setHeuristic(calHeristic(tmpNode, goalNode));
            tmp.push_back(tmpNode);
        }
        roadmap.push_back(tmp);
    }

    // ����ϰ���
    defineObstacle(roadmap);

    // ��һ������
    namedWindow("aStar", WINDOW_NORMAL);
    
    Mat background(mapSize * imgGridSize,
                   mapSize * imgGridSize,
                   CV_8UC3,//8λ�޷���char��,3ͨ��
                   cv::Scalar(255, 255, 255));

    // ������ͼ
    drawMap(background, startNode, goalNode, roadmap);
    imshow("aStar", background);
    waitKey(5);

    aStar(startNode, goalNode, roadmap, background);
    waitKey();
    return 0;
}