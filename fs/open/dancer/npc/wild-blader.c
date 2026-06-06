// 新增南方蠻族入主人間 war
//排版 by blazakira 2011/9/19
//補上紀錄戰功時 npc的名字 by blazakira 2011/10/19

#include <ansi.h>
inherit NPC;

string do_special_fight();
string do_special_perform1();

void create()
{
  set_name("秦嘯天",({"wild blader","wild","blader"}));
  set("long","秦嘯天，南方三霸之一，本是金刀門門主王元霸之師兄，二十年前因\n"+
    "搶劫朝廷軍營事跡敗露而遭逐出師門，流放南方蠻夷之地，數十年來\n"+
    "苦心鍛煉刀法而有所大成，逐漸成為南蠻刀之霸主，一心只想著重回\n中原屠殺人間，以報流放南蠻數十年之苦。");
  set("gender","男性");
  set("class","blademan");
  set("nickname","南雄 - 刀霸");
  set("combat_exp",7000000);
  set("attitude","heroism");
  set("env/連擊","YES");
  set("age",62);
  set("str", 99);
  set("cor", 99);
  set("int", 99);
  set("spi", 99);
  set("cps", 99);
  set("con", 99);
  set("kar", 99);
  set("max_gin", 40000);
//  set("gin", 40000);
  set("max_kee", 150000);
//  set("kee", 150000);
  set("max_sen", 40000);
//  set("sen", 40000);
  set("max_atman", 35000);
  set("atman", 35000);
  set("max_mana", 35000);
  set("mana", 35000);
  set("max_force", 100000);
  set("force", 150000);
  set("functions/gold-dest/level",100);
  set("functions/fast-dest/level",100);
  set_skill("blade",120);
  set_skill("parry",120);
  set_skill("move",120);
  set_skill("dodge",120);
  set_skill("force",250);
  set_skill("magic",120);
  set_skill("spells",120);
  set_skill("riding",100);
  set_skill("gold-blade",100);
  set_skill("fast-blade",100);
  set_skill("sixforce",200);
  map_skill("blade","fast-blade");
  map_skill("parry","gold-blade");
  map_skill("force","sixforce");
  set_temp("roared", 1 );
  set_temp("apply/armor",100);
  set("random_move",200);
  set("force_factor",15);
  set("mystery",1);
  set("chat_chance_combat",80);
  set("chat_msg_combat",({
    (: do_special_perform1 :),
  }));
  setup();
  set("chat_chance",100);
  set("chat_msg",({
    (: random_move :),
  }));
  set("family/family_name","金刀門");
  set("title","金刀門第五代門主");
  carry_object("/daemon/class/blademan/obj/gold-blade2")->wield();
  add_money("cash",100);
}

int accept_fight(object me,object who)
{
  who=this_player();
  kill_ob(who);
  command("say "HIC"哈哈哈，就讓你見識什麼是刀者之魂吧！！！\n\n\n\n    "HIR"   ╭─╮            ╔                            ▁▂▃▄▅▆▇◤\n"HIR"       │  ╭╮︽︽︽︽︽║▆▆▆▆▆▆▆▆▆▆▆▆▇███████◤\n"HIR"       │  ╰╯︾︾︾︾︾║███████████████████◤\n"HIR"       ╰╮              ╚\n"HIR"         〨\n"HIR"         ⊙\n"HIR"         ╰═════\n"NOR);
  who->start_busy(1);
  return 1;
}

int accept_kill(object who)
{
  who=this_player();
  kill_ob(who);
  command("say "HIC"哈哈哈，就讓你見識什麼是刀者之魂吧！！！\n\n\n\n    "HIR"   ╭─╮            ╔                            ▁▂▃▄▅▆▇◤\n"HIR"       │  ╭╮︽︽︽︽︽║▆▆▆▆▆▆▆▆▆▆▆▆▇███████◤\n"HIR"       │  ╰╯︾︾︾︾︾║███████████████████◤\n"HIR"       ╰╮              ╚\n"HIR"         〨\n"HIR"         ⊙\n"HIR"         ╰═════\n"NOR);
  who->start_busy(1);
  return 1;
}

string do_special_perform1()
{
  if( query_skill_mapped("blade") == "fast-blade" ) {
    command("perform blade.fast-dest");
    map_skill("blade", "gold-blade");
  }
  else if( query_skill_mapped("blade") == "gold-blade" ) { 
    command("perform blade.gold-dest");
    map_skill("blade", "fast-blade");
  }
  command("perform blade.gold-dest");
  return "";
}

void heart_beat()
{
  object env,mob,*enemy;
  int i,j,damage,exp1,exp2;
  string msg;
  j=random(100);
  mob = this_object();
  if(!mob || !environment(mob)) return ;
  env = environment(mob);
  enemy=mob->query_enemy();
  if(mob->is_fighting())
  {
    i=sizeof(enemy);
    for(j=0;j<i;j++)
    {
      exp1=mob->query("combat_exp");
      if(!enemy[j]) continue;
      exp2=enemy[j]->query("combat_exp");
      if(exp2>exp1)
        mob->set("combat_exp",exp2+random(16888));
    }
  }

  if(!mob->query_temp("fast-dest") && mob->is_fighting() && !mob->is_busy())
  {
    map_skill("blade", "fast-blade");
    command("perform blade.fast-dest");
  }
  if( j < 40 && is_fighting())
  {
    enemy=mob->query_enemy();
    for(i=0;i<sizeof(enemy);i++) {
      if(!enemy[i]) continue;
      if(environment(mob) == environment(enemy[i]))
      {
        message_vision(HIY"\n$N隨著體內殺氣無限提升，橫刀高喊："HIW"『  "HIM"魔 威 天 下  "HIW"～  "HIY"刀 "HIB"霸 人 間  "HIW"』\n\n        "HIW"《  "HIR"魔 "HIW"． "HIR"道 "HIW"． "HIR"極 "HIW"． "HIR"殺 "HIW"． "HIR"之   "HIY"狂   龍   "HIC"七   斬   訣  "HIW"》\n\n"NOR,mob,enemy[i]);
        damage = random(300)+100;
        msg = HIB"$N體內戰意源源不絕傾洩而出"HIW"《"HIY"狂龍"HIC"七斬訣"HIW"》"HIB"壹式"HIW"★"HIY"天刀"HIC"驚流痕"HIW"★"HIB"，$n"HIB"被無限刀意砍得體無完膚！\n"NOR;
        if(damage > 200) {
          message_vision(msg,mob,enemy[i]);
          enemy[i]->receive_damage("kee",damage,mob);
          COMBAT_D->report_status(enemy[i]);
        }
        else {
          msg +="( "HIW"$n出招似有若無，身影疾退數步，在無形之中將此招一一閃過。 "NOR+WHT")\n"NOR;
          message_vision(msg,mob,enemy[i]);
        }
        damage = random(300)+100;
        msg = HIB"$N體內戰意源源不絕傾洩而出"HIW"《"HIY"狂龍"HIC"七斬訣"HIW"》"HIB"貳式"HIW"★"HIM"雷刀"HIR"破霜闕"HIW"★"HIB"，$n"HIB"被無限刀意砍得體無完膚！\n"NOR;
        if(damage > 200) {
          message_vision(msg,mob,enemy[i]);
          enemy[i]->receive_damage("kee",damage,mob);
          COMBAT_D->report_status(enemy[i]);
        }
        else {
          msg +="( "HIW"$n出招似有若無，身影疾退數步，在無形之中將此招一一閃過。 "NOR+WHT")\n"NOR;
          message_vision(msg,mob,enemy[i]);
        }
        damage = random(300)+100;
        msg = HIB"$N體內戰意源源不絕傾洩而出"HIW"《"HIY"狂龍"HIC"七斬訣"HIW"》"HIB"參式"HIW"★"HIY"地刀"HIG"震山河"HIW"★"HIB"，$n"HIB"被無限刀意砍得體無完膚！\n"NOR;
        if(damage > 200) {
          message_vision(msg,mob,enemy[i]);
          enemy[i]->receive_damage("kee",damage,mob);
          COMBAT_D->report_status(enemy[i]);
        }
        else {
          msg +="( "HIW"$n出招似有若無，身影疾退數步，在無形之中將此招一一閃過。 "NOR+WHT")\n"NOR;
          message_vision(msg,mob,enemy[i]);
        }
        damage = random(300)+100;
        msg = HIB"$N體內戰意源源不絕傾洩而出"HIW"《"HIY"狂龍"HIC"七斬訣"HIW"》"HIB"肆式"HIW"★"HIR"火刀"HIY"焚混沌"HIW"★"HIB"，$n"HIB"被無限刀意砍得體無完膚！\n"NOR;
        if(damage > 200) {
          message_vision(msg,mob,enemy[i]);
          enemy[i]->receive_damage("kee",damage,mob);
          COMBAT_D->report_status(enemy[i]);
        }
        else {
          msg +="( "HIW"$n出招似有若無，身影疾退數步，在無形之中將此招一一閃過。 "NOR+WHT")\n"NOR;
          message_vision(msg,mob,enemy[i]);
        }
        damage = random(300)+100;
        msg = HIB"$N體內戰意源源不絕傾洩而出"HIW"《"HIY"狂龍"HIC"七斬訣"HIW"》"HIB"伍式"HIW"★"HIG"風刀"HIR"滅星辰"HIW"★"HIB"，$n"HIB"被無限刀意砍得體無完膚！\n"NOR;
        if(damage > 200) {
          message_vision(msg,mob,enemy[i]);
          enemy[i]->receive_damage("kee",damage,mob);
          COMBAT_D->report_status(enemy[i]);
        }
        else {
          msg +="( "HIW"$n出招似有若無，身影疾退數步，在無形之中將此招一一閃過。 "NOR+WHT")\n"NOR;
          message_vision(msg,mob,enemy[i]);
        }
        damage = random(300)+100;
        msg = HIB"$N體內戰意源源不絕傾洩而出"HIW"《"HIY"狂龍"HIC"七斬訣"HIW"》"HIB"陸式"HIW"★"HIM"雨刀"HIG"淋寰宇"HIW"★"HIB"，$n"HIB"被無限刀意砍得體無完膚！\n"NOR;
        if(damage > 200) {
          message_vision(msg,mob,enemy[i]);
          enemy[i]->receive_damage("kee",damage,mob);
          COMBAT_D->report_status(enemy[i]);
        }
        else {
          msg +="( "HIW"$n出招似有若無，身影疾退數步，在無形之中將此招一一閃過。 "NOR+WHT")\n"NOR;
          message_vision(msg,mob,enemy[i]);
        }
        damage = random(300)+100;
        msg = HIB"$N體內戰意源源不絕傾洩而出"HIW"《"HIY"狂龍"HIC"七斬訣"HIW"》"HIB"柒式"HIW"★"HIC"雪刀"HIM"冰千里"HIW"★"HIB"，$n"HIB"被無限刀意砍得體無完膚！\n"NOR;
        if(damage > 200) {
          message_vision(msg,mob,enemy[i]);
          enemy[i]->apply_condition("ad-blade",random(5)+5);
          enemy[i]->receive_damage("kee",damage,mob);
          COMBAT_D->report_status(enemy[i]);
        }
        else {
          msg +="( "HIW"$n出招似有若無，身影疾退數步，在無形之中將此招一一閃過。 "NOR+WHT")\n"NOR;
          message_vision(msg,mob,enemy[i]);
        }
      }
    }
  }

  if( 70 < j && mob -> query("kee") < mob->query("max_kee")*0.6 )
  {
    message_vision( HIY"\n秦嘯天運氣丹田，瞬間刀中竄出無數陰魂，身上的傷口也漸漸癒合。\n"NOR, mob);
    mob->delete_busy();
    mob->clear_condition();
    mob->receive_heal("kee",1000);
    mob->receive_curing("kee",1000);
    mob->receive_heal("gin",800);
    mob->receive_curing("gin",800);
    mob->receive_heal("sen",800);
    mob->receive_curing("sen",800);
  }

  if( 40< j < 70 && is_fighting() ) 
  {
    enemy=mob->query_enemy();
    for(i=0;i<sizeof(enemy);i++) {
      if(!enemy[i]) continue;
      if(environment(mob) == environment(enemy[i]))
      {
        message_vision( HIR"\n\n$N目露兇光，大喝一聲 "HIW"『  "HIY"天  雷  刀  "HIW"』\n\n"HIW"瞬間天際閃過數道雷霆從天而降擊中$N\n\n"HIG"$N身上散發出陣陣綠光，將吸收的雷霆逼入刀中，刀法如漫天飛雪般的將$n團團圍住。\n\n"NOR, mob ,enemy[i] );
        enemy[i]->receive_damage("kee",500,mob);
        enemy[i]->receive_damage("gin",500,mob);
        enemy[i]->receive_damage("sen",500,mob);
        enemy[i]->start_busy(1);
        COMBAT_D->report_status(enemy[i]);
      }
    }
  }
  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  object winner = query_temp("last_damage_from");
  string name = winner->query("name");
  string class1 = winner->query("family/family_name");
  set("combat_exp",7000000);
  if(!winner)
  {
    ::die();
    return ;
  }
  tell_object(users(),HIW"\n\n\n    "HIW"『  "HIC"異 域 奇 緣    "HIY"橫 刀 稱 王 霸 群 雄 ！ \n\n"+
    "             "HIG"鄉 愁 離 情    "HIM"浩 瀚 星 海 恨 悠 悠 ！ "HIW"』\n\n\n"+HIR+
    "想我"HIC"南雄"HIM"刀霸"HIR"雄據南蠻數十載，如今敗於"+HIC+class1+HIB"弟子"+HIY+name+HIR+"之手。\n"+HIR+
    "中原果真是臥虎藏龍，深藏不露，恨啊 ！！！\n\n\n"NOR);
  message_vision(HIY"\n"+winner->name()+"打死秦嘯天得到五百點戰功\!!\n"NOR,winner);
  write_file("/log/get_warp",sprintf("%s(%s) 打敗秦嘯天得到五百點戰功\於 %s\n",
    winner->name(1),winner->query("id"),ctime(time())));
  winner->add("war_score",500);
  ::die();
}
