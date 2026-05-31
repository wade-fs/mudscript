#include <combat.h>
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
object ob = me->query_temp("weapon");
int funlv,forlv,hit,damage,kar,h,k = me->query("kee");
k = k%3;
kar = me->query_kar();
if(kar > 35) kar = 35;
funlv=me->query_function("ghost-sword",1);
forlv=me->query("force");
hit=0;
damage;
if(!ob || (string)ob->query("skill_type") != "sword")
return notify_fail("你沒拿劍喔．\n");
if( !target ) target = offensive_target(me);
if(me->query("class")!="bandit")
return notify_fail("你不是惡人所以不能用。\n");
if( me->query_skill("badsword",1) < 30 ) 
 return notify_fail("你的魔日劍法還不夠精純，無沒使出魔日斬。\n" NOR);
if( !target || !target->is_character() || !me->is_fighting(target) )
 return notify_fail("魔日斬只能在戰鬥中使用。\n");
if(me->query("force")<200)
 return notify_fail("你的內力不夠。\n");
if(me->query("kee")<250)
 return notify_fail("你的氣不夠。\n");

message_vision(HIG"$N"HIY"縱身一躍，將全身功\力集中於劍尖，憑空發出一擊。"HIR"
\n\t☆  "BYEL+HIW"魔"NOR"  "BYEL+HIW"日"NOR"  "BYEL+HIW"斬"NOR+HIR"  ☆\n\n"NOR,me);

if(8 > random(10))
        {
/*
if((funlv >= 85 && random(kar) > random(target->query_kar())) || me->query("id") == "frequency")
{
  message_vision(HIW"\n$N劍尖朝天，將全身魔勁解放，和烈日相互輝映，迫出魔日劍法最霸道一式：
  
    
\t"HIB"魔  "HIY"日  "HIM"邪  "HIR"陽  "HIG"殺\n\n"NOR,me,target);
  for(h=0;h<=k;h++)
  {
    forlv = forlv%3;
    //message_vision("k = "+k+",h = "+h+",forlv = "+forlv+"。\n"NOR,me);
    if(forlv == 0)
                 {
                   message_vision(HIC"魔氣如飛瀑般，挾著驚人氣勢朝$N飛撲而來。
"HIB"$N靈覺受到詭暗魔氣的侵襲，全身靈力不斷被強壓直下。\n"NOR,target);
                   target->set("atman",(target->query("atman"))/5);
                 }
    else if(forlv == 1)
                 {
                   message_vision(HIY"劍芒如飛瀑般，挾著驚人氣勢朝$N飛撲而來。
"YEL"$N丹田受到鋒銳劍芒的衝擊，全身內勁向體外狂洩而去。\n"NOR,target);
                   target->set("force",(target->query("force"))/4);
                 }
    else if(forlv == 2)
                 {
                   message_vision(HIR"陽炎如飛瀑般，挾著驚人氣勢朝$N飛撲而來。
"RED"$N神魂受到邪異陽炎的灼烙，全身法力源源不絕的蒸發。\n"NOR,target);
                   target->set("mana",(target->query("mana"))/5);
                 }
    forlv = forlv + 1;
  }
  me->add("kee",-1);
  me->add("force",-200);
}*/
           message_vision(RED"$n反應不及，"BYEL+HIW"魔日斬"RED"已盡數貫穿$n的身體。\n" NOR,me,target);
           damage = random(forlv*2) + funlv;
   if (damage > 800) {damage = 800;}
        target->receive_wound("kee",damage);
        me->add("force",-100);
        hit=1;
        } 
        else {
              message_vision(NOR "$n在危急時刻猛然一躍，機靈的躲開了"BYEL+HIW"魔日斬"NOR"。\n",me,target);
             }
        me->start_busy(1);
        if (funlv < 100)
        me->function_improved("ghost-sword", funlv * 2 + random(100));
        if(hit==1) COMBAT_D->report_status(target);

        return 1;
}

