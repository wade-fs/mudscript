// Room: /open/gsword/room/gsword3-6.c
inherit ROOM;

void create ()
{
  set ("short", "後堂");
  set ("long", @LONG
這裡是仙劍派的後堂，堂上布置肅穆，兩壁懸著一柄柄長劍，劍鞘黝
黑，劍繐陳舊，料想是前幾代各宗師的佩劍。前方牆上掛著一張畫像，畫
中人物容貌俊雅，看來不過三十多歲，看他雙目遠視，氣定神閒，腰間一
把玉衡天劍，你不禁驚呼一聲，他不正是仙劍開山祖師 ─ 逍遙子。怎地
竟如此年輕。
 
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/gsword/room/g5-3.c",
  "northwest" : "/open/gsword/room/sproom.c",
]));

  set("light_up", 1);

  setup();
}
