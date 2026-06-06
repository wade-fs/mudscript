// Room: /open/gsword/room/gsword6-1.c
inherit ROOM;

void create ()
{
  set ("short", "大花圃");
	set( "build", 300 );
  set ("long", @LONG
這是一個大花圃 ,花圃中盡是深紅和粉紅的玫瑰 ,爭芳競豔 ,嬌麗無儔 .
春風和栩 ,但覺滿鼻芳香 ,幾支蝴蝶穿梭其中 ,蝶舞花開 ,真是人間一大美
景 .

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/npc/bee" : 2,
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/gsword/room/g4-8.c",
  "south" : "/open/gsword/room/g4-16.c",
  "east" : "/open/gsword/room/g4-12.c",
]));
  set("clean_up",0);
   set("objects",([
  "/open/gsword/npc/swordman-1.c" : 1,
 "/open/gsword/npc/swordman-2.c" : 1,
 "/open/gsword/npc/swordman-3.c" : 1,
  ]));
  setup();
}
