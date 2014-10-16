ZCZip
=====

解压缩与压缩
修改压缩与解压缩支持ARC模式
版本说明iOS研究院 305044955 
//需要添加引用库libz 由原先手动修改为自动 
//进行解压缩
ZipArchive*zip=[[ZipArchive alloc]init]; 
//解压缩目标目录 
[zip UnzipOpenFile:toPath]; 
//解压缩到哪
NSString*zipToPath=[LIBPATH stringByAppendingString:@"绿色简约"];
[zip UnzipFileTo:zipToPath overWrite:YES]; 
//完成解压缩（注意最后一步，必须写） 
[zip UnzipCloseFile];
