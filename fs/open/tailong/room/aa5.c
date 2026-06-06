// Room: /u/o/ookami/newarea/aa5.c 
inherit ROOM;
 
void create ()
{
  set ("short", "大門");
  set ("long", @LONG
走到這裡,前方就是剛才所見的大寺廟了,抬頭一望,只見大門的上
方寫的是崇聖寺三個大字,不禁滿腹疑問,這裡不是天龍寺嗎?前面有一
個小僧,去問問他好了
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"aa6",
  "south" : __DIR__"aa4.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/tailong/npc/monk1.c":1,
]));
  set("outdoors", "/u/o/ookami/newarea");

  setup();
  replace_program(ROOM);
}
