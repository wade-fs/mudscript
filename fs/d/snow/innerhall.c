// Room: /d/snow/innerhall.c

inherit ROOM;

void create ()
{
  set ("short", "過去時空 武館內院");
  set ("long", @LONG
這裡是淳風武館的內院﹐平常武館弟子沒有館主的允許是不敢到這
裡來的﹐往東是柳家的祠堂﹐館主和家眷的臥房分別位於往北一條走道
的兩旁﹐廚房以及柴房、僕役的臥房都在往南的走道兩旁﹐往西則是天
井。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"inneryard",
]));

  setup();
}
