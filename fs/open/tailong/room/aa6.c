// Room: /u/o/ookami/newarea/aa6.c 
inherit ROOM;
 
void create ()
{
  set ("short", "中央走道");
  set ("long", @LONG
走進天龍寺的內部,放眼望去,四周有著裝飾地美輪美奐的各式建築
,簡直不輸給皇宮大內,不過這也難怪,段氏每年都會出資修築,而經過這
些年的修建,天龍寺可說是全國數一數二的大寺院,只不過位在大理的山
上,又是段家先輩皈依之地,因此名號並不響亮
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"aa5",
  "west" : __DIR__"aa7",
  "east" : __DIR__"aa8",
]));

set("objects", ([ /* sizeof() == 1 */
"/open/tailong/npc/monk2.c":1,
]));
  setup();
  replace_program(ROOM);
}
