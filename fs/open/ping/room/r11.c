// Room: /u/m/moner/open/room/r11.c 
inherit ROOM;
void create ()
{
  set ("short", "大道盡頭");
	set( "build", 48 );
  set ("long", @LONG

   行至大道盡頭, 明亮的天色已被濃密的枝葉覆蓋住, 走在草地上,
不時發出窸窸窣窣的聲音, 環顧四方, 一個人影也沒有, 跟先前的明
亮舒適真有天壤之別, 你每走一步, 心臟就撲通撲通的跳, 好像四周
都是陷阱一般, 更加的小心翼翼, 風行山寨終於到了。。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r12.c",
  "enter" : __DIR__"r10.c",
]));
  set("outdoors", "wind");

  setup();
  replace_program(ROOM);
}
