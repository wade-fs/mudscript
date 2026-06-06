// Room: /u/m/moner/open/room/r6.c 
inherit ROOM;
 
void create ()
{
  set ("short", "大廳");
	set( "build", 56 );
  set ("long", @LONG
    這裡是二頭目劉信的大廳, 放眼望去, 一片銀白色, 所有的擺設都是
純銀製品。現在劉信是風行山寨內的二當家, 所有的事情雷霸幾乎都放手
給劉信去做, 劉信看你闖進來, 對你邪惡的笑著, 他不似張繼那麼衝動 ,
但是看似有很深的心機, 讓你摸不透, 你不禁打了個冷顫。


LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r5.c",
]));
set("objects",([
"/open/ping/npc/5.c":1,
]));

  setup();
  replace_program(ROOM);
}
