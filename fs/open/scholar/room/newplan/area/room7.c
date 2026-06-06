// Room: /u/s/sueplan/newplan/area/room7
inherit ROOM;

void create ()
{
  set ("short", "天府星");
  set ("long", @LONG
紂王還沒娶妲己為第二夫人以前，有個正式的姜皇后。姜皇后一位
賢慧的婦人，具有才能，協助夫君治好殷朝一時。不過，自從妲己奉九
天玄女之命混進宮中後，紂王的寵愛自然傾向妲己一人身上。姜皇后也
無形中失去權力，後來又受了妲己嫉妒心而慘遭殺害。            
    姜皇后的家鄉，物產豐富。當她任皇后以後，她除慈悲待人外，還
貢獻自己優越的才能和地方豐富的物產。因此，姜皇后死後，她靈魂被
召去永駐天府星，掌管『才能』、『物產』、『慈悲』。  

LONG);

  set("no_transmit", 1);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"room6.c",
  "north" : __DIR__"room8.c",
]));

  setup();
}
