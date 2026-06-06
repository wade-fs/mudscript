// Room: /d/snow/eroad3.c

inherit ROOM;

void create ()
{
  set ("short", "過去時空 山路");
  set ("long", @LONG
這是一條說寬不寬﹐說窄倒也不窄的山路﹐路面用幾塊生滿青苔的
大石鋪成﹐西面是一段坡地﹐從這裡可以望見西邊有幾間房屋錯落在林
木間﹐東面則是山壁﹐山路往西南銜接一條黃土小徑。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"eroad2",
]));
  set("outdoors", "snow");

  setup();
}
