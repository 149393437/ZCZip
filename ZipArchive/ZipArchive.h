//
//  ZipArchive.h
//  
//
//  Created by ZhangCheng on 14-4-25.
//  Copyright (c) 2014年 张 诚. All rights reserved.
/*
 版本说明iOS研究院 305044955
 //需要添加引用库libz 由原先手动修改为自动
 //进行解压缩
 ZipArchive*zip=[[ZipArchive alloc]init];
 //解压缩目标目录
 [zip  UnzipOpenFile:toPath];
 //解压缩到哪
 NSString*zipToPath=[LIBPATH stringByAppendingString:@"绿色简约"];
 [zip UnzipFileTo:zipToPath overWrite:YES];
 //完成解压缩（注意最后一步，必须写）
 [zip UnzipCloseFile];
 
 */


#import <UIKit/UIKit.h>

#include "minizip/zip.h"
#include "minizip/unzip.h"


@protocol ZipArchiveDelegate <NSObject>
@optional
-(void) ErrorMessage:(NSString*) msg;
-(BOOL) OverWriteOperation:(NSString*) file;

@end


@interface ZipArchive : NSObject {
@private
	zipFile		_zipFile;
	unzFile		_unzFile;
	
	NSString*   _password;
	id			_delegate;
}

@property (nonatomic, retain) id delegate;

-(BOOL) CreateZipFile2:(NSString*) zipFile;
-(BOOL) CreateZipFile2:(NSString*) zipFile Password:(NSString*) password;
-(BOOL) addFileToZip:(NSString*) file newname:(NSString*) newname;
-(BOOL) CloseZipFile2;

-(BOOL) UnzipOpenFile:(NSString*) zipFile;
-(BOOL) UnzipOpenFile:(NSString*) zipFile Password:(NSString*) password;
-(BOOL) UnzipFileTo:(NSString*) path overWrite:(BOOL) overwrite;
-(BOOL) UnzipCloseFile;
@end
