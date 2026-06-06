inherit ROOM;
void create()
{
	set("short", "林間小路");
	set("long", @LONG
你現在正走在一條林間的小路上，小路兩旁長滿了高聳的松樹，從
林間傳來陣陣鳥叫聲，小路往東西兩個方向延伸出去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/tendo/room/tower/make2",
  "west" : "/open/tendo/room/tower/make4",
]));
     set("outdoors",1);
	setup();
}
