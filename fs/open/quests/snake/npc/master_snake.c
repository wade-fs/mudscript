//新增銀針門doctor_book quest的關鍵道具的相關動作 並補上receive_wound的攻擊者 by blazakira 2011/4/16
//增加瀧山派封印技『狂龍訣』quest的線索判斷 by blazakira 2011/9/5

inherit NPC;
inherit SSERVER;
#include <killed.fun>       // 7.21.93 by Firedancer
#include <count-time.fun>   // 7.21.93 by Firedancer
#include <ansi.h>

void create()
{
  set_name("蛇郎君",({"master snake","snake"}));
  set("age",32);
  set("title",HIR + "煉獄蛇王" + NOR);
  set("nickname",HIW + "人面蛇心" + NOR);
  set("attitude","aggressive");
  set("gender","男性");
  set("long","蛇寨寨主，生性殘暴，是非不分，佔據蛇寨為王，四處姦淫擄掠，無惡不作。\n");
  set("max_gin",20000);
  set("max_kee",20000);
  set("max_sen",20000);
  set("max_force",50000);
  set("force",50000);
  set("force_factor",20);
  set("combat_exp",800000);
  set_skill("whip",120);
  set_skill("snake-whiper",120);
  set_skill("parry",120);
  set_skill("dodge",120);
  set_skill("move",120);
  set_skill("black-steps",120);
  set_skill("force",200);
  set_skill("snowforce",200);
  map_skill("whip","snake-whiper");
  map_skill("parry","snake-whiper");
  map_skill("dodge","black-steps");
  map_skill("move","black-steps");
  map_skill("force","snowforce");
  setup();

  carry_object("/open/quests/snake/npc/obj/un_whip")->wield();
  carry_object("/open/quests/snake/npc/obj/helmet")->wear();
  carry_object("/open/quests/snake/npc/obj/snake_gem")->wear();
  carry_object("/open/quests/snake/npc/obj/un_cloth")->wear();

//  carry_object("/open/magic-manor/obj/master_snake_head");
}

void heart_beat()
{
  object ob,env,target;
  int i,j,kee,eff,max;

  ob = this_object();
  env = environment(ob);
  target = offensive_target(ob);

  if( !target )
    return ::heart_beat(1);

  max = (int)ob->query("max_kee");
  eff = (int)ob->query("eff_kee");
  kee = (int)ob->query("kee");

  if( ob->query_busy() && random(100) < 80 )
  {
    message_vision(HIW+"$N大喝一聲～破～!!$N的奇經六脈恢復了正常!!\n" + NOR,ob);
    ob->delete_busy();
  }

  if( random(100) < 80 )
  {
    if( eff < max || kee < eff )
    {
      message_vision(HIY + "$N點穴療傷，將體內的瘀傷給逼出，氣色恢復了許\多～\n" + NOR,ob);
      ob->receive_curing("kee",800);
      ob->receive_heal("kee",800);
      COMBAT_D->report_status(ob,1);
    }
  }

  if( env == environment(target) )
  {
    i = (int)ob->query_skill("dodge");
    j = (int)target->query_skill("dodge");
    
    if( random(i) > random(j) && (int)target->query_busy() < 3 )
    {
      message_vision(HIY + "$N使出自創步法"+HIW+"‵"+HIG+"蛇行步"+HIW+"‵"+HIY+"～

        左右晃動，似有若無的規律性，不斷的尾隨於$n的身後～

                $N看準時機，猛然握著鞭柄往$n的各路穴道打去～\n" + NOR,ob,target);
      target->start_busy(1);
    }

    if( random(i) > random(j) )
    {
      message_vision(HIY + "
$N領略到"+NOR+YEL+"〔"+MAG+"邪靈"+WHT+"。"+CYN+"蛇鞭"+YEL+"〕"+HIY+"之奧義

                        "+HIW+"～　"+HIC+"萬　鞭　歸　一　"+HIW+"～"+HIY+"

鞭法幻化成無數多條，以左右夾擊之勢，攻向$n。\n" + NOR,ob,target);
      message_vision(HIY + "$N閃避不及，只好正面抵擋$n的攻勢～\n" + NOR,target,ob);
      target->receive_wound("kee",800,ob);
      COMBAT_D->report_status(target,1);
    }
  }
  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  object obj;
  string arg;
  object ob = this_object();
  object me = query_temp("last_damage_from");
  object obh = new("/open/magic-manor/obj/master_snake_head");
  string name = me->query("name");

  if( me->query("family/family_name")==0 )
    arg = "無知平民";
  else
    arg = me->query("family/family_name");

//  if( !me->query("family/title") )
//    arg = arg+"平民";
//  else
//    arg = arg+me->query("family/family_name");

  tell_object(users(),HIC + "
天空突然一陣雷雨交加～

        " + HIG+ob->name(1)+"大怒道：該死的 " + HIC+arg+HIG + " 啊～

                        邪靈主派我來人間界進行的殺戮計劃竟然被 " + HIC+me->name(1)+HIG + " 給毀壞了～\n"+NOR);
  if ( kill_jobs(5,me,this_object(),"area/hole_stone") ) finish_time(me,"area/hole_stone");
  else start_time(me,"area/hole_stone"); // 7.21.93 by Firedancer

  if( !present("snake amulet",me) )
  {
    if( random(9) == 7 && userp(me) )
    {
      if( me->query_temp("quests/magic-manor-02") == 6 )
      {
        me->set_temp("quests/kill-snake",1);
        message_vision(HIY + "$N在臨死之前掉了一件護身符在$n的身上。\n" + NOR,ob,me);
        log_file("open-area/get_amulet", sprintf("%s(%s) 得到青蛇護符於 %s\n",name,me->query("id"), ctime(time()) ));
        obj = new("/autoload/open-area/snake_amulet");
        obj->move(me);
      } else {
        message_vision(HIY + "$N在臨死之前掉了一件護身符在$n的身上。\n" + NOR,ob,me);
        log_file("open-area/get_amulet", sprintf("%s(%s) 得到青蛇護符於 %s\n",name,me->query("id"), ctime(time()) ));
        obj = new("/autoload/open-area/snake_amulet");
        obj->move(me);
      }
    } else {
      if( me->query_temp("quests/magic-manor-02") == 6 )
      {
        me->set_temp("quests/kill-snake",1);
      }
    }
  } else if( me->query_temp("quests/magic-manor-02") == 6 )
  {
    me->set_temp("quests/kill-snake",1);
  }

  if( random(3) == 1 )
  {
    if( random(2) == 1 && me && me->query_temp("wu/ask_crazydragon") == 4 )
    {
      message_vision(HIR + "$N" + HIR + "一招勁力太強橫，竟然把$n" + HIR + "給轟的支離破碎了，連賞金的頭也給轟爛了!!\n" + NOR,me,this_object());
    }
    else
    {
      message_vision(HIW + "$N" + HIW + "順利的擊殺了$n" + HIW + "，並將$n" + HIW + "的賞金頭給割了下來!!\n" + NOR,me,this_object());
      if(me && me->query_temp("wu/ask_crazydragon") == 4) {
        obh->set_temp("wu/ask_crazydragon",5);
      }
      obh->move(me);
      //加入丐幫所需 temp   by pana
      if (me->query("family/family_name")=="丐幫") {
        me->set_temp("beggar_ko_snake",1);
      }
    }
  } else {
    message_vision(HIR + "$N" + HIR + "一招勁力太強橫，竟然把$n" + HIR + "給轟的支離破碎了，連賞金的頭也給轟爛了!!\n" + NOR,me,this_object());
  }

//加入銀針門神農quest所需 temp by blazakira
  if (me && me->query("family/family_name")=="銀針門" && random(100) > 30 && query_temp("record_damage/"+me->query("id")) > query("max_kee")/5) {
    me->set_temp("spiritup",query("id"));
  }

  ::die();
}

void record_damage(int damage, object who)
{
  if(!who) return ;
  if(who && !userp(who)) return ;
  add_temp("record_damage/"+who->query("id") , damage);
}
varargs int receive_damage(string type, int damage, object who)
{
  ::receive_damage(type,damage,who);
  who = query_temp("last_damage_from");
  record_damage(damage,who);
}
varargs int receive_wound(string type, int damage, object who)
{
  ::receive_wound(type,damage,who);
  who = query_temp("last_damage_from");
  record_damage(damage,who);
}
