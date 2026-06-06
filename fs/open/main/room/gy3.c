// Room: /open/main/room/gy3.c
inherit ROOM;

void create ()
{
  set ("short", "帳篷");
  set ("long", @LONG
你一踏進來，哇哩咧！這麼嘟好，隨便走居然碰到大尾的肥魚
臨陣退縮雖然可以留下一條小命，不過敵前逃亡不免會受國人恥笑
而且還給所有同胞蒙羞，為了拯救疾苦百姓，必須做個決擇。

LONG);

  set("objects", ([ /* sizeof() == 1 */
 //  "/open/main/npc/general.c" : 1,
]));
  set("outdoors", "/open/main");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"gy2.c",
]));

  setup();
}
