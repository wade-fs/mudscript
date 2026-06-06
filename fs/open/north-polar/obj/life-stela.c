//排版 與增加本物件是否存在的判斷 by blazakira 2011/9/2

inherit ITEM;
#include <ansi.h>
#include "/open/open.h"

void create()
{
  set_name("生靈之柱", ({"stela"}));
  set("long","由七海神柱供給無上能量，散發出莊嚴肅穆的神之氣息，你直覺意識到，任何嘗試破壞的行為都將招致天譴。\n");
  set("unit","根");
  set_weight(1000000);
  set("no_get",1);
  set("no_sac",1);
  setup();
}

void init()
{
  add_action("do_punch","punch");
  add_action("do_insert","insert");
}

int do_punch(string str)
{
  object me,ob,room,room2,mob,*ppl;
  int i,j;
  me = this_player();
  ob = this_object();
  room = environment(ob);
  ppl = all_inventory(environment(me));
  j = sizeof(ppl);
  if(!str || str != "stela") return notify_fail("你想擊打什麼東西!?\n");
  if(room->query_temp("punch-1") && room->query_temp("punch-2") && room->query_temp("punch-3") &&
     room->query_temp("punch-4") && room->query_temp("punch-5") && room->query_temp("punch-6") &&
     room->query_temp("punch-7"))
  {
    if(!room->query_temp("god-die"))
    {
      if(!(present("dragon-god")))
      {
        message_vision(HIW"$N逆天的一擊即將碰上神柱之際，海皇終於現身了，一揮手便將$N轟退數十丈之遠。\n"NOR,me);
        mob = new("open/north-polar/npc/dragon-god");
        mob->move(room);  
        for (i=0 ; i < j ; i++)
        {
          if(userp(ppl[i]))
            ppl[i]->start_busy(50);
        }
        call_out("speek",5,mob);
      } else {
        mob = present("dragon-god");
        message_vision(HIW"$n怒道"HIG"："HIC"「"HIY"$N本皇在此還容得你胡搞!?  $N給我去死吧!!"HIY"」\n"NOR,me,mob);
        mob->kill_ob(me);
      }
    } else {
      message_vision(HIR"$N以全身力量向"+ob->query("name")+""HIR"轟出一拳，"+ob->query("name")+""HIR"柱身上浮現水瓶般大小的空洞，似乎可放入(insert)東西。\n"NOR,me);
      tell_object(users(),HIM"\n從"+room->query("short")+""HIM"傳出陣陣隆隆聲響...\n\n"NOR);
      room->delete_temp("god-die");
      room->delete_temp("punch-1");
      room->delete_temp("punch-2");
      room->delete_temp("punch-3");
      room->delete_temp("punch-4");
      room->delete_temp("punch-5");
      room->delete_temp("punch-6");
      room->delete_temp("punch-7");
      room->set_temp("destructed",1);
    }
  } else {
    message_vision("$N試圖擊毀$n"NOR"，卻被強大的反震力轟飛老遠。\n",me,ob);
    me->unconcious();
    me->move("/open/north-polar/store");
  }
  return 1;
}

int do_insert(string str)
{
  object me,room,bottle,ob;
  me = this_player();
  room = environment(me);
  bottle = present("god-bottle",me);
  ob = this_object();
  if(!room->query_temp("destructed"))
  {
    return 0;
  }
  else
  {
    if(!str || str != "god-bottle") 
    {
      write("你想嵌入什麼東西在柱上呢!?\n");
      return 1;
    }
    if(!bottle->query("be_used"))
    {
      message_vision("$N將"+bottle->query("name")+""NOR"嵌入後，什麼事都沒發生，於是又取下。\n",me);
      return 1;
    } else {
      message_vision(HIW"$N將$n"HIW"穩穩的嵌進生靈之柱中，一道強光射向天海，暫時開啟了一條通路。\n"NOR,me,bottle);
      destruct(bottle);
      room->delete_temp("destructed");
      room->add("exits/up","/open/north-polar/old-temple");
      call_out("close",40,ob);
      call_out("succeed",5,me);
    }
  }
  return 1;
}

int close(object ob)
{
  message_vision(YEL"\n強光逐漸淡去，通路也隨著消失。\n"NOR,ob);
  environment(ob)->delete("exits/up");
  return 1;
}

int succeed()
{
  object me = this_player();
  tell_object(users(),HIW"\n大水退去，冰山再度凝結，"HIG""+me->query("name")+""HIW"不屈不撓挑戰神的勇氣終於擊潰了"HIR"龍神"HIW"，
 
 
    "HIY"海皇"HIW"與他的霸念，將再度於"HIY"海神殿"HIW"中沉睡千年了... \n\n"NOR);
  call_out("get_ring",5,me);
  return 1;
}

int get_ring()
{
  object me = this_player();
  if(!present("light-ring",me))  
  {
    message_vision(HIC"\n一枚湛藍潔淨的戒指落在$N手上。\n"NOR,me);
    new("/autoload/north-polar/light-ring")->move(me);
    write_file("/log/north-polar/get_ring",sprintf("%s(%s) 封印海皇得到淨水光之戒於 %s\n",me->name(1),me->query("id"),ctime(time())));
  } else {me->set("use_light_ring",0);}
  return 1;
}

int speek(object mob)
{
  if(!mob) return;
  message_vision(HIW"\n海皇冷冷的說道："HIR"『"HIG"一千年了，自神話時代以來，都沒有人膽敢向我挑釁。"HIR"』\n"NOR,mob);
  call_out("speek1",5,mob);
}

int speek1(object mob)
{
  if(!mob) return;
  message_vision(HIR"\n                『"HIG"年輕人勇於向強者挑戰是件好事。"HIR"』\n"NOR,mob);
  call_out("speek2",5,mob);
}

int speek2(object mob)
{
  if(!mob) return;
  message_vision(HIR"\n                『"HIG"但是過度的自信，將會變成毀滅自己的開始。"HIR"』\n"NOR,mob);
  call_out("speek3",5,mob);
}

int speek3(object mob)
{
  if(!mob) return;
  message_vision(HIR"\n                『"HIG"更不用提還想阻擋本皇清洗地上世界的目標。"HIR"』\n"NOR,mob);
  call_out("speek4",5,mob);
}

int speek4(object mob)
{
  if(!mob) return;
  message_vision(HIR"\n                『"HIG"來領死吧!!你們這些低賤的生物!!!!"HIR"』\n"NOR,mob);
  call_out("speek5",5,mob);
}

int speek5(object mob)
{
  object *ppl;
  int i,j;
  if(!mob) return;
  ppl = all_inventory(environment(mob));
  j = sizeof(ppl);
  mob->delete("no_kill");
  mob->delete("no_fight");
  mob->set("attitude","aggressive");
  for (i=0 ; i < j ; i++)
  {
    if(userp(ppl[i]) && !wizardp(ppl[i]) && living(ppl[i]) && ppl[i]->is_character() && !ppl[i]->is_corpse() && ppl[i] != mob)
      mob->kill_ob(ppl[i]);
    ppl[i]->delete_busy();
  }
  return 1;
}
