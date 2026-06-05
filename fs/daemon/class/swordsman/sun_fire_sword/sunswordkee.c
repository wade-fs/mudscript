// appo 所作..翻版前..請先告知
#include <ansi.h>
#include <combat.h>
inherit F_FUNCTION;
inherit SSERVER;
int clear_state(object me);
int perform(object me)
{
    string msg;
    int i,j;
    object ob,room,*enemy,target;
    room = environment(me);
    enemy=me->query_enemy(room);
    i=sizeof(enemy);
    target=offensive_target(me);
    if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type") != "sword")
	return notify_fail("你需要裝備一把劍ㄡ，才能施展『連陽七擊』。\n");
    if(me->query("quests/sunfire")!=1)
	return notify_fail("你的劍法的技巧不足無法使出『連陽七擊』。\n");
    if(me->query_temp("usesunsword",1))
	return notify_fail("你已經在用了。\n");
    if(!me->is_fighting())
	return notify_fail("『連陽七擊』只能在戰鬥中使用。\n");
    if(!target) 
	return notify_fail("沒敵人..打屁阿..。\n");

    if(environment(me)!=environment(target))
	return notify_fail("沒敵人..打屁阿..。\n");
    if(!enemy)
	return notify_fail("『沒敵人..打鳥歐。\n");
    if(me->query("force") < 1000)
	return notify_fail("你的內力不夠。\n");
    me->add("force",-100);
    message_vision(HIY + "\n
$N大開大闔，囤積身上連陽氣勁，只見無數光點漸漸往$N身上聚集...轉眼間.
       $N耀上天空..身上連陽氣勁瞬間轉移到配劍中...只聽$N大喊:
                            " + HIW + "『" + HIC + "～禁     斷～" + HIW + "』\n" + NOR + "
              " + HIG + "『" + HIR + "    破 ＊ 體 ＊ 連 ＊ 陽 ＊ 七 ＊ 絕 ＊ 斬  " + HIG + "』
                                      " + WHT + "██" + NOR + "
                                       " + RED + "█" + NOR + "
                               " + WHT + "██    " + RED + "█    " + WHT + "██" + NOR + "
                                " + RED + "█     " + RED + "█     " + RED + "█" + NOR + "
                         " + WHT + "██   " + RED + "█  " + CYN + "◢██◣  " + RED + "█   " + WHT + "██" + NOR + "
                          " + RED + "█    " + RED + "█   " + HIY + "｜朝｜" + NOR + "   " + RED + "█    " + RED + "█" + NOR + "
                   " + WHT + "██   " + RED + "█  " + CYN + "◢█◣ " + HIY + "｜陽｜" + NOR + " " + CYN + "◢█◣  " + RED + "█   " + WHT + "██" + NOR + "
                    " + RED + "█    " + RED + "█  " + HIC + "｜冬｜ " + HIY + " ◣◢  " + HIM + "｜夕｜" + NOR + "  " + RED + "█    " + RED + "█" + NOR + "
                    " + RED + "█  " + CYN + "◢█◣" + HIC + "｜陽｜ " + HIY + " ██  " + HIM + "｜陽｜" + NOR + "" + CYN + "◢█◣  " + RED + "█" + NOR + "
                    " + RED + "█  " + HIW + "｜豔｜" + HIC + "｜  ｜ " + HIY + " ██  " + HIM + "｜  ｜" + HIG + "｜暖｜" + NOR + "  " + RED + "█" + NOR + "
                  " + CYN + "◢█◣" + HIW + "｜陽｜" + HIC + "｜  ｜ " + HIY + " ██  " + HIM + "｜  ｜" + HIG + "｜陽｜" + NOR + "" + CYN + "◢█◣" + NOR + "
                  " + HIR + "｜烈｜" + HIW + "｜  ｜" + HIC + "｜  ｜ " + HIY + " ██  " + HIM + "｜  ｜" + HIG + "｜  ｜" + HIB + "｜殘｜" + NOR + "
	          " + HIR + "｜陽｜" + HIW + "｜  ｜" + HIC + "｜  ｜ " + HIY + " ██  " + HIM + "｜  ｜" + HIG + "｜  ｜" + HIB + "｜陽｜" + NOR + "
	          " + HIR + "｜  ｜" + HIW + "｜  ｜" + HIC + "｜  ｜ " + HIY + " ██  " + HIM + "｜  ｜" + HIG + "｜  ｜" + HIB + "｜  ｜" + NOR + "
                  " + HIR + "｜  ｜" + HIW + "｜  ｜" + HIC + "｜  ｜ " + HIY + " ██  " + HIM + "｜  ｜" + HIG + "｜  ｜" + HIB + "｜  ｜" + NOR + "
                  " + HIR + "｜  ｜" + HIW + "｜  ｜" + HIC + "｜  ｜  " + HIY + "◥◤  " + HIM + "｜  ｜" + HIG + "｜  ｜" + HIB + "｜  ｜" + NOR + "
	          " + HIR + "｜  ｜" + HIW + "｜  ｜" + HIC + "｜  ｜        " + HIM + "｜  ｜" + HIG + "｜  ｜" + HIB + "｜  ｜" + NOR + "
		  " + HIR + "｜  ｜" + HIW + "｜  ｜" + HIC + " ＼／         " + HIM + " ＼／ " + HIG + "｜  ｜" + HIB + "｜  ｜" + NOR + "
		  " + HIR + "｜  ｜" + HIW + "｜  ｜                    " + HIG + "｜  ｜" + HIB + "｜  ｜" + NOR + "
		  " + HIR + "｜  ｜ " + HIW + "＼／                     " + HIG + " ＼／ " + HIB + "｜  ｜" + NOR + "
		  " + HIR + "｜  ｜                                " + HIB + "｜  ｜" + NOR + "
 		   " + HIR + "＼／                                 " + HIB + " ＼／" + NOR + "
\n" + NOR,me);
     message_vision(HBYEL + "$N連陽劍氣，浩瀚無窮，瞬間整個空間接籠罩在金黃色的劍光下..\n" + NOR,me);
     for(j=0;j < i;j++)
     {
         if( !enemy[j] || environment(me) != environment(enemy[j]))
          continue;

           enemy[j]->receive_damage("kee",300+random(200));
           enemy[j]->start_busy(1);
           COMBAT_D->report_status(enemy[j]);
          }
           me->add("force",-50);
           me->start_busy(1);
        call_out("act1",0,msg,target,me);
        message_vision( NOR,me);
return 1;
}
int clear_state(object me)
{
  if(me) me->delete_temp("usesunsword");
  return notify_fail("『沒敵人..打鳥歐。\n");
}
int act1(string msg,object target,object me)
{
        object room,*enemy;
        int damage,i,j,kee_lv;
        if(!me) return clear_state(me);
        room = environment(me);
        enemy=me->query_enemy(room);
        target=offensive_target(me);
        kee_lv=me->query_function("sunswordkee");
        j=sizeof(enemy);
        if (j<1)
        {
        me->delete_temp("usesunsword");
        return notify_fail("『沒敵人..打鳥歐。\n");
        }
        else
        {
        damage = 50 + kee_lv + random(me->query_skill("sun_fire_sword"));
        message_vision(HBCYN + "$N身上連陽氣勁發出駭人光芒...\n" + NOR,me);
     for(i=0;i < j;i++)
     {
         if( !enemy[i] || environment(me) != environment(enemy[i]))
          continue;
 if(random((me->query("combat_exp")/10000)+me->query_skill("sun_fire_sword")*10+me->query_skill("dodge"))>random(enemy[i]->query_skill("dodge")+enemy[i]->query_skill("parry")+(enemy[i]->query("combat_exp")/20000)))
          {
           message_vision(HBCYN + "$N峰迴路轉內勁猛然上竄使出" + HIY + "『烈陽無情』," + HIC + "劍光如烈陽狂燄直奔$n心口。\n" + NOR,me,enemy[i]);
           message_vision(HIR + "$n閃躲不及，當場被此宏大的劍氣貫穿。\n" + NOR,me,enemy[i]);
           me->add("force",-50);
           enemy[i]->receive_damage("kee",damage);
           COMBAT_D->report_status(enemy[i]);
          }
         else {
           message_vision(HBCYN + "$N峰迴路轉內勁猛然上竄使出" + HIY + "『烈陽無情』," + HIC + "劍光如烈陽狂燄直奔$n心口。\n" + NOR,me,enemy[i]);
           message_vision(HIB + "$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n" + NOR,me,enemy[i]);
           me->add("force",-20);
          }
        }
        me->set_temp("usesunsword",1);
    if(kee_lv >=110) me->set("functions/sunswordkee/level",110);
    else function_improved("sunswordkee",random(20)+15);
        call_out("act2",1,msg,target,me);
        return 1;
        }
}

int act2(string msg,object target,object me)
{
        object room,*enemy;
        int damage,i,j,kee_lv;
        if(!me) return clear_state(me);
        kee_lv=me->query_function("sunswordkee");
        room = environment(me);
        enemy=me->query_enemy(room);
        target=offensive_target(me);
        j=sizeof(enemy);
        if (j<1)
        {
        me->delete_temp("usesunsword");
        return notify_fail("『沒敵人..打鳥歐。\n");
        }
        else
        {
        damage = 70 + kee_lv + random(me->query_skill("sun_fire_sword"));
        message_vision(HBCYN + "$N身上連陽氣勁發出駭人光芒...\n" + NOR,me);
     for(i=0;i < j;i++)
     {
         if( !enemy[i] || environment(me) != environment(enemy[i]))
          continue;
         if(random((me->query("combat_exp")/10000)+me->query_skill("sun_fire_sword")*10+me->query_skill("dodge"))>random(enemy[i]->query_skill("dodge")+enemy[i]->query_skill("parry")+(enemy[i]->query("combat_exp")/20000)))
          {
            message_vision(HBCYN + "$N收光為暈斂剛成柔，使出了" + HIY + "『殘陽千意』," + HIC + "瞬間身化殘影落步，劍尖直刺$n。\n" + NOR,me,enemy[i]);
            message_vision(HIR + "$n閃躲不及，當場被此宏大的劍氣貫穿。\n" + NOR,me,enemy[i]);
            me->add("force",-50);
            enemy[i]->receive_damage("kee",damage);
            COMBAT_D->report_status(enemy[i]);
          } else {
            message_vision(HBCYN + "$N收光為暈斂剛成柔，使出了" + HIY + "『殘陽千意』," + HIC + "瞬間身化殘影落步，劍尖直刺$n。\n" + NOR,me,enemy[i]);
            message_vision(HIB + "$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n" + NOR,me,enemy[i]);
            me->add("force",-20);
          }
        }
       me->set_temp("usesunsword",1);
    if(kee_lv >=110) me->set("functions/sunswordkee/level",110);
    else function_improved("sunswordkee",random(20)+15);
       call_out("act3",1,msg,target,me);
       return 1;
       }
}

int act3(string msg,object target,object me)
{
        object room,*enemy;
        int damage,i,j,kee_lv;
        if(!me) return clear_state(me);
        room = environment(me);
        enemy=me->query_enemy(room);
        target=offensive_target(me);
        kee_lv=me->query_function("sunswordkee");
        j=sizeof(enemy);
        if (j<1)
        {
        me->delete_temp("usesunsword");
        return notify_fail("『沒敵人..打鳥歐。\n");
        }
        else
        {
        damage = 90 + kee_lv + random(me->query_skill("sun_fire_sword"));
        message_vision(HBCYN + "$N身上連陽氣勁發出駭人光芒...\n" + NOR,me);
     for(i=0;i < j;i++)
     {
         if( !enemy[i] || environment(me) != environment(enemy[i]))
          continue;

 if(random((me->query("combat_exp")/10000)+me->query_skill("sun_fire_sword")*10+me->query_skill("dodge"))>random(enemy[i]->query_skill("dodge")+enemy[i]->query_skill("parry")+(enemy[i]->query("combat_exp")/20000)))

          {
           message_vision(HBCYN + "$N飛身高躍倏然使出了" + HIY + "『豔陽浩氣』," + HIC + "劍光如浩日輝煌，筆直落在$n眉心。\n" + NOR,me,enemy[i]);
           message_vision(HIR + "$n閃躲不及，當場被此宏大的劍氣貫穿。\n" + NOR,me,enemy[i]);
           me->add("force",-50);
           enemy[i]->receive_damage("kee",damage);
           enemy[i]->set_temp("no_power",1);
           enemy[i]->apply_condition("no_power",1);
           COMBAT_D->report_status(enemy[i]);
          } else {
           message_vision(HBCYN + "$N飛身高躍倏然使出了" + HIY + "『豔陽浩氣』," + HIC + "劍光如浩日輝煌，筆直落在$n眉心。\n" + NOR,me,enemy[i]);
           message_vision(HIB + "$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n" + NOR,me,enemy[i]);
           me->add("force",-20);
          }
        }
        me->set_temp("usesunsword",1);
    if(kee_lv >=110) me->set("functions/sunswordkee/level",110);
    else function_improved("sunswordkee",random(20)+15);
        call_out("act4",1,msg,enemy,me);
        return 1;
        }
}

int act4(string msg,object target,object me)
{
        object room,*enemy;
        int damage,i,j,kee_lv;
        if(!me) return clear_state(me);
        room = environment(me);
        enemy=me->query_enemy(room);
        target=offensive_target(me);
        kee_lv=me->query_function("sunswordkee");
        j=sizeof(enemy);
        if (j<1)
        {
        me->delete_temp("usesunsword");
        return notify_fail("『沒敵人..打鳥歐。\n");
        }
        else
        {
        damage = 100 + kee_lv + random(me->query_skill("sun_fire_sword"));
        message_vision(HBCYN + "$N身上連陽氣勁發出駭人光芒...\n" + NOR,me);
     for(i=0;i < j;i++)
     {
         if( !enemy[i] || environment(me) != environment(enemy[i]))
          continue;
 if(random((me->query("combat_exp")/10000)+me->query_skill("sun_fire_sword")*10+me->query_skill("dodge"))>random(enemy[i]->query_skill("dodge")+enemy[i]->query_skill("parry")+(enemy[i]->query("combat_exp")/20000)))

          {
           message_vision(HBCYN + "$N步若游光使出若有若無.使出" + HIY + "『暖陽無鋒』," + HIC + "劍氣烘燃，一流宏大的劍壓逼近$n。\n" + NOR,me,enemy[i]);
           message_vision(HIR + "$n閃躲不及，當場被此宏大的劍氣貫穿。\n" + NOR,me,enemy[i]);
           me->add("force",-50);
           enemy[i]->receive_damage("kee",damage);
           COMBAT_D->report_status(enemy[i]);
           } else {
           message_vision(HBCYN + "$N步若游光使出若有若無.使出" + HIY + "『暖陽無鋒』," + HIC + "劍氣烘燃，一流宏大的劍壓逼近$n。\n" + NOR,me,enemy[i]);
           message_vision(HIB + "$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n" + NOR,me,enemy[i]);
           me->add("force",-20);
          }
        }
               me->set_temp("usesunsword",1);
    if(kee_lv >=110) me->set("functions/sunswordkee/level",110);
    else function_improved("sunswordkee",random(20)+15);
         call_out("act5",1,msg,target,me);

        return 1;
        }
}
int act5(string msg,object target,object me)
{
        object room,*enemy;
        int damage,i,j,kee_lv;
        if(!me) return clear_state(me);
        room = environment(me);
        enemy=me->query_enemy(room);
        target=offensive_target(me);
        j=sizeof(enemy);
        kee_lv=me->query_function("sunswordkee");
        if (j<1)
        {
        me->delete_temp("usesunsword");
        return notify_fail("『沒敵人..打鳥歐。\n");
        }
        else
        {
        damage = 110 + kee_lv + random(me->query_skill("sun_fire_sword"));
        message_vision(HBCYN + "$N身上連陽氣勁發出駭人光芒...\n" + NOR,me);
     for(i=0;i < j;i++)
     {
         if( !enemy[i] || environment(me) != environment(enemy[i]))
          continue;
 if(random((me->query("combat_exp")/10000)+me->query_skill("sun_fire_sword")*10+me->query_skill("dodge"))>random(enemy[i]->query_skill("dodge")+enemy[i]->query_skill("parry")+(enemy[i]->query("combat_exp")/20000)))

          {
           message_vision(HBCYN + "$N撫劍如靜，心若止水劍光瀲豔，" + HIY + "『冬陽無意』," + HIC + "泛起波波殺意如刃向$n繞流而去。\n" + NOR,me,enemy[i]);
           message_vision(HIR + "$n閃躲不及，當場被此宏大的劍氣貫穿。\n" + NOR,me,enemy[i]);
           me->add("force",-50);
           enemy[i]->receive_damage("kee",damage);
           COMBAT_D->report_status(enemy[i]);
          } else {
           message_vision(HBCYN + "$N撫劍如靜，心若止水劍光瀲豔，" + HIY + "『冬陽無意』," + HIC + "泛起波波殺意如刃向$n繞流而去。\n" + NOR,me,enemy[i]);
           message_vision(HIB + "$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n" + NOR,me,enemy[i]);
           me->add("force",-20);
          }
        }
        me->set_temp("usesunsword",1);
    if(kee_lv >=110) me->set("functions/sunswordkee/level",110);
    else function_improved("sunswordkee",random(20)+15);
        call_out("act6",1,msg,target,me);
        return 1;
        }
}
int act6(string msg,object target,object me)
{
        object room,*enemy;
        int damage,i,j,kee_lv;
        if(!me) return clear_state(me);
        kee_lv=me->query_function("sunswordkee");
        room = environment(me);
        enemy=me->query_enemy(room);
        target=offensive_target(me);
        j=sizeof(enemy);
        if (j<1)
        {
        me->delete_temp("usesunsword");
        return notify_fail("『沒敵人..打鳥歐。\n");
        }
        else
        {
               damage = 120 + kee_lv + random(me->query_skill("sun_fire_sword"));
        message_vision(HBCYN + "$N身上連陽氣勁發出駭人光芒...\n" + NOR,me);
     for(i=0;i < j;i++)
     {
         if( !enemy[i] || environment(me) != environment(enemy[i]))
          continue;

if(random((me->query("combat_exp")/10000)+me->query_skill("sun_fire_sword")*10+me->query_skill("dodge"))>random(enemy[i]->query_skill("dodge")+enemy[i]->query_skill("parry")+(enemy[i]->query("combat_exp")/20000)))
          {
           message_vision(HBCYN + "$N將手上長劍" + HIC + "收鞘而入，聚精凝神使出" + HIY + "『朝陽豔氣』," + HIC + "只見劍光如晨光乍現劃向$n。\n" + NOR,me,enemy[i]);
           message_vision(HIR + "$n閃躲不及，當場被此宏大的劍氣貫穿。\n" + NOR,me,enemy[i]);
           me->add("force",-50);
           enemy[i]->receive_damage("kee",damage);
           enemy[i]->start_busy(2);
           enemy[i]->set_temp("no_power",1);
           enemy[i]->apply_condition("no_power",1);
           COMBAT_D->report_status(enemy[i]);
          } else {
           message_vision(HBCYN + "$N將手上長劍" + HIC + "收鞘而入，聚精凝神使出" + HIY + "『朝陽豔氣』," + HIC + "只見劍光如晨光乍現劃向$n。\n" + NOR,me,enemy[i]);
           message_vision(HIB + "$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，必過這要命的一招
                                在避過殺招之後，由於餘招不斷$n，亦被畫出好幾道傷口。\n" + NOR,me,enemy[i]);
           me->add("force",-20);
           enemy[i]->receive_damage("kee",50);
           enemy[i]->start_busy(1);
          }
        }
        me->set_temp("usesunsword",1);
    if(kee_lv >=110) me->set("functions/sunswordkee/level",110);
    else function_improved("sunswordkee",random(20)+15);
        call_out("act7",1,msg,target,me);
        return 1;
        }
}
int act7(string msg,object target,object me)
{
        object room,*enemy;
        int damage,i,j,kee_lv;
        if(!me) return clear_state(me);
        room = environment(me);
        enemy=me->query_enemy(room);
        target=offensive_target(me);
        j=sizeof(enemy);
        me->delete_temp("usesunsword");
        if (j<1)
        {
        me->delete_temp("usesunsword");
        return notify_fail("『沒敵人..打鳥歐。\n");
        }
        else
        {
        damage = 150 + kee_lv + random(me->query_skill("sun_fire_sword"));
        kee_lv=me->query_function("sunswordkee");
        message_vision(HBCYN + "$N身上連陽氣勁發出駭人光芒...\n" + NOR,me);
     for(i=0;i < j;i++)
     {
         if( !enemy[i] || environment(me) != environment(enemy[i]))
          continue;
if(random((me->query("combat_exp")/10000)+me->query_skill("sun_fire_sword")*10+me->query_skill("dodge"))>random(enemy[i]->query_skill("dodge")+enemy[i]->query_skill("parry")+(enemy[i]->query("combat_exp")/20000)))
            {
           message_vision(HBCYN + "$N手裡的配劍" + HIC + "泛出陣陣如暮色般的劍氣，" + HIY + "『夕陽無心』," + HIC + "猶如霞光滿天盡落$n身上。\n" + NOR,me,enemy[i]);
           message_vision(HIR + "$n閃躲不及，當場被此宏大的劍氣貫穿。\n" + NOR,me,enemy[i]);
           me->add("force",-50);
           enemy[i]->receive_damage("kee",damage);
           COMBAT_D->report_status(enemy[i]);
          } else {
           message_vision(HBCYN + "$N手裡的配劍" + HIC + "泛出陣陣如暮色般的劍氣，" + HIY + "『夕陽無心』," + HIC + "猶如霞光滿天盡落$n身上。\n" + NOR,me,enemy[i]);
           message_vision(HIB + "$n全神貫注盯緊$N，在費盡千辛萬苦之後總算找出破綻，閃過這一擊。\n" + NOR,me,enemy[i]);
           me->add("force",-20);
         }
     }
    if(kee_lv >=110) me->set("functions/sunswordkee/level",110);
    else function_improved("sunswordkee",random(20)+15);
    return 1;
  }
}

