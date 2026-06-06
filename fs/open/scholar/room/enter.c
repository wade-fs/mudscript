// Room: /u/j/judd/room/enter_room.c
inherit ROOM;

void create ()
{
  set ("short", "儒門入口");
  set ("long", @LONG
前方有一棟看起來相當特別的建築，想必就是儒門了，然而
卻看不到任何的入口，只有一枝巨型石筆立在眼前，上面寫著”
七孔鳳凰筆(pen)”，地上還有各式奇怪的圖案，不知道有什麼意
義。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"newplan/area/groom1.c",
  "north" : "/open/start/room/r3.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "pen" : "你仔細的瞧了瞧，發現這支筆有被轉動(turn)過的痕跡。
",
]));
  set("outdoors", "/open/start");

  setup();
}
void init()
{
  add_action("do_turn", "turn");
}
int do_turn(string str)
{
  object who;
  who = this_player();

       tell_object(who,"\n你小心翼翼的轉動七彩鳳凰筆。\n\n");

tell_object(who,"咻的一聲，你整個人不知不覺的被一股吸力給吸進去了。\n\n");
        who->move(__DIR__"r24");
        foreach(object npc in all_inventory(this_object()) )
        {
          if(userp(npc)) continue;
          if(npc->query_leader() == who) npc->move(__DIR__"r24");
        }

tell_room(this_object(),"你只聽到"+who->query("name")+"驚叫一聲，已經看不到他的身影了。\n");
        return 1;
}

