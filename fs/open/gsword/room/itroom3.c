// Room: /u/s/smore/room/suking/suking9.c

inherit ROOM;
void create ()
{
  set ("short", "蜀中花園");
  set ("long", @LONG
這裡是蜀中大將軍心愛的花園,種滿了各地收集來的奇花異草,
只見處處馨香,團花僅簇,但卻有那麼一點點的奇異,就是這若大
的花園裡,竟不見蝶飛蜂舞,似忽有些密秘.
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword");
  set("exits", ([ /* sizeof() == 2 */
   "west":__DIR__"suking10",
   "south":__DIR__"itroom4.c",
  ]));
  setup();
}
