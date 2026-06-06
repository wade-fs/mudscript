// Room: /open/gsword/room/gsword6-1.c
inherit ROOM;

void create ()
{
  set ("short", "大花圃");
	set( "build", 12 );
  set ("long", @LONG
這是一個大花圃 ,花圃中盡是深紅和粉紅的玫瑰 ,爭芳競豔 ,嬌麗無儔 .
春風和栩 ,但覺滿鼻芳香 ,幾支蝴蝶穿梭其中 ,蝶舞花開 ,真是人間一大美
景 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/gsword/room/g4-13.c",
]));

  setup();
}
