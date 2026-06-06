// Room: /u/d/dhk/questsfan/rm3
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "山林"CYN"崎"NOR"路");
  set ("long", @LONG
你延著崎嶇的山路漸漸的往山上慢行，延途依舊薄霧漫
漫，而且越走四周風景越來珍奇，一些不常見甚至於沒見過
或連聽都沒聽過的動、植物一股腦兒的都栩栩如生的出現在
你的面前。

LONG);

  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"rm2",
  "eastup" : __DIR__"rm4",
]));

  setup();
}
