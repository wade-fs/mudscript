inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIB + "密函" + NOR,({"letter"}));
	set("unit","封");
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
信中寫著﹕

速殺「黑仙羅漢」並將屍體帶來﹐葉某當有重酬﹗

				葉秀殺
LONG);
	return 1;
}
