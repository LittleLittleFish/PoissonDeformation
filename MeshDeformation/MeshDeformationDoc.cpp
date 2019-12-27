// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// MeshDeformationDoc.cpp : CMeshDeformationDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MeshDeformation.h"
#endif

#include "MeshDeformationDoc.h"
#include "UI/MeshDeformationView.h"
#include "Utility/MyAfxFunction.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMeshDeformationDoc

IMPLEMENT_DYNCREATE(CMeshDeformationDoc, CDocument)

BEGIN_MESSAGE_MAP(CMeshDeformationDoc, CDocument)
	ON_COMMAND(ID_FILE_OPEN, &CMeshDeformationDoc::OnDocMeshOpen)
	ON_COMMAND(ID_FILE_SAVE, &CMeshDeformationDoc::OnDocMeshSave)
END_MESSAGE_MAP()


// CMeshDeformationDoc ����/����
 
CMeshDeformationDoc::CMeshDeformationDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMeshDeformationDoc::~CMeshDeformationDoc()
{
}

BOOL CMeshDeformationDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMeshDeformationDoc ���л�

void CMeshDeformationDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMeshDeformationDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMeshDeformationDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMeshDeformationDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMeshDeformationDoc ���

#ifdef _DEBUG
void CMeshDeformationDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMeshDeformationDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMeshDeformationDoc ����

//����mesh
void CMeshDeformationDoc::OnDocMeshOpen()
{
	theApp.m_triMesh.LoadMesh();
	theApp.resetDeformation();

	//������ͼ��ʾ
	afxGetMainView()->updateView();
	afxGetPickMesh()->SetDesMesh(theApp.m_triMesh.GetMesh());
}

//����mesh
void CMeshDeformationDoc::OnDocMeshSave()
{
	theApp.m_triMesh.SaveMesh();
}
