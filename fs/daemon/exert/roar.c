// roar.c 震昏 by Onion
//加入,只要玩家set no_roar_player,就可以避掉在同一格的玩家by bss
#include <ansi.h>
int exert(object me,object target)
{

        object *enemy;
        int force_cost = me->query("max_force")/4+30;
        int valid,i;

        string *ATT_MESSAGE=({
        "但$N似乎早有準備﹐硬受$n一擊卻恍然無事的樣子。",
        "但$N只是受到一點驚嚇便恢復正常。",
        "結果$N似乎被$n嚇的目瞪口呆, 一時無法言語。",
        "$N覺得頭昏眼花，分不清楚東南西北。",
        "結果$N被$n的喝聲驚的跌坐在地上, 口吐白沫, 久久無法動作。",
        "只見得$N雙手摀耳, 慘叫一聲, 昏厥了過去。"
        });
        if( me->query("class") != "fighter" )
          return notify_fail("只有武者才能使出。\n");
        if( environment(me)->query("no_fight")==1 )
          return notify_fail("這裡不準戰鬥。\n");
        if( force_cost > me->query("force") )
          return notify_fail("你的內力不夠。\n");
        if(me->query_temp("no_roar"))
          return notify_fail("因為蠍毒的作用，你一句話也說不出來。\n");

        message_vision("\n$N大喝一聲, 將全身內力貫注丹田, 忽然間一股震耳欲聾的聲音罔若平地焦雷般的半空爆開﹗\n",me);
        me->add("force",-force_cost);
        enemy = all_inventory( environment(me) );
        for( i=0; i<sizeof(enemy); i++ )
        if( enemy[i]->is_character() && !enemy[i]->is_corpse() && living(enemy[i]) &&
            !enemy[i]->query_temp("roared") && !enemy[i]->query("no_kill") && enemy[i]!=me &&
            !in_edit(enemy[i]) && !in_input(enemy[i]) && !enemy[i]->query_temp("netdead") &&
  !wizardp(enemy[i]) && !enemy[i]->query("horse"))
        {
    if(enemy[i]->query("family/privs") == -1 &&  uptime() % 900 < 300 )
      continue;
// 加入 對 16歲以下的人 roar無效 by anmy
        if(!(me->query("env/no_roar_player") && userp(enemy[i]))){
        if(enemy[i]->query("age")>=16)
        {
                if( me->query("max_force") > enemy[i]->query("max_force") )
                        valid=random(sizeof(ATT_MESSAGE)-1)+1;
                else
                        valid=random(sizeof(ATT_MESSAGE)-1);
                message_vision(""+ATT_MESSAGE[valid]+"\n",enemy[i],me);
                if( valid == sizeof(ATT_MESSAGE)-1 )
                        enemy[i]->unconcious();
                else
                {
                        enemy[i]->kill_ob(me);
                        me->kill_ob(enemy[i]);
                        enemy[i]->start_busy(valid);
                        enemy[i]->receive_damage("kee", force_cost/4);
                        COMBAT_D->report_status(enemy[i],1);
                }
                if(enemy[i])
                enemy[i]->set_temp("roared",1);
        }
        }
        }
        return 1;
}
