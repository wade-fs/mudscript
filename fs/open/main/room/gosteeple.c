inherit ROOM;
void create ()
{
set ("short", "濃霧");
  set ("long", @LONG
霧氣慢慢的加重了,你的四周彷彿都被霧氣所淹沒了,
在視線不佳的情形下,你依稀可以看到東邊似乎有一座
高塔...
LONG);
set("exits",([
"west":__DIR__"s22",
"east":"/open/steeple/steeple",
]));
  setup();
}
