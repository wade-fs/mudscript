// 新增南蠻war 薛霸天
//補上紀錄戰功時 npc的名字 by blazakira 2011/10/19

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("薛霸天",({"wind fighter","wind","fighter"}) );
  set("long","鬼影子，生性兇殘，武道界之人階聞名喪膽，相傳他是鬼影老人的師\n弟，也有人說他是任嘯天的師兄，但詳情沒人知道，只知道鬼影子身\n兼雪蒼派與瀧山派之絕學，在其深厚的內力基礎之下，慘害武林數十\n年無人能敵。\n");
  set("gender","男性");
  set("class","fighter");
  set("nickname",HIR + "鬼"NOR+RED"影" + HIR + "子" + NOR);
  set("title",HIY + "雪蒼派" + HIW + "『" + HIR + "陽字訣" + HIW + "』" + HIY + "傳人" + NOR);
  set("combat_exp",12000000);
  set("attitude","heroism");
  set("age",168);
  set("bellicosity",9999);
  set("str", 99);
  set("cor", 99);
  set("int", 99);
  set("spi", 99);
  set("cps", 99);
  set("per", 99);
  set("con", 99);
  set("kar", 99);
  set("kee",150000);
  set("gin",40000);
  set("sen",40000);
  set("atman",40000);
  set("mana",40000);
  set("force",2000000);
  set("max_kee",150000);
  set("max_gin",40000);
  set("max_sen",40000);
  set("max_mana",40000);
  set("max_atman",40000);
  set("max_force",15000);
  set("quests/read_snow",3);
  set_temp("roared", 1 );
  set("mystery",1);
  set("fire_strike",1);
  set("super_fire",1);
  set("env/瀧山連擊","YES");
  set_temp("kang-power", 1 );
  set("quests/ya",1);
  set("go_ya",1);
  set_skill("unarmed",120);
  set_skill("parry",120);
  set_skill("move",120);
  set_skill("dodge",120);
  set_skill("magic",120);
  set_skill("spells",120);
  set_skill("force",350);
  set_skill("snow-martial",120);
  set_skill("lungshan",120);
  set_skill("snow-kee",120);
  set_skill("fire-kee",120);
  set_skill("black-steps",120);
  set_skill("henma-steps",120);
  set_skill("snowforce",277);
  set_skill("haoforce",277);
  set_skill("necromancy",120);
  set_skill("dremagic",120);
  map_skill("unarmed","snow-martial");
  map_skill("parry","snow-kee");
  map_skill("dodge","henma-steps");
  map_skill("move","black-steps");
  map_skill("force","haoforce");
  map_skill("spells","necromancy");
  map_skill("magic","dremagic");
  set_temp("apply/armor",100);
  set("random_move",200);
  set("functions/ice-fingers/level",100);
  set("functions/snow-powerup/level",100);
  set("functions/kang_kee/level",100);
  set("force_factor",90);
  setup();
  carry_object("/open/snow/obj/figring.c")->wield();
  carry_object("/open/snow/obj/liucloth.c")->wear();
  set("chat_chance",100);
  set("chat_msg",({
    (: random_move :),
  }));
  set("chat_chance_combat",60);
  set("chat_msg_combat",({
  }));
  set_temp("def_cold1",1);
}

int accept_fight(object who)
{
//  who=this_player();
  message_vision(sprintf("\n" + HIY + "哈哈哈！就讓你見識老夫的" + HIW + "【 " + HIG + "霸 " + HIW + "～ " + HIG + "氣 " + HIW + "～ " + HIB + "千 " + HIW + "～ " + HIM + "秋 " + HIW + "】。\n\n" + NOR),who);
  fight_ob(who);
//  command("perform snow-kee.snow-powerup");
  return 1;
}

int accept_kill(object who)
{
//  who=this_player();
  message_vision(sprintf("\n" + HIC + "哼！小子你有種，看來非得逼老夫使出奧義精華來對付你了！！！\n\n        " + HIW + "【  " + HIG + "橫 " + HIM + "霸 " + HIY + "天 下  " + HIW + "～  " + HIM + "驚  " + HIB + "天  " + HIG + "九  " + HIR + "流  " + HIW + "】\n\n" + NOR),who);
  kill_ob(who);
//  command("perform snow-kee.snow-powerup");
  return 1;
}

void heart_beat()
{
  object winner = query_temp("last_damage_from");
  object me,*target,victim,*player;
  int i,j,k,a,b,c,d=0;
  a=random(100);
  me=this_object();
  if(me->is_fighting()||me->is_killing()) {
    target=me->query_enemy();
    player=me->query_enemy();
    if(i=sizeof(target)) {
      for(j=0;j<i;j++)
      {
        a=me->query("combat_exp");
        if(!target[j]) continue;
        b=target[j]->query("combat_exp");
        if(b>a)
          me->set("combat_exp",b+random(16888));
      }
      if(a >= 6 && a <= 35) {
        message_vision(HIY + "\n薛霸天的身影隨風舞動，疾速轉動不停，瞬息間天地彷彿旋轉了起來\n\n"
          HIG + "驚 " + HIM + "天 " + HIY + "九 流 " + HIW + "之 【 " + HIB + "無  上  空  間  " + HIR + "困  敵  流 " + HIW + "】\n\n"
          HBRED+HIW"瞬間四周圍忽然黯淡無光，你的身旁彷彿有道無形之網困你而動彈不得。" + NOR + "\n\n" + NOR,me);
        for(b=0;b<i;b++) {
          if(userp(target[b])) continue;
          target[b]->start_busy(1);
        }
      }
      if(random(100) > 40) {
        for(c=0;c<i;c++) {
          if(!userp(target[c])) continue;
          player[d]=target[c];
          d = d + 1;
        }
        victim=player[random(d)];
        if(!victim) { } else {
          if(a >= 1 && a <= 5) {
            if(environment(me) == environment(victim)) {
              for(k=0;k<10;k++) {
                message_vision(HIR + "薛霸天領悟陰陽訣之" + HIG + "終極殺招" + HIR + "，" + HIW + "『" + HIG + "驚" + HIM + "天" + HIY + "九流" + HIW + "---"HBRED+HIW"狂霸天下"NOR+HIW"』" + HIR + "綿綿不絕的擊向$N\n" + NOR,victim);
                victim->receive_damage("kee",400,me);
                COMBAT_D->report_status(victim);
              }
              victim->set_temp("last_damage_from",me);
              victim->start_busy(1);
            }
          }
          else if(a >= 36 && a <= 45) {
            if(environment(me) == environment(victim))
              for(b=0;b<5;b++) {
                message_vision(HIG + "薛霸天領悟陰陽訣之" + HIY + "禁邪招" + HIG + "，" + HIW + "『" + HIG + "驚" + HIM + "天" + HIY + "九流" + HIW + "---"HBGRN+HIW"秋風掃落葉"NOR+HIW"』" + HIG + "綿綿不絕的擊向$N\n" + NOR,victim);
                victim->receive_wound("kee",300,me);
                COMBAT_D->report_status(victim,1);
              }
         } else if(a >= 56 && a <= 60) {
           if(environment(me) == environment(victim))
             for(b=0;b<6;b++) {
               message_vision(HIY + "薛霸天領悟陰陽訣之" + HIB + "武學精華" + HIY + "，" + HIW + "『" + HIG + "驚" + HIM + "天" + HIY + "九流" + HIW + "---"HBYEL+HIW"邪心魔性"NOR+HIW"』" + HIY + "綿綿不絕的擊向$N\n" + NOR,victim);
               victim->receive_damage("kee",500,me);
               COMBAT_D->report_status(victim);
             }
         }
         else if(a >= 71 && a <= 75) {
           if(environment(me) == environment(victim))
             for(b=0;b<6;b++) {
               message_vision(HIB + "薛霸天領悟陰陽訣之" + HIM + "奧義招" + HIB + "，" + HIW + "『" + HIG + "驚" + HIM + "天" + HIY + "九流" + HIW + "---"HBBLU+HIW"石破天驚"NOR+HIW"』" + HIB + "綿綿不絕的擊向$N\n" + NOR,victim);
               victim->receive_wound("kee",400,me);
               COMBAT_D->report_status(victim,1);
            }
        }
        else if( a >= 86 && a <= 90) {
          if(environment(me) == environment(victim))
            for(b=0;b<7;b++) {
              message_vision(HIM + "薛霸天領悟陰陽訣之" + HIC + "無上心法" + HIM + "，" + HIW + "『" + HIG + "驚" + HIM + "天" + HIY + "九流" + HIW + "---"HBMAG+HIW"流水無蹤"NOR+HIW"』" + HIM + "綿綿不絕的擊向$N\n" + NOR,victim);
              victim->receive_damage("kee",600,me);
              COMBAT_D->report_status(victim);
            }
        }
        else if(a >= 94 && a <= 98) {
          if(environment(me) == environment(victim))
            for(b=0;b<8;b++) {
              message_vision(HIC + "薛霸天領悟陰陽訣之" + HIR + "無限殺意" + HIC + "，" + HIW + "『" + HIG + "驚" + HIM + "天" + HIY + "九流" + HIW + "---"HBCYN+HIW"日月無光"NOR+HIW"』" + HIC + "綿綿不絕的擊向$N\n" + NOR,victim);
              victim->receive_wound("kee",400,me);
              COMBAT_D->report_status(victim,1);
            }
        }
        else if(a == 99 || a == 66 || a == 0) {
          if(environment(me) == environment(victim))
            for(b=0;b<9;b++) {
              message_vision(HIR + "薛霸天領悟陰陽訣之" + HIG + "狂霸" + HIY + "極招" + HIR + "，" + HIW + "『" + HIG + "驚" + HIM + "天" + HIY + "九流" + HIW + "---" + HIG + "忘棄" + HIM + "紅塵" + HIW + "』" + HIR + "綿綿不絕的擊向$N\n" + NOR,victim);
              victim->receive_wound("kee",500,me);
              COMBAT_D->report_status(victim);
            }
        }
        else { }
      }
    }
  }
  me=this_object();
  target=me->query_enemy();
  if(random(100) > 50)
  {
    if(i=sizeof(target))
    {
      if(!me->query("change"))
      {
        if(random(10) >= 5)
        {
          message_vision(HIY + "\n薛霸天運起" + HIW + "『" + HIC + "陰" + HIR + "陽" + HIG + "訣" + HIW + "』" + HIY + "之陰柔內勁擊向你的胸前，只見你疼痛不堪，血流不止！\n" + NOR,me);
          for(j=0;j < i;j++) {
            target[j]->add("kee",-500);
            target[j]->apply_condition("hart",10);
          }
        } else {
          message_vision(HIM + "\n薛霸天運起" + HIW + "『" + HIC + "陰" + HIR + "陽" + HIG + "訣" + HIW + "』" + HIM + "無上心法，體內兩道內勁不停相吸，內力也漸漸回復了不少。\n" + NOR,me);
          me->receive_curing("gin",500);
          me->receive_heal("gin",500);
          me->receive_curing("sen",500);
          me->receive_heal("sen",500);
          me->add("force",1500);
          me->delete_busy();
          me->clear_condition();
        }
      } else {
        if(random(10) >= 5) {
          for(j=0;j < i;j++) {
            message_vision(HIM + "\n\n" + HIC + "薛霸天體內" + HIW + "『" + HIC + "陰" + HIR + "陽" + HIG + "訣" + HIW + "』" + HIC + "的陰陽內勁不斷的遊走全身，臉色發青的大喊：\n\n"
              HIR + "日為陽" + HIW + "，" + HIC + "月為陰" + HIW + "，" + HIR + "陰" + HIC + "陽" + HIR + "交" + HIC + "匯" + HIW + "，" + HIR + "生" + HIC + "生" + HIR + "不" + HIC + "息\n\n"
              HIC + "陰 " + HIR + "陽 " + HIG + "訣 " + HIB + "傲 世 天 下 " + HIW + "【 " + HIM + "兩  " + HIY + "極  " + HIC + "陰  " + HIR + "陽 " + HIW + "】\n\n"
              RED + "瞬間兩道強烈的氣勁如排山倒海般的將你淹沒！！！\n" + NOR,me);
              target[j]->add("kee",-700);
              target[j]->apply_condition("cold",10);
            }
        } else {
          message_vision(HIY + "\n薛霸天體內氣勁漸散，體力漸感不支，急忙運起" + HIW + "『" + HIC + "陰" + HIR + "陽" + HIG + "訣" + HIW + "』" + HIY + "，只見一道聖光籠罩，薛霸天的臉色看起來好了不少。\n" + NOR,me);
          me->receive_curing("gin",500);
          me->receive_heal("gin",500);
          me->receive_curing("kee",500);
          me->receive_heal("kee",500);
          me->receive_curing("sen",500);
          me->receive_heal("sen",500);
          me->delete_busy();
          me->add("force",2000);
          me->clear_condition();
        }
      }
    }
  }
  if((me->query("eff_kee") < 25000 || me->query("kee") < 25000) && !me->query("change"))
  {
      tell_object(users(),"");
      tell_object(users(),"\n" + HIC + "薛霸天喝道：可恨的" + HIW + ""+winner->query("name")+"" + HIC + "，我看你是活膩了！\n看來我得使出我的真本領了，準備受死吧！！！\n\n" + NOR);
      tell_object(users(),"");
      me->set("force_factor",90);
      me->set("fire_strike",1);
      me->set("super_fire",1);
      me->set("family/family_name","瀧山派");
      me->set("env/瀧山連擊","YES");
      me->set("combat_exp",15000000);
      me->set("kee",80000);
      me->set("gin",40000);
      me->set("sen",40000);
      me->set("atman",40000);
      me->set("mana",40000);
      me->set("force",2000000);
      me->set("max_kee",80000);
      me->set("max_gin",40000);
      me->set("max_sen",40000);
      me->set("max_mana",40000);
      me->set("max_atman",40000);
      me->set("max_force",15000);
      me->set_skill("lungshan", 120);
      me->set_skill("haoforce", 277);
      me->set_skill("fire-kee",120);
      me->set_temp("kang-power",1);
      map_skill("unarmed", "lungshan");
      map_skill("parry","fire-kee");
      map_skill("force", "haoforce");
      me->reset_action();
      me->set("change",1);
      me->delete_busy();
      me->clear_condition();
      me->set("title",HIY + "瀧山派" + HIW + "『" + HIC + "陰字訣" + HIW + "』" + HIY + "傳人" + NOR);
    }
  }
  me->clean_up_enemy();
  ::heart_beat();
}

void die()
{
  object winner = query_temp("last_damage_from");
  string name = winner->query("name");
  string class1 = winner->query("family/family_name");
  set("combat_exp",12000000);
  if(!winner)
  {
    ::die();
    return ;
  }
  tell_object(users(),HIR + "\n\n\n    錦瑟無端五十絃    一絃一柱思華年\n\n        "
    HIC + "莊生曉夢迷蝴蝶    望帝春心託杜鵑\n\n            "
    HIG + "滄海月明珠有淚\    藍田日暖玉生煙\n\n                "
    HIM + "此情可待成追憶    只是當時已惘然\n\n"
    HIY + "\n想我" + HIM + "薛霸天" + HIY + "憑" + HIC + "陰" + HIR + "陽" + HIY + "兩極之高深武學縱橫南蠻數十年，未逢敵手\n如今敗於"+HIG+class1+HIB"弟子"+HIY+name+HIY+"之手，我不甘心啊！！！\n\n\n" + NOR);
  message_vision(HIY + "\n"+winner->name()+"打死薛霸天得到三百點戰功\!!\n" + NOR,winner);
  write_file("/log/get_warp",sprintf("%s(%s) 打敗薛霸天得到三百點戰功\於 %s\n",
    winner->name(1),winner->query("id"),ctime(time())));
  winner->add("war_score",300);
  ::die();
}
