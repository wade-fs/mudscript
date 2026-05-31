// fund, 你寫程式都不寫 help 的啊

inherit F_CLEAN_UP;
int main(object me,string arg)
{
	string cmds,str;
	string file;

	seteuid(getuid());
	if (!arg) return notify_fail ("啊? 你要什麼命令?\n");
	if(sscanf(arg,"%s %s",cmds,str)!=2)
		cmds=arg;
	file="/daemon/class/normal/cmds/"+cmds;
	if(file_size(file+".c")>0)
		return file->main(me,str);
	file="/daemon/class/"+me->query("class")+"/cmds/"+cmds;
	if(file_size(file+".c")<=0)
		return notify_fail("沒有這樣指令。\n");
	if (me->query_condition("block_sweat"))
    return notify_fail ("受到蒙汗藥的抑制，你無法正常使用技能。\n");
	return file->main(me,str);
}

int help (object me)
{
        write(@HELP
指令格式 : cmd <工會門派專用指令>
指令說明 :
           這個指令可以讓你使用門派專用指令。
HELP);
}
