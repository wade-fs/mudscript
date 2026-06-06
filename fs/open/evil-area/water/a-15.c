inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 揚 湖"NOR);
	set("long",@LONG
輕飄而來的花香撲鼻，你忍不住的陶醉其中，回想著人間各地，
似乎也只有煙雨江南才能與此地相抗衡，風光景色，優美鳥啼，細雨
輕飄，如詩如畫，你幾乎已經忘了自己身處恐怖的邪靈界了。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"a-16",
"north":__DIR__"a-14",
]));
	setup();
}

 
