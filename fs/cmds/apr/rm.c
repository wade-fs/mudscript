inherit F_CLEAN_UP; 
int main(object me, string arg)
{
  string        src, dst, dest, *dirs;
  mixed         *file;
  string        dir, srcdir;
  int           i, j; 
  seteuid(geteuid(me));
  // 解析參數
  if (!arg || sscanf(arg, "%s", src)!=1 )
  return notify_fail("指令格式: rm <原檔名> \n");
  // 取得 source 檔名
  dir = resolve_path(me->query("cwd"), src);
  dirs = explode(dir, "/");
  srcdir = dir;
  i = sizeof(dir) - sizeof(dirs[<1]);
  srcdir = dir[0..i-1];
  if( file_size(dir)==-2 && dir[<1] != '/' ) dir += "/";
  file = get_dir(dir, -1);
  if( !sizeof(file) ) {
    if (file_size(dir) == -2)
      return notify_fail("目錄是空的。\n");
    else
      return notify_fail("沒有這個檔案: "+src+"。\n");
  }
  i = sizeof(file);
    while(i--) {
      if (file[i][1]!=-2) {
        src = srcdir+file[i][0];
        if(rm(src)){
          write("rm "+src+" OK!!!\n");
        }
        else{
              return notify_fail("你沒有刪除"+src+"的權力\n");
        }
      }
    }

  return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 :  rm <檔名>
               <檔名如為 * 能一次 rm 掉 so 小心使用>
此指令可讓你(妳)刪除檔案。
HELP
    );
    return 1;
}
 
