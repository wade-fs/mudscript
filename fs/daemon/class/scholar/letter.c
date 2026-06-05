inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR + "挑戰書" + NOR,({"letter"}));
	set("unit","封");
	set("no_drop",1);
	set("no_give",1);
	set("no_get",1);
	set("value",1);
        setup();
}
void init() 
{
	add_action("do_read","read");
}
int do_read( string arg )
{
	if( !arg || arg != "letter" ) return 0;
	write(@LONG
挑戰書寫著﹕

聖賢書小賊﹐有膽來雪蒼山古奇峰一決生死。

			幻影娘子  雪魂
LONG);
	return 1;
}
