inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 揚 湖"NOR);
	set("long",@LONG
輕飄而來的花香撲鼻，你忍不住的陶醉其中，回想著人間各地，
似乎也只有煙雨江南才能與此地相抗衡，風光景色，優美鳥啼，細雨
輕飄，如詩如畫，你幾乎已經忘了自己身處恐怖的邪靈界了。
往西邊望去，似乎有一座建築物在那，北邊兩旁均有沙丘圍繞著，在
沙丘的凹陷處，有一棟土堆堆成的半圓形住屋，你可以看到在其住屋
的頂部，有一個排氣孔，正不斷的冒著黑煙，你忍不住的抱怨起，在
如此的地方竟然會有人排放著嗚煙。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/mob02":2,
]));
	set("exits",([
"north":__DIR__"a-27",
"east":__DIR__"a-07",
"west":__DIR__"a-05",
]));
	setup();
}

 
