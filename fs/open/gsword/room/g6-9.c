// Room: /open/gsword/room/g6-8.c
inherit ROOM;

void create ()
{
  set ("short", "後山小徑");
  set ("long", @LONG
一條順著峭壁邊緣延伸的小徑，寬僅數尺，南邊即為萬丈深谷，道路
往西方延伸，通往未知的區域！
 
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "牌子上寫著 :
擅闖仙劍禁地者 ~~~ 死 !
",
]));
  set("light_up", 1);
  set("outdoors", "/open/gsword/room");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"g6-10",
  "east" : __DIR__"g6-8.c",
]));

  setup();
}
