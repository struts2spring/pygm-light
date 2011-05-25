/* magick/magick_config_api.h.  Generated from magick_config_api.h.in by configure.  */
/* Defines required by <magick/api.h> */

/* Define if you have X11 library */
#define HasX11 1

/* Number of bits in a pixel Quantum (8/16/32) */
#define QuantumDepth 8

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/* #undef WORDS_BIGENDIAN */

/* Prefix Magick library symbols with a common string. */
/* #undef PREFIX_MAGICK_SYMBOLS */

#if (QuantumDepth == 8)
#  define MaxColormapSize  256U
#  define MaxMap  255U
#  define MaxMapFloat 255.0f
#  define MaxMapDouble 255.0
#  define MaxRGB  255U
#  define MaxRGBFloat 255.0f
#  define MaxRGBDouble 255.0
#  define ScaleCharToMap(value)        ((unsigned char) (value))
#  define ScaleCharToQuantum(value)    ((Quantum) (value))
#  define ScaleLongToQuantum(value)    ((Quantum) ((value)/16843009UL))
#  define ScaleMapToChar(value)        ((unsigned int) (value))
#  define ScaleMapToQuantum(value)     ((Quantum) (value))
#  define ScaleQuantum(quantum)        ((unsigned long) (quantum))
#  define ScaleQuantumToChar(quantum)  ((unsigned char) (quantum))
#  define ScaleQuantumToLong(quantum)  ((unsigned long) (16843009UL*(quantum)))
#  define ScaleQuantumToMap(quantum)   ((unsigned char) (quantum))
#  define ScaleQuantumToShort(quantum) ((unsigned short) (257U*(quantum)))
#  define ScaleShortToQuantum(value)   ((Quantum) ((value)/257U))
#  define ScaleToQuantum(value)        ((unsigned long) (value))
#  define ScaleQuantumToIndex(value)   ((unsigned char) (value))
   typedef unsigned char Quantum;
#elif (QuantumDepth == 16)
#  define MaxColormapSize  65536U
#  define MaxMap 65535U
#  define MaxMapFloat 65535.0f
#  define MaxMapDouble 65535.0
#  define MaxRGB  65535U
#  define MaxRGBFloat 65535.0f
#  define MaxRGBDouble 65535.0
#  define ScaleCharToMap(value)        ((unsigned short) (257U*(value)))
#  define ScaleCharToQuantum(value)    ((Quantum) (257U*(value)))
#  define ScaleLongToQuantum(value)    ((Quantum) ((value)/65537UL))
#  define ScaleMapToChar(value)        ((unsigned int) ((value)/257U))
#  define ScaleMapToQuantum(value)     ((Quantum) (value))
#  define ScaleQuantum(quantum)        ((unsigned long) ((quantum)/257UL))
#  define ScaleQuantumToChar(quantum)  ((unsigned char) ((quantum)/257U))
#  define ScaleQuantumToLong(quantum)  ((unsigned long) (65537UL*(quantum)))
#  define ScaleQuantumToMap(quantum)   ((unsigned short) (quantum))
#  define ScaleQuantumToShort(quantum) ((unsigned short) (quantum))
#  define ScaleShortToQuantum(value)   ((Quantum) (value))
#  define ScaleToQuantum(value)        ((unsigned long) (257UL*(value)))
#  define ScaleQuantumToIndex(value)   ((unsigned short) (value))
   typedef unsigned short Quantum;
#elif (QuantumDepth == 32)
#  define MaxColormapSize  65536U
#  define MaxRGB  4294967295U
#  define MaxRGBFloat 4294967295.0f
#  define MaxRGBDouble 4294967295.0
#  define ScaleCharToQuantum(value)    ((Quantum) (16843009U*(value)))
#  define ScaleLongToQuantum(value)    ((Quantum) ((value)))
#  define ScaleQuantum(quantum)        ((unsigned long) ((quantum)/16843009UL))
#  define ScaleQuantumToChar(quantum)  ((unsigned char) ((quantum)/16843009U))
#  define ScaleQuantumToLong(quantum)  ((unsigned long) (quantum))
#  define ScaleQuantumToShort(quantum) ((unsigned short) ((quantum)/65537U))
#  define ScaleShortToQuantum(value)   ((Quantum) (65537U*(value)))
#  define ScaleToQuantum(value)        ((unsigned long) (16843009UL*(value)))
#  define ScaleQuantumToIndex(value)   ((unsigned short) ((value)/65537U))

/*
  MaxMap defines the maximum index value for algorithms which depend
  on lookup tables (e.g. colorspace transformations and
  normalization). When MaxMap is less than MaxRGB it is necessary to
  downscale samples to fit the range of MaxMap. The number of bits
  which are effectively preserved depends on the size of MaxMap.
  MaxMap should be a multiple of 255 and no larger than MaxRGB.  Note
  that tables can become quite large and as the tables grow larger it
  may take more time to compute the table than to process the image.
*/
#define MaxMap 65535U
#define MaxMapFloat 65535.0f
#define MaxMapDouble 65535.0
#if MaxMap == 65535U
#  define ScaleCharToMap(value)        ((unsigned short) (257U*(value)))
#  define ScaleMapToChar(value)        ((unsigned int) ((value)/257U))
#  define ScaleMapToQuantum(value)     ((Quantum) (65537U*(value)))
#  define ScaleQuantumToMap(quantum)   ((unsigned short) ((quantum)/65537U))
#else
#  define ScaleCharToMap(value)        ((unsigned short) ((MaxMap/255U)*(value)))
#  define ScaleMapToChar(value)        ((unsigned int) ((value)/(MaxMap/255U)))
#  define ScaleMapToQuantum(value)     ((Quantum) ((MaxRGB/MaxMap)*(value)))
#  define ScaleQuantumToMap(quantum)   ((unsigned short) ((quantum)/(MaxRGB/MaxMap)))
#endif
typedef unsigned int Quantum;
#else
#  ifndef _CH_
#    error "Specified value of QuantumDepth is not supported"
#  endif
#endif
