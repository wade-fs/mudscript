//增加死亡時 玩家已不存在時的判斷 與昏迷時不予攻擊的判斷 by blazakira 2011/3/19
//更改message_vision()的表示為tell_room() 與補上receive_wound的攻擊方參數 by blazakira 2011/9/12

inherit NPC;
#include "/open/open.h"
#include <ansi.h>
string do_special_fight();

void create()
{
  set_name("金極飄", ({ "golden king","golden","king" }) );
  set("long","金靈塔的鎮塔之王，能力比小金妖和金靈獸不知強上幾倍。\n");
  set("title",HIY + "(金色靈氣)" + NOR + "金靈塔王" + NOR);
  set("gender","男性");
  set("age", 60);
  set("max_gin", 80000);
  set("max_kee", 80000);
  set("max_sen", 80000);
  set("max_force", 20000);
  set("force",200000);
  set("max_atman",50000);
  set("max_mana",50000);
  set("atman",50000);
  set("mana",50000);
  set("force_factor",20);
  set("attitude","aggressive");
  set("str", 35);
  set("cor", 35);
  set("spi", 35);
  set("int", 35);
  set_temp("apply/armor", 150);
  set_temp("apply/defense", 250);
  set("class","blademan");
  set("env/連擊","YES");
  set("bellicosity",10000);
  set("functions/gold-dest/level",100);
  set("functions/fast-dest/level",100);
  set_skill("blade",150);
  set_skill("fast-blade",150);
  set_skill("gold-blade",150);
  set_skill("nine-steps",150);
  set_skill("move",150);
  set_skill("dodge",150);
  set_skill("parry",150);
  set_skill("force",150);
  set_skill("sixforce",150);
  map_skill("dodge","nine-steps");
  map_skill("move","nine-steps");
  map_skill("parry","gold-blade");
  map_skill("blade","fast-blade");
  map_skill("force","sixforce");

  set("combat_exp", 8000000);
  set("gold-monster",1);
  set("chat_chance_combat",50);
  set("chat_msg_combat",({   (: do_special_fight :)   }) );
  setup();
  set("family/family_name","金刀門");
  add_money("cash",3);
  carry_object("/open/magic-manor/gold/obj/golden-blade")->wield();
}

void heart_beat()
{
  object mob,me,obj;
  mixed enemy;
  int i,j=0,k=random(3);
  mob = this_object();
  me = this_player();
  if(!mob||!environment(mob)) return;
  enemy = all_inventory( environment(mob) );
  i = sizeof(enemy);

  if( !mob->is_fighting() || mob->is_fighting() && !query_temp("unconcious") )
  {
    for (j=0 ; j < i ; j++)
    {
      if( !enemy[j] ) continue;
      {
        if(!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
           && living(enemy[j]) && !enemy[j]->query("gold-monster") )
          mob->kill_ob(enemy[j]);
      }
    }
  }

  if(random(10) > 6 && mob->is_fighting() )
  {
    tell_room(mob,HIM + "\n夕陽殘照，暮色泛起，餘暉映照於大地，$N感受如此無限晚意輕輕帶出

      " + HIW + "----===≡◎ 金封大地式 ◎≡===----
     " + NOR+YEL + "  『" + HIY + "金靈蛇動．殘陽墜" + NOR+YEL + "』\n\n" + NOR);
    for (j=0 ; j < i ; j++)
    {
      if( !enemy[j] ) continue;
      {
        if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
            && !enemy[j]->query("gold-monster") )
        {
          if( !enemy[j]->query_temp("magic-manor/fire-shield") )
          {
            message_vision(HIY + "$N" + HIY + "只感一陣頭痛欲裂，震耳欲聾，七孔流出絲絲血跡!!\n" + NOR,(enemy[j]));
            enemy[j]->receive_wound("kee",600,mob);
            enemy[j]->start_busy(2);
            COMBAT_D->report_status(enemy[j],1);
          } else {
            message_vision(HIR + "$N" + HIR + "身上的火靈之氣緩和了部份的招式衝擊!!\n" + NOR,(enemy[j]));
            enemy[j]->receive_wound("kee",300,mob);
            enemy[j]->start_busy(k);
            COMBAT_D->report_status(enemy[j],1);
          }
        }
      }
    }
  }
  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  object me=query_temp("last_damage_from");
  int j;
  if( me && userp(me) && me->query_temp("not_robot") > time() )
  {
    if ( me->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj12/guava-doll")->move(environment(me));
        message_vision(HIM + "\n從金極飄的身上掉下了一件奇怪的東西!!\n" + NOR,me,me);
        write_file("/log/sky/obj12/guava_doll",sprintf("%s(%s) 讓金極飄掉下了芭樂娃娃於 %s\n",
          me->name(1),me->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
      {
        new("/open/sky/obj12/guava-doll")->move(environment(me));
        message_vision(HIM + "\n從金極飄的身上掉下了一件奇怪的東西!!\n" + NOR,me,me);
        write_file("/log/sky/obj12/guava_doll",sprintf("%s(%s) 讓金極飄掉下了芭樂娃娃於 %s\n",
          me->name(1),me->query("id"),ctime(time())));
      }
    }
  }
  if( me ) {
    if( !me->query_temp("magic-manor/goldmagic") )
    {
      message_vision(HIY + "金極飄死後的靈魂忽然化為一道金色靈光，灌入了$N" + HIY + "的身體之中!!\n" + NOR,me);
      me->set_temp("magic-manor/goldmagic",1);
      if( !me->query("magic-manor/kill-gold") )
      {
        me->set("magic-manor/kill-gold",1);
      } else {
        me->add("magic-manor/kill-gold",1);
      }
    } else {
      if( !me->query("magic-manor/kill-gold") )
      {
        me->set("magic-manor/kill-gold",1);
      } else {
        me->add("magic-manor/kill-gold",1);
      }
    }
    me->delete_temp("magic-manor/breakgold",1);
  }
  tell_room(this_object(),"\n\n塔身因為金靈王的滅亡而慢慢的出現了一些裂痕.....\n");
  :: die();
}

string do_special_fight()
{
  if( query_skill_mapped("blade") == "fast-blade" )
  {
    command("perform blade.fast-dest");
    map_skill("blade", "gold-blade");
  }
  else if( query_skill_mapped("blade") == "gold-blade" )
  { 
    command("perform blade.gold-dest");
    map_skill("blade", "fast-blade");
  }
  command("perform blade.gold-dest");
  return "";
}
