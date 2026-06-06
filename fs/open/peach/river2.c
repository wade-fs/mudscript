// Room: /u/w/whatup/peach/river2
inherit ROOM;

void create ()
{
  set ("short", "迷霧小溪");
  set ("long", @LONG
一條小溪，水並不深，但是在大霧之中仍然讓你提心吊膽，兩旁
高大且濃密的樹木，像是張牙舞爪的妖怪，一步步的向你逼近，越往
前行走，越是讓人感到害怕，漸漸的迷失方向感及時間感，彷彿你不
存在於這個世界上一樣。
LONG);

  set("outdoors", "/u/b");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"river1.c",
  "east" : __DIR__"river3.c",
]));

  setup();
}
