// Room: /u/p/poloer/dragon/dr8
inherit ROOM;

void create ()
{
  set ("short", "郊外小路");
  set ("long", @LONG
  一條被野草覆蓋的小路，使你不得用手撥開草叢才能通
  行，並得小心亦亦的往前。前方似乎是個山谷似的，不過四
  周卻沒有任何生物，真是太奇怪了。

LONG);

  set("no_transmit", 2);
  set("outdoors", "/u/p");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dr9",
  "east" : __DIR__"dr7",
]));

  setup();
}
