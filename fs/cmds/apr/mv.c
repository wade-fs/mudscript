// mv.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
        notify_fail("指令格式: mv <原檔名> <目標檔名> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
 
        if(file_size(src)==-1) return notify_fail("沒有"+src+"這個檔!!\n");
        if( !rename(src, dst) ) {
          log_file ("file_operation", sprintf("%s更改檔名 %s --> %s 於%s\n",
            me->short(), src, dst, CHINESE_D->chinese_time(time()))
          );
          write("Ok.\n");
	}
        else
                write("你沒有足夠的讀寫權利。\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : mv <原檔名> <目標檔名>
 
此指令可讓你(妳)修改某個檔案或目錄名稱。
HELP
    );
    return 1;
}
 
