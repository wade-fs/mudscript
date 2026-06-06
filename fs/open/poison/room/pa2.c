// Room: /u/r/ranko/room/pa1.c
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
這是一條彎彎曲曲的小路，路上石子不少，踩在腳底怪不舒服
的，不時還得注意地上以免被拌倒了，兩旁雜草叢生，似乎欠缺人
來打理。西邊通往農田，東邊則通往晒穀場。
 
LONG);
 
 
 
 

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"f1.c",
  "south" : __DIR__"pa1.c",
  "north" : __DIR__"pa3.c",
  "east" : __DIR__"pl1.c",
]));
  set("outdoors", "/open/poison");

  setup();
}
