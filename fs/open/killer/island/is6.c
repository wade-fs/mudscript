// Room: /u/u/unfinished/room/is6.c
inherit ROOM;

void create ()
{
  set ("short", "斜坡");
  set ("long", @LONG
一條南北向的斜坡, 西邊洶湧的海水不斷的拍打著岩壁. 此地有許多樹木,
東方即是茂盛的樹林. 便地的碎石子讓你感到移動不便. 在你的北方是一大片樹
林, 看起來若要往北行就不得不穿過這片陰暗的樹林, 最好備妥照明用具, 以免
在陰暗的樹林中迷失.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"is1",
  "north" : __DIR__"is10.c",
]));
  set("outdoors", "/u/u");

  setup();
}
