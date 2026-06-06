// Room: /u/f/funkcat/room/house2h.c

inherit ROOM;
			
void create ()
{
  set ("short", "和房");
  set ("long", @LONG
鋪滿榻榻米的房間，門是糊滿白紙的和式門，房間之中有個小矮桌
對面的牆上掛了大大的忍字。旁邊的矮櫃上還擱著一副扶桑將軍的戰甲
及兩把武士刀。奇怪，京城裡怎麼聚集了一大群扶桑人，難道是要密謀
造反!?

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"j4",
]));
// set("objects", ([ /* sizeof() == 1 */
// "/open/capital/npc/black.c" : 1,
//]));

  setup();
}
int valid_leave(object me,string dir)
{
  int i;
  i=me->query("japanese");
  if ((i=0) && ( dir=="south") && (present("jushirou",environment(me))))
  return notify_fail("天楓十四郎擋住你的去路說:想走?沒那麼簡單!\n");
  return ::valid_leave(me,dir);
}
							

