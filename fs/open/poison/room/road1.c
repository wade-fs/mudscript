#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "陰朁道");
  set ("long", @LONG
這裡是武林中最令人畏懼的一條道路「陰朁道」這條路往西通往冥
蠱魔教的總地「冥蠱魔殿」﹐在這裡要小心﹐四周的任何事物都可能已
經被人下了毒﹐如果隨意觸摸﹐性命難保。
LONG);

  set("light_up", 1);

  setup();
}
