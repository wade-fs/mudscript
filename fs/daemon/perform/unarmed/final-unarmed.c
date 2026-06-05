//final-unarmed 終極拳勢...by chan
//可以隔一個房間攻擊....但是戰鬥中無法使用...
//同一個mob可以用三次.左右.......同時不管沒有沒有成功都算一次..
//使用一次扣內力50%(上限是一萬....扣的越多威力越強....)、精氣神各扣1/3
//只限武者使用,EXP限定在三百萬以上方能使用....
//扣的氣用比率算為700 ~   之間..............
//招式的message由玩家自行設計..只有四招..
//一開始只能lv 0 ~ 20只有一招 20 ~ 40 二招 40~ 60 三招 60 ~ 80 四招...
//相關指令... design_final_skill.c
//相關指令... show_final_skill.c
//解謎..必須要ko fire-king及exp在五百萬以上才能使用......
//戰鬥中不能用所以busy自己也沒有用.所以用完後不busy自己
//將receive_xxx的攻擊參數補上攻擊方之參數 by blazakira 2011/8/22

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, string arg,object victim)
{
  string path,vipath,roompath,msg;
  int value,use,skee,damage=500,sforce,fun;
  if(me->query("class") != "fighter")
   return notify_fail("只有武者可以用!!!!\n");
  if(!victim) return notify_fail("你要打誰???\n");
  if(!environment(victim)) return notify_fail("你要打那裡??\n");
  vipath=file_name(environment(victim));
  if(me->query("combat_exp") < 5000000)
    return notify_fail("你的武學程度無法使用終極拳勢!!\n");
  if(me->query("kee") < (me->query("max_kee") / 3))
    return notify_fail("你的氣不夠了.....\n");
  if(me->query("atman") <(me->query("max_atman") /3))
    return notify_fail("你的靈力不夠了.....\n");
  if(me->query("mana") <(me->query("max_mana") /3))
    return notify_fail("你的法力不夠了.....\n");
  if(me->query("force") < (me->query("max_force") /2))
    return notify_fail("你的內力不夠!!!\n");
  if(victim->query_temp("final-attack") > 2)
    return notify_fail("對同一個人只能使用三次.....\n");
  if( !me->query("final/ko_king"))
    return notify_fail("你並沒有資格使用終極拳勢!!!!\n");
  if(me->is_fighting(victim))
    return notify_fail("戰鬥中無法使用!!!!!\n");
  roompath=environment(me)->query("exits/"+arg);
  if(!roompath) return notify_fail("方向好像不大對!!\n");
  if(me->query("env/test_final")){
    printf("%s\t%s\n",vipath,roompath);
  }
  if(vipath[sizeof(vipath)-2..sizeof(vipath)-1]!=".c") vipath+=".c";
  if(roompath[sizeof(roompath)-2..sizeof(roompath)-1]!=".c") roompath+=".c";
  if( vipath != roompath) //表示在相鄰的房間......
    return notify_fail("敵人不在附近的區域.....\n");
  value = me->query("functions/final-unarmed/level");
  value = value / 20;
  value = random(value)+1; //用亂數來找出所設計的message....
  if(value > 4)
    value = 4;
  path = sprintf("%d",value);
  if(!me->query("final/action"+path))
    return notify_fail("尚有招式尚未設計!!!無法使用!!!\n");
  msg=me->query("final/action"+path);
  switch(value) //四招強度、特功、作用不同.....
  {
    case 1: //第一招強力攻擊.....加上內傷
      printf("\n");
      message_vision(msg,me,victim); //送出message.....
      skee=me->query("max_atman") / 5;
      me->add("atman",-skee);
      skee=me->query("max_mana") / 5;
      me->add("mana",-skee);
      skee=me->query("max_kee") / 5;
      me->add("kee",-skee); //氣精氣先扣1/5
      sforce=me->query("force") / 2;
      if(sforce > 100000) //這是秘密wiz.不準說出去....
        sforce = 100000;
      me->add("force",-sforce);
      fun = me->query("functions/final-unarmed/level")*10;
      damage=damage+skee+(sforce/200)+fun;//其中500是基本的,加上扣的kee 及force /50 +fun*10
      //若以kee 6000 force 10萬來算及fun 100..扣的kee為 500 + 1200 + 1000 + 500 = 3200
      if(fun > random(2000)) //這太強了.所以上限是50%就是一半.的機率,初期只有10% grin...
      {
        message_vision(HIR + "$n被$N的凌厲氣勁所擊中,頓時全身血脈爆開!!撒出無數的血雨!!!\n" + NOR,me,victim);
        victim->receive_wound("kee",damage,me);
        COMBAT_D->report_status(victim,1);
        victim->apply_condition("star-stial",random(10));
        //增加打中的成功次數
        victim->add_temp("final-attack-hit",1);
      }
      else {
        message_vision(HIW + "$n看出$N所發出的猛烈氣勁軌道,急駛輕功\躲過了致命一擊!!\n" + NOR,me,victim);
        COMBAT_D->report_status(victim);
      }
      break;
    case 2: //強力攻擊外外加讓對方force enforce 變 0 加上 內傷
      printf("\n");
      message_vision(msg,me,victim);  //送出message.....
      skee=me->query("max_atman") / 4;
      me->add("atman",-skee);
      skee=me->query("max_mana") / 4;
      me->add("mana",-skee);
      skee=me->query("max_kee") / 4;
      me->add("kee",-skee); //氣精氣先扣1/4
      sforce=me->query("force") / 2;
      if(sforce > 100000) //這是秘密wiz.不準說出去....
        sforce = 100000;
      me->add("force",-sforce);
      fun = me->query("functions/final-unarmed/level")*10;
      damage=damage+skee+(sforce/200)+fun;//其中500是基本的,加上扣的kee及force /50 +fun*10
      //若以kee 6000 force 10萬來算及fun 100..扣的kee為 500 + 1200 + 1000 + 500 = 3500
      if(fun > random(2000)) //這太強了.所以上限是50%就是一半.的機率,初期只有10% grin...
      {
        message_vision(HIR + "$n被$N的凌厲氣勁所擊中,頓時全身血脈爆開!!撒出無數的血雨!!!\n" + NOR,me,victim);
        message_vision(HIC + "$N的凌厲氣勁在$n四周形成無數的氣旋瞬間$n的內力完全流失掉!!!\n" + NOR,me,victim);
        victim->receive_wound("kee",damage,me);
        COMBAT_D->report_status(victim,1);
        victim->apply_condition("star-stial",random(10));
        victim->set("force_factor",0);
        victim->set("force",0);
        //增加打中的成功次數
        victim->add_temp("final-attack-hit",1);
      }
      else {
        message_vision(HIW + "$n看出$N所發出的猛烈氣勁軌道,急駛輕功\躲過了致命一擊!!\n" + NOR,me,victim);
        message_vision(HIC + "$N的凌厲氣勁在$n四周形成無數的氣旋瞬間$n的內力完全流失掉!!!\n" + NOR,me,victim);
        victim->set("force",0);
        COMBAT_D->report_status(victim);
      }
      break;
    case 3: //強力攻擊外外加讓對方force enforce 變 0 及perform 無法使用 加上內傷
      printf("\n");
      message_vision(msg,me,victim); //送出message.....
      skee=me->query("max_atman") / 4;
      me->add("atman",-skee);
      skee=me->query("max_mana") / 4;
      me->add("mana",-skee);
      skee=me->query("max_kee") / 4;
      me->add("kee",-skee); //氣精氣先扣1/4
      sforce=me->query("force") / 2;
      if(sforce > 100000) //這是秘密wiz.不準說出去....
        sforce = 100000;
      me->add("force",-sforce); //內力在扣....
      fun = me->query("functions/final-unarmed/level")*10;
      damage=damage+skee+(sforce/200)+fun; //其中500是基本的,加上扣的kee及force /50 +fun*10
      //若以kee 6000 force 10萬來算及fun 100..扣的kee為 500 + 1200 + 1000 + 500 = 3500
      if(fun > random(2000)) //這太強了.所以上限是50%就是一半.的機率,初期只有10% grin...
      {
        message_vision(HIR + "$n被$N的凌厲氣勁所擊中,頓時全身血脈爆開!!撒出無數的血雨!!!\n" + NOR,me,victim);
        message_vision(HIC + "$N的凌厲氣勁在$n四周形成無數的氣旋瞬間$n的內力完全流失掉!!!\n" + NOR,me,victim);
        message_vision(HIW + "$N的凌厲氣勁在$n四周形成龐大的龍捲風$n的感覺自己無法在自由地使用絕學!!!\n" + NOR,me,victim);
        victim->receive_wound("kee",damage,me);
        COMBAT_D->report_status(victim,1);
        victim->set_temp("no_power_f",1);
        victim->apply_condition("no_power_f",random(5));
        victim->apply_condition("star-stial",random(10));
        victim->set("force_factor",0);
        victim->set("force",0);
        //增加打中的成功次數
        victim->add_temp("final-attack-hit",1);
      }
      else {
        message_vision(HIW + "$n看出$N所發出的猛烈氣勁軌道,急駛輕功\躲過了致命一擊!!\n" + NOR,me,victim);
        message_vision(HIC + "$N的凌厲氣勁在$n四周形成無數的氣旋瞬間$n的內力完全流失掉!!!\n" + NOR,me,victim);
        message_vision(HIW + "$N的凌厲氣勁在$n四周形成龐大的龍捲風$n的感覺自己無法在自由地使用絕學!!!\n" + NOR,me,victim);
        victim->set("force",0);
        victim->set_temp("no_power_f",1);
        victim->apply_condition("no_power_f",random(5));
        COMBAT_D->report_status(victim);
      }
      break;
    case 4: //強力攻擊外外加讓對方force enforce 變 0 及perform exert 無法使用..加上內傷
      printf("\n");
      message_vision(msg,me,victim); //送出message.....
      skee=me->query("max_atman") / 3;
      me->add("atman",-skee);
      skee=me->query("max_mana") / 3;
      me->add("mana",-skee);
      skee=me->query("max_kee") / 3;
      me->add("kee",-skee); //氣精氣先扣1/4
      sforce=me->query("force") / 2;
      if(sforce > 100000) //這是秘密wiz.不準說出去....
        sforce = 100000;
      me->add("force",-sforce); //內力在扣....
      fun = me->query("functions/final-unarmed/level")*10;
      damage=damage+skee+(sforce/200)+fun; //其中500是基本的,加上扣的kee及force /50 +fun*10
      //若以kee 6000 force 10萬來算及fun 100..扣的kee為 500 + 2000 + 1000 + 500 = 4000
      if(fun > random(2000))//這太強了.所以上限是50%就是一半.的機率,初期只有10% grin...
      {
        message_vision(HIR + "$n被$N的凌厲氣勁所擊中,頓時全身血脈爆開!!撒出無數的血雨!!!\n" + NOR,me,victim);
        message_vision(HIC + "$N的凌厲氣勁在$n四周形成無數的氣旋瞬間$n的內力完全流失掉!!!\n" + NOR,me,victim);
        message_vision(HIW + "$N的凌厲氣勁在$n四周形成龐大的龍捲風$n的感覺自己無法在自由地使用絕學!!!\n" + NOR,me,victim);
        message_vision(MAG + "$n的護身氣勁被$N凌厲氣旋所破!!$n感覺真氣被氣旋所擾無法正常運行!!\n" + NOR,me,victim);
        victim->receive_wound("kee",damage,me);
        COMBAT_D->report_status(victim,1);
        victim->set_temp("no_power_f",1);
        victim->set_temp("no_power_e",1);
        victim->apply_condition("no_power_f",random(5));
        victim->apply_condition("no_power_e",random(5));
        victim->apply_condition("star-stial",random(10));
        victim->set("force_factor",0);
        victim->set("force",0);
        //增加打中的成功次數
        victim->add_temp("final-attack-hit",1);
      }
      else {
        message_vision(HIW + "$n看出$N所發出的猛烈氣勁軌道,急駛輕功\躲過了致命一擊!!\n" + NOR,me,victim);
        message_vision(HIC + "$N的凌厲氣勁在$n四周形成無數的氣旋瞬間$n的內力完全流失掉!!!\n" + NOR,me,victim);
        message_vision(HIW + "$N的凌厲氣勁在$n四周形成龐大的龍捲風$n的感覺自己無法在自由地使用絕學!!!\n" + NOR,me,victim);
        message_vision(MAG + "$n的護身氣勁被$N凌厲氣旋所破!!$n感覺真氣被氣旋所擾無法正常運行!!\n" + NOR,me,victim);
        victim->set("force",0);
        victim->set_temp("no_power_f",1);
        victim->set_temp("no_power_e",1);
        victim->apply_condition("no_power_f",random(2));
        victim->apply_condition("no_power_e",random(2));
        COMBAT_D->report_status(victim);
      }
      COMBAT_D->report_status(me);
      break;
  }
  message_vision(HIR + "$N使出終極拳勢後感覺精、氣、神及全身功\力耗盡!!趕快查看自己的傷勢!!\n" + NOR,me);
  COMBAT_D->report_status(me);
  if(me->query("functions/final-unarmed/level") < 100)
    function_improved("final-unarmed",random(me->query("max_force")/25));
  victim->add_temp("final-attack",1);
  return 1;
}
