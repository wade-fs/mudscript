//加入ctitle npc -CHAD-20090421

inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "一般民宅");
	set( "build", 12 );
        set ("long", @LONG
走進這間屋子，裏面的擺設很簡單，所有的傢俱都打掃的一塵不
染，在你左側的牆上掛了兩張字畫，仔細一看墨跡猶乾未乾的，似是
完成未久的兩幅作品，看來應該就是正拿著毛筆的這位高人所畫的。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "south"  : __DIR__"town10",
        ]));
        set("objects",([
        "/open/ctitle/npc/fay" : 1,
        ]));
        set("light_up", 1);
        setup();
}
