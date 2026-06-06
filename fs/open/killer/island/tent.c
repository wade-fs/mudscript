inherit ROOM;
#include <ansi.h>
string out();
void create ()
{
set("short", "臨時帳棚");
  set ("long", @LONG
這裡面堆滿了許多的食物跟水，但有些食物已經被海水給
浸濕了，大多不能食用，除了食物外，這帳棚還堆積著不少物
品，或許裡面藏有稀世罕見的奇珍異寶也說不定。

LONG);
  set("light_up", 1);
  setup();
}
