// Room: /u/d/devils/school8.c

inherit ROOM;

void create ()
{
        set("valid_startroom", 1);
  set ("short", "正晴武館");
  set ("long", @LONG
這是正晴武館大廳，挑高四米二，雕樑畫棟，裝飾華麗，五張太師椅
位於上首，居中的太師椅坐著一位威嚴的老者，正以銳利的目光盯著你，
他便是館主－－任正晴...
LONG);

  set("exits", ([ /* sizeof() == 5 */
  "south" : "/open/wu/room/school11",
  "north" : "/open/wu/room/school10",
  "west" : "/open/wu/room/school7",
  "eastup" : "/open/wu/room/school15",
  "east" : "/open/wu/room/school9",
]));

        set("objects",([
          "/daemon/class/fighter/master_jen":1,
        ]));
  set("light_up", 1);
        set("no_clean_up", 0);
  setup();
  call_other("obj/board/lungshan_b.c","???");
}
int valid_leave(object me, string dir)
{
        if(me->query("class")!="fighter"&&dir=="south")
return notify_fail("不是武者不准進!\n");
return ::valid_leave(me,dir);
}
void init()
{
  add_action("do_pass","pass");
}
int do_pass()
{
  object me;
  me = this_player();
  me->move("/open/center/room/inn");
  return 1;
}
