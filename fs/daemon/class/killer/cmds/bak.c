//排版 by blazakira 2011/10/8

#include <ansi.h>
inherit F_GUILDCMDS;

void do_kill(object me,object target);
void do_fkill(object me,object target);

int main(object me, string arg)
{
  object env, target, weapon1, weapon2;
  object *inv;
  int i;
  env = environment(me);

  if( arg=="vis" ) {
    if( !me->query_temp("invis") )
      return notify_fail("幹嘛？你又沒在藏起來。\n");
    message_vision(HIY + "$N從房間的角落中走了出來。\n" + NOR,me,target);
    me->delete_temp("invis");
  }
  if( arg=="invis" ) {
    if( me->query_temp("invis") ) {
      return notify_fail("你不是已經藏起來了嗎？\n");
    }
    if( me->is_fighting() ) { //避免連續藏匿背刺！
      return notify_fail("媽的，戰鬥中，人家看著你，你藏個屁呀！\n"); }

    inv = all_inventory(env);
    for( i=0; i<sizeof(inv); i++ ) {
      if( userp(inv[i]) && inv[i]!=me )
        return notify_fail("這裡還有別人在，現在藏匿會被發現的。\n");
    }
    tell_object(me,HIY + "你找到一個隱密的角落，藏匿了起來。\n" + NOR);
    me->set_temp("invis",1); 
  } 
  if( arg == "vis" || arg == "invis" ) return 1;
  if( !arg || arg=="") return notify_fail("請 help bak 觀看指令格式。\n");
  target=present(arg,environment(this_player()));
  if(!target) {
    write(HIC+"這裡沒有 "+arg+" 這個人喔。\n"+NOR);
    return 1;
  }

  if( (!(weapon1= me->query_temp("weapon")) ||
      (string)weapon1->query("skill_type") != "dagger") &&
      (!(weapon2= me->query_temp("secondary_weapon")) ||
      (string)weapon2->query("skill_type") != "dagger") ) {
    return notify_fail(HIY + "你沒拿匕首，沒有辦法刺殺敵人。\n" + NOR);
    return 1;
  }
  if( environment(me)->query("no_fight") ) {
    return notify_fail(HIY + "這裡不准戰鬥。\n" + NOR);
  }
  if(wizardp(target) && !wizardp(me)) {
    return notify_fail(HIY + "傻孩子，你打不贏巫師的。\n" + NOR);
  }
  if(target==me) return notify_fail (HIY + "要刺殺自己，你瘋啦。\n" + NOR);
  call_out("do_kill", 1, me, target);
  call_out("do_fkill", 1, me, target);
  return 1;
}

void do_kill(object me,object target)
{
  object env, weapon;
  object *inv;
  int i;
  if(!me || !target) return ;
  if( !me->is_fighting() && target->query("kee") > 0 ) {     
    if( !me->query_temp("invis") ) {
      tell_object(me,HIY + "你沒藏匿起來，會被發現的。\n" + NOR);
      return 0;
    }
    if( me->query("max_sen")!=me->query("sen") ) {
      tell_object(me,HIY + "你沒有足夠的神，去做再一次的刺殺。\n" + NOR);
      return 0;
    }
    if( target !=me )
    {
      message_vision(HIC+"$N偷偷摸摸地走到$n背後。\n"+NOR,me,target);
      if(random(10) > 2)
      {
        switch(random(3))
        {
          case 0:
            message_vision(HIW+"\n$N以極快的速度，瞄準$n用力一刺，使$n受到極大的傷害。\n"+NOR,me,target);     
            target->receive_wound("kee", (int)target->query("max_kee")*20/100,me);
            break;
          case 1:
            message_vision(HIW+"\n$N對著$n的背部狠狠一捅，使$n血流不止。\n"+NOR,me,target);
            target->receive_wound("kee", (int)target->query("max_kee")*15/100,me);
            break;
          case 2:
            message_vision(HIW+"\n$N無聲無息的以暗器手法，把匕首往$n身上一扔，使$n受到極大的打擊。\n"+NOR,me,target);
            target->receive_wound("kee", (int)target->query("max_kee")*25/100,me);
            break;
        }
        COMBAT_D->report_status(target,1);
        message_vision(HIR+"\n$n見身上插著$N的匕首，忿怒地想殺死$N。\n"+NOR,me,target);

        // 雙手武器  以副為先
        if( weapon=me->query_temp("secondary_weapon") )
        {
          weapon=me->query_temp("secondary_weapon");
        }
        else {
          weapon=me->query_temp("weapon");
        }

        weapon->unequip();
        weapon->move(target);

        //改變名字 
        if( weapon->query("BAK")!="USED" ) {
          weapon->set("name","染血的"+weapon->name()+"");
        }

        //每用一次 武器就變壞       
        if( weapon->query("weapon_prop/damage") >= 3 )
        {
          weapon->add("weapon_prop/damage", -3 );
        }
        else {
          weapon->set("value", 0 );
          weapon->set("no_sell",1);
          weapon->set("weapon_prop", 0);
        }

        weapon->set("BAK","USED");
        me->reset_action();
        me->kill_ob(target);
        target->kill_ob(me);
        me->delete_temp("invis");
        me->receive_damage("sen", (int)me->query("sen")/10,me);
        target->apply_condition("bleeding",random(10)+1);
        COMBAT_D->report_status(target);
      }
      else {
        message_vision(HIW+"\n$n突然發現了$N的存在，使$N找不到下手的機會。\n"+NOR,me,target);
        me->add("sen",-10);
        me->delete_temp("invis");
      }
    }
  }
}

void do_fkill(object me,object target)
{
  object env, weapon;
  object *inv;
  int i, bel;
  if(!me || !target) return ;
  bel=(int)me->query("bellicosity");
// 由於現在能賭殺氣又殺手賭殺氣輸還能用 cmd bc 所以
// 殺手殺氣都能賭無限且只要殺氣超過10萬以上都有必殺
// 能力故設限  By Swy
  if( bel > 30000 ) bel=30000;
  if( me->is_fighting(target) )
  {
    if( bel < 20 ) {
      tell_object(me,HIY + "你的殺氣不夠喔！\n" + NOR);
      return 0;
    }
    if( me->query("force") < 20 ) {
      tell_object(me,HIY + "你的內力不夠喔！\n" + NOR);
      return 0;
    }
    if( me->is_busy() ) {
      tell_object(me,HIY + "你的還沒有準備好做下一波的刺殺。\n" + NOR);
      return 0;
    }

    if(target !=me )
    {
      message_vision(HIM+"\n$N拿匕首，見人就刺。\n"+NOR,me,target);
      if (  random(10) > 2 ) {
        switch(random(3))
        {
          case 0:
            message_vision(HIW+"$N對著$n瘋狂的大叫～殺殺殺～，連續往$n身上亂刺去。\n"+NOR,me,target);
            target->receive_wound("kee",bel/25,me);
            me->add("force",-20);
            break;
          case 1:
            message_vision(HIW+"$N大喝一聲～殺ㄚ～對$n快速衝過去，胡亂地對$n刺了幾下。\n"+NOR,me,target);
            target->receive_wound("kee",bel/20,me);
            me->add("force",-20);
            break; 
          case 2:
            message_vision(HIW+"$N眼露兇光，猛地對準$n直戳過去，口中還～哈哈～大笑著。\n"+NOR,me,target);
            target->receive_wound("kee",bel/15,me);
            me->add("force",-20);
            break;
        }
        COMBAT_D->report_status(target,1);
        me->start_busy(random(3)); 
      }
      else {
        message_vision(HIW+"\n$n側身一躲，$N的刺殺被$n閃過了。\n"+NOR,me,target);
        me->add("force",-20);
        inv = all_inventory(environment(target));

        for(i=0;i<sizeof(inv);i++)
        {
          if(inv[i]->is_character() && inv[i]!=target && inv[i]!= me 
          && !inv[i]->is_corpse() && inv[i]->query("id")!=me->query("sub_id")
          && inv[i]->query("sub_id")!=me->query("id")  )
          {
            if(random(2)==0)
            {
              target = inv[i];
              message_vision(HIC+"$N刺中了在旁邊觀看熱鬧的的$n。\n"+NOR,me,target);
              message_vision(HIC+"$n告訴$N說道：可惡！竟敢打我，我要你出代價。\n"+NOR,me,target);
              target->receive_wound("kee",bel/25,me);
              COMBAT_D->report_status(target,1);
              target->fight_ob(me);
            }
          }
        }
      }
    }
  }
  if(!target) return ;
  if ( (int)target->query("kee") < 0  )
    target->die();
}

int help(object me)
{
  write(@HELP

指令格式： cmd bak [敵人 | invis | vis]

說明： cmd bak [invis]
       可以使你藏匿起來，但只能藏在這個房間，若走動就消失。
       cmd bak [vis]
       在同一個房間可以使你取消藏匿，也可走動就取消。
       cmd bak [敵人]
       可以讓你刺殺敵人，又可分為兩種:
     1.一種為要藏匿後刺殺，須在沒有戰鬥中使用，此將使敵人受到極大的創傷
       且武器會留在敵人身上，但武器耐用度會減少，可使敵人血流不止。
     2.另為戰鬥中瘋狂刺殺，不須藏匿，需要殺氣和內力夠，此威力小很多，但若有
       旁觀者在的話小心刺中他ㄛ，他也會來打你的ㄛ。

       *修正版--可以雙手拿不同的武器使用背刺 但其中一支須為匕首*
HELP);
  return 1;
}
