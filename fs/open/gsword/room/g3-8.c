// Room: /open/gsword/room/g3-7.c
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
一條小走廊 ,連往仙劍派弟子們的寢居 ,在仙劍派中 ,除了掌門人及輩份
較高的仙劍七俠能擁有自己的寢居 ,其它弟子 ,只能一起睡通鋪囉 !

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/gsword/room/g3-9.c",
  "south" : "/open/gsword/room/g3-10.c",
  "east" : "/open/gsword/room/g3-7.c",
]));

  set("light_up", 1);

  setup();
}
