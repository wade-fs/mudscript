//取消額外傷害函數中的判斷 me=this_player();因為系統似乎已經指定 by blazakira 2010/12/9
//將receive_wound補上攻擊方的參數 by blazakira 2011/7/23
//針對add("force")做額外限制 >> force 不夠當然不能用副攻呀 by blazakira 2011/7/23
//將report_status()區分為kee & eff_kee的表述 by blazakira 2011/8/10

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void earthkill(object me,object victim,object weapon,int damage);
void killall(object me,object victim,object weapon,int damage);
void heartkill(object me,object victim,object weapon,int damage);
void threekill(object me,object victim,object weapon,int damage);
void skykill(object me,object victim,object weapon,int damage);
void bloodkill(object me,object victim,object weapon,int damage);
void burn(object me,object victim,object weapon,int damage);
void cold(object me,object victim,object weapon,int damage);

mapping *action = ({
  (["action":"$N不是忍者所以無法使用。",
    "dodge"      : 0,
    "parry"      : 0,
    "damage"     : 0,
    "damage_type": "刺傷"
  ]),
  (["action":HIW + "$N" + HIW + "東瀛伊賀流地斬十式第一式短刃技『" + HIR + "空  蟬" + HIW + "』，身型一晃，手中兵器已經襲向$n" + HIW + "弱點。" + NOR,
    "damage"     : 100,
    "force"      : 100,
    "damage_type": "刺傷"
  ]),
  (["action":HIW + "$N" + HIW + "東瀛伊賀流地斬十式第二式短刃技『" + HIR + "山  嵐" + HIW + "』，穩健的攻擊逼得$n" + HIW + "手忙腳亂。" + NOR,
    "damage"     : 110,
    "force"      : 110,
    "damage_type": "割傷"
  ]),
  (["action":HIW + "$N" + HIW + "東瀛伊賀流地斬十式第三式短刃技『" + HIR + "冰  舞" + HIW + "』，只見$N迅速的繞到$n" + HIW + "身後準備給予致命的一擊。" + NOR,
    "damage"     : 120,
    "force"      : 120,
    "post_action": (: cold :),
    "damage_type": "凍傷"
  ]),
  (["action":HIW + "$N" + HIW + "東瀛伊賀流地斬十式第四式短刃技『" + HIR + "炎  襲" + HIW + "』，手中兵器如火焰般撲向$n" + HIW + "。" + NOR,
    "damage"     : 130,
    "force"      : 130,
    "post_action": (: burn :),
    "damage_type": "燒傷"
  ]),
  (["action":HIW + "$N" + HIW + "東瀛伊賀流地斬十式第五式短刃技『" + HIR + "血  殺" + HIW + "』，$n" + HIW + "濺出的鮮血隨風四處飄散。" + NOR,
    "damage"     : 145,
    "force"      : 145,
    "post_action": (: bloodkill :),
    "damage_type": "刺傷"
  ]),
  (["action":HIW + "$N" + HIW + "左右晃動，步法散中有序，身影忽然消失在空氣之間，使出忍者至高武術之『" + HIR + "滅  天  閃" + HIW + "』。" + NOR,
    "damage"     : 150,
    "force"      : 150,
    "post_action": (: skykill :),
    "damage_type": "刺傷"
  ]),
  (["action":HIW + "$N" + HIW + "使出東瀛伊賀流地斬十式第七式短刃技『" + HIR + "三  方  斬" + HIW + "』，刀光四起，四處鮮血飛濺。" + NOR,
    "damage"     : 200,
    "force"      : 200,
    "post_action": (: threekill :),
    "damage_type": "刺傷"
  ]),
  (["action":HIW + "$N" + HIW + "激發全身殺氣，一招『" + HIR + "破  心  擊" + HIW + "』以凌人的霸氣震攝$n" + HIW + "。" + NOR,
    "damage"     : 200,
    "force"      : 200,
    "post_action": (: heartkill :),
    "damage_type": "刺傷"
  ]),
  (["action":HIW + "$N" + HIW + "使出地斬奧義『" + HIR + "撼  地  訣" + HIW + "』，在極短的時間內朝著$n" + HIW + "週身破綻進行猛攻。" + NOR,
    "damage"     : 200,
    "force"      : 200,
    "post_action": (: earthkill :),
    "damage_type": "刺傷"
  ]),
  (["action":HIW + "$N" + HIW + "如鬼魅般的迅速移動身型，只見刀光一閃，一招『" + HIR + "瞬  殺  四  方" + HIW + "』朝著四周猛劈。" + NOR,
    "damage"     : 250,
    "force"      : 250,
    "post_action": (: killall :),
    "damage_type": "刺傷"
  ]),
});

int valid_enable(string usage)
{
  return usage=="dagger" || usage=="parry";
}

mapping query_action(object me, object weapon, object victim, object *enemy,object room)
{
  int skill_level, limit, i, j=0,kill_hurt;
  skill_level=(int)me->query_skill("earth-kill", 1); //取得使用者的技能基礎等級
  limit=(int)(skill_level/10); //極限值取技能等級/10
  enemy=me->query_enemy(); //取得敵人資料
  i=sizeof(enemy); //敵人數量
  victim=enemy[random(i)]; //目標敵人
  kill_hurt=(me->query("earth-kill/killsword/exp")); //傷害值為killsword的exp
  if (kill_hurt > 1500) kill_hurt=1500; //killsword的傷害值最高為1500
  if (me->query_skill("earth-kill",1) > 90 && random(me->query("functions/manakee/level")) > 120
      && me->query_temp("earthkill")!=1)
  {
    message_vision(HIG + "
                       ～ ～  " + HIR + "秘 奧 義  " + HIG + "～ ～
                  " + YEL + "『" + HIB + " 狂 亂 烈 風 之 空 蟬 地 斬 " + YEL + "』

               " + HIM + "真 ˙ 伊 賀 流 秘 義" + HIW + " －－" + HIY + "『 " + HIC + "空    蟬 " + HIY + "』
                        
               " + GRN + "裏 ˙ 伊 賀 流 奧 義" + HIW + " －－" + HIY + "『" + YEL + " 地    斬 " + HIY + "』

      " + HIW + "$N" + HIW + "雙奧義同時施展，招式如狂風暴雨般的猛襲$n" + HIW + "。\n" + NOR,me,victim);
    victim->receive_wound("kee",me->query_skill("force"),me); //將使用者的force作為傷害 //估計500
    victim->start_busy(1);
    COMBAT_D->report_status(victim,1);
  }
  if (skill_level > 90 && random(100)>65 && me->query("bellicosity") > me->query("force")
      && me->query("bellicosity") > 8000 && me->query_temp("earthkill")!=1
      && me->query("quest/be_pker")==1 && me->query("force") > 1000)
  {
    message_vision("\n",me);
    me->do_command("snort");
    me->do_command("say 嘿嘿....就讓你見識一下真正的殺人劍招！");
    message_vision(HIW + "\n\t殺  人  劍 ～～～ " + HIY + "『 斬  人 』 " + HIW + "！\n" + NOR,me);
    victim->receive_wound("kee",kill_hurt/4,me); //以最高值來估計 傷害值為375
    COMBAT_D->report_status(victim,1);
    me->add("force",-100); //force累計100
    me->add("bellicosity",-50);
    if (me->query("bellicosity") > 13000)
    {
      message_vision(HIW + "\n\t殺  人  劍 ～～～ " + HIC + "『 斬  魂 』 " + HIW + "！\n" + NOR,me);
      victim->receive_wound("kee",kill_hurt/3,me); //以最高值來估計 傷害值為500
      me->add("force",-200); //force累計300
      me->add("bellicosity",-100);
      COMBAT_D->report_status(victim,1);
    }
    if (me->query("bellicosity") > 18000)
    {
      message_vision(HIW + "\n\t殺  人  劍 ～～～ " + HIG + "『 斬  鬼 』 " + HIW + "！\n" + NOR,me);
      victim->receive_wound("kee",kill_hurt/2,me); //以最高值來估計 傷害值為750
      me->add("force",-300); //force累計600
      me->add("bellicosity",-150);
      COMBAT_D->report_status(victim,1);
    }
    if (me->query("bellicosity") > 23000)
    {
      message_vision(HIW + "\n\t殺  人  劍 ～～～ " + HIR + "『 斬  神 』 " + HIW + "！\n" + NOR,me);
      victim->receive_wound("kee",kill_hurt,me); //以最高值來估計 傷害值為1500
      me->add("force",-400); //force累計1000
      me->add("bellicosity",-200);
      COMBAT_D->report_status(victim,1);
    }
    message_vision(HIB + "\n招式過後，天空灑下了一片腥紅血雨！\n" + NOR,me);
    me->do_command("haha");
  }
  if (random(15000)< (me->query_cor()+me->query_cps())+me->query("quest/add_bak")+me->query("earth-kill/bak/exp"))
  {
    message_vision(HIY + "\n$N" + HIY + "趁著$n" + HIY + "短暫的疏忽，給了$n" + HIY + "致命的背刺！\n\n" + NOR,me,victim);
    if (victim->query("max_kee")/2 > 100000) //以最低值來估計 給予對手100001以上的傷害時 才會有訊息
    {
      room=environment(me);
      tell_object(users(),HIW + "一陣強烈能量從"+room->query("short")+HIW + "傳出！！\n" + NOR);
    }
    victim->receive_wound("kee",victim->query("max_kee")/2,me);
    COMBAT_D->report_status(victim,1);
  }
  if (me->query("earth-kill/twoblade/exp") > 0 && me->query_temp("left_blade")==1
      && me->query_temp("right_blade")==1) //二刀流雙手短刃技 可能有專屬的wp
  {
    message_vision(HIW + "\n$N" + HIW + "使出二刀流雙手短刃技之『" + HIR + "雙  刃" + HIW + "』，只見$N" + HIW + "迅速的朝著$n" + HIW + "發動猛攻。\n" + NOR,me,victim);
    if (random(100)>20)
    {
      message_vision(NOR + "結果照成非常嚴重的刺傷。\n" + NOR,me);
      victim->receive_wound("kee",me->query("earth-kill/twoblade/exp"),me); //二刀流雙手短刃技的經驗為傷害力 //應亦為quest行為中取得
      COMBAT_D->report_status(victim,1);
    }
    else
    {
      message_vision(NOR + "但是被$N格開了。\n" + NOR,victim);
    }
  }
  if (me->query("class") != "killer")
    return action[0];
  if (limit < 2 )
    return action[random(2)+1];
  if (limit == 2 )
    return action[random(3)+1];
  if (limit == 3 )
    return action[random(4)+1];
  if (limit == 4 )
    return action[random(5)+1];
  if (limit == 5 )
    return action[random(6)+1];
  if (limit == 6 )
    return action[random(7)+1];
  if (limit == 7 )
    return action[random(8)+1];
  if (limit == 8 )
    return action[random(7)+2];
  if (limit == 9 )
    return action[random(7)+3];
  else
    return action[random(6)+5];
}

void earthkill(object me, object victim, object  weapon, int damage)
{
  int cor,j=0;
  cor=me->query_cor();
  if (random(me->query("functions/manakee/level")) > 55-cor && me->query_temp("earthkill")!=1
      && me->query("bellicosity") > 3000)
  {
    me->set_temp("earthkill",1); //連擊開始的紀錄mark
    for(j = 0;j < 15; j++)
    {
      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
    me->delete_temp("earthkill");
  }
}

void killall(object me, object victim, object  weapon, int damage)
{
  int i,hurt,j=0,force;
  object *enemy;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  hurt=me->query("PKS")+600; //MKS為最高殺敵數 HKS為高手殺敵數 則PKS為... //基礎傷害從600起跳
  force=me->query("force")*i; //額外增加force的限制 by blazakira
  if (hurt > 1500) hurt=1500;
  if (force < 500) force=500;
  if (random(me->query("functions/manakee/level")) > 40 && me->query_temp("earthkill")!=1 && me->query("force") > force)
  {
    message_vision(HIW + "只見$N" + HIW + "在刀光中狂舞，鮮血四處飛濺著！\n" + NOR,me);
    for (j=0 ; j < i ; j++)
    {
      if (random(100) > 20)
      {
        message_vision(HIR + "$N" + HIR + "閃躲不及，被刀光劈中，鮮血狂噴！\n" + NOR,enemy[j]);
        enemy[j]->receive_wound("kee",hurt,me);
        me->add("force",-400);
        COMBAT_D->report_status(enemy[j],1);
      }
      else
      {
        message_vision(YEL + "$N" + YEL + "側身一避，躲開了這致命的一擊！\n" + NOR,enemy[j]);
      }
    }
  }
}

void heartkill(object me, object victim, object  weapon, int damage)
{
  int hurt;
//  me=this_player();
  hurt=me->query("bellicosity")/25; //傷害來自於殺氣
  if (hurt > 800) hurt = 800; //殺氣為20000才會有最大值
  if (random(me->query("functions/manakee/level")) > 80 && me->query_temp("earthkill")!=1 && me->query("force") > 500
      && me->query("bellicosity") > 500 )
  {
    message_vision(HIC + "$N" + HIC + "被$n" + HIC + "散發出的強大氣息震攝住，全身無法動彈！\n" + NOR,victim,me);
    victim->receive_damage("kee",hurt,me);
    me->add("force",-300);
    if (random(100) > 20 ) victim->start_busy(1);
    me->add("bellicosity",-40);
    COMBAT_D->report_status(victim); //補上攻擊後的判斷 by blazakira
  }
}

void skykill(object me, object victim,object weapon,object *enemy)
{
  int hurt;
//  me=this_player();
  enemy=me->query_enemy();
  hurt=me->query("bellicosity")/20; //傷害來自於殺氣
  if (hurt > 800) hurt = 800; //殺氣為16000才會有最大值
  if (random(me->query("functions/manakee/level")) > 40 && me->query_temp("earthkill")!=1 && me->query("bellicosity") > 600
      && me->query("force") > 200)
  {
    message_vision(YEL + "\n『" + HIB + "臨˙兵˙鬥˙者˙皆˙陣˙列˙在˙前" + YEL + "』" + HIW + "～～$N" + HIW + "口中默唸忍術九字真言。\n" + NOR,me);
    message_vision(HIY + "$N" + HIY + "的兵器忽然灑出無數刀氣朝向$n" + HIY + "直攻而去，只見$n" + HIY + "閃避不及，被$N" + HIY + "的刀氣擊中！\n" + NOR,me,victim);
    victim->receive_wound("kee",hurt,me);
    me->add("bellicosity",-30);
    me->add("force",-200);
    COMBAT_D->report_status(victim,1);
  }
}

void threekill(object me, object victim, object  weapon,object *enemy)
{
  int i,hurt,k,j=0;
//  me=this_player();
  enemy=me->query_enemy();
  i=sizeof(enemy);
  hurt=me->query("bellicosity")/25; //傷害來自於殺氣
  if (hurt > 250) hurt = 250; //殺氣為6250才會有最大值
  if (random(me->query("functions/manakee/level")) > 50 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600
      && me->query("force") > 150) //因為有三次 所以應為50*3
  {
    for (j=0 ; j < 3; j++)
    {
      message_vision(HIG + "$N" + HIG + "無聲無息的繞到$n" + HIG + "身後，冷不防的在$n" + HIG + "背後刺了一刀！\n" + NOR,me,victim);
      victim->receive_wound("kee",hurt,me);
      me->add("bellicosity",-20);
      me->add("force",-50);
      COMBAT_D->report_status(victim,1);
    }
  }
}

void bloodkill(object me, object victim, object  weapon,object *enemy)
{
  int str,cor,intt,spi,cps,per,con,kar,hurt;
//  me=this_player();
  str=me->query_str(); //參考值為str 35
  cps=me->query_cps(); //參考值為cps 30
  per=me->query_per(); //參考值為cor 30+eq 245>>30~275
  con=me->query_con(); //參考值為con 35
  kar=me->query_kar(); //參考值為kar 35+eq 245>>35~280
  intt=me->query_int(); //參考值為int 35+eq 245>>35~280
  cor=me->query_cor(); //參考值為cor 35+eq 245>>35~280
  spi=me->query_spi(); //參考值為spi 35+eq 245>>35~280
  hurt=(str+cor+intt+spi+cps+per+con+kar)*3; //傷害來自於天賦 傷害值為 35+35+35+35+30+30+35+35=270 ~ 35+280+280+280+30+275+35+280=1495之間
  if (random(me->query("functions/manakee/level")) > 40 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600
      && me->query("force") > 200)
  {
    message_vision(HIR + "$N" + HIR + "吸取風中飄散的鮮血，將血氣納為己用！\n" + NOR,me);
    victim->receive_wound("kee",hurt,me);
    me->receive_curing("kee",hurt);
    me->receive_heal("kee",hurt);
    me->add("bellicosity",-150);
    me->add("force",-200);
    COMBAT_D->report_status(victim,1);
    COMBAT_D->report_status(me,1);
  }
}

void burn(object me, object victim, object  weapon,object *enemy)
{
  int hurt;
//  me=this_player();
  hurt=me->query("functions/manakee/level")*3; //傷害來自於魔氣殺等級 150*3=450
  if (random(me->query("functions/manakee/level")) > 50 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600
      && me->query("force") > 100)
  {
    message_vision(HIR + "由$N" + HIR + "殺意激發出來的炎勁不斷侵襲$n" + HIR + "！\n" + NOR,me,victim);
    victim->receive_wound("kee",hurt,me);
    victim->apply_condition("burn",10);
    me->add("bellicosity",-25);
    me->add("force",-100);
    COMBAT_D->report_status(victim,1);
  }
}

void cold(object me, object victim, object  weapon,object *enemy)
{
  int hurt;
//  me=this_player();
  hurt=me->query("functions/manakee/level")*3; //傷害來自於魔氣殺等級 150*3=450
  if (random(me->query("functions/manakee/level")) > 50 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600
      && me->query("force") > 100)
  {
    message_vision(HIC + "由$N" + HIC + "殺意激發出來的寒勁不斷侵襲$n" + HIC + "！\n" + NOR,me,victim);
    victim->receive_wound("kee",hurt,me);
    victim->apply_condition("cold",10);
    me->add("bellicosity",-25);
    me->add("force",-100);
    COMBAT_D->report_status(victim,1);
  }
}

string perform_action_file(string action)
{
  return CLASS_D("killer")+"/earth-kill/"+action;
}

int valid_learn(object me)
{
  tell_object(me,"地斬無法從學習中獲得進展，必須自己修行方有成果！\n");
  return 0;
}
