// Room: /open/gsword/room/gsword1-1.c
inherit ROOM;

void create ()
{
  set ("short", "小徑");
  set ("long", @LONG
這是一條通往藏經閣的小徑，小徑上長滿了青苔，似乎甚少人通行，
兩旁巨木參天，走在其中，但覺神清氣爽，高山上的空氣真是新鮮。傳說
仙劍派的藏經閣收藏了全天下最齊全的武林秘籍，不過卻是甚難進入。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/g5-13.c",
  "east" : "/open/gsword/room/g5-15.c",
]));

  setup();
}
