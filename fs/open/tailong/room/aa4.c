// Room: /u/o/ookami/newarea/aa4 
inherit ROOM;
 
void create ()
{
  set ("short", "點蒼山腰");
  set ("long", @LONG
當你走到這裡,你看到前方有一棟金碧輝煌的建築物,好像是一座佛
寺,但是遠遠看去又好像是一座宮殿,令人嘆為觀止,仔細想想,這應該就
是有名的天龍寺了吧
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"aa3.c",
  "north" : __DIR__"aa5.c",
]));
  set("outdoors", "/u/o/ookami/newarea");

  setup();
  replace_program(ROOM);
}
