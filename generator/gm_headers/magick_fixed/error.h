/*
  Copyright (C) 2003, 2004 GraphicsMagick Group
  Copyright (C) 2002 ImageMagick Studio
  Copyright 1991-1999 E. I. du Pont de Nemours and Company
 
  This program is covered by multiple licenses, which are described in
  Copyright.txt. You should have received a copy of Copyright.txt with this
  package; otherwise see http://www.graphicsmagick.org/www/Copyright.html.
 
  ImageMagick Exception Methods.
*/
#ifndef _MAGICK_ERROR_H
#define _MAGICK_ERROR_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* defined(__cplusplus) || defined(c_plusplus) */

#include "magick/magick_config.h"
#include "magick/forward.h"
#include "magick/common.h"

/*
  Enum declarations.
*/
typedef enum
{
  UndefinedExceptionBase = 0,
  ExceptionBase = 1,
  ResourceBase = 2,
  ResourceLimitBase = 2,
  TypeBase = 5,
  AnnotateBase = 5,
  OptionBase = 10,
  DelegateBase = 15,
  MissingDelegateBase = 20,
  CorruptImageBase = 25,
  FileOpenBase = 30,
  BlobBase = 35,
  StreamBase = 40,
  CacheBase = 45,
  CoderBase = 50,
  ModuleBase = 55,
  DrawBase = 60,
  RenderBase = 60,
  ImageBase = 65,
  WandBase = 67,
  TemporaryFileBase = 70,
  TransformBase = 75,
  XServerBase = 80,
  X11Base = 81,
  UserBase = 82,
  MonitorBase = 85,
  LocaleBase = 86,
  DeprecateBase = 87,
  RegistryBase = 90,
  ConfigureBase = 95
} ExceptionBaseType;

typedef enum
{
  UndefinedException = 0,
  EventException = 100,
  ExceptionEvent = EventException + ExceptionBase,
  ResourceEvent = EventException + ResourceBase,
  ResourceLimitEvent = EventException + ResourceLimitBase,
  TypeEvent = EventException + TypeBase,
  AnnotateEvent = EventException + AnnotateBase,
  OptionEvent = EventException + OptionBase,
  DelegateEvent = EventException + DelegateBase,
  MissingDelegateEvent = EventException + MissingDelegateBase,
  CorruptImageEvent = EventException + CorruptImageBase,
  FileOpenEvent = EventException + FileOpenBase,
  BlobEvent = EventException + BlobBase,
  StreamEvent = EventException + StreamBase,
  CacheEvent = EventException + CacheBase,
  CoderEvent = EventException + CoderBase,
  ModuleEvent = EventException + ModuleBase,
  DrawEvent = EventException + DrawBase,
  RenderEvent = EventException + RenderBase,
  ImageEvent = EventException + ImageBase,
  WandEvent = EventException + WandBase,
  TemporaryFileEvent = EventException + TemporaryFileBase,
  TransformEvent = EventException + TransformBase,
  XServerEvent = EventException + XServerBase,
  X11Event = EventException + X11Base,
  UserEvent = EventException + UserBase,
  MonitorEvent = EventException + MonitorBase,
  LocaleEvent = EventException + LocaleBase,
  DeprecateEvent = EventException + DeprecateBase,
  RegistryEvent = EventException + RegistryBase,
  ConfigureEvent = EventException + ConfigureBase,

  WarningException = 300,
  ExceptionWarning = WarningException + ExceptionBase,
  ResourceWarning = WarningException + ResourceBase,
  ResourceLimitWarning = WarningException + ResourceLimitBase,
  TypeWarning = WarningException + TypeBase,
  AnnotateWarning = WarningException + AnnotateBase,
  OptionWarning = WarningException + OptionBase,
  DelegateWarning = WarningException + DelegateBase,
  MissingDelegateWarning = WarningException + MissingDelegateBase,
  CorruptImageWarning = WarningException + CorruptImageBase,
  FileOpenWarning = WarningException + FileOpenBase,
  BlobWarning = WarningException + BlobBase,
  StreamWarning = WarningException + StreamBase,
  CacheWarning = WarningException + CacheBase,
  CoderWarning = WarningException + CoderBase,
  ModuleWarning = WarningException + ModuleBase,
  DrawWarning = WarningException + DrawBase,
  RenderWarning = WarningException + RenderBase,
  ImageWarning = WarningException + ImageBase,
  WandWarning = WarningException + WandBase,
  TemporaryFileWarning = WarningException + TemporaryFileBase,
  TransformWarning = WarningException + TransformBase,
  XServerWarning = WarningException + XServerBase,
  X11Warning = WarningException + X11Base,
  UserWarning = WarningException + UserBase,
  MonitorWarning = WarningException + MonitorBase,
  LocaleWarning = WarningException + LocaleBase,
  DeprecateWarning = WarningException + DeprecateBase,
  RegistryWarning = WarningException + RegistryBase,
  ConfigureWarning = WarningException + ConfigureBase,

  ErrorException = 400,
  ExceptionError = ErrorException + ExceptionBase,
  ResourceError = ErrorException + ResourceBase,
  ResourceLimitError = ErrorException + ResourceLimitBase,
  TypeError = ErrorException + TypeBase,
  AnnotateError = ErrorException + AnnotateBase,
  OptionError = ErrorException + OptionBase,
  DelegateError = ErrorException + DelegateBase,
  MissingDelegateError = ErrorException + MissingDelegateBase,
  CorruptImageError = ErrorException + CorruptImageBase,
  FileOpenError = ErrorException + FileOpenBase,
  BlobError = ErrorException + BlobBase,
  StreamError = ErrorException + StreamBase,
  CacheError = ErrorException + CacheBase,
  CoderError = ErrorException + CoderBase,
  ModuleError = ErrorException + ModuleBase,
  DrawError = ErrorException + DrawBase,
  RenderError = ErrorException + RenderBase,
  ImageError = ErrorException + ImageBase,
  WandError = ErrorException + WandBase,
  TemporaryFileError = ErrorException + TemporaryFileBase,
  TransformError = ErrorException + TransformBase,
  XServerError = ErrorException + XServerBase,
  X11Error = ErrorException + X11Base,
  UserError = ErrorException + UserBase,
  MonitorError = ErrorException + MonitorBase,
  LocaleError = ErrorException + LocaleBase,
  DeprecateError = ErrorException + DeprecateBase,
  RegistryError = ErrorException + RegistryBase,
  ConfigureError = ErrorException + ConfigureBase,

  FatalErrorException = 700,
  ExceptionFatalError = FatalErrorException + ExceptionBase,
  ResourceFatalError = FatalErrorException + ResourceBase,
  ResourceLimitFatalError = FatalErrorException + ResourceLimitBase,
  TypeFatalError = FatalErrorException + TypeBase,
  AnnotateFatalError = FatalErrorException + AnnotateBase,
  OptionFatalError = FatalErrorException + OptionBase,
  DelegateFatalError = FatalErrorException + DelegateBase,
  MissingDelegateFatalError = FatalErrorException + MissingDelegateBase,
  CorruptImageFatalError = FatalErrorException + CorruptImageBase,
  FileOpenFatalError = FatalErrorException + FileOpenBase,
  BlobFatalError = FatalErrorException + BlobBase,
  StreamFatalError = FatalErrorException + StreamBase,
  CacheFatalError = FatalErrorException + CacheBase,
  CoderFatalError = FatalErrorException + CoderBase,
  ModuleFatalError = FatalErrorException + ModuleBase,
  DrawFatalError = FatalErrorException + DrawBase,
  RenderFatalError = FatalErrorException + RenderBase,
  ImageFatalError = FatalErrorException + ImageBase,
  WandFatalError = FatalErrorException + WandBase,
  TemporaryFileFatalError = FatalErrorException + TemporaryFileBase,
  TransformFatalError = FatalErrorException + TransformBase,
  XServerFatalError = FatalErrorException + XServerBase,
  X11FatalError = FatalErrorException + X11Base,
  UserFatalError = FatalErrorException + UserBase,
  MonitorFatalError = FatalErrorException + MonitorBase,
  LocaleFatalError = FatalErrorException + LocaleBase,
  DeprecateFatalError = FatalErrorException + DeprecateBase,
  RegistryFatalError = FatalErrorException + RegistryBase,
  ConfigureFatalError = FatalErrorException + ConfigureBase
} ExceptionType;

/*
  Typedef declarations.
*/

/*
  ExceptionInfo is used to report exceptions to higher level routines,
  and to the user.
*/
typedef struct _ExceptionInfo
{
  /*
    Exception severity, reason, and description
  */
  ExceptionType
    severity;

  char
    *reason,
    *description;

  /*
    Value of errno (or equivalent) when exception was thrown.
  */
  int
    error_number;

  /*
    Reporting source module, function (if available), and source
    module line.
  */
  char
    *module,
    *function;

  unsigned long
    line;

  /*
    Structure sanity check
  */
  unsigned long
    signature;
} ExceptionInfo;

/*
  Exception typedef declarations.
*/
typedef void
  (*ErrorHandler)(const ExceptionType,const char *,const char *);

typedef void
  (*FatalErrorHandler)(const ExceptionType,const char *,const char *);

typedef void
  (*WarningHandler)(const ExceptionType,const char *,const char *);

/*
  Exception declarations.
*/
extern MagickExport const char
  *GetLocaleExceptionMessage(const ExceptionType,const char *),
  *GetLocaleMessage(const char *);

extern MagickExport ErrorHandler
  SetErrorHandler(ErrorHandler);

extern MagickExport FatalErrorHandler
  SetFatalErrorHandler(FatalErrorHandler);

extern MagickExport void
  CatchException(const ExceptionInfo *),
  CopyException(ExceptionInfo *copy, const ExceptionInfo *original),
  DestroyExceptionInfo(ExceptionInfo *),
  GetExceptionInfo(ExceptionInfo *),
  MagickError(const ExceptionType,const char *,const char *),
  MagickFatalError(const ExceptionType,const char *,const char *),
  MagickWarning(const ExceptionType,const char *,const char *),
  _MagickError(const ExceptionType,const char *,const char *),
  _MagickFatalError(const ExceptionType,const char *,const char *),
  _MagickWarning(const ExceptionType,const char *,const char *),
  SetExceptionInfo(ExceptionInfo *,ExceptionType),
  ThrowException(ExceptionInfo *,const ExceptionType,const char *,const char *),
  ThrowLoggedException(ExceptionInfo *exception, const ExceptionType severity,
    const char *reason,const char *description,const char *module,
    const char *function,const unsigned long line);

extern MagickExport WarningHandler
  SetWarningHandler(WarningHandler);

/*
  Exception define definitions.
*/

#include <magick/log.h>

#if defined(MAGICK_IMPLEMENTATION)
#  if defined(MAGICK_IDBASED_MESSAGES)

#    define MagickMsg(severity_,msg_) GetLocaleMessageFromID(MGK_##severity_##msg_)

/* Severity ID translated. */
#    define ThrowException(exception_,severity_,reason_,description_) \
  (ThrowLoggedException(exception_,severity_,GetLocaleMessageFromID(\
    MGK_##severity_##reason_),description_,GetMagickModule()))

/* No IDs translated */
#    define ThrowException2(exception_,severity_,reason_,description_) \
  (ThrowLoggedException(exception_,severity_,reason_,description_,\
    GetMagickModule()))

/* Serverity and description IDs translated */
#    define ThrowException3(exception_,severity_,reason_,description_) \
  (ThrowLoggedException(exception_,severity_,GetLocaleMessageFromID(\
    MGK_##severity_##reason_),GetLocaleMessageFromID(\
    MGK_##severity_##description_),GetMagickModule()))

#    define MagickError(severity_,reason_,description_) \
  (_MagickError(severity_,GetLocaleMessageFromID(MGK_##severity_##reason_),\
    description_))

#    define MagickFatalError(severity_,reason_,description_) \
  (_MagickFatalError(severity_,GetLocaleMessageFromID(\
    MGK_##severity_##reason_),description_))

#    define MagickWarning(severity_,reason_,description_) \
  (_MagickWarning(severity_,GetLocaleMessageFromID(MGK_##severity_##reason_),\
    description_))

#    define MagickError2(severity_,reason_,description_) \
  (_MagickError(severity_,reason_,description_))

#    define MagickFatalError2(severity_,reason_,description_) \
  (_MagickFatalError(severity_,reason_,description_))

#    define MagickWarning2(severity_,reason_,description_) \
  (_MagickWarning(severity_,reason_,description_))

#    define MagickError3(severity_,reason_,description_) \
  (_MagickError(severity_,GetLocaleMessageFromID(MGK_##severity_##reason_),\
    GetLocaleMessageFromID(MGK_##severity_##description_)))

#    define MagickFatalError3(severity_,reason_,description_) \
  (_MagickFatalError(severity_,GetLocaleMessageFromID(MGK_##severity_##reason_),\
    GetLocaleMessageFromID(MGK_##severity_##description_)))

#    define MagickWarning3(severity_,reason_,description_) \
  (_MagickWarning(severity_,GetLocaleMessageFromID(MGK_##severity_##reason_),\
    GetLocaleMessageFromID(MGK_##severity_##description_)))
/* end #if defined(MAGICK_IDBASED_MESSAGES) */
#  else

#    define MagickMsg(severity_,msg_) GetLocaleExceptionMessage(severity_,#msg_)

#    define ThrowException(exception_,severity_,reason_,description_) \
  (ThrowLoggedException(exception_,severity_,#reason_,description_,GetMagickModule()))

#    define ThrowException2(exception_,severity_,reason_,description_) \
  (ThrowLoggedException(exception_,severity_,reason_,description_,GetMagickModule()))

#    define ThrowException3(exception_,severity_,reason_,description_) \
  (ThrowLoggedException(exception_,severity_,#reason_,#description_,GetMagickModule()))

#    define MagickError(severity_,reason_,description_) \
  (_MagickError(severity_,#reason_,description_))

#    define MagickFatalError(severity_,reason_,description_) \
  (_MagickFatalError(severity_,#reason_,description_))

#    define MagickWarning(severity_,reason_,description_) \
  (_MagickWarning(severity_,#reason_,description_))

#    define MagickError2(severity_,reason_,description_) \
  (_MagickError(severity_,reason_,description_))

#    define MagickFatalError2(severity_,reason_,description_) \
  (_MagickFatalError(severity_,reason_,description_))

#    define MagickWarning2(severity_,reason_,description_) \
  (_MagickWarning(severity_,reason_,description_))

#    define MagickError3(severity_,reason_,description_) \
  (_MagickError(severity_,#reason_,#description_))

#    define MagickFatalError3(severity_,reason_,description_) \
  (_MagickFatalError(severity_,#reason_,#description_))

#    define MagickWarning3(severity_,reason_,description_) \
  (_MagickWarning(severity_,#reason_,#description_))

#  endif
#endif /* defined(MAGICK_IMPLEMENTATION) */

#define ThrowBinaryException(severity_,reason_,description_) \
do { \
  if (image != (Image *) NULL) \
    { \
      ThrowException(&image->exception,severity_,reason_,description_); \
    } \
  return(MagickFail); \
} while (0);

#define ThrowBinaryException2(severity_,reason_,description_) \
do { \
  if (image != (Image *) NULL) \
    { \
      ThrowException2(&image->exception,severity_,reason_,description_); \
    } \
  return(MagickFail); \
} while (0);

#define ThrowBinaryException3(severity_,reason_,description_) \
do { \
  if (image != (Image *) NULL) \
    { \
      ThrowException3(&image->exception,severity_,reason_,description_); \
    } \
  return(MagickFail); \
} while (0);

#define ThrowImageException(code_,reason_,description_) \
do { \
  ThrowException(exception,code_,reason_,description_); \
  return((Image *) NULL); \
} while (0);

#define ThrowImageException2(code_,reason_,description_) \
do { \
  ThrowException2(exception,code_,reason_,description_); \
  return((Image *) NULL); \
} while (0);

#define ThrowImageException3(code_,reason_,description_) \
do { \
  ThrowException3(exception,code_,reason_,description_); \
  return((Image *) NULL); \
} while (0);

#define ThrowReaderException(code_,reason_,image_) \
do { \
  if (UndefinedException == exception->severity) \
    { \
      ThrowException(exception,code_,reason_,image_ ? (image_)->filename : 0); \
    } \
  if (image_) \
    { \
       CloseBlob(image_); \
       DestroyImageList(image_); \
    } \
  return((Image *) NULL); \
} while (0);

#define ThrowWriterException(code_,reason_,image_) \
do { \
  assert(image_ != (Image *) NULL); \
  ThrowException(&(image_)->exception,code_,reason_,(image_)->filename); \
  if (image_info->adjoin) \
    while ((image_)->previous != (Image *) NULL) \
      (image_)=(image_)->previous; \
  CloseBlob(image_); \
  return(MagickFail); \
} while (0);

#define ThrowWriterException2(code_,reason_,image_) \
do { \
  assert(image_ != (Image *) NULL); \
  ThrowException2(&(image_)->exception,code_,reason_,(image_)->filename); \
  if (image_info->adjoin) \
    while ((image_)->previous != (Image *) NULL) \
      (image_)=(image_)->previous; \
  CloseBlob(image_); \
  return(MagickFail); \
} while (0);

#define ThrowWriterException3(code_,reason_,image_) \
do { \
  assert(image_ != (Image *) NULL); \
  ThrowException3(&(image_)->exception,code_,reason_,(image_)->filename); \
  if (image_info->adjoin) \
    while ((image_)->previous != (Image *) NULL) \
      (image_)=(image_)->previous; \
  CloseBlob(image_); \
  return(MagickFail); \
} while (0);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* defined(__cplusplus) || defined(c_plusplus) */

#endif /* !defined(_MAGICK_ERROR_H) */

/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 2
 * fill-column: 78
 * End:
 */
