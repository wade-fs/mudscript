///open/prayer/room/hole/12.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	四周牆壁坑坑洞洞，還有一些生鏽的兵刃插在上面，顯然這裡曾經
	有過激烈的打鬥．地上全是一沱一沱的的糞便，紅紅綠綠怪恐怖的
	，天啊!!難道這些怪物有毒??唉喲!!那你豈不是已經中毒了??

LONG	);
 
    set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/ditail-snake2" : 1,		//雙頭響尾蛇
]));

	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"5",
  "south" : __DIR__"9",
  "west":__DIR__"10",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
