// Room: /u/o/onion/room/bedroom.c

inherit ROOM;

void create()
{
	set("short", "僕人臥室");
	set("long", @LONG
這裡是鑣局內僕人生活起居的地方,裡面的擺設並不算太差,看起來和平民的住家類似,
這裡有幾個僕人正坐在椅子上聊天,聊的似乎很起勁的樣子,說的口沫橫飛...

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room4",
]));
        set("objects", (["/u/o/onion/npc/worker": 1, 
        		 "/u/o/onion/npc/footboy": 1 ]));
                      
	setup();
}
