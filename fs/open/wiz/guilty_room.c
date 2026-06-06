// Room: /u/b/bss/guilty_room
inherit ROOM;

void create ()
{
  set ("short", "狂想天牢");
  set ("long", @LONG
這是一間四週以鐵欄竿圍起來的監牢, 裡面住的都是一些窮兇
惡極的罪犯, 看來都是因為違反了player_rules或是利用bugs被關
進來的, 以前的巫師會二話不說的那些犯罪的人purge,但是難免有
玩家會覺得被冤, 想要上訴, 所以作了這麼一間房間, 最主要是讓
玩家有上訴的管道
這間房間照理說是沒辦法出去才對,如果誰先找到方法出去的話,我就會將他減刑
要上訴的人請post
LONG);

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
]));
  set("no_magic", 1);
  set("light_up", 1);

  set("valid_startroom",1);
  set("no_transmit",1);
  set("guilty_room",1);
  set("no_chome", 1);
  set("no_scale", 1);
  setup();
  call_other("/obj/board/guilty_b","???");
}
