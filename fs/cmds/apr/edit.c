// edit.c

inherit F_CLEAN_UP;

int main(object me, string file)
{
	if( !file ) return notify_fail("指令格式﹕edit <檔名>\n");

	if( in_edit(me) ) return notify_fail("你已經在使用編輯器了。\n");

	seteuid(geteuid(me));
	file = resolve_path(me->query("cwd"), file);
	ed(file);
	log_file ("file_operation", sprintf("%s編輯檔案 %s 於%s\n",
	  me->short(), file, CHINESE_D->chinese_time(time()))
	);
	me->set("cwf", file);
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : edit <檔名>, edit here

利用此一指令可直接在線上編輯檔案。
HELP
    );
    return 1;
}
