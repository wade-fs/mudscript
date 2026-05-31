#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string key, chinz;
    string cls;

        seteuid(geteuid());
	if( !arg || arg=="" )
		return notify_fail("指令格式﹕delguild <職業代碼> <門派名稱>\n");

    if(sscanf(arg,"%s %s",cls,key)==2){
    GUILD_D->remove_translate(cls,key);
	write("刪除一個門派"+key+"。\n");

	return 1;
	}
	return 0;
}

int help()
{
	write ( @HELP
指令格式﹕delguild <職業代碼> <門派名稱>
 
HELP
	);
	return 1 ;
}
