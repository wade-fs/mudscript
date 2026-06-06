// Room: /u/p/poloer/dragon/g1
inherit ROOM;

void create ()
{
  set ("short", "魔王殿");
  set ("long", @LONG
一間看來很雄偉的建築物，但不知為什麼房屋四周竟然都沒有半
點生物，看起來非常悽涼，烏鴉在上空飛著並且不時發出丫～ㄚ的聲
音，聽起來讓人毛骨聳然。仔細觀察這間房屋，發覺這竟然是用人的
骨頭所搭建而成的，朱紅色的大門頂上有幅用血寫的牌扁，上面寫著
「魔王殿」 。

LONG);

  set("outdoors", "/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"c9",
  "enter" : __DIR__"g2",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
