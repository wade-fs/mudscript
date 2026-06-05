//專門修正給npc使用的版本  by Neverend
#include <command.h>
#include <ansi.h>
#include <combat.h>
#include <skill.h>
inherit F_FUNCTION;
inherit SSERVER;
void damage_msg(int damage,object me, object target); 
int perform(object me, object target)
{
       string msg;
       int ski_value, max_lv, a, i, b, damage, fun;
       ski_value= random(me->query_skill("rain-throwing",1));
       max_lv=me->query_skill("rain-throwing",1);
        fun=me->query("functions/manakee/level");

   if( !target ) target = offensive_target(me);

   if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『魔氣殺』只能對戰鬥中的對手使用。\n");

  if( target->is_busy() )
 return notify_fail(""+BOLD+"你的殺氣正纏著敵人,一時無法再凝聚強大殺氣!"+NOR+"\n");

	if( !me->query("can_use_mobkee") )
	return notify_fail("你想作啥呀？\n");

   damage=target->query("max_kee")*4*ski_value/1000;
  if (damage > 1000) damage=1000;
    me->add("bellicosity",-(ski_value/5));

       message_vision(""+HIR+"$N自殘己身,以殺意換成魔氣。"+NOR+"\n
            "+GRN+"……$N身上發出一股強大的魔氣……"+NOR+"\n
    "+HIG+"■$N身上魔氣逐漸地聚集在雙手,在雙手上形成兩團殺氣■"+NOR+"\n
            $N倏地大喝一聲––"+HIC+"『魔氣殺』"+NOR+"––\n\n",me,target);

     if( ski_value == random(max_lv) && target->query_temp("no_die_soon")!=1){
      message_vision(""+RED+"$N突然喉頭一動～～　"+MAG+"只見$N口中噴出一道血柱往"+target->query("name")+"射去～～"+NOR+"\n
"+HIB+"$N使的乃魔氣殺之"+NOR+"
              "+BLU+"終極～必殺奧義"+NOR+" 『"+HIY+"魔血氣殺"+NOR+"』\n
"+HBGRN+""+target->query("name")+"慘遭滅頂,但$N也支持不住了。"+NOR+"\n",me,target);
     target->receive_damage("kee", damage*3,me);

function_improved ("manakee", random(me->query_skill("rain-throwing",1))*3);
return 1;
     }
       
    else if( ski_value < 10 ){
      msg =""+HIY+"$N的殺意轉換魔氣失敗。\n\n";
  me->add("kee",-50);
                        }
 
    else if( ski_value <  20 ){
     msg = "第一層 『"+HIY+"魔氣無常"+NOR+"』。\n\n";
     target->start_busy(random(fun/75)+1 );
     target->receive_damage("kee", damage,me);
  me->add("kee",-100);
                       }
    
    else if( ski_value <  30 ){
     msg = "第二層 『"+HIY+"火魔煞神"+NOR+"』。\n\n";
     target->start_busy(random(fun/70)+1 );
     target->receive_damage("kee", damage,me);
  me->add("kee",-100);
                       }

     else  if( ski_value < 40 ){
     msg = "第三層 『"+HIY+"商魂魔身"+NOR+"』。\n\n";
     target->start_busy(random(fun/65)+1 );
     target->receive_damage("kee", damage,me);
  me->add("kee",-100);
                       }

     else if( ski_value <  50 ){
     msg = "第四層 『"+HIY+"劍魔滅世"+NOR+"』。\n\n";
     target->start_busy(random(fun/60) +1);
     target->receive_damage("kee", damage,me);
  me->add("kee",-100);
                       }

     else if( ski_value <  60 ){
     msg = "第五層 『"+HIY+"狂魔破空"+NOR+"』。\n\n";
     target->start_busy(random(fun/55) +1);
     target->receive_damage("kee", damage,me);
  me->add("kee",-100);
                       }

     else if( ski_value <  70 ){
     msg = "第六層 『"+HIY+"群魔亂舞"+NOR+"』。\n\n";
     target->start_busy(random(fun/50) +1);
     target->receive_damage("kee", damage,me);
  me->add("kee",-100);
                       }

     else if( ski_value <  80 ){
     msg = "第七層 『"+HIY+"天極魔殺"+NOR+"』。\n\n";
     target->start_busy(random(fun/60) +2);
     target->receive_damage("kee", damage,me);
  me->add("kee",-100);
                       }

     else if( ski_value <  90 ){
     msg = "第八層 『"+HIY+"鬥魔無生魂"+NOR+"』。\n\n";
     target->start_busy(random(fun/50) +2);
     target->receive_damage("kee", damage,me);
  me->add("kee",-100);
                       }

     else   {
     msg = "第九層 『"+HIY+"風魔狂轉業"+NOR+"』。\n\n";
     target->start_busy(random(fun/40) +2);
     target->receive_damage("kee", damage,me);
  me->add("kee",-100);
                      }

 if( target && ski_value>50 && (int)me->query("force")>100 && 50 < random(max_lv) ) {
 msg +=""+HIC+"$N對『"+HIR+"魔氣殺"+NOR+""+HIC+"』忽有頓誤,功\力不斷地提升起來:"+NOR+"\n";
  b=(ski_value/10);
  if(b>9) { b=9; }
  for(i=2;i<=b;i++)
  {
    switch(i)
    {
     case 2:
     msg +="第一層 『"+HIY+"魔氣無常"+NOR+"』。\n";
     break;
     case 3:
     msg +="第二層 『"+HIY+"火魔煞神"+NOR+"』。\n";
     break;
     case 4:
     msg +="第三層 『"+HIY+"商魂魔身"+NOR+"』。\n";
     break;
     case 5:
     msg +="第四層 『"+HIY+"劍魔滅世"+NOR+"』。\n";
     break;
     case 6:
     msg +="第五層 『"+HIY+"狂魔破空"+NOR+"』。\n";
     break; 
     case 7:
     msg +="第六層 『"+HIY+"群魔亂舞"+NOR+"』。\n";
     break;
     case 8:
     msg +="第七層 『"+HIY+"天極魔殺"+NOR+"』。\n";
     break;
     case 9:
     msg +="第八層 『"+HIY+"鬥魔無生魂"+NOR+"』。\n";
     break;
    }
     if( ((int)target->query_skill("move",1)
     + random((int)target->query_skill("dodge",1))*5 )
     <  ski_value + random((int)me->query_skill("dodge",1)*i
     + (int)target->query_skill("move",1)) )
     {
          target->receive_damage("kee",(fun*i/5),me);
          msg +="$n閃躲不及,因此中招了。\n";
          me->add("force",-10);
     }
     else
     {
          msg +="$N的攻擊被$n避了開來。\n";
  }
 }
}
    else {
     if( target ) {
     if( ski_value < 10 ){
      msg +=""+CYN+"$N的攻擊對敵人毫無影響。"+NOR+"\n";
      }
      else if( damage < 50 ) msg+=""+RED+"結果對$n勉強造成一處輕微創傷"+NOR+"\n";
      else if( damage < 150 ) msg +=""+YEL+"結果對$n造成一處創傷"+NOR+"\n";
      else if( damage < 300 ) msg +=""+MAG+"結果對$n造成頗為嚴重的創傷"+NOR+"\n";
      else if( damage < 450 ) msg +=""+CYN+"結果對$n造成相當嚴重的創傷"+NOR+"\n";
      else if( damage < 600 ) msg +=""+BOLD+"結果對$n造成十分嚴重的創傷"+NOR+"\n";
      else if( damage < 750 ) msg +=""+HIR+"結果對$n造成極其嚴重的創傷"+NOR+"\n";
      else msg +=""+HIC+"結果對$n造成非常可怕的嚴重創傷"+NOR+"\n";
         }
         }
if ((fun >=100) &&  (fun <150))
{//解第三進職有解到葉孤城那裡，才可以提升到150
        if (this_player()->query("upkee")  == 1)
function_improved ("manakee", random(me->query_skill("rain-throwing",1))*7);
}

if ((fun >=50) &&  (fun <100))
{//解過第二進職才可以提升到100
        if (this_player()->query("quest/memory")  == 1)
function_improved ("manakee", random(me->query_skill("rain-throwing",1))*5);
}
if (fun < 50)
{//解過第一進職才有資格用魔氣殺
function_improved ("manakee", random(me->query_skill("rain-throwing",1))*3);
                    }
     message_vision(msg, me, target);
        return 1;
}
