

//****************************************************************************
//**
//** Copyright (c) 2010 DigitalPersona, Inc.
//**
//****************************************************************************
//**
//** version: 5.0.3
//** Built on "Jul 18 2010" "12:01:27"
//**
//****************************************************************************



#ifndef __DPFR_VER__
#define __DPFR_VER__ ((0x5<<8) | 0x0)
#endif //__DPFR_VER__

#pragma once
#ifndef __DP_DEFS_H
#define __DP_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#define IN
#define OUT

#define FT_BOOL int
#define FT_FALSE 0
#define FT_TRUE 1
typedef unsigned char FT_BYTE;
typedef void *FT_HANDLE;
typedef unsigned short FT_WORD;
typedef unsigned int FT_DWORD;
typedef wchar_t FT_WCHAR;
typedef const FT_WCHAR *FT_PCWCHAR;
#ifndef NULL
#define NULL 0
#endif

/* Fingerprint feature extraction or fingerprint comparison module version information structure. */

typedef struct
{
  unsigned  major;    /* Major version number */
  unsigned  minor;    /* Minor version number */
  unsigned  revision; /* Revision number */
  unsigned  build;    /* Build number */
}
FT_VERSION_INFO, *FT_VERSION_INFO_PT;

#ifndef  _MSC_VER
#ifndef __int64
  #define __int64 long long
#endif // !__int64
#endif // _MSC_VER

#if defined(__GNUC__) && !defined(__cdecl)
#define __cdecl __attribute__ ((cdecl))
#endif // __GNUC__


typedef struct
{
  int width;      /* Image width in pixels */
  int height;     /* Image height in pixels */
}
FT_IMAGE_SIZE, *FT_IMAGE_SIZE_PT;

typedef FT_BYTE *FT_IMAGE_PT;         /* image buffer address */
typedef FT_BYTE const * FT_IMAGE_PTC;

/*************** Fingerprint Feature Extraction, Enrollment, and Verification  *******************/

/* Feature set purpose. */
typedef enum
{
  FT_PRE_REG_FTR, /* Use this value for a fingerprint feature set to be used for enrollment. */
  FT_REG_FTR,     /* Use this value for a fingerprint template. */   
  FT_VER_FTR,     /* Use this value for a fingerprint feature set to be used for verification. */
} 
FT_FTR_TYPE;


/****************************** Fingerprint Feature Extraction ***********************************/

/* Image quality. */
typedef enum
{
  FT_GOOD_IMG,            /* The fingerprint image quality is good. */
  FT_IMG_TOO_LIGHT,       /* The fingerprint image is too light. */
  FT_IMG_TOO_DARK,        /* The fingerprint image is too dark. */
  FT_IMG_TOO_NOISY,       /* The fingerprint image is too blurred. */
  FT_LOW_CONTRAST,        /* The fingerprint image contrast is too low. */
  FT_UNKNOWN_IMG_QUALITY  /* The fingerprint image quality is  undetermined. */
}
FT_IMG_QUALITY, *FT_IMG_QUALITY_PT; 


/*Fingerprint features quality. */
typedef enum
{
  FT_GOOD_FTR,            /* The fingerprint features quality is good. */
  FT_NOT_ENOUGH_FTR,      /* There are not enough fingerprint features. */
  FT_NO_CENTRAL_REGION,   /* The fingerprint image does not contain the central portion of the finger. */
  FT_UNKNOWN_FTR_QUALITY, /* The fingerprint features quality is undetermined. */
  FT_AREA_TOO_SMALL       /* The fingerprint image area is too small. */
} 
FT_FTR_QUALITY, *FT_FTR_QUALITY_PT;



/* Target false accept rate (FAR). These are percentages, that is, a rate of 0.1 means 0.1% = 1/1000. */

typedef double FT_FA_RATE;

#define HIGH_SEC_FA_RATE 0.0001f     /* For high security, use this low value of FAR. */
#define MED_SEC_FA_RATE 0.0010f      /* For mid-range security, use this mid-range value of FAR. */
#define LOW_SEC_FA_RATE 0.0100f      /* For low security, use this high value of FAR. */
#define DFLT_FA_RATE MED_SEC_FA_RATE /* Default value for target FAR. */

/********************************** Deprecated. Do not Use !!! *************************************/
typedef unsigned __int64 FT_DEVICE_TYPE;

typedef FT_BOOL FT_REG_OPTIONS, *FT_REG_OPTIONS_PT;

enum {
  FT_DEFAULT_REG    = 0x0,
};
typedef enum
{
  FT_LOW_VER_SCORE,
  FT_MEDIUM_VER_SCORE,
  FT_HIGH_VER_SCORE,
  FT_BAD_SCORE,
  FT_UNKNOWN_SCORE
}
FT_VER_SCORE, *FT_VER_SCORE_PT;

#define FT_KEY_LEN 16



#ifdef __cplusplus
}
#endif

#endif // __DP_DEFS_H
