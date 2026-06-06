inherit ROOM;

void create ()
{
  set ("short", "農家前院");
  set ("long", @LONG
這裡是一戶農家的院子 ,有幾隻雞在廣場上悠閒的跺著步子 ,時
而昂首闊步 ,時而低頭啄食 ,好一幅美麗的農家情景啊 .

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room25",
  "east" : __DIR__"room29",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/start/npc/hen.c" : 2,
]));

  setup();
}
