//written by acelan...../u/a/acelan/room/wood1.c

inherit ROOM;

void create ()
{
  set ("short", "殺手後山");
  set ("long", @LONG
這裡是殺手總壇的後山, 群樹參天, 遮住了大部分的陽光, 陰暗
的光線中, 你並沒有看到任何人, 可是卻彷彿有一股濃濃的殺意正迎
面向你撲來, 你開始懷疑是否要繼續前進。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/killer/room/outr11",
  "north" : __DIR__"wood3.c",
]));

  setup();
}
