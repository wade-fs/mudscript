//增加 使用者與對手的存在與否的判斷 與 receive_xxx的攻擊方參數 by blazakira 2011/9/16

#include <ansi.h>
#include <combat.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, object target)
{
  string msg;
  object ob,enemy;
  enemy=offensive_target(me);
  if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type") != "sword")
    return notify_fail("你需要裝備一把劍ㄡ，才能施展『昊陽競月極式』。\n");
  if(!me->query("quests/sunmoon"))
    return notify_fail("你的劍法的技巧不足無法使出『昊陽競月極式』。\n");
  if(!me->is_fighting())
    return notify_fail("『昊陽競月極式』只能在戰鬥中使用。\n");
  if(me->query_temp("per")==1) return notify_fail("你已經在用了。\n");

  if(me->query("force") < 1000)
    return notify_fail("你的內力不夠。\n");
  me->add("force",-500);
  message_vision(HIW"\n
                    "HIW"『"HIC"仙劍～至極之招～"HIW"』\n"NOR"
                    "HIG"『"HIR"連陽"HIW"月影"HIR"雙劍合擊"HIG"』\n"NOR"
             "HIG"『"HIW"日月並行絕式"HIR"～昊陽～"HIM"競月"HIC"破天式"HIG"』
    \n"NOR, me);
  call_out("act1",1,msg,enemy,me);
  call_out("act2",2,msg,enemy,me);
  call_out("act3",3,msg,enemy,me);
  call_out("act4",4,msg,enemy,me);
  call_out("act5",5,msg,enemy,me);
  call_out("act6",6,msg,enemy,me);
  call_out("act7",7,msg,enemy,me);
  call_out("act8",8,msg,enemy,me);
  call_out("act9",9,msg,enemy,me);
  call_out("act10",10,msg,enemy,me);
  call_out("act11",11,msg,enemy,me);
  call_out("act12",12,msg,enemy,me);
  call_out("act13",13,msg,enemy,me);
  call_out("act14",14,msg,enemy,me);
  message_vision( NOR,me);
  return 1;
}

int act1(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  me->set_temp("no_power",1);
  me->apply_condition("no_power",1);
  i=sizeof(enemy);
  damage = 100 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision( HIC"$N峰迴路轉內勁猛然上竄使出仙劍禁斷之連陽七訣第一式"HIY"『烈陽』"HIC"，劍光如烈陽狂燄直奔$n心口。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision( HIC"$N峰迴路轉內勁猛然上竄使出仙劍禁斷之連陽七訣第一式"HIY"『烈陽』"HIC"，劍光如烈陽狂燄直奔$n心口。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}

int act2(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 110 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision(HIB"$N收光為暈斂剛成柔，手中的長劍消失於黑暗中，四周劍芒頓時消失，不由自主使出月影幻式『陰月』，\n瞬間$n完全無法見光，只覺疾風拂向$n大腿。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIB"$N收光為暈斂剛成柔，手中的長劍消失於黑暗中，四周劍芒頓時消失，不由自主使出月影幻式『陰月』，\n瞬間$n完全無法見光，只覺疾風拂向$n大腿。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}

int act3(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 120 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision(HIC"$N收光為暈斂剛成柔，使出了仙劍禁斷之連陽七訣第二式"HIY"『殘陽』"HIC"，瞬間身化殘影落步，劍尖分指$n背心。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIC"$N收光為暈斂剛成柔，使出了仙劍禁斷之連陽七訣第二式"HIY"『殘陽』"HIC"，瞬間身化殘影落步，劍尖分指$n背心。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}

int act4(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 130 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision(HIB"一片昏暗中突見一陣光亮，只見$N身若游光使出月影幻式『新月』，\n劍氣四竄，一流宏大的劍壓曲地逼近$n肩膀。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIB"一片昏暗中突見一陣光亮，只見$N身若游光使出月影幻式『新月』，\n劍氣四竄，一流宏大的劍壓曲地逼近$n肩膀。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}

int act5(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 140 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision(HIC"$N飛身高躍倏然使出了仙劍禁斷之連陽七訣第三式"HIY"『豔陽』"HIC"，劍光如浩日輝煌，筆直落在$n眉心。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      enemy[i]->set_temp("no_power",1);
      enemy[i]->apply_condition("no_power",1);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIC"$N飛身高躍倏然使出了仙劍禁斷之連陽七訣第三式"HIY"『豔陽』"HIC"，劍光如浩日輝煌，筆直落在$n眉心。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}

int act6(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 140 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision(HIB"$N飛身高躍倏然使出了月影幻式『滿月』，劍光如圓月照亮黑暗，直指$n眉心。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      enemy[i]->set_temp("no_power",1);
      enemy[i]->apply_condition("no_power",1);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIB"$N飛身高躍倏然使出了月影幻式『滿月』，劍光如圓月照亮黑暗，直指$n眉心。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}

int act7(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 150 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision(HIC"$N步若游光使出仙劍禁斷之連陽七訣第四式"HIY"『暖陽』"HIC"，劍氣烘燃，一流宏大的劍壓曲地逼近$n。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIC"$N步若游光使出仙劍禁斷之連陽七訣第四式"HIY"『暖陽』"HIC"，劍氣烘燃，一流宏大的劍壓曲地逼近$n。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}

int act8(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 150 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision(HIB"$N撫劍如靜，心靜劍寧，月影幻式『月缺』，$N泛起波波殺意如刃向$n繞流而去。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIB"$N撫劍如靜，心靜劍寧，月影幻式『月缺』，$N泛起波波殺意如刃向$n繞流而去。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}

int act9(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 160 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision(HIC"$N撫劍如靜，心若止水劍光瀲豔，仙劍禁斷之連陽七訣第五式"HIY"『冬陽』"HIC"泛起波波殺意如刃向$n繞流而去。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIC"$N撫劍如靜，心若止水劍光瀲豔，仙劍禁斷之連陽七訣第五式"HIY"『冬陽』"HIC"泛起波波殺意如刃向$n繞流而去。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}


int act10(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 160 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision(HIB"如月之上弦般，$N將手裡的長劍畫出一道半圓，月影幻式『上弦』，劍影破空而下落在$n身上。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIB"如月之上弦般，$N將手裡的長劍畫出一道半圓，月影幻式『上弦』，劍影破空而下落在$n身上。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}
int act11(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 160 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision( HIC"$N耍了個劍花將劍收鞘而入，聚精凝神使出仙劍禁斷之連陽七訣第六式"HIY"『朝陽』"HIC"，只見劍光如晨光乍現劃向$n。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      enemy[i]->start_busy(2);
      enemy[i]->set_temp("no_power",1);
      enemy[i]->apply_condition("no_power",1);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision( HIC"$N耍了個劍花將劍收鞘而入，聚精凝神使出仙劍禁斷之連陽七訣第六式"HIY"『朝陽』"HIC"，只見劍光如晨光乍現劃向$n。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，避過這要命的一招。\n"HIR"在避過殺招之後，由於餘招不斷，$n亦被畫出好幾道傷口。\n"NOR,me,enemy[i]);
      me->add("force",-20);
      enemy[i]->receive_damage("kee",50,me);
      enemy[i]->start_busy(1);
      COMBAT_D->report_status(enemy[i]);
    }
    me->delete_temp("per");
  }
  return 1;
}

int act12(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 170 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision(HIB"如月之下弦般，$N將手中長劍峰迴路轉由下而上畫出半圓劍影，月影幻式『下弦』，\n劍影猶如萬馬奔騰由下而上直奔$n小腹。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIB"如月之下弦般，$N將手中長劍峰迴路轉由下而上畫出半圓劍影，月影幻式『下弦』，\n劍影猶如萬馬奔騰由下而上直奔$n小腹。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}

int act13(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 180 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision( HIC"$N手中緊握的長劍泛出陣陣如暮色般的劍氣，仙劍禁斷之連陽七訣第七式"HIY"『夕陽』"HIC"猶如霞光滿天盡落$n身上。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision( HIC"$N手中緊握的長劍泛出陣陣如暮色般的劍氣，仙劍禁斷之連陽七訣第七式"HIY"『夕陽』"HIC"猶如霞光滿天盡落$n身上。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n"NOR,me,enemy[i]);
      me->add("force",-20);
    }
    me->delete_temp("per");
  }
  return 1;
}

int act14(string msg,object target,object me)
{
  object *enemy;
  int damage,i;
  if(!me || !target) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  damage = 180 + random(me->query_skill("sun_moon_sword"));
  while(i--)
  {
    if( !enemy[i] ) continue;
    if(random(me->query_skill("sun_moon_sword")*10+me->query_skill("dodge"))>random(target->query_skill("dodge")+target->query_skill("parry")))
    {
      me->set_temp("per",1);
      message_vision(HIB"$N將佩劍收入鞘中，身影消失於黑暗中，月影幻式『蝕』，無數道無形殺氣直直逼$n而去。\n"NOR,me,enemy[i]);
      message_vision(HIR"$n閃躲不及，當場被此宏大的劍氣貫穿。\n"NOR,me,enemy[i]);
      me->add("force",-50);
      enemy[i]->receive_damage("kee",damage,me);
      enemy[i]->start_busy(1);
      COMBAT_D->report_status(enemy[i]);
    } else {
      message_vision(HIB"$N將佩劍收入鞘中，身影消失於黑暗中，月影幻式『蝕』，無數道無形殺氣直直逼$n而去。\n"NOR,me,enemy[i]);
      message_vision(HIB"$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，避過這要命的一招。\n"HIR"在避過殺招之後，由於餘招不斷，$n亦被畫出好幾道傷口。\n"NOR,me,enemy[i]);
      me->add("force",-20);
      enemy[i]->receive_damage("kee",50,me);
      COMBAT_D->report_status(enemy[i]);
    }
    me->delete_temp("no_power",1);
    me->delete_condition("no_power");
    me->delete_temp("per");
  }
  return 1;
}
