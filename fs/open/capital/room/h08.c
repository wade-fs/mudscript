// Room: /open/capital/room/h08.c

inherit ROOM;

void create ()
{
  set ("short", "扁鵲胡同");
	set( "build", 24 );
  set ("long", @LONG
一代神醫扁鵲曾在此地懸壺，故後人為紀念他的善行，便將此胡同
取名為扁鵲。當時扁鵲在此曾收了許多的弟子，後經代代相傳，弟子日
漸眾多，便在此成立了銀針門，為醫界之大宗, 許多的醫者都是在此地
接受基礎醫術的訓練, 東面那間房舍就是銀針門。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"h06",
  "east" : __DIR__"CUR",
]));
  set("outdoors", "/open/capital");

  setup();
}
