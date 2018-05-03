#pragma once
#include "TabDlg.h"
#include "CalendarHelper.h"
#include "DrawCommon.h"
#include "afxwin.h"

// CHistoryTrafficCalendarDlg 对话框

class CHistoryTrafficCalendarDlg : public CTabDlg
{
	DECLARE_DYNAMIC(CHistoryTrafficCalendarDlg)

public:
	CHistoryTrafficCalendarDlg(deque<HistoryTraffic>& history_traffics, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CHistoryTrafficCalendarDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HISTORY_TRAFFIC_CALENDAR_DIALOG };
#endif

protected:
	deque<HistoryTraffic>& m_history_traffics;
	DayTraffic m_calendar[CALENDAR_HEIGHT][CALENDAR_WIDTH];
	int m_year;
	int m_month;
	__int64 m_month_total_traffic;		//当前月总流量数

	int m_year_max;
	int m_year_min;

	CComboBox m_year_combo;
	CComboBox m_month_combo;
	CToolTipCtrl m_tool_tips;

	CRect m_draw_rect;
	const int m_start_x{ theApp.DPI(10) };		//绘图的起始X坐标
	const int m_start_y{ theApp.DPI(38) };		//绘图的起始Y坐标

	void SetDayTraffic();
	void MonthSelectChanged();
	void CalculateMonthTotalTraffic();		//计算当前月总流量数
	void SetComboSel();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnCbnSelchangeYearCombo();
	afx_msg void OnCbnSelchangeMonthCombo();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedPreviousButton();
	afx_msg void OnBnClickedNextButton();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};
