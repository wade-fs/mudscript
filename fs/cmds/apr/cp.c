// cp.c
// 增加 萬用字元(?*) 的使用
// fixed by wade 1995 10 23
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
  string        src, dst, dest, *dirs;
  // 底下是為了能 cp * 用的
  mixed         *file;
  string        dir, srcdir;
  int           i, j;
 
  seteuid(geteuid(me));

  // 解析參數
  if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
    notify_fail("指令格式: cp <原檔名> <目標檔名> \n");

  // 判斷是否是合法的目標檔名
  dst = resolve_path(me->query("cwd"), dst);
  if(dst[<1] == '/') dst = dst[0..<2];
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
  if( file_size(dst)==-2 ) {    // 代表 dest 是個目錄
    while(i--) {
      if (file[i][1]!=-2) {
        src = srcdir+file[i][0];
        dirs = explode(src, "/");
        dest = dst+ "/" + dirs[<1];
        write("cp "+src+" to "+dest+" OK!!!\n");

        if (cp(src, dest) != 1 || file_size(dest) == -1)
          write("你沒有讀寫"+dest+"的權利。\n");
        else {
          write("cp "+src+" to "+dest+" OK!!!\n");

          log_file ("wiz/FILE_OPERATION",
            sprintf("%s(%s)拷貝檔案 %s --> %s 於%s\n",
              me->query("name"),me->query("id"),src, dest, ctime(time()))
          );
        }
      }
    }
  }
  else
    while(i--) {
      if (file[i][1]!=-2) {
        src = srcdir+file[i][0];

        if (cp(src, dst) != 1 || file_size(dst) == -1)
          write("你沒有讀寫"+dst+"的權利。\n");
        else {
          write("cp "+src+" to "+dst+" OK!!!\n");
          log_file ("wiz/COPY_FILE",
            sprintf("%s(%s)拷貝檔案 %s --> %s 於%s\n",
              me->query("name"),me->query("id"),src,dst,ctime(time()))
          );
        }
      }
    }

  return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : cp <原檔名> <目標檔名>
 
此指令可讓你(妳)拷貝檔案。
HELP
    );
    return 1;
}
 
