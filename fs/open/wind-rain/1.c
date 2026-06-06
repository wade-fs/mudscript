// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","大門");
	set( "build", 12 );
set ("long", @LONG
一進門內，便傳來一股幽香，上面筩瓦青龍脊，門欄窗櫺俱是細雕
時新花樣，未粉朱墨，一色水磨群牆，下面白色石階鑿成流水蓮花
模樣，左右一望均是白雪芬薔，而下虎皮豹斑石隨意亂砌自成紋理
非凡富麗，再裡一望，霜石岭嶒縱橫拱立而上，藤蘿掩映，三方迎
覽。
LONG);



  set("exits", ([
            "east"  : __DIR__"2",
            "west"  : __DIR__"48",
            "south" : __DIR__"49",
            "out"   : __DIR__"room9",
                ]));

       

        setup();
}
