// Room: /d/snow/hockshop.c

#include <room.h>

inherit HOCKSHOP;

void create ()
{
  set ("short", "[1;35m過去時空[0m 豐登當鋪");
  set ("long", @LONG
這是一家中等規模的當鋪﹐老舊的櫃臺上放著一張木牌(sign)﹐屋
裡的光線不是很亮﹐往東的出口被一塊藍色布簾遮著﹐上面有「非請莫
入」的字樣﹐西邊有一扇木雕門(door)通往大街。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mstreet3",
  "east" : __DIR__"hockshop2",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "west" : (: look_door,     "west" :),
  "sign" : "本當鋪財力雄厚﹐童叟無欺﹐歡迎惠顧﹐絕對保密。
客倌可以在這裡典當(pawn)、賣斷(sell)各種貨物﹐銅錢、銀兩、黃金、銀票
一概通用。
",
]));

  setup();
}
