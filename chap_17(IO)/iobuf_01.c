/*
C:\msys64\ucrt64\include\stdio.h
*/
#ifndef _FILE_DEFINED
struct _iobuf
{
#ifdef _UCRT
    void *_Placeholder;
#else
    char *_ptr;      // 현재 위치 포인터
    int _cnt;        // 버퍼에 남아있는 문자 수
    char *_base;     // 버퍼의 시작 위치 포인터
    int _flag;       // 파일 상태 플래그
    int _file;       //  파일 디스크립터
    int _charbuf;    // 버퍼링되지 않은 단일 문자 저장
    int _bufsiz;     // 버퍼 크기
    char *_tmpfname; // 임시 파일 이름
#endif
};
typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif