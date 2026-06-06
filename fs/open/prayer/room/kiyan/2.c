//open/prayer/room/kiyan/2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","書房");
        set("long",@LONG

	書房的書櫃全部都是以西洋橡木做成的，高有數丈．櫃中四處可見
	古詩古詞的書本，內中還參雜不少的武學圖騰．不過最引人注意的
	要屬那成堆八卦與易理類的書籍了!!

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "west":__DIR__"3",		//右護法
 
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
  setup();
}

