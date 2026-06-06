inherit ITEM;
#include <ansi.h>
#include "/open/open.h"

void create()
{
  set_name("太平洋神柱", ({"stela"}));
  set("long","調節太平洋海域水量的古老神柱，據說擁有自我修復的奇妙能力，若是想強行破壞(punch)的話...。\n");
  set("unit","根");
  set_weight(1000000);
  set("no_get",1);
  set("no_sac",1);

  setup();
}

void init()
{
         add_action("do_punch","punch");
}

int do_punch(string str)
{
  object me,ob,room,room2,mob;
  me = this_player();
  ob = this_object();
  room = environment(ob);
  if(!room->query_temp("can_punch"))
  {
   if(!(present("sea dragon")))
   {
    message_vision(HIY + "正當$N將要下手之際，守護"+room->query("short")+"" + HIY + "的太平洋海神出現制止了$N的動作。\n" + NOR,me);
    mob = new("open/north-polar/npc/sea-dragon");
    mob->move(room);  
    mob->kill_ob(me);
   }else{
    mob = present("sea dragon");
    message_vision(HIW + "$n冷笑道" + HIG + "：" + HIY + "「$N你是沒看到我在這裡嗎!?" + HIY + "」\n" + NOR,me,mob);
    mob->kill_ob(me);
        }
   return 1;
  }
  if(!str || str != "stela")  return notify_fail("你想擊打什麼東西!?\n");
  message_vision(HIR + "$N以全身力量向"+ob->query("name")+"" + HIR + "轟出一拳，在"+ob->query("name")+"" + HIR + "柱身上造成了短時間難以回復的傷害。\n" + NOR,me);
  tell_object(users(),HIR + "\n從"+room->query("short")+"" + HIR + "傳出陣陣隆隆聲響...\n\n" + NOR);
  room->delete_temp("can_punch");
  ob->move("/open/north-polar/main");
  room2 = environment(ob);
  room2->set_temp("punch-4",1);
  destruct(ob);
  return 1;
}
