///open/prayer/room/hole/15.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	這裡比剛剛走過的通道狹岝，牆上全是魔獸黏黏的唾液，也不知道
	有沒有毒??處處充滿危機，在這狹岝的地方也沒辦法施展武功，還
	是趕快離開這個鬼地方吧!!身上的藥草也快要用完了....希望上天
	保祐能讓你平安離開此地!!

LONG	);
    set("objects", ([ /* sizeof() == 2 */
   "/open/prayer/npc/emery-giant" : 1,		
   "/open/prayer/npc/bird" : 1,		
]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"4",
  "east" : __DIR__"14",
  "west":__DIR__"13",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
