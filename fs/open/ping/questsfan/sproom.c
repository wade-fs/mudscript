// Room: /u/d/dhk/questsfan/sproom
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "尊天洞天");
  set ("long", @LONG

  『 兩 眼 看 世 間 ， 人 心 似 冰 寒 ，

     白 往 今 生 路 ， 王 者 恨 中 嘆 。 』

望眼所及周圍只有簡單的起居用品，而於此洞正中央
處有一位氣宇軒昂、風度超凡的聖者正在打坐吸納天
地之氣。
LONG);

  set("no_magic", 1);
  set("objects", ([ /* sizeof() == 2 */
  "/u/d/dhk/obj/good.c" : 1,
  __DIR__"npc/sky.c" : 1,
]));
  set("light_up", 1);
  set("no_fight", 1);

  setup();
}
