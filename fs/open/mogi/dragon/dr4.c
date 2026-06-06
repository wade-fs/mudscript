// Room: /u/p/poloer/dragon/dr4
inherit ROOM;

void create ()
{
  set ("short", "亂葬崗");
  set ("long", @LONG
  這裡是村外的郊區，四周人煙稀少，只有一大片的墳墓
  一不小心還會踩到屍骨，莫非這裡是人常說的亂葬崗，不時
  還有鬼火出現，在身旁繞啊繞，恐怖極了。
  西邊有條小路，不過被野草覆蓋，看不出通往那裡。

LONG);

  set("no_transmit", 2);
  set("outdoors", "/u/p");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dr5",
  "north" : __DIR__"dr3",
]));

  setup();
}
