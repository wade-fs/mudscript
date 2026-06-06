// Room: /open/grassland/camp01
inherit ROOM;

void create ()
{
  set ("short", "帳棚");
  set ("long", @LONG
踏進這個帳棚，神秘的光芒映入眼簾，前方中間的空地上一個人正
專心的將謎一般的物質做加工，四周瀰漫著怪異的味道，可是地上擺放
的物品卻讓你驚奇萬分，都是一些神兵利器，有如大拍賣一樣丟在四周。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"r11",
]));
  set("no_transmit", 1);
  set("no_scale",1);

  setup();
}
