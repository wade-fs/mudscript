//將receive_damage receive_wound的攻擊參數補上攻擊方之參數 與COMBAT_D->report_status() by blazakira 2011/7/2
//區分狀態的表達方式COMBAT_D->report_status(target) 與 COMBAT_D->report_status(target,1) by blazakira 2011/8/16


#include <command.h>
#include <ansi.h>
#include <combat.h>
#include <skill.h>
inherit F_FUNCTION;
inherit SSERVER;

int fun;

void damage_msg(int damage,object me, object target);
int perform(object me, object target)
{
  int ski_value,damage,i;
  string msg;
  fun=me->query("functions/badroar/level");
  ski_value=random(fun+me->query_skill("badstrike",1))+1;
  damage=ski_value*((fun/10));
  if( !target ) target = offensive_target(me);
  if(!target) return notify_fail("你找不到敵人!!\n");
  if (me->query_skill_mapped("force")!="badforce" || me->query_skill_mapped("unarmed")!="badstrike")
    return notify_fail("不用惡化魔功\和惡霸掌怎能發揮混殺吼的功\力？\n");
  if(!me->is_fighting(target))
    return notify_fail("你又沒在戰鬥，嚇鬼啊!?\n");
  if(me->query_temp("no_roar"))
    return notify_fail("因為蠍毒的作用，你一句話也說不出來。\n");

  if( me->query_skill("badstrike",1) < 30 )
    return notify_fail("沒底子還想唬人，去練練吧！\n");
  if( me->query_skill("badforce",1) < 50 )
    return notify_fail("起碼也要有點氣勢才能嚇人啊，你看看你!!\n");
  if(me->query("force")<300)
    return notify_fail("沒內力，回家吃屎吧！\n");
  if(me->query("quests/badroar") != 1)
    return notify_fail("你在幹嘛啊...亂吼亂吼的...？\n");
  if( me->query("class")!="bandit")
    return notify_fail("你又不怎麼邪惡，怎麼會用這等邪招？\n");
  if( target->is_busy() )
    return notify_fail("敵人 busy 中，快攻擊吧。\n");
  message_vision(HIY"$N"HIY"緊閉雙眼，整個身體散發出不可思議的氣息！\n"NOR,me,target);
  if(me->query_temp("crazy")) {
    i=random(4);
    if(damage>45)
      damage=damage-45;
  }
  else
    i=0;
  if(80>random(100)) {
//2002-12-25 --by kalin:修改k kee的傷害力,不然bandit=廢
    if(ski_value>=175 && me->query("force")>=2500 && !target->query_temp("no_badroar_max") && !me->query_temp("crazy"))
    {
      int force=me->query("force")*4/5;
      me->add("force",-force);
      target->receive_wound("gin",(target->query("gin")*1/3),me);
      target->receive_wound("kee",(target->query("kee")*4/5),me);
      target->receive_wound("sen",(target->query("sen")*1/3),me);
      message_vision(HIW"\n\t$N"HIW"身子忽然一頓，雙手飛舞，步法急轉，"HIC"\n\n\t使出的正是惡人谷不傳絕學----"HIM"天魔亂舞"HIB"\n\n\t但見$N"HIB"趁$n"HIB"正竭力閃躲群魔刀舞時，
"HIY"\n\t倏地轉至$n"HIY"身前，口中不住地唸唸有詞："HIG"\n\n\t\t窮兇惡極，神哭鬼嚎"HIC"\n\n\t使出的正是惡人谷不傳秘訣----"HIM"混沌氣殺"HIW"
\n\t只見$n"HIW"連受$N"HIW"兩大絕技所傷，身體承受不住強大傷害，全身噴出道道血柱！"HIR"
\n\t這招正是惡人極殺技----"MAG"天魔混殺擊"HIR"！\n\n"NOR,me,target);
      write(HIW"你使盡全力使出惡人極殺，感到全身虛弱，毫無力氣。\n"NOR);
      message_vision(RED"$n"RED"中了$N"NOR+RED"的"HIR"天魔混殺擊"RED"，全身鮮血直流!!!!\n"NOR,me,target);
      target->apply_condition("bleeding",10);
      me->set_temp("badroar_maxroar"); //狀態表達的分類紀錄mark而已 by blazakira
    }
    else if ( ski_value < 7 )
    {
      me->add("force",-50);
      write(HIM"你忽然發現苗頭不對，整個身體又像洩了氣的皮球一樣，毫無半分神氣。\n"NOR);
      say( GRN"你看見"+me->query("name")+GRN"的臉忽圓忽扁，臉蛋紅通通的，不禁笑了出來。\n"NOR);
    }
    else if ( ski_value < 30 )
    {
      me->add("force",-100);
      if(i==0)
        target->receive_damage("sen",damage,me);
      else if(i==1)
        target->receive_damage("gin",damage,me);
      else
        target->receive_damage("kee",damage,me);
      write(HIB"你喝然擺\出一付小嘍囉的樣子，試著將對手嚇倒！\n"NOR,me,target);
      say(MAG"你看到了"+me->query("name")+MAG"一付小嘍囉的神態，不禁怔了一下！\n"NOR);
    }
    else if ( ski_value < 60 )
    {
      me->add("force",-150);
      if(i==0)
        target->receive_damage("sen",damage,me);
      else if(i==1)
        target->receive_damage("gin",damage,me);
      else
        target->receive_damage("kee",damage,me);
      write(HIB"你雙手一張，嘴唇微翹，試著用個十足小癟三的模樣唬住對手。\n"NOR,me,target);
      say(MAG"你看到了"+me->query("name")+MAG"那一臉小癟三的神情，不禁被那氣息迷住。\n"NOR);
    }
    else if ( ski_value < 90 )
    {
      me->add("force",-200);
      if(i==0)
        target->receive_damage("sen",damage,me);
      else if(i==1)
        target->receive_damage("gin",damage,me);
      else
        target->receive_damage("kee",damage,me);
      write(HIB"你整個身子一擺\，雙眼微凸，裝出一付土霸王的威勢！\n"NOR,me,target);
      say(MAG"你看到了"+me->query("name")+MAG"那付土霸王的威勢，身上雞皮疙瘩都冒了出來！\n"NOR);
    }
    else if ( ski_value < 120 )
    {
      me->add("force",-250);
      if(i==0)
        target->receive_damage("sen",damage,me);
      else if(i==1)
        target->receive_damage("gin",damage,me);
      else
        target->receive_damage("kee",damage,me);
      write(HIB"你身上殺氣散發，兩眼直瞪對手，那付神情，活像要把對手吃了下去！\n"NOR,me,target);
      say(MAG"你看到了"+me->query("name")+MAG"那付惡貫滿盈的氣勢，不禁冷汗直流，全身發抖!!!!\n"NOR);
    }
    else if ( ski_value < 150 )
    {
      me->add("force",-300);
      if(i==0)
        target->receive_damage("sen",damage,me);
      else if(i==1)
        target->receive_damage("gin",damage,me);
      else
        target->receive_damage("kee",damage,me);
      write(HIB"\n\n\t你將隱藏在你身體中的殺氣悉數放了出來，"HIY"\n\n\t然後用那邪惡的眼神橫掃對手，"HIW"\n\n\t這付邪惡的模樣，彷彿連神，連鬼都要懼怕三分!!!!!!\n\n"NOR,me,target);
      say(MAG"你看到了"+me->query("name")+MAG"那全身的邪氣，不禁為那"HIM"神"RED"鬼"HIW"皆懼"MAG"的樣子嚇的全身無力，毫無作戰意志！\n"NOR);
    }
    else
    {
      me->add("force",-400);
      if(i==0)
        target->receive_damage("sen",damage,me);
      else if(i==1)
        target->receive_damage("gin",damage,me);
      else
        target->receive_damage("kee",damage,me);
      write(HIB"\n\n\t你忽然領悟到"HIW"窮兇惡極，神哭鬼嚎"HIB"的精義"HIC"\n\n\t於是閉眼吸氣，體內真氣及殺氣圍繞在你的四周，\n\n\t看來有如天神下凡般神秘，卻又有如魔鬼出竅般恐怖!!!!"HIY"
\n\t忽然你雙眼一睜，四周氣氛大變，風雨交加!!"HIG"\n\n\t你大喝一聲，一道光芒朝你的對手射去!!!!!!!\n\n"NOR,me,target);
      say(MAG"\n\n\t你看到"+me->query("name")+MAG"那四周的異變，不覺身子已被嚇住，動彈不得"HIR"\n\n\t忽然只看見"+me->query("name")+HIR"雙眼一睜，只覺自己身處地獄深處，又覺自己正站在天堂之中!!"HIM"
\n\n\t忽然又聽見"+me->query("name")+HIM"大喝一聲，心中一怔，你已感到頭昏腦脹，身心俱裂!!!!!!\n\n"NOR);
    }
    //max之外的傷害結果敘述
    if ( ski_value < 7 )
    {
      message_vision(HIW"$N"HIW"跟本嚇唬不了$n"HIW"!!!\n"NOR,me,target);
    }
    else if (damage < 250 )
      message_vision(HIC"$N"HIC"的模樣稍微讓$n"HIC"怔了一下！\n"NOR,me,target);
    else if (damage < 500 )
      message_vision(HIM"$N"HIM"的模樣確實地嚇到了$n"HIM"!!\n"NOR,me,target);
    else if (damage < 750 )
      message_vision(HIB"$n"HIB"被$N"HIB"的壯大氣勢給唬住了!!!\n"NOR,me,target);
    else if (damage < 1000 )
      message_vision(HIY"$n"HIY"感染了$N"HIY"所散發出的王者架勢，嚇的神智不清!!!!\n"NOR,me,target);
    else if (damage < 1250 )
      message_vision(HIG"$N"HIG"所展現的王者風範嚇的$n"HIG"六神無主!!!!!\n"NOR,me,target);
    else if (damage < 1500 )
      message_vision(HIR"結果$n"HIR"彷彿看到惡鬼般，渾身無力，毫無作戰意志!!!!!!\n"NOR,me,target);
    else if (damage < 1750 )
      message_vision(MAG"結果$n"MAG"像是剛從地獄回來般，絲毫提不起精神!!!!!!!\n"NOR,me,target);
    else if (damage < 1950 )
      message_vision(BLU"$n"BLU"被$N"BLU"嚇的魂魄盡失，面貌彷彿老去了一大半!!!!!!!!\n"NOR,me,target);
    else message_vision(RED"$n"RED"被$N"RED"嚇的魂飛魄散，整個人失去了生命力!!!!!!!!!\n"NOR,me,target);
    if(!target->is_busy())
      target->start_busy(2);
    if(me->query_temp("badroar_maxroar")) { //只是要表達給玩家所以在玩家身上設mark就好 避免對手被多位惡人圍毆時 mark重疊的情況　by blazakira
      COMBAT_D->report_status(target,1);
      me->delete_temp("badroar_maxroar");
    }
    else
      COMBAT_D->report_status(target);
  }
  else {
    message_vision(HIW"結果被$n"HIW"閃了過去。\n"NOR,me,target);
  }
  if (fun < 150) {
    if (fun < 100 || random(fun) < 30) {
      function_improved("badroar",random(me->query("max_force")/10));
    }
  }
  else me->set("functions/badroar/level",150);
  me->start_busy(1);
  return 1;
}
