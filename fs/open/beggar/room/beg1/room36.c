// Room: /u/g/guetenr/beggar/room/beg1/room36.c
inherit ROOM;

void create ()
{
  set ("short", "水田");
  set ("long", @LONG
沿著田埂走過來，幾隻在水田自在飛翔棲息的白鷺鷥，恣意地踏著腳步
悠遊著，渾然不察你的到來；在早春淡藍的天色裏，襯著淺淺斑斑綠意的秧
田，鷺鷥潔白的身影翩然來去其間，構成一幅天然的好景致，令你讚嘆不已
，巴不得脅下立生雙翼，與之偕遊天宇雲影共徘徊；水田向四方漫去。你在
不遠處看到一個小山寨，不過卻不知如何循徑而入。眼前有一條小河，您要
不要泛舟西進呢??(board boat)
LONG);

  set("outdoors", "/open/");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room34.c",
]));

  setup();
}

void init()
{
add_action("do_board","board");
}

int do_board(string str)
{
object me;
me=this_player();
if(str!="boat")
return notify_fail("你要幹麻?無聊喔??\n");
write("你慢慢的划著小舟!!\n");
  me->move("open/beggar/room/beg2/clr1.c");
  return 1;
}

