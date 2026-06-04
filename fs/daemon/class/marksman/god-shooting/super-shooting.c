//射手遠距攻擊  by frequency  2003  June
//合併victim->receive_damage("kee",hurt); 與 victim->set_temp("last_damage_from",me); by blazakira 2011/10/19

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, string arg,object victim)
{
  int fun,skill,hurt,a,b,c;
  object ob;
  victim = me->query_temp("mark_goal");
  if(me->query("class") != "marksman")
    return notify_fail("你會射箭嗎!!\n");
  if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type")!="archery" || ob->query("arrow/amount") < 1100)
    return notify_fail("要裝備弓和足量的箭才能用吧。\n");
  if(!victim) 
    return notify_fail("射射射...你要射誰??\n");
  if(me->query_skill("archery") < 120)
    return notify_fail("你的射擊技巧還太差，射了也是白射。\n");
  if(me->query("force") < (me->query("max_force") /2))
    return notify_fail("你的內力不夠!!\n");
  if(me->is_fighting())
    return notify_fail("戰鬥中哪來時間讓你聚精會神瞄準!?\n");
  if(victim->is_ghost())
  {
    me->delete_temp("mark_goal");
    return notify_fail("對方已經在地獄了，放過他吧。\n");
  }
  fun = me->query("functions/super-shooting/level");
  skill = me->query_skill("archery");
  hurt = (fun + skill)*2;
  a = random(1+(fun/25));

  if(me->query_cps() < random(50)) //遠距攻擊所以命中率要比一般function稍低
  {
    message_vision(GRN + "\n$n完全識破$N的發箭意圖，以驚世身法閃過千百箭雨。\n" + NOR,me,victim);
    victim->add_temp("be_shooted",1);
  } else {
    if(a == 0)
    {
      message_vision(HIY + "\n$N搭上"+ob->query("arrow/name")+"" + HIY + "，將手中"+ob->query("name")+"" + HIY + "的弦拉滿，冰心訣內勁緩緩灌注，

" + HIC + "推動" + HIR + "【" + HIW + "流星箭訣" + HIR + "】" + HIC + "的失傳古武流" + HIR + "《" + HIG + "飛蝗流羽" + HIR + "》

" + HIB + "數十道，不，數百道"+ob->query("arrow/name")+"" + HIB + "挾著驚天氣勢朝遠空飛去。\n\n\n" + NOR,me,victim);

      b = 1 + random(3);
      for(c=0;c < b;c++)
      {
        message_vision(HIR + "$n乍見數百"+ob->query("arrow/name")+"" + HIR + "迎面射來，完全不明所以然，接二連三的中箭了。\n" + NOR,me,victim);
        victim->receive_damage("kee",hurt,me);
//        victim->set_temp("last_damage_from",me);
        COMBAT_D->report_status(victim);
      }
      victim->add_temp("be_shooted",1);
      ob->set("arrow/amount",ob->query("arrow/amount")-200);
    } else if ( a == 1)
    {
      message_vision(HIY + "\n$N搭上"+ob->query("arrow/name")+"" + HIY + "，將手中"+ob->query("name")+"" + HIY + "的弦拉滿，冰心訣內勁緩緩灌注，

" + HIG + "推動" + HIR + "【" + HIW + "流星箭訣" + HIR + "】" + HIG + "的失傳古武流" + HIR + "《" + HIB + "轅門射戢" + HIR + "》

" + HIM + "聚精會神的一箭射出，直指$n項上首級。\n\n\n" + NOR,me,victim);

      message_vision(HIR + "$n避無可避，以畢生修為硬擋"+ob->query("arrow/name")+"" + HIR + "，雖成功\截下，卻耗力過鉅。無法動彈。\n" + NOR,me,victim);
      victim->start_busy(2);
      victim->add_temp("be_shooted",1);
      COMBAT_D->report_status(victim);
      ob->set("arrow/amount",ob->query("arrow/amount")-1);
    } else if ( a == 2)
    {
      message_vision(HIY + "\n$N搭上"+ob->query("arrow/name")+"" + HIY + "，將手中"+ob->query("name")+"" + HIY + "的弦拉滿，冰心訣內勁緩緩灌注，

" + HIM + "推動" + HIR + "【" + HIW + "流星箭訣" + HIR + "】" + HIM + "的失傳古武流" + HIR + "《" + HIC + "流星趕月" + HIR + "》

" + HIG + "璀璨的箭雨逐漸消失於長空，留下逐漸模糊的美麗死亡輪廓。\n\n\n" + NOR,me,victim);

      b = 1 + random(5);
      for(c=0;c < b;c++)
      {
        message_vision(HIR + "$n乍見數百"+ob->query("arrow/name")+"" + HIR + "迎面射來，完全不明所以然，接二連三的中箭了。\n" + NOR,me,victim);
        victim->receive_damage("kee",hurt,me);
//        victim->set_temp("last_damage_from",me);
        COMBAT_D->report_status(victim);
      }
      victim->add_temp("be_shooted",1);
      ob->set("arrow/amount",ob->query("arrow/amount")-300);
    } else if ( a == 3)
    {
      message_vision(HIY + "\n$N搭上"+ob->query("arrow/name")+"" + HIY + "，將手中"+ob->query("name")+"" + HIY + "的弦拉滿，冰心訣內勁緩緩灌注，

" + HIG + "推動" + HIR + "【" + HIW + "流星箭訣" + HIR + "】" + HIG + "的失傳古武流" + HIR + "《" + HIM + "鳳舞九天" + HIR + "》

" + HIB + "數千枝"+ob->query("arrow/name")+"" + HIB + "直衝天庭，接著無匹箭氣引首，如暴雨般射向$n。\n\n\n" + NOR,me,victim);

      b = 1 + random(9);
      for(c=0;c < b;c++)
      {
        message_vision(HIR + "$n乍見數千"+ob->query("arrow/name")+"" + HIR + "迎面射來，完全不明所以然，照單全收。\n" + NOR,me,victim);
        victim->receive_damage("kee",hurt,me);
//        victim->set_temp("last_damage_from",me);
        COMBAT_D->report_status(victim);
      }
      victim->add_temp("be_shooted",1);
      ob->set("arrow/amount",ob->query("arrow/amount")-1000);
    } else {
      message_vision(HIY + "\n$N搭上"+ob->query("arrow/name")+"" + HIY + "，將手中"+ob->query("name")+"" + HIY + "的弦拉滿，冰心訣內勁緩緩灌注，

" + HIB + "推動" + HIR + "【" + HIW + "流星箭訣" + HIR + "】" + HIB + "的失傳古武流" + HIR + "《" + HIC + "箭嘯神州" + HIR + "》

" + HIG + "凝聚冰心訣凍氣的一箭，「嘯」一聲巨響，石破天驚般劃破長空而去。\n\n\n" + NOR,me,victim);

      message_vision(HIR + "$n乍見驚人箭氣襲來，完全不明所以然，遭強大箭氣貫體而過。\n" + NOR,me,victim);
      victim->receive_damage("kee",hurt*7,me);
//      victim->set_temp("last_damage_from",me);
      victim->add_temp("be_shooted",1);
      COMBAT_D->report_status(victim);
      ob->set("arrow/amount",ob->query("arrow/amount")-1);
    }
  }
  message_vision(HIW + "\n瘋狂發箭之後，$N受到流星箭訣強大的後作力衝擊，委頓在地，久久無法動彈。\n\n" + NOR,me);
  me->start_busy(random(2)+1);
  me->receive_damage("kee",10,me);
  me->add("force",-400);
  COMBAT_D->report_status(me);
  if(victim->query_temp("be_shooted") > 5 && victim->query_temp("be_shooted") > random(20))
  {
    message_vision(HIB + "\n$n再也無法忍受$N的牽制，憤而以畢生功\力將$N隔空強拉至面前，展開猛烈攻擊。\n\n" + NOR,me,victim);
    me->move(environment(victim));
    victim->kill_ob(me);
    victim->delete_temp("be_shooted");
    victim->delete_temp("marked");
    me->delete_temp("mark");
    me->delete_temp("mark_goal");
  }
  if(me->query("functions/super-shooting/level") < 100)
  {
    if(me->query("marksman/punch_rock") == 1)
    {
      function_improved("super-shooting",200+random(200));
    } else {
      function_improved("super-shooting",random(200));
    }
  }
  return 1;
}
