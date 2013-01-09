#ifndef _GLOBALS_H
#define _GLOBALS_H

//netpsersec.ini strings
#define SZ_APPNAME "NetPerSec"
#define SZ_NETPERSEC_INI "netpersec.ini"
#define SZ_CONFIG "Settings"
#define SZ_FIRST "First"
#define SZ_SAMPLERATE "SampleRate"
#define SZ_AVERAGEWINDOW "AverageWindow"
#define SZ_RANGE_RECV "RangeRecv"
#define SZ_RANGE_SENT "RangeSent"
#define SZ_GRAPHOPTIONS "GraphOptions"
#define SZ_DISPLAYBYTES "DisplayBytes"
#define SZ_STARTUP "StartUp"
#define SZ_ONTOP "OnTop" 
#define SZ_BARGRAPH "BarGraph"
#define SZ_AUTOSCALE_RECV "AutoScaleRecv"
#define SZ_AUTOSCALE_SENT "AutoScaleSent"
#define SZ_ICON_STYLE "IconStyle"
#define SZ_COLOR_BACK "ColorBackground"
#define SZ_COLOR_RECV "ColorRecv"
#define SZ_COLOR_SENT "ColorSent"
#define SZ_COLOR_AVE  "ColorAve"
#define SZ_COLOR_ICON "ColorIconBack"
#define SZ_WINPOS_LEFT "WinLeft"
#define SZ_WINPOS_TOP  "WinTop"
#define SZ_MONITOR_MODE "MonitorMode"
#define SZ_ADAPTER_INDEX "AdapterIndex"

//timer ids
#define	TIMER_ID_WINPROC  1
#define TIMER_ID_SESSION  2 


//default colors
#define COLOR_ICON_SENT RGB(0,0,255)
#define COLOR_ICON_RECV RGB(255,0,0)
#define COLOR_AVERAGE RGB(0,128,128)
#define COLOR_ICON_BACK RGB(255,255,255)

//these entries contain the current SNMP sample
typedef struct
{
    DWORD Bps;          //bytes per second          
    DWORD ave;          //average throughput
    DWORD time;         //time in milliseconds that the sample was taken
    double total;       //total received or sent in bits
} STATS_STRUCT;

//system tray icon style
typedef enum {
    ICON_BARGRAPH,
    ICON_HISTOGRAM,
} ICON_STYLE;

//monitor mode
typedef enum {
    MONITOR_ALL,
    MONITOR_DUN,
    MONITOR_ADAPTER,
} MONITOR_MODE;

#define MAX_SAMPLES 61
#define ELEMENTS(x) (sizeof(x) / sizeof(int) )

#define MAX_ICON_COLORS 16
extern COLORREF IconColors[MAX_ICON_COLORS];

//loaded via ini file
extern int g_nSampleRate;        //milliseconds
extern int g_nAveragingWindow;   //seconds
extern int g_Range_Recv;  //for graph window (in bps)
extern int g_Range_Sent;  //for graph window (in bps)
extern int g_GraphOptions; 
extern int g_DisplayBytes;
extern BOOL g_bStartWithWindows;
extern BOOL g_bOnTop; 
extern BOOL g_bShowBarGraph;
extern BOOL g_bAutoScaleRecv;
extern BOOL g_bAutoScaleSent;
extern MONITOR_MODE g_MonitorMode;
extern double g_dbResetRecv;   //when user clicks reset
extern double g_dbResetSent;   //these values are subtracted from the total
extern DWORD g_dwAdapter;      //specific adapter index to monitor

extern COLORREF g_ColorBack;
extern COLORREF g_ColorRecv; 
extern COLORREF g_ColorSent;
extern COLORREF g_ColorAve ; 
extern COLORREF g_ColorIconBack;
extern ICON_STYLE g_IconStyle;



// Prototypes 
void ReadSettings( );
void SaveSettings( );
void ShowError( UINT nID, int nType );
void FormatBytes( double Bytes, CString *pString, BOOL bPerSecond = TRUE /* bPerSecond = TRUE */ );
LPSTR FormatNumber( DWORD N );
void WritePrivateProfileInt( LPCSTR pSection, int nValue );
int GetPrivateProfileString( LPCSTR pKey,LPCSTR lpDefault, LPSTR lpReturn, int nSize );
int GetPrivateProfileInt( LPCSTR pKey, int nDefault = 0 );
void WritePrivateProfileString( LPCSTR pSection, LPCSTR pValue );
void LoadWindowPosition( CRect *pRect );
void SaveWindowPosition( CRect *pRect );
DWORD GetServicePack( );

#endif