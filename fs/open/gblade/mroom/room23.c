// Room: /u/m/moner/room/room23.c
inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG

這是平時廚子們做菜的地方，在右邊的一角放著小山一般高的蔬菜，
廚子在賣力的燒著菜，手中的菜刀盤旋飛舞，看來刀法不會必你差多
少，陣陣的白煙從鐵鍋中冒出，絲絲的香氣傳入你的鼻中，你忍不住
流了滿地的口水。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room10.c",
]));
  set("light_up", 1);

  setup();
}
