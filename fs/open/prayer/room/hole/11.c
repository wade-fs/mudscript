///open/prayer/room/hole/11.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	濃霧逐漸散去後, 你赫然發現地上有無數的蟲蟻在爬行!!角落有一
	團黑黑的物體....... 走近一看, 竟是一隻雙頭的響尾蛇!!它正露
	出貪婪的眼光, 直盯著你瞧......可惡的怪獸!!跟你拼了!!

LONG	);
    set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/ditail-snake" : 1,		//雙頭響尾蛇
]));
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"13",
  "south" : __DIR__"2",
  "west" : __DIR__"6",
  "north":__DIR__"9",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
