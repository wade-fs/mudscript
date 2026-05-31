#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string key, chinz;
    string cls;

        seteuid(geteuid());
	if( !arg || arg=="" )
		return notify_fail("指令格式﹕addguild <職業代碼> <門派名稱> <門派領袖>\n");

    if(sscanf(arg,"%s %s %s",cls,key,chinz)==3){
        GUILD_D->add_translate(cls,key,chinz);
		write("增加一個新門派"+key+"。\n");
		return 1;
	}
	

	return 0;
}

int help()
{
	write ( @HELP
指令格式﹕addguild <職業代碼> <門派名稱> <門派領袖>
 
HELP
	);
	return 1 ;
}
