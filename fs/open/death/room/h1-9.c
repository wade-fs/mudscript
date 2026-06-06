// Room: /open/death/room/h1-9    edit by Pokai
inherit ROOM;

void create ()
{
  set ("short", "第一殿--通道");
  set ("long", @LONG
你看到前方不遠處有座城門，門上一個石匾刻著：『往第二殿』四
個大字；你發現城門下的守備格外地森嚴，守衛們對來往的孤魂野鬼都
會詳加調查，對稍微可疑的鬼魂都不會放行。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"h1-5",
  "south" : __DIR__"h1-10",
]));
  set("light_up", 1);

  setup();
}
