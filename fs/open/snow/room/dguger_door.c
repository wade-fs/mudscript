/*****************************************************************************
By Kalin (2003-06-17)
*****************************************************************************/
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short","諸葛草蘆前院");
  set ("long", @LONG
這裡是神算先生諸葛臥龍住處的前院，神算先
生應該就住在裡面吧？門前有位小童正若有所思的
望著天空。
LONG);

  set("exits", ([ /* sizeof() == 3 */
]));

  set("objects",([
        "/daemon/class/scholar/boy" : 1,
        ]));
  set("light_up", 1);
  set("no_transmit", 1);
  setup();
}

void init()
{ 
  object ob;
  ob  = this_player();
  add_action("do_shout", "shout");
}

int do_shout(string str)
{
  if(!this_player()->query_temp("scholar_godplan_gi_dguger_letter"))
  { //理論上用不到此判斷 因為在路觀圖上已有判斷 但是原設計者應是避免有作弊手段抵達此地 by blazakira 註解 2010/10/10
    message("system",HIR + "\n儒門九代令公之首「" + HIY + "聖賢書" + HIR + "」" + HIC + "舉起拳頭砸中" + HIW + ""+this_player()->name()+"" + HIC + "的腦袋，吼道：你在那鬼叫什麼？！\n" + NOR,users());
    return 0;
  }
  if(str != "神算先生在嗎?")
    return 0;
  if(random(3)>0)
    return 0;
  message_vision("草蘆的大門緩緩的打開了。\n",this_player()); 
  set("exits/enter","/open/snow/room/dguger_room");
  call_out("do_close",15);
}

void do_close()
{
  if(!query("exits/enter"))
    return;
  delete("exits/enter");
  tell_room(this_object(),HIC + "(大門碰一聲的關了。)\n" + NOR);
}
