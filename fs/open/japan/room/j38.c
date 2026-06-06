inherit ROOM;

void create()
{
  set ("short", "民房");
  set ("long", @LONG
殘破的木製房屋，屋內相當零亂。每一件物品物品似乎都遭受到
破壞，連一件完整的物品都沒有。房間角落似乎龜縮著一個人影。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"j30.c",
  ]));
  setup();
}
