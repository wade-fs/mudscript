inherit ROOM;

void create ()
{
  set ("short", "農家正廳");
	set( "build", 20 );
  set ("long", @LONG
這裡是農家的正廳 ,廳中坐著一位穿著簡樸的男人 ,看來他就是
這裡的主人吧 ..... ?不過看他那犀利的眼神 ,好像不是一般的
農人喔 ,真奇怪 ,這裡怎麼會有這種人ㄋ ?

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room31",
  "north" : __DIR__"room30",
  "west" : __DIR__"room28",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/long.c" : 1,
]));

  setup();
}
