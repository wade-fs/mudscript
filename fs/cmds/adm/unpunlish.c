#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string key, chinz;
	string class;

        seteuid(geteuid());
	if( !arg || arg=="" )
		return notify_fail("指令格式﹕unpunlish <受罰者> <刑罰>\n");

	if(sscanf(arg,"%s %s",class,key)==2){
	PUNLISH_D->remove_translate(class,key);
	write("解除"+class+"的"+key+"刑罰\n");

	return 1;
	}
	return 0;
}

int help()
{
	write ( @HELP
指令格式﹕unpunlish <受罰者> <刑罰>\n
 
HELP
	);
	return 1 ;
}
