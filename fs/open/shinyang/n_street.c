// Room: /open/shinyang/n_street.c
inherit ROOM;

void create ()
{
  set ("short", "北出口城門");
  set ("long", @LONG
由這裡進入襄陽城，前面站著數位衛兵，正在作嚴密的檢查，防止蒙古
大軍的入侵。
LONG);

  set("outdoors", "/open/shinyang");

  setup();
}
