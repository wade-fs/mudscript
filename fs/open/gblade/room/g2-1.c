inherit ROOM;
void create ()
{
  set ("short", "長廊");
	set( "build", 19 );
  set ("long", @LONG

角落掛著水晶玻璃各色風燈，精緻非常。你想像到了晚上，所有的燈都點
起來，那銀光雪浪的光景；心裡不禁暗暗嘆到：『太奢華浪費了。』
長廊一邊是通往王宅的內院，一邊是通往王宅招待外賓的廂房。


LONG);

   set("light_up", 1);
   set("exits", ([ /* sizeof() == 2 */
   "north" :__DIR__"g2-2.c",
   "south" :__DIR__"g1-6.c",
]));

  setup();
}


