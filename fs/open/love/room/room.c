inherit ROOM;

void create ()
{
  set ("short", "關卡");
  set ("long", @LONG
你走到了這裡，已經算是到了世界的盡頭，你遠遠的看見遠方好像
有一座華麗的城堡,但是誰都看得出來這是一座殺戮之城,你想要
進城，你最好先秤秤自已的斤兩，因為這有四位武藝不凡的勇士
守在這，如果你不想死的話就請趕快離開。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/main/room/d3.c",
  "enter" : __DIR__"room1",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/love/npc/guard" : 4,
]));

  setup();
}
int valid_leave(object me, string dir)
 {
   object guard = present("door guard",environment(me));
   if(dir=="enter"&& guard)
   {
    if(!me->query_temp("allow-enter"))
    return notify_fail("關卡守衛攔住你，說道:你以為絕情門是隨便就進的去嗎?
先過我這關吧!!\n");
   }
  return 1;
 }

