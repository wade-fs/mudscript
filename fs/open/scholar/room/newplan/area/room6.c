// Room: /u/s/sueplan/newplan/area/room6
inherit ROOM;

void create ()
{
  set ("short", "廉貞星");
  set ("long", @LONG
假如紂王的周圍全都是盡忠愛國的志士，可能也不會導致殷潮的滅
亡。也可以說，是許多奸臣助長他害人害己的。其中有一個叫費仲的大
奸臣，誣害了不少朝內的許多忠臣賢士，奉承紂王，專橫權勢。
    殷朝滅亡後，費仲被姜尚所捕。姜尚非常厭惡這種非人的畜生，於
是下斬首費仲。太白金星知道天界的神不足，即召費仲的靈魂去住廉貞
星，封為邪惡之神，專管『歪曲』。這等於基督叫中的所謂『魔鬼』。 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/scholar_yea.c" : 1,
]));
  set("light_up", 1);
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room7.c",
  "south" : __DIR__"room5.c",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if(dir=="enter"&&present("scholar",environment(me)))
  {
  return notify_fail("你發覺有人擋在你面, 不讓你過!!!\n");
  }
  return 1;
}
