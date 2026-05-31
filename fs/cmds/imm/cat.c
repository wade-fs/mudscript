// cat.c

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return notify_fail("你想要顯示那個檔案?\n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("沒有這個檔案。\n");
        log_file("wiz/CAT", sprintf("%s(%s) 在%s 觀看檔案%s %s\n"
        ,me->query("name"),me->query("id"),file_name(environment(me)),file, ctime(time()) ));
	cat(file);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : cat <檔案>

此指令可讓你(妳)直接讀取某檔案之程式。
HELP
    );
    return 1;
}
