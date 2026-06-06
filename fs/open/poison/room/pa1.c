// Room: /u/r/ranko/room/pa1.c
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
這是一條彎彎曲曲的小路，路上石子不少，踩在腳底怪不舒服
的，不時還得注意地上以免被拌倒了，兩旁雜草叢生，似乎欠缺人
來打理。往北方走去可到農田及晒穀場，南方則回到村子中央。
 
LONG);
 
 

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"pa2.c",
  "south" : __DIR__"v3.c",
]));
  set("outdoors", "/open/poison");

  setup();
}
