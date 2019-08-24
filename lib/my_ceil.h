#ifndef __MY_CEIL_H_
#define __MY_CEIL_H_
/** pour l'export des function */
#ifdef WIN32
#ifdef SDK_EXPORTS
//si le header est utilise dans le fichier source de la fonction a exporter
//il faudra mettre definir la macro SDK_EXPORTS
// et devant chaque function la macro SDK_API
#define SDK_API __declspec( dllexport )
#else
//si le header est utilise dans le fichier d'utilisation de la librarie

#define SDK_API __declspec( dllimport )
#endif//SDK_EXPORTS
#else
#ifdef __cplusplus
#define SDK_API extern "C"
#else
#define SDK_API extern
#endif//__cplusplus
#endif//WIN32


SDK_API double my_ceil(double d);
SDK_API double my_ceil2(double d);
#endif//__MY_CEIL_H_
