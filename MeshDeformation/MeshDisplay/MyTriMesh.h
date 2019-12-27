#pragma once
#include "windows.h"
#include "../Utility/baseHeadFile.h"
#include "../Utility/predefine.h"
#include "glut.h"

class MyTriMesh
{
protected:
	TriMesh m_mesh;

private:
	bool m_updateDistList;

public:
	int m_disType;
	bool m_show;
	GLuint m_drawMesh;

	//��Χ������
	Point3D m_centerOfAABB;
	double boundBoxEdgeLen;
	vector<Vector3D> m_vertexNormal;

public:
	MyTriMesh(void);
	~MyTriMesh(void);

public:
	void init();
	void Draw();
	void LoadMesh();
	void SaveMesh();
	int vertexSize(){return m_mesh.n_vertices();};
	int faceSize(){return m_mesh.n_faces();};
	void SetMeshDisMode(int mode){m_disType = mode;UpdateDisList();};
	bool empty(){return m_mesh.vertices_empty();;};
	void DrawList();
	void UpdateDisList(TriMesh* tmesh = 0){if(tmesh){m_mesh = *tmesh;} m_updateDistList = true; };
	void SetMesh(TriMesh* mesh_);
	TriMesh* GetMesh(){return &m_mesh;};

	//�����Ƭ��ʾ����
	void GetAABBofObject();
	void ReComputeVertexNormal();
	double GetAverageEdgeLength();
};

 