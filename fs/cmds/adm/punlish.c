#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string key, chinz;
	string class;

        seteuid(geteuid());
	if( !arg || arg=="" )
		return notify_fail("指令格式﹕punlsih <受罰者> <刑罰>\n");

	if(sscanf(arg,"%s %s",class,key)==2){
		switch(key)
		{
		case "no_call" :
			PUNLISH_D->add_translate(class,key,"no_call");
			break;
		default :
			return notify_fail("沒有這種刑罰。\n");
		}

		return 1;
	}
	

	return 0;
}

int help()
{
	write ( @HELP
指令格式﹕punlish <受罰者> <處罰>
 
HELP
	);
	return 1 ;
}
